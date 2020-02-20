#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LF = motor(PORT2, ratio18_1, false);
motor RF = motor(PORT1, ratio18_1, false);
motor LB = motor(PORT3, ratio18_1, false);
motor RB = motor(PORT4, ratio18_1, false);
motor IL = motor(PORT12, ratio18_1, false);
motor IR = motor(PORT15, ratio18_1, false);
motor IntakeLift = motor(PORT6, ratio18_1, false);
motor CubeLift = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);
pot Selector = pot(Brain.ThreeWirePort.A);
inertial IMU = inertial(PORT8);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}