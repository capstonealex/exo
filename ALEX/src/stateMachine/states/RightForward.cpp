
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
}
void RightForward::during(void)
{
}
void RightForward::exit(void)
{

    std::cout
        << "RightForward State Exited at Time: " << OWNER->mark << endl;
}