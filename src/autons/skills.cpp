#include "vex.h"
#include "../assistants/assistants.h"
#include "autons.h"

void skills() {
  setIntakePct(100);
  vex::task::sleep(200);
  moveForward(1300, 19);
  vex::task::sleep(100);
  turnClockwise(30, 20);
  vex::task::sleep(100);
  moveForward(100, 19);
  vex::task::sleep(100);

  turnClockwise(-60, 20);
  vex::task::sleep(100);
  moveForward(100, 19);
  vex::task::sleep(100);

  turnClockwise(35, 20);
  vex::task::sleep(100);

  moveForward(2000, 19);

  vex::task::sleep(1000);
  moveForward(-500, 25);

  turnClockwise(-70, 20);
  
  moveForward(290, 20);
  vex::task::sleep(200);
  intakeMove(-750);
  vex::task::sleep(500);
  liftCubes();
  moveForward(50, 15);
  vex::task::sleep(200);
  allDown();
  backOut();
  vex::task::sleep(1000);
  stopAllMotors();
}