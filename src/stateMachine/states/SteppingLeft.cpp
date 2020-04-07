#include "exoStateMachine.h"
////////// STATE ////////////////////
// Stepping Left
///////////////////////////////////////////////
void SteppingLeft::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "==================" << endl
        << " Stepping Left" << endl
        << "==================" << endl;
    OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->TrajParamMap[2]);
    OWNER->robot->trajectoryObj.setTrajectoryStanceRight();
    OWNER->robot->startNewTraj();
    // CO_OD_RAM.currentState = intToStateODMap[this.getName()]
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Step L"];
}

void SteppingLeft::during(void)
{
    OWNER->robot->moveThroughTraj();
}

void SteppingLeft::exit(void)
{
    std::cout
        << "SteppingLeft State Exited at Time: " << OWNER->mark << endl;
}