#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void WalkSelect::entry(void)
{
    std::cout
        << "======================" << endl
        << " YELLOW -> STAIR LEFT FOWARD" << endl
        << " GREEN   -> LEFT FOWARD" << endl
        << "======================" << endl;
}
void WalkSelect::during(void)
{
    // Press yellow button to leave state
}
void WalkSelect::exit(void)
{
    std::cout
        << "Walk Select State Exited at Time: " << OWNER->mark << endl;
}
