#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"

void blueLeft() {
  blue6cube();
}

void blue5cube() {
  setIntakePct(100);
  vex::task::sleep(200);
  moveForward(1200, 23);
  CubeLift.resetRotation();
  vex::task::sleep(300);
  setIntakePct(15);
  turnClockwise(-375, 30);
  vex::task::sleep(100);
  moveForward(880, 50);
  intakeMove(-600);
  vex::task::sleep(700);
  liftCubes();
  CubeLift.stop();
  moveForward(35, 12);
  vex::task::sleep(400);
  allDown();
  backOut();
}

void blue6cube() {
  setIntakePct(100);
  moveForward(1200, 31);
  vex::task::sleep(100);
  moveForward(-90, 30);
  turnClockwise(70, 30);
  moveForward(280, 25);
  vex::task::sleep(400);
  setIntakePct(0);
  turnClockwise(-442, 22);
  setIntakePct(70);
  vex::task::sleep(300);
  moveForward(1000, 80);
  setIntakePct(0);
  intakeMove(-620);
  vex::task::sleep(600);
  liftCubes();
  moveForward(30, 15);
  allDown();
  backOut();
  vex::task::sleep(2000);
  stopAllMotors();
}