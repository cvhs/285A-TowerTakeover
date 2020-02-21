#include "vex.h"
#include "autons.h"
#include "../assistants/assistants.h"
using namespace vex;

void executeAuton() {
  deploy();
  double val = Selector.value(percentUnits::pct);
  double sectorSpan = 100 / numAutos;
  if (val <= sectorSpan) {
    skills();
  } else if (val <= 2*sectorSpan) {
    blueRight();
  } else if (val <= 3*sectorSpan) {
    blue5cube();
  } else if  (val <= 4*sectorSpan) {
    blue6cube();
  } else if  (val <= 5*sectorSpan) {
    redLeft();
  } else if  (val <= 6*sectorSpan) {
    red5cube();
  } else if  (val <= 7*sectorSpan) {
    red6cube();
  }
}