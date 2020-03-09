#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void StairStanding::entry(void)
{
    std::cout
        << "======================" << endl
        << " GREEN -> Stiar Left Leg Up" << endl
        << "======================" << endl;
}
void StairStanding::during(void)
{
    // Press yellow button to leave state
}
void StairStanding::exit(void)
{
    std::cout
        << "StairStanding State Exited at Time: " << OWNER->mark << endl;
}
