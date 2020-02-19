#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"

void blueLeft() {
  setIntakePct(100);
  vex::task::sleep(200);
  moveForward(1200, 31);
  turnClockwise(100, 30);
  moveForward(230, 20);
  vex::task::sleep(100);
  turnClockwise(-470, 30);
  vex::task::sleep(100);
  setIntakePct(0);
  moveForward(950, 80);
  intakeMove(-600);
  vex::task::sleep(700);
  liftCubes();
  moveForward(40, 20);
  vex::task::sleep(200);
  backOut();
  vex::task::sleep(500);
}