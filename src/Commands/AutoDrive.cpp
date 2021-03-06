// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include <chrono>
#include "AutoDrive.h"

const int WHEEL_DIAMETER = 5;
const float PI = 3.1415;

AutoDrive::AutoDrive(float desiredInches, bool forward, double timeout): Command(), mDesiredInches(desiredInches),
																		 mForward(forward), mTimeout(timeout) {
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	currentAngle = 0;
	kP_ang = 0.03;
	currentDist = 0;
	distError = 0;
	kP_dist = 0.15;
}


// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	SetTimeout(mTimeout);
	Robot::chassis->gyro->Reset();
	Robot::chassis->driveEncoder->Reset();
	Robot::chassis->shifter->Set(DoubleSolenoid::kReverse);
}

// Called repeatedly when this Command is scheduled to run currentAngle * kP_ang)
void AutoDrive::Execute() {
	currentAngle = Robot::chassis->gyro->GetAngle();
	// encoder returns degrees of rotation. Below converts this to inches.
	currentDist = abs(Robot::chassis->driveEncoder->GetDistance()) / 360 * WHEEL_DIAMETER * PI;
	//currentDist = abs(Robot::chassis->driveEncoder->GetValue())   // 0-360 resets to 0 after 360, this kind of encoder is butterly useless. (for our case, says it can be used as a gyro, but ask those around you: "why?")
	distError = mDesiredInches - currentDist;

	// If forward, drive forward.
	if(mForward)
	{
		Robot::chassis->robotDrive->Drive(-0.2 - (distError * kP_dist / mDesiredInches), currentAngle*kP_ang*-1);
	}

	// else, drive backwards
	else
	{
		Robot::chassis->robotDrive->Drive(0.2 + (distError * kP_dist / mDesiredInches), currentAngle*kP_ang);
	}

	SmartDashboard::PutNumber("autoAngle", currentAngle);
	SmartDashboard::PutNumber("autoDist", currentDist);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
    return (distError <= 0.33 || IsTimedOut());
}

// Called once after isFinished returns true
void AutoDrive::End() {
	if(mForward){
		Robot::chassis->robotDrive->Drive(0.6, currentAngle*kP_ang);
	}
	else
	{
		Robot::chassis->robotDrive->Drive(-0.6, currentAngle*kP_ang*-1);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	Robot::chassis->leftA->Set(0.0);
	Robot::chassis->leftB->Set(0.0); //if there's more, you should add more. but we split 'em so it's all good as in: B = (B+C)
	Robot::chassis->rightA->Set(0.0);
	Robot::chassis->rightB->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {
	Robot::chassis->leftA->Set(0.0);
	Robot::chassis->leftB->Set(0.0);
	Robot::chassis->rightA->Set(0.0);
	Robot::chassis->rightB->Set(0.0);
}
