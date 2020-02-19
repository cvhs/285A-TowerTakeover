#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"

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