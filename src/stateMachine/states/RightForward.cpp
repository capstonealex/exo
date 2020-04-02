//////////////////////////////////////////
// RIGHT FORWARD
//////////////////////////////////////////
#include "exoStateMachine.h"

void RightForward::entry(void)
{
	std::cout
		<< "RightForward State Entered at Time:: " << OWNER->mark << endl
		<< "========================" << endl
		<< " GREEN  -> KEEP STEPPING " << endl
		<< " YELLOW -> FEET TOGETHER" << endl
		<< " BLUE -> LEFT HIGH STEP" << endl
        << "========================\n" << endl;
}
void RightForward::during(void)
{
}
void RightForward::exit(void)
{

    std::cout
        << "RightForward State Exited at Time: " << OWNER->mark << endl;
}
