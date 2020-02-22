#include "vex.h"
#include "screens.h"

competition Comp;

int displayed = -1;
char fnames [7][6] = { "0.png", "1.png", "2.png", "3.png", "4.png", "5.png", "6.png"};
char names [7][15] = {"SKILLS       ", "BLUE LARGE   ", "BLUE 5       ", "BLUE 6       ", "RED LARGE    ", "RED 5        ", "RED 6        "};
bool imuCalibShown = true;

void displayAuto(int num) {
  if (num != displayed) {
    // Brain
    Brain.Screen.drawImageFromFile(fnames[num], 0, 0);

    // Controller
    Controller1.Screen.setCursor(1, 0);
    Controller1.Screen.print("AUTON: ");
    Controller1.Screen.print(names[num]);

    displayed = num;
  }
}

void brainScreenUpdate() {
  double val = Selector.value(percentUnits::pct);
  double sectorSpan = 100 / 7;
  if (val <= sectorSpan) {
    displayAuto(0);
  } else if (val <= 2*sectorSpan) {
    displayAuto(1);
  } else if (val <= 3*sectorSpan) {
    displayAuto(2);
  } else if  (val <= 4*sectorSpan) {
    displayAuto(3);
  } else if  (val <= 5*sectorSpan) {
    displayAuto(4);
  } else if  (val <= 6*sectorSpan) {
    displayAuto(5);
  } else if  (val <= 7*sectorSpan) {
    displayAuto(6);
  }

  if (IMU.isCalibrating() != imuCalibShown) {
    if (IMU.isCalibrating()) {
      Brain.Screen.drawImageFromFile("inProg.png", 285, 0);
    } else {
      Brain.Screen.drawImageFromFile("compl.png", 285, 0);
    }
  }

}

int screensTask() {
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(white);
  Brain.Screen.setPenColor(white);
  Brain.Screen.drawRectangle(0, 0, 480, 230);
  Brain.Screen.drawImageFromFile("inProg.png", 285, 0);
  Brain.Screen.drawImageFromFile("banner.png", 370, 0);

  while(true) {
    brainScreenUpdate();
    vex::task::sleep(80);
  }
  return(0);
}

vex::timer tim;

int driverTimer() {
  
  while(true) {
    vex::task::sleep(250);
    double drivtim = (104000 - tim.time());
    double skiltrim = (59000 - tim.time());

    drivtim /= 1000;
    skiltrim /= 1000;
    
    Controller1.Screen.setCursor(2, 0);
    Controller1.Screen.print("TIME: ");
    Controller1.Screen.print(IMU.gyroRate(axisType::zaxis, velocityUnits::dps));

    Controller1.Screen.setCursor(3, 0);
    Controller1.Screen.print("SKILLS: ");
    Controller1.Screen.print(IMU.heading());
  }
  return(0);
}

void startScreens() {
  vex::task runScreens( screensTask );
}

void startDriverTimer() {
  tim.clear();
  vex::task driver( driverTimer );
}
