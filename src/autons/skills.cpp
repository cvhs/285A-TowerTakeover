#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"

void skills() {
  setIntakePct(100);
  vex::task::sleep(200);
  moveForward(2500, 23);
  vex::task::sleep(100);
}