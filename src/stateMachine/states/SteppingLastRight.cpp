#include "exoStateMachine.h"
///////// STATE ////////////////////
// Stepping Last Right
///////////////////////////////////////////////
void SteppingLastRight::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "==================" << endl
        << " Stepping Last Right" << endl
        << "==================" << endl;
    OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->TrajParamMap[2]);
    OWNER->robot->trajectoryGenerator.setTrajectoryStanceLeft();
    OWNER->robot->startNewTraj();
    // CO_OD_RAM.currentState = intToStateODMap[this.getName()]
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Step last R"];
}

void SteppingLastRight::during(void)
{
    OWNER->robot->moveThroughTraj();
}

void SteppingLastRight::exit(void)
{
    std::cout
        << "SteppingLastRight State Exited at Time: " << OWNER->mark << endl;
}
