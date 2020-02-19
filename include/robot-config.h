using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LF;
extern motor RF;
extern motor LB;
extern motor RB;
extern motor IL;
extern motor IR;
extern motor IntakeLift;
extern motor CubeLift;
extern controller Controller1;
extern pot Selector;
extern inertial IMU;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );