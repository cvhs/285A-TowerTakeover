#ifndef ASSISTANTS_H_
#define ASSISTANTS_H_
#include "vex.h"

void liftUp();

void deploy();

void allDown();
 
void setIntakePct(double v);
 
void intakeMove(double deg);

double getLeftVel();
 
double getRightVel();

double getClockwiseTurnVel();

void setLeftVel(double v);

void slamBack();

void setRightVel(double v);

void setVel(double v);
 
void setStopping(vex::brakeType stop);
 
void moveForward(double deg, double vel);
 
void turnClockwise(double deg, double vel);

void turnIMU(double deg);

void turnIMUAbsolute(double deg);
 
void liftCubes();
 
void backOut();

void basicDriveBackForth();

void stopAllMotors();

void calibrateGyro();

#endif