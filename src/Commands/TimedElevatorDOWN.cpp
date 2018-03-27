// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "TimedElevatorDOWN.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

TimedElevatorDOWN::TimedElevatorDOWN(double timeout): frc::Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator.get());
	mTimeout = timeout;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void TimedElevatorDOWN::Initialize() {
	SetTimeout(mTimeout); // 1 SECOND IS ~14 INCHES | 2 IS ~27.5 INCHES | 1.5 is close enough
}

// Called repeatedly when this Command is scheduled to run
void TimedElevatorDOWN::Execute() {
	Robot::elevator->lift->Set(0.7);
}

// Make this return true when this Command no longer needs to run execute()
bool TimedElevatorDOWN::IsFinished() {
	return IsTimedOut() || !Robot::elevator->switchBottom->Get();
}

// Called once after isFinished returns true
void TimedElevatorDOWN::End() {
	Robot::elevator->lift->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TimedElevatorDOWN::Interrupted() {

}