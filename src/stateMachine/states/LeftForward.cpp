#include "exoStateMachine.h"
//////////////////////////////////////////
// LEFT FORWARD
//////////////////////////////////////////
void LeftForward::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "LeftForward State Entered at Time:: " << OWNER->mark << endl
        << "=========================" << endl
        << " GREEN  -> KEEP STEPPING" << endl
        << " YELLOW -> FEET TOGETHER" << endl
		<< " BLUE -> RIGHT HIGH STEP" << endl
        << "=========================" << endl;
}
void LeftForward::during(void)
{
}
void LeftForward::exit(void)
{
    std::cout << "LeftForward State Exited at Time: " << OWNER->mark << endl;
}
