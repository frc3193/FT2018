// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RampLeftToggle.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RampLeftToggle::RampLeftToggle(): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::ramp.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void RampLeftToggle::Initialize() {
	if (Robot::ramp->left->Get() == frc::DoubleSolenoid::Value::kForward) {
		Robot::ramp->left->Set(frc::DoubleSolenoid::Value::kReverse);
	}
	else {
		Robot::ramp->left->Set(frc::DoubleSolenoid::Value::kForward);
	}
}

// Called repeatedly when this Command is scheduled to run
void RampLeftToggle::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool RampLeftToggle::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void RampLeftToggle::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RampLeftToggle::Interrupted() {

}
