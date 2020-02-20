#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"
using namespace vex;

void executeAuton() {
  deploy();
  double val = Selector.value(percentUnits::pct);
  double sectorSpan = 100 / 4;
  if (val <= sectorSpan) {
    redRight();
  } else if (val <= 2*sectorSpan) {
    blueLeft();
  } else if (val <= 3*sectorSpan) {
    redLeft();
  } else if  (val <= 4*sectorSpan) {
    blueRight();
  }
}