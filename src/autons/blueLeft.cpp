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
  vex::task::sleep(200);
  turnClockwise(-422, 20);
  setIntakePct(0);
  vex::task::sleep(300);
  moveForward(950, 80);
  intakeMove(-600);
  vex::task::sleep(300);
  liftCubes();
  moveForward(50, 20);
  backOut();
  vex::task::sleep(500);
}