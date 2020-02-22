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

void blue6cube() {
  setIntakePct(100);
  moveForward(1200, 31);
  vex::task::sleep(400);
  moveForward(-90, 30);
  turnClockwise(70, 30);
  moveForward(250, 20);
  vex::task::sleep(400);
  setIntakePct(0);
  turnClockwise(-422, 22);
  setIntakePct(70);
  vex::task::sleep(300);
  moveForward(1000, 80);
  setIntakePct(0);
  intakeMove(-520);
  vex::task::sleep(300);
  liftCubes();
  moveForward(30, 15);
  allDown();
  backOut();
  vex::task::sleep(2000);
  stopAllMotors();
}