#include "vex.h"
#include "assistants.h"
using namespace vex;


void liftUp() {
  CubeLift.spin(directionType::fwd, 14 + ((1640 - CubeLift.rotation(rotationUnits::deg)) / 15), velocityUnits::pct);
}
void deploy() {
  IntakeLift.setVelocity(100, percentUnits::pct);
  IntakeLift.rotateTo(-900, rotationUnits::deg);
  IntakeLift.rotateTo(0, rotationUnits::deg); 
}

void stopAllMotors() {
  LF.setStopping(brakeType::brake);
  RF.setStopping(brakeType::brake);
  LB.setStopping(brakeType::brake);
  RB.setStopping(brakeType::brake);
  LF.stop();
  RF.stop();
  LB.stop();
  RB.stop();
}
 
void setIntakePct(double v) {
  IL.spin(directionType::fwd, (v/100)*12, voltageUnits::volt);
  IR.spin(directionType::fwd, (v/100)*-12, voltageUnits::volt);
}
 
void intakeMove(double deg) {
  IL.startRotateFor(directionType::fwd, deg, rotationUnits::deg, 100, velocityUnits::pct);
  IR.startRotateFor(directionType::fwd, -deg, rotationUnits::deg, 100, velocityUnits::pct);
}

double getLeftVel() {
  double speed = (LF.velocity(percentUnits::pct) + LB.velocity(percentUnits::pct)) / 2;
  return speed;
}
 
double getRightVel() {
  double speed = (RF.velocity(percentUnits::pct) + RB.velocity(percentUnits::pct)) / 2;
  return -speed;
}

double getClockwiseTurnVel() {
  return (getLeftVel() - getRightVel()) / 2;
}

void setLeftVel(double v) {
  LF.spin(directionType::fwd, v, percentUnits::pct);
  LB.spin(directionType::fwd, v, percentUnits::pct);
}

void setRightVel(double v) {
  RF.spin(directionType::fwd, -v, percentUnits::pct);
  RB.spin(directionType::fwd, -v, percentUnits::pct);
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

void turnIMU(double deg) {
  turnIMUAbsolute(deg + IMU.heading());
}

void turnIMUAbsolute(double deg) {
  double maxSettleSpeed = 2;
  double maxSettleError = 2;

  double target = deg;
  while(target < 0) {
    target += 360;
  }

  bool holdExit = true;
  while(holdExit) {
    double error = target - IMU.heading();

    if (error > 180) {
      error = target - IMU.heading() - 360;
    }
    if (error < -180) {
      error = target - IMU.heading() + 360;
    }

    double P = 0.9 * error;
    double D = 1.1 * getClockwiseTurnVel();
    
    double total = P - D;
    setLeftVel(total);
    setRightVel(-total);
    Controller1.Screen.newLine();
    Controller1.Screen.print(IMU.heading());

    if ((fabs(D) < maxSettleSpeed) && (fabs(error) < maxSettleError)) {
      holdExit = false;
      stopAllMotors();
    }

    wait(20, timeUnits::msec);
  }
}
 
void liftCubes() {
  while (CubeLift.rotation(rotationUnits::deg) < 1620) {;
    liftUp();
  }
  CubeLift.stop();
}
 
 
void backOut() {
  IL.spin(directionType::fwd, -9, voltageUnits::volt);
  IR.spin(directionType::fwd, 9, voltageUnits::volt);
  LF.spin(directionType::fwd, -12, voltageUnits::volt);
  LB.spin(directionType::fwd, -12, voltageUnits::volt);
  RF.spin(directionType::fwd, 12, voltageUnits::volt);
  RB.spin(directionType::fwd, 12, voltageUnits::volt);
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

void calibrateGyro() {
  IMU.calibrate();
  while(IMU.isCalibrating()) {
    wait(10, timeUnits::sec);
    Controller1.Screen.print("IMU DONE");
  }
}