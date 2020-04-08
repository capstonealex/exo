#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Sitting Down ------------/////
////////////////////////////////////
void SittingDwn::entry(void)
{
    std::cout << "Sitting Down State Entered at Time:" << OWNER->mark << endl
              << "===================" << endl
              << " GREEN -> SIT DOWN " << endl
              << "===================" << endl;

    OWNER->robot->trajectoryGenerator.setTrajectoryParameter(OWNER->robot->TrajParamMap[8]);
    OWNER->robot->startNewTraj();
    // CO_OD_RAM.currentState = intToStateODMap[this.getName()];
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Sitting Down"];
}
void SittingDwn::during(void)
{
    // long lastTarget = 0;
    // if the green button is pressed move. Or do nothing/
    OWNER->robot->moveThroughTraj();
}
void SittingDwn::exit(void)
{
    std::cout
        << "Sitting Down State Exited at Time t: " << OWNER->mark << endl;
}