#include "exoStateMachine.h"
// Negative bending control machine
void StandingUp::entry(void)
{
    std::cout << "Standing Up State Entered at Time:" << OWNER->mark << endl
              << "===================" << endl
              << " GREEN -> STAND UP" << endl
              << "===================" << endl;
    OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->TrajParamMap[9]);
    OWNER->robot->startNewTraj();
    // CO_OD_RAM.currentState = intToStateODMap[this.getName()]
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Standing Up"];
}

void StandingUp::during(void)
{
    // if the green button is pressed move. Or do nothing
    OWNER->robot->moveThroughTraj();
}
void StandingUp::exit(void)
{
    std::cout
        << "Standing up motion State Exited at Time: " << OWNER->mark << endl;
}