// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoCenter.h"
#include "AutoDrive.h"
#include "AutoIntakeReverse.h"
#include "AutoTurn.h"
#include "../Robot.h"
#include "IntakeOpen.h"
#include "TimedElevatorUP.h"

const int ROBOT_PLACEMENT = 130; // INCHES. 130 is the edge of the tape.  Get the distance of the robot from the point where the right half of the alliance wall connects with the angled part, the teleporter or whatever it's called to the center of the center of the robot.

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoCenter::AutoCenter() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	std::string goalPositions = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		if(goalPositions[0] == 'R'){
			AddSequential(new AutoDrive(78, true, 3)); // Go 6.5' out from the alliance wall so it doesn't clip anything while turning.
			AddSequential(new AutoTurn(90, true, 2)); // turn 90 degrees in the correct direction
			AddSequential(new AutoDrive(ROBOT_PLACEMENT - 16 + 48 - 162 + 72, true, 3)); // line up the robot with the side edge of the switch
			AddSequential(new AutoTurn(45, false, 2)); // turn 45 degrees towards the switch
			AddSequential(new AutoDrive(93.34, true, 3)); // align robot with near side of the switch
			AddSequential(new AutoTurn(45, false, 2)); // turn to face straight (back side to alliance wall)
			AddSequential(new AutoDrive(24, true, 1)); // center with the switch
			AddSequential(new AutoTurn(90, false, 2)); // face switch.
			AddSequential(new IntakeOpen()); // lower the intake
			AddSequential(new AutoDrive(42, true, 1)); // move as close as possible to the switch (Need short timeout)
			AddSequential(new TimedElevatorUP(1.5)); // raise elevator, need servos though.
			AddSequential(new AutoIntakeReverse(2));
		}
		//else if(goalPositions[0] == 'L'){
		else{
			AddSequential(new AutoDrive(78, true, 3)); // Go 6.5' out from the alliance wall so it doesn't clip anything while turning.
			AddSequential(new AutoTurn(90, false, 2)); // turn 90 degrees in the correct direction
			AddSequential(new AutoDrive(-(ROBOT_PLACEMENT + 48 - 162) + 72, true, 3)); // line up the robot with the side edge of the switch
			AddSequential(new AutoTurn(45, true, 2)); // turn 45 degrees towards the switch
			AddSequential(new AutoDrive(93.34, true, 3)); // align robot with near side of the switch
			AddSequential(new AutoTurn(45, true, 2)); // turn to face straight (back side to alliance wall)
			AddSequential(new AutoDrive(24, true, 1)); // center with the switch
			AddSequential(new AutoTurn(90, true, 2)); // face switch.
			AddSequential(new IntakeOpen()); // lower the intake
			AddSequential(new AutoDrive(42, true, 1)); // move as close as possible to the switch (Need short timeout)
			AddSequential(new TimedElevatorUP(1.5)); // raise elevator, need servos though.
			AddSequential(new AutoIntakeReverse(2));
		}

              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
              // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 }