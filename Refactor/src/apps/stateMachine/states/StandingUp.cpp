#include "TestMachine.h"
// Negative bending control machine
void StandingUp::entry(void) {
    std::cout << "Standing Up State Entered at Time:" << endl
              << "===================" << endl
              << " GREEN -> STAND UP" << endl
              << "===================" << endl;
    OWNER->robot->initPositionControl();
    OWNER->robot->setTrajectory();
    OWNER->trajComplete = false;
}

void StandingUp::during(void) {
    // if the green button is pressed move. Or do nothing
    std::cout << "STANDING UP" << endl;
    OWNER->trajComplete = OWNER->robot->moveThroughTraj();
}
void StandingUp::exit(void) {
    std::cout
        << "Standing up motion State Exited"
        << endl;
}