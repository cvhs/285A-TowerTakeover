#include "vex.h"
#include "../assistants/assistants.h"
#include "autons.h"

void skills() {
  setIntakePct(100);
  vex::task::sleep(200);
  moveForward(2500, 23);
  vex::task::sleep(100);
}