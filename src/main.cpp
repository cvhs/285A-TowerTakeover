#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LF                   motor         1               
// RF                   motor         2               
// RB                   motor         9               
// LB                   motor         10              
// L1                   motor         4               
// L2                   motor         5               
// Controller1          controller                    
// IN1                  motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;


void pre_auton(void) {
  vexcodeInit();
}

void autonomous(void) {

}


void usercontrol(void) {
  while (1) {

    double vLEFT_VERTICAL = (double)Controller1.Axis3.value() * 100 / 127;
    double vRIGHT_VERTICAL = (double)Controller1.Axis2.value() * 100 / 127;
    double vRIGHT_HORIZONTAL = (double)Controller1.Axis1.value() * 100 / 127;
    double vLEFT_HORIZONTAL = (double)Controller1.Axis4.value() * 100 / 127;

    LF.spin(directionType::fwd, vLEFT_VERTICAL + vRIGHT_HORIZONTAL + vLEFT_HORIZONTAL, velocityUnits::pct);
    LB.spin(directionType::fwd, vLEFT_VERTICAL + vRIGHT_HORIZONTAL - vLEFT_HORIZONTAL, velocityUnits::pct);
    RF.spin(directionType::fwd, -(vLEFT_VERTICAL - vRIGHT_HORIZONTAL - vLEFT_HORIZONTAL), velocityUnits::pct);
    RB.spin(directionType::fwd, -(vLEFT_VERTICAL - vRIGHT_HORIZONTAL + vLEFT_HORIZONTAL), velocityUnits::pct);
  
    if (Controller1.ButtonR2.pressing()) {
      L1.spin(directionType::fwd, vRIGHT_VERTICAL, velocityUnits::pct);
      L2.spin(directionType::fwd, -vRIGHT_VERTICAL, velocityUnits::pct);
    } else {
      L1.spin(directionType::fwd, 0, velocityUnits::pct);
      L1.setStopping(hold);
      L2.spin(directionType::fwd, 0, velocityUnits::pct);
      L2.setStopping(hold);
    }

    if (Controller1.ButtonL1.pressing()) {
      IN1.spinToPosition(110, degrees); 
    } else if (Controller1.ButtonL2.pressing()) {
      IN1.spinToPosition(0, degrees);
    }


    wait(20, msec);
  }
}












int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
