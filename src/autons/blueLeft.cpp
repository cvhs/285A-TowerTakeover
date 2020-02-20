#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"

void blueLeft() {
  blue6cube();
}

void blue5Cube() {
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
  turnClockwise(90, 30);
  moveForward(250, 20);
  vex::task::sleep(400);
  turnClockwise(-445, 20);
  vex::task::sleep(100);
  setIntakePct(0);
  moveForward(1050, 90);
  intakeMove(-600);
  vex::task::sleep(700);
  liftCubes();
  moveForward(40, 20);
  vex::task::sleep(200);
  backOut();
  vex::task::sleep(500);
}