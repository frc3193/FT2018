// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoTurn.h"


AutoTurn::AutoTurn(float desiredDegrees, bool clockwise, double timeout): Command(), mDesiredDegrees(desiredDegrees),
																		  mClockwise(clockwise), mTimeout(timeout){
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	angleError = 0;
	currentDegrees = 0;
	kP = 0.8;
}


// Called just before this Command runs the first time
void AutoTurn::Initialize() {
	SetTimeout(mTimeout);
	Robot::chassis->gyro->Reset();

}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {
	currentDegrees = Robot::chassis->gyro->GetAngle();

	angleError = mDesiredDegrees - abs(currentDegrees);
	if(mClockwise)
	{
		//currentDegrees = Robot::chassis->gyro->GetAngle();
		Robot::chassis->leftA->Set(-0.2 - angleError/mDesiredDegrees*kP);
		Robot::chassis->leftB->Set(-0.2 - angleError/mDesiredDegrees*kP);
		Robot::chassis->rightA->Set(-0.2 - angleError/mDesiredDegrees*kP);
		Robot::chassis->rightB->Set(-0.2 - angleError/mDesiredDegrees*kP);
		SmartDashboard::PutNumber("MotorSpeed", (-0.2 - angleError/mDesiredDegrees*kP));
	}
	else
	{
		//currentDegrees = (Robot::chassis->gyro->GetAngle() *-1);
		Robot::chassis->leftA->Set(0.3 + angleError/mDesiredDegrees*kP);
		Robot::chassis->leftB->Set(0.3 + angleError/mDesiredDegrees*kP);
		Robot::chassis->rightA->Set(0.3 + angleError/mDesiredDegrees*kP);
		Robot::chassis->rightB->Set(0.3 + angleError/mDesiredDegrees*kP);
		SmartDashboard::PutNumber("MotorSpeed", (0.3 + angleError/mDesiredDegrees*kP));
	}
	SmartDashboard::PutNumber("TurnError", angleError);
	SmartDashboard::PutNumber("currentDeg", currentDegrees);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() {

    return (angleError <= 0.75  || IsTimedOut());
}

// Called once after isFinished returns true
void AutoTurn::End() {
	Robot::chassis->leftA->Set(0.0);
	Robot::chassis->leftB->Set(0.0);
	Robot::chassis->rightA->Set(0.0);
	Robot::chassis->rightB->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {
	Robot::chassis->leftA->Set(0.0);
	Robot::chassis->leftB->Set(0.0);
	Robot::chassis->rightA->Set(0.0);
	Robot::chassis->rightB->Set(0.0);
}
