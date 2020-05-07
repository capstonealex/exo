#include "StandingUp.h"

// Negative bending control machine
void StandingUp::entry(void) {
    std::cout << "===================" << endl
              << " GREEN -> STAND UP" << endl
              << "===================" << endl;
    trajectoryGenerator->initialiseTrajectory(STAND, 2);
    robot->startNewTraj();
    robot->setTrajectory();
}

void StandingUp::during(void) {
    // if the green button is pressed move. Or do nothing
    robot->moveThroughTraj();
}
void StandingUp::exit(void) {
    std::cout
        << "Standing up motion State Exited"
        << endl;
}