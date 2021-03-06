#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"

void blueRight() {
  setIntakePct(50);
  moveForward(600, 15);
  vex::task::sleep(200);
  setIntakePct(10);
  turnClockwise(220, 20);
  setIntakePct(100);
  CubeLift.resetRotation();
  vex::task::sleep(200);
  moveForward(600, 41);
  vex::task::sleep(200);
  turnClockwise(110, 20);
  vex::task::sleep(200);
  moveForward(290, 41);
  vex::task::sleep(200);
  intakeMove(-450);
  vex::task::sleep(500);
  liftCubes();
  CubeLift.stop();
  moveForward(50, 15);
  vex::task::sleep(200);
  allDown();
  backOut();
  vex::task::sleep(1000);
  stopAllMotors();
}