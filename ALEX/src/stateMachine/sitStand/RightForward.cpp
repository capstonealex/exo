
//////////////////////////////////////////
// RIGHT FORWARD
//////////////////////////////////////////
#include "RightForward.h"
void RightForward::entry(void)
{
    //READ TIME OF MAIN
    printf("RightForward State Entered at Time %d\n", owner->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE TO KEEP STEPPING OR YELLOW TO BRING FEET TOGETHER\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void RightForward::during(void)
{
}
void RightForward::exit(void)
{

    printf("RightForward State Exited at Time %d\n", owner->mark);
}
