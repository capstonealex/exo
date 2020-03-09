#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void StairLeftLegUp2::entry(void)
{
    std::cout
        << "======================" << endl
        << " GREEN -> Stair Left Leg Down" << endl
        << "======================" << endl;
}
void StairLeftLegUp2::during(void)
{
    // Press yellow button to leave state
}
void StairLeftLegUp2::exit(void)
{
    std::cout
        << "StairLeftLegUp2 State Exited at Time: " << OWNER->mark << endl;
}
