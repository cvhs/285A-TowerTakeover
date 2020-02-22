#include "vex.h"
#include "assistants/assistants.h"
#include "autons/autons.h"
using namespace vex;
competition Competition;
 
void pre_auton( void ) {
  calibrateGyro();
}
 
void autonomous( void ) {
  executeAuton();
}
 
 
int driveTask() {
  while(1) {
    double vLEFT_VERTICAL = (double)Controller1.Axis3.value() * 12 / 127;
    double vRIGHT_VERTICAL = (double)Controller1.Axis2.value() * 12 / 127;
    double vRIGHT_HORIZONTAL = (double)Controller1.Axis1.value() * 12 / 127;
    double vLEFT_HORIZONTAL = (double)Controller1.Axis4.value() * 12 / 127;

    LF.spin(directionType::fwd, vLEFT_VERTICAL, voltageUnits::volt);
    LB.spin(directionType::fwd, vLEFT_VERTICAL, voltageUnits::volt);
    RF.spin(directionType::fwd, -vRIGHT_VERTICAL, voltageUnits::volt);
    RB.spin(directionType::fwd, -vRIGHT_VERTICAL, voltageUnits::volt);

    vex::task::sleep( 20 );
    
  }
  return(0);
}
 
 
void usercontrol( void ) {
 
 vex::task d( driveTask );
 // User control code here, inside the loop
 while (1) {
   
 
   if (Controller1.ButtonR1.pressing()) {
     IL.spin(directionType::fwd, -12, voltageUnits::volt);
     IR.spin(directionType::fwd, 12, voltageUnits::volt);
   } else if (Controller1.ButtonR2.pressing()) {
     IL.spin(directionType::fwd, 12, voltageUnits::volt);
     IR.spin(directionType::fwd, -12, voltageUnits::volt);
   } else {
     IL.stop(brakeType::hold);
     IR.stop(brakeType::hold);
   }
 
   if (Controller1.ButtonY.pressing()) {
     while(Controller1.ButtonY.pressing()) {}
     while(CubeLift.rotation(rotationUnits::deg) < 1600) {
       liftUp();
     }
     CubeLift.stop(brakeType::hold);
   }

   if (Controller1.ButtonLeft.pressing()) {
     while(Controller1.ButtonLeft.pressing()) {}
     deploy();
   }

   if (Controller1.ButtonRight.pressing()) {
     turnIMU(90);
   }
 
 
   // Macro To Intake  1048 784
 
   if (Controller1.ButtonX.pressing()) {
      while(Controller1.ButtonX.pressing()) {}
      CubeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.rotateTo(-300, rotationUnits::deg);
      CubeLift.rotateTo(400, rotationUnits::deg);
      IntakeLift.rotateTo(-1200, rotationUnits::deg);
      CubeLift.rotateTo(600, rotationUnits::deg);
   }
 
   if (Controller1.ButtonA.pressing()) {
     while(Controller1.ButtonA.pressing()) {}
      CubeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.rotateTo(-300, rotationUnits::deg);
      CubeLift.rotateTo(350, rotationUnits::deg);
      IntakeLift.rotateTo(-930, rotationUnits::deg);
   }
 
   if (Controller1.ButtonB.pressing()) {
     while(Controller1.ButtonB.pressing()) {}
     CubeLift.setVelocity(100, percentUnits::pct);
     IntakeLift.setVelocity(100, percentUnits::pct);
     CubeLift.startRotateTo(0, rotationUnits::deg);
     IntakeLift.rotateTo(0, rotationUnits::deg);
   }
 
   if (Controller1.ButtonUp.pressing()) {
 
     IntakeLift.spin(directionType::fwd, -12, voltageUnits::volt);
   } else if (Controller1.ButtonDown.pressing()) {
     IntakeLift.spin(directionType::fwd, 12, voltageUnits::volt);
   } else {
     IntakeLift.stop(brakeType::hold);
   }
  
   if (Controller1.ButtonL1.pressing()) {
     CubeLift.spin(directionType::fwd, -9, voltageUnits::volt);
     while(Controller1.ButtonL1.pressing()) {}
     CubeLift.stop(brakeType::hold);
   } else if (Controller1.ButtonL2.pressing()) {
     while(Controller1.ButtonL1.pressing()) {
       liftUp();
     }
     CubeLift.stop(brakeType::hold);
   }
  
   vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
 }
 
}
 
 
 
//
// Main will set up the competition functions and callbacks.
//
int main() {
   //Set up callbacks for autonomous and driver control periods.
   Competition.autonomous( autonomous );
   Competition.drivercontrol( usercontrol );
  
   //Run the pre-autonomous function.
   pre_auton();
     
   //Prevent main from exiting with an infinite loop.                       
   while(1) {
     vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
     double val = Selector.value(percentUnits::pct);
     double sectorSpan = 100 / 7;
     Controller1.Screen.clearLine();
     if (val <= sectorSpan) {
       Controller1.Screen.print("Skills");
     } else if (val <= 2*sectorSpan) {
       Controller1.Screen.print("Blue Right (BIG GOAL)");
     } else if (val <= 3*sectorSpan) {
       Controller1.Screen.print("Blue 5 Cube");
     } else if  (val <= 4*sectorSpan) {
       Controller1.Screen.print("Blue 6 Cube");
     } else if  (val <= 5*sectorSpan) {
       Controller1.Screen.print("Red Left (BIG GOAL)");
     } else if  (val <= 6*sectorSpan) {
       Controller1.Screen.print("Red 5 Cube");
     } else if  (val <= 7*sectorSpan) {
       Controller1.Screen.print("Red 6 Cube");
     }
   }   
     
}

