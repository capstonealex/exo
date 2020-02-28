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

    OWNER->robot->trajectoryObj.setTrajectoryParameter(OWNER->robot->trajectoryObj.TrajParamMap[8]);
    OWNER->robot->startNewTraj();
    //TODO, when OD WORKING: OD.CS = StateODMap[this.getName()]
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
        << "Sitting Down State Exited at Time: " << OWNER->mark << endl;
}