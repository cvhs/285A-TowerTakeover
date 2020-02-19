#ifndef ASSISTANTS_H_
#define ASSISTANTS_H_
#include "vex.h"

void liftUp();

void deploy();
 
void setIntakePct(double v);
 
void intakeMove(double deg);

void setVel(double v);
 
void setStopping(vex::brakeType stop);
 
void moveForward(double deg, double vel);
 
void turnClockwise(double deg, double vel);
 
void liftCubes();
 
void backOut();

void basicDriveBackForth();

#endif