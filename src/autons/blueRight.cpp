#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"

void blueRight() {
  setIntakePct(100);
  moveForward(600, 15);
  vex::task::sleep(200);
  turnClockwise(220, 30);
  vex::task::sleep(200);
  moveForward(600, 41);
  vex::task::sleep(200);
  turnClockwise(110, 30);
  vex::task::sleep(200);
  moveForward(300, 41);
  vex::task::sleep(200);
  intakeMove(-500);
  vex::task::sleep(500);
  liftCubes();
  moveForward(40, 20);
  vex::task::sleep(200);
  backOut();
  vex::task::sleep(500);
}