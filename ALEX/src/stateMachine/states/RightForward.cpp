
//////////////////////////////////////////
// RIGHT FORWARD
//////////////////////////////////////////
#include "exoStateMachine.h"

void RightForward::entry(void)
{
    std::cout
        << "========================" << endl
        << " GREEN  -> KEEP STEPPING " << endl
        << " YELLOW -> FEET TOGETHER" << endl
        << "========================n" << endl;
    // CO_OD_RAM.currentState = intToStateODMap[this.getName()];
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Standing"];
}
void RightForward::during(void)
{
}
void RightForward::exit(void)
{

    std::cout
        << "RightForward State Exited at Time: " << OWNER->mark << endl;
}
