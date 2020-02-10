using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LF;
extern motor RF;
extern motor RB;
extern motor LB;
extern motor L1;
extern motor L2;
extern controller Controller1;
extern motor IN1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );