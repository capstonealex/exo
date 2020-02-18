
//////////////////////////////////////////
// RIGHT FORWARD
//////////////////////////////////////////
#include "exoStateMachine.h"

void RightForward::entry(void)
{
    //READ TIME OF MAIN
    printf("RightForward State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE TO KEEP STEPPING OR YELLOW TO BRING FEET TOGETHER\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    std::cout << "RFWD STATE Robot object address: " << OWNER->robot << endl;
}
void RightForward::during(void)
{
}
void RightForward::exit(void)
{

    printf("RightForward State Exited at Time %d\n", OWNER->mark);
}
