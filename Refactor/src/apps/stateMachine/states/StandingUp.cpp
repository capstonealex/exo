#include "TestMachine.h"
// Negative bending control machine
void StandingUp::entry(void) {
    std::cout << "Standing Up State Entered at Time:" << endl
              << "===================" << endl
              << " GREEN -> STAND UP" << endl
              << "===================" << endl;
    // OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[9]);
    // OWNER->robot->startNewTraj();
}

void StandingUp::during(void) {
    // if the green button is pressed move. Or do nothing
    std::cout << "STADING UP" << endl;
    // OWNER->robot->moveThroughTraj();
}
void StandingUp::exit(void) {
    std::cout
        << "Standing up motion State Exited";
}