// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "AutoRight.h"
#include "AutoDrive.h"
#include "AutoIntakeReverse.h"
#include "AutoTurn.h"
#include "../Robot.h"
#include "ElevatorUP.h"
#include "IntakeOpen.h"
#include "TimedElevatorUP.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoRight::AutoRight() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

	std::string goalPositions = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		if(goalPositions[0] == 'R'){
			// switch
			AddSequential(new AutoDrive(168, true, 5)); // move to center of the scale
			AddSequential(new AutoTurn(90, true, 3)); // turn to face it
			AddSequential(new IntakeOpen()); // lower the intake
			AddSequential(new AutoDrive(42, true, 2)); // get right up against the close scale
			AddSequential(new TimedElevatorUP(1.5)); // safety first when raising the elevator
			AddSequential(new AutoIntakeReverse(2));
		}

		else if(goalPositions[1] == 'L'){
			// scale
			AddSequential(new AutoDrive(324, true, 6)); // move to center of the scale
			AddSequential(new AutoTurn(90, true, 3)); // turn to face it
			AddSequential(new IntakeOpen()); // lower the intake maybe this OPENS the intake? I mean, if I had to guess...
			AddSequential(new ElevatorUP()); // I'm pretty sure that the elevator is the long thing, but I still don't know.
			AddSequential(new AutoDrive(42, true, 2)); // get right up against the scale, overshooting is good cause the bot might need to go up a slope, from what i can get from the picture.
			AddSequential(new AutoIntakeReverse(2));
		}

		else {
			// going straight (to cross that bonus line)
			AddSequential(new AutoDrive(196, true, 5)); // move where i think the best spot for the driver to begin control would be, right after the close scale a little after the "PLATFORM ZONE" begins.
		}

              // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
              // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=COMMAND_DECLARATIONS
 };
