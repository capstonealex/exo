
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
    //TODO, when OD WORKING: OD.CS = StateODMap[this.getName()]
}
void RightForward::during(void)
{
}
void RightForward::exit(void)
{

    std::cout
        << "RightForward State Exited at Time: " << OWNER->mark << endl;
}
