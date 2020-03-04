#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void Standing::entry(void)
{
    std::cout
        << "======================" << endl
        << " YELLOW -> Sit DOWN" << endl
        // << " BLUE   -> WALK SELECT" << endl
        << " Trigger startWalk with BLUE"
        << "======================" << endl;
    // CO_OD_RAM.currentState = intToStateODMap[this.getName()];
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Standing"];
}
void Standing::during(void)
{
    // Press yellow button to leave state
}
void Standing::exit(void)
{
    std::cout
        << "Standing State Exited at Time: " << OWNER->mark << endl;
}
