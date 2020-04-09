#include "exoStateMachine.h"
/////////// STATE ////////////////////
// Stepping Last Left
///////////////////////////////////////////////
void SteppingLastLeft::entry(void)
{
    std::cout
        << "==================" << endl
        << " Stepping Last Left" << endl
        << "==================" << endl;
    OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->movementTrajMap[2]);
    OWNER->robot->trajectoryGenerator.setTrajectoryStanceRight();
    OWNER->robot->startNewTraj();
    /// CO_OD_RAM.currentState = intToStateODMap[this.getName()]
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Step last L"];
}

void SteppingLastLeft::during(void)
{
    OWNER->robot->moveThroughTraj();
}

void SteppingLastLeft::exit(void)
{
    std::cout
        << "SteppingLastLeft State Exited at Time: " << OWNER->mark << endl;
}