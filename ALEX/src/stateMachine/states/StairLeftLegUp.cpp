#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void StairLeftLegUp::entry(void)
{
	std::cout
		<< "======================" << endl
		<< " GREEN -> Stair Right Leg Up" << endl
		<< "======================" << endl;
}
void StairLeftLegUp::during(void)
{
	// Press yellow button to leave state
}
void StairLeftLegUp::exit(void)
{
	std::cout
		<< "StairLeftLegUp State Exited at Time: " << OWNER->mark << endl;
}
