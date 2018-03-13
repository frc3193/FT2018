// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoCenter.h"
#include "Commands/AutoDoNothing.h"
#include "Commands/AutoGoStraight.h"
#include "Commands/AutoLeft.h"
#include "Commands/AutoRight.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ChassisShift.h"
#include "Commands/ChassisTankDrive.h"
#include "Commands/DoNothing.h"
#include "Commands/ElevatorDOWN.h"
#include "Commands/ElevatorDefault.h"
#include "Commands/ElevatorUP.h"
#include "Commands/IntakeClose.h"
#include "Commands/IntakeDefault.h"
#include "Commands/IntakeForward.h"
#include "Commands/IntakeOpen.h"
#include "Commands/IntakeReverse.h"
#include "Commands/PressureUP.h"
#include "Commands/RampDeploy.h"
#include "Commands/RampLeftToggle.h"
#include "Commands/RampRightToggle.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES


OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    coDriver.reset(new frc::Joystick(1));
    
    cRStick.reset(new frc::JoystickButton(coDriver.get(), 10));
    cRStick->WhenPressed(new RampRightToggle());
    cLStick.reset(new frc::JoystickButton(coDriver.get(), 9));
    cLStick->WhenPressed(new RampLeftToggle());
    cRBumper.reset(new frc::JoystickButton(coDriver.get(), 6));
    cRBumper->WhenPressed(new IntakeOpen());
    cLBumper.reset(new frc::JoystickButton(coDriver.get(), 5));
    cLBumper->WhenPressed(new IntakeClose());
    cY.reset(new frc::JoystickButton(coDriver.get(), 4));
    cY->WhileHeld(new ElevatorUP());
    cX.reset(new frc::JoystickButton(coDriver.get(), 3));
    cX->WhileHeld(new IntakeReverse());
    cB.reset(new frc::JoystickButton(coDriver.get(), 2));
    cB->WhileHeld(new IntakeForward());
    cA.reset(new frc::JoystickButton(coDriver.get(), 1));
    cA->WhileHeld(new ElevatorDOWN());
    driver.reset(new frc::Joystick(0));
    
    dRStick.reset(new frc::JoystickButton(driver.get(), 10));
    dRStick->WhenPressed(new ChassisShift());
    dLStick.reset(new frc::JoystickButton(driver.get(), 9));
    dLStick->WhenPressed(new ChassisShift());
    dRBumper.reset(new frc::JoystickButton(driver.get(), 6));
    dRBumper->WhileHeld(new DoNothing());
    dLBumper.reset(new frc::JoystickButton(driver.get(), 5));
    dLBumper->WhileHeld(new DoNothing());
    dX.reset(new frc::JoystickButton(driver.get(), 3));
    dX->WhileHeld(new DoNothing());
    dB.reset(new frc::JoystickButton(driver.get(), 2));
    dB->WhileHeld(new DoNothing());
    dA.reset(new frc::JoystickButton(driver.get(), 1));
    dA->WhileHeld(new DoNothing());

    // SmartDashboard Buttons
    frc::SmartDashboard::PutData("RampRightToggle", new RampRightToggle());
    frc::SmartDashboard::PutData("RampLeftToggle", new RampLeftToggle());
    frc::SmartDashboard::PutData("RampDeploy", new RampDeploy());
    frc::SmartDashboard::PutData("PressureUP", new PressureUP());
    frc::SmartDashboard::PutData("IntakeReverse", new IntakeReverse());
    frc::SmartDashboard::PutData("IntakeOpen", new IntakeOpen());
    frc::SmartDashboard::PutData("IntakeForward", new IntakeForward());
    frc::SmartDashboard::PutData("IntakeClose", new IntakeClose());
    frc::SmartDashboard::PutData("ElevatorUP", new ElevatorUP());
    frc::SmartDashboard::PutData("ElevatorDOWN", new ElevatorDOWN());
    frc::SmartDashboard::PutData("ChassisTankDrive", new ChassisTankDrive());
    frc::SmartDashboard::PutData("ChassisShift", new ChassisShift());
    frc::SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    fightStick.reset(new frc::Joystick(2));

    fR3.reset(new frc::JoystickButton(coDriver.get(), 10));
    fR3->WhenPressed(new RampRightToggle());
    fL3.reset(new frc::JoystickButton(coDriver.get(), 9));
    fL3->WhenPressed(new RampLeftToggle());
    fOP.reset(new frc::JoystickButton(coDriver.get(), 8));
    fOP->WhenPressed(new RampDeploy());
    fSH.reset(new frc::JoystickButton(coDriver.get(), 7));
    fSH->WhenPressed(new DoNothing());
    fRB.reset(new frc::JoystickButton(coDriver.get(), 6));
    fRB->WhenPressed(new DoNothing());
    fLB.reset(new frc::JoystickButton(coDriver.get(), 5));
    fLB->WhenPressed(new DoNothing());
    fY.reset(new frc::JoystickButton(coDriver.get(), 4));
    fY->WhileHeld(new IntakeForward());
    fX.reset(new frc::JoystickButton(coDriver.get(), 3));
    fX->WhileHeld(new IntakeReverse());
    fB.reset(new frc::JoystickButton(coDriver.get(), 2));
    fB->WhileHeld(new DoNothing());
    fA.reset(new frc::JoystickButton(coDriver.get(), 1));
    fA->WhileHeld(new DoNothing());
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<frc::Joystick> OI::getdriver() {
   return driver;
}

std::shared_ptr<frc::Joystick> OI::getcoDriver() {
   return coDriver;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
std::shared_ptr<frc::Joystick> OI::getfightStick() {
   return fightStick;
}
