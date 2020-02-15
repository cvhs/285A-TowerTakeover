/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\ankua                                            */
/*    Created:      Sat Nov 02 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::competition
brain BrIAN;
vex::competition Competition;
controller Controller;

vex::motor LF = motor(PORT12);
vex::motor RF = motor(PORT11);
vex::motor LB = motor(PORT14);
vex::motor RB = motor(PORT13);
vex::motor IL = motor(PORT10);
vex::motor IR = motor(PORT19);

motor IntakeLift = motor(PORT8);
motor CubeLift = motor(PORT15);
pot Selector = pot(BrIAN.ThreeWirePort.A);
// define your global instances of motors and other devices here


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ..
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void deploy() {
  IntakeLift.setVelocity(100, percentUnits::pct);
  IntakeLift.rotateTo(-900, rotationUnits::deg);
  IntakeLift.rotateTo(0, rotationUnits::deg);

}

void setIntakePct(double v) {
  IL.spin(directionType::fwd, (v/100)*12, voltageUnits::volt);
  IR.spin(directionType::fwd, (v/100)*-12, voltageUnits::volt);
}

void intakeMove(double deg) {
  IL.startRotateFor(directionType::fwd, deg, rotationUnits::deg, 100, velocityUnits::pct);
  IR.startRotateFor(directionType::fwd, -deg, rotationUnits::deg, 100, velocityUnits::pct);
}


void setVel(double v) {
  LF.setVelocity(v, percentUnits::pct);
  RF.setVelocity(v, percentUnits::pct);
  LB.setVelocity(v, percentUnits::pct);
  RB.setVelocity(v, percentUnits::pct);
}

void setStopping(vex::brakeType stop) {
  LF.setStopping(stop);
  RF.setStopping(stop);
  LB.setStopping(stop);
  RB.setStopping(stop);
}

void moveForward(double deg, double vel) {
  setVel(vel);
  LF.startRotateFor(deg, rotationUnits::deg);
  RF.startRotateFor(-deg, rotationUnits::deg);
  LB.startRotateFor(deg, rotationUnits::deg);
  RB.startRotateFor(-deg, rotationUnits::deg);
  while(!LF.isDone()){}
  while(!RF.isDone()){}
  while(!LB.isDone()){}
  while(!RB.isDone()){}
}

void turnClockwise(double deg, double vel) {
  setVel(vel);
  LF.startRotateFor(deg, rotationUnits::deg);
  RF.startRotateFor(deg, rotationUnits::deg);
  LB.startRotateFor(deg, rotationUnits::deg);
  RB.startRotateFor(deg, rotationUnits::deg);
  while(!LF.isDone()){}
  while(!RF.isDone()){}
  while(!LB.isDone()){}
  while(!RB.isDone()){}
}

void liftCubes() {
  while (CubeLift.rotation(rotationUnits::deg) < 1200) {;
    if (CubeLift.rotation(rotationUnits::deg) < 300) {
      IL.spin(directionType::fwd, -1, voltageUnits::volt);
      IR.spin(directionType::fwd, 1, voltageUnits::volt);
      CubeLift.spin(directionType::fwd, 12, voltageUnits::volt);
    } else if (CubeLift.rotation(rotationUnits::deg) < 600) {
      IL.spin(directionType::fwd, -1, voltageUnits::volt);
      IR.spin(directionType::fwd, 1, voltageUnits::volt);
      CubeLift.spin(directionType::fwd, 9, voltageUnits::volt);
    } else {
      IL.spin(directionType::fwd, -1, voltageUnits::volt);
      IR.spin(directionType::fwd, 1, voltageUnits::volt);
      CubeLift.spin(directionType::fwd, 5, voltageUnits::volt);
    }
  }
  CubeLift.stop();
}


void backOut() {
  IL.spin(directionType::fwd, -3, voltageUnits::volt);
  IR.spin(directionType::fwd, 3, voltageUnits::volt);
  LF.spin(directionType::fwd, -3, voltageUnits::volt);
  LB.spin(directionType::fwd, -3, voltageUnits::volt);
  RF.spin(directionType::fwd, 3, voltageUnits::volt);
  RB.spin(directionType::fwd, 3, voltageUnits::volt);

}
void basicDriveBackForth() {
  LF.spin(directionType::fwd, -70, percentUnits::pct);
  LB.spin(directionType::fwd, -70, percentUnits::pct);
  RF.spin(directionType::fwd, 70, percentUnits::pct);
  RB.spin(directionType::fwd, 70, percentUnits::pct);
  vex::task::sleep(2000);
  LF.spin(directionType::fwd, 70, percentUnits::pct);
  LB.spin(directionType::fwd, 70, percentUnits::pct);
  RF.spin(directionType::fwd, -70, percentUnits::pct);
  RB.spin(directionType::fwd, -70, percentUnits::pct);
  vex::task::sleep(1000);
  LF.spin(directionType::fwd, 0, percentUnits::pct);
  LB.spin(directionType::fwd, 0, percentUnits::pct);
  RF.spin(directionType::fwd, 0, percentUnits::pct);
  RB.spin(directionType::fwd, 0, percentUnits::pct);
}


void blueLeft() {
  setIntakePct(100);
  vex::task::sleep(200);
  moveForward(1200, 23);
  vex::task::sleep(100);
  turnClockwise(-375, 30);
  vex::task::sleep(100);
  setIntakePct(0);
  moveForward(880, 50);
  intakeMove(-600);
  vex::task::sleep(700);
  liftCubes();
  moveForward(40, 20);
  vex::task::sleep(200);
  backOut();
  vex::task::sleep(500);
}

void redRight() {
  setIntakePct(100);
  vex::task::sleep(200);
  moveForward(1200, 23);
  vex::task::sleep(100);
  turnClockwise(390, 30);
  vex::task::sleep(100);
  setIntakePct(0);
  moveForward(880, 50);
  intakeMove(-600);
  vex::task::sleep(700);
  liftCubes();
  moveForward(40, 20);
  vex::task::sleep(200);
  backOut();
  vex::task::sleep(500);
}

void blueRight() {
  moveForward(-1200, 23);
  moveForward(1200, 23);
  /*setIntakePct(100);
  vex::task::sleep(200);
  moveForward(500, 30);
  vex::task::sleep(1000);
  turnClockwise(260, 30);
  vex::task::sleep(100);
  moveForward(500, 30);
  vex::task::sleep(1000);
  turnClockwise(90, 30);
  moveForward(400, 30);
  vex::task::sleep(100);
  intakeMove(-600);
  vex::task::sleep(700);
  liftCubes();
  moveForward(40, 20);
  vex::task::sleep(200);
  backOut();
  vex::task::sleep(500);*/
}

void nextStep() {
}

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  
  vex::task::sleep(200);
  double val = Selector.value(percentUnits::pct);
  double sectorSpan = 100 / 4;
  deploy();
  if (val <= sectorSpan) {
    redRight();
  } else if (val <= 2*sectorSpan) {
    blueLeft();
  } else if (val <= 3*sectorSpan) {
    blueLeft();
  } else if  (val <= 4*sectorSpan) {
    blueRight();
  }
  

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

int driveTask() {
  
    while(1) {
      double vLEFT_VERTICAL = (double)Controller.Axis3.value() * 12 / 127;
      double vRIGHT_VERTICAL = (double)Controller.Axis2.value() * 12 / 127;
      double vRIGHT_HORIZONTAL = (double)Controller.Axis1.value() * 12 / 127;
      double vLEFT_HORIZONTAL = (double)Controller.Axis4.value() * 12 / 127;

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

    if (Controller.ButtonR1.pressing()) { 
      IL.spin(directionType::fwd, -12, voltageUnits::volt);
      IR.spin(directionType::fwd, 12, voltageUnits::volt);
    } else if (Controller.ButtonR2.pressing()) {
      IL.spin(directionType::fwd, 12, voltageUnits::volt);
      IR.spin(directionType::fwd, -12, voltageUnits::volt);
    } else {
      IL.stop(brakeType::hold);
      IR.stop(brakeType::hold);
    }

    if (Controller.ButtonY.pressing()) {
      while(Controller.ButtonY.pressing()) {
        IL.spin(directionType::fwd, -2, voltageUnits::volt);
        IR.spin(directionType::fwd, 2, voltageUnits::volt);
        LF.spin(directionType::fwd, -2, voltageUnits::volt);
        LB.spin(directionType::fwd, -2, voltageUnits::volt);
        RF.spin(directionType::fwd, 2, voltageUnits::volt);
        RB.spin(directionType::fwd, 2, voltageUnits::volt);
      }
    }


    // Macro To Intake  1048 784

    if (Controller.ButtonX.pressing()) {
      while(Controller.ButtonX.pressing()) {}
      CubeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.rotateTo(-300, rotationUnits::deg);
      CubeLift.rotateTo(500, rotationUnits::deg);
      IntakeLift.rotateTo(-1200, rotationUnits::deg);
    }

    if (Controller.ButtonA.pressing()) {
      while(Controller.ButtonA.pressing()) {}
      CubeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.rotateTo(-300, rotationUnits::deg);
      CubeLift.rotateTo(500, rotationUnits::deg);
      IntakeLift.rotateTo(-890, rotationUnits::deg);
    }

    if (Controller.ButtonB.pressing()) {
      while(Controller.ButtonB.pressing()) {}
      CubeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.setVelocity(100, percentUnits::pct);
      IntakeLift.rotateTo(0, rotationUnits::deg);
      CubeLift.rotateTo(0, rotationUnits::deg);
    }

    if (Controller.ButtonUp.pressing()) {

      IntakeLift.spin(directionType::fwd, -12, voltageUnits::volt);
    } else if (Controller.ButtonDown.pressing()) {
      IntakeLift.spin(directionType::fwd, 12, voltageUnits::volt);
    } else {
      IntakeLift.stop(brakeType::hold);
    }
    
    if (Controller.ButtonL1.pressing()) { 
      CubeLift.spin(directionType::fwd, -9, voltageUnits::volt);
    } else if (Controller.ButtonL2.pressing()) {
      if (CubeLift.rotation(rotationUnits::deg) < 300) {
        IL.spin(directionType::fwd, -1, voltageUnits::volt);
        IR.spin(directionType::fwd, 1, voltageUnits::volt);
        CubeLift.spin(directionType::fwd, 12, voltageUnits::volt);
      } else if (CubeLift.rotation(rotationUnits::deg) < 500) {
        IL.spin(directionType::fwd, -1, voltageUnits::volt);
        IR.spin(directionType::fwd, 1, voltageUnits::volt);
        CubeLift.spin(directionType::fwd, 9, voltageUnits::volt);
      } else {
        IL.spin(directionType::fwd, -1, voltageUnits::volt);
        IR.spin(directionType::fwd, 1, voltageUnits::volt);
        CubeLift.spin(directionType::fwd, 6, voltageUnits::volt);
      }
      
    } else {
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
      double sectorSpan = 100 / 4;
      Controller.Screen.clearLine();
      if (val <= sectorSpan) {
        Controller.Screen.print("Red 5 cube EPIC");
      } else if (val <= 2*sectorSpan) {
        Controller.Screen.print("Blue 5 cube EPIC");
      } else if (val <= 3*sectorSpan) {
        Controller.Screen.print("Red Lame");
      } else if  (val <= 4*sectorSpan) {
        Controller.Screen.print("Blue Lame");
      }
    }    
       
}