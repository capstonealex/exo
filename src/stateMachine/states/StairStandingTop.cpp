#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void StairStandingTop::entry(void)
{
    std::cout
        << "======================" << endl
        << " GREEN -> Stair Right Leg Down" << endl
        << "======================" << endl;
}
void StairStandingTop::during(void)
{
    // Press yellow button to leave state
}
void StairStandingTop::exit(void)
{
    std::cout
        << "StairStandingTop State Exited at Time: " << OWNER->mark << endl;
}
