#include "LeftForward.h"
//////////////////////////////////////////
// LEFT FORWARD
//////////////////////////////////////////
void LeftForward::entry(void)
{
    //READ TIME OF MAIN
    printf("LeftForward State Entered at Time %d\n", owner->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE TO KEEP STEPPING\n");
    printf("PRESS YELLOW TO BRING FEET TOGETHER\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void LeftForward::during(void)
{
}
void LeftForward::exit(void)
{
    printf("LeftForward State Exited at Time %d\n", owner->mark);
}
