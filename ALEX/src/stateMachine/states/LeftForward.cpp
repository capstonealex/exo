#include "exoStateMachine.h"
//////////////////////////////////////////
// LEFT FORWARD
//////////////////////////////////////////
void LeftForward::entry(void)
{
    //READ TIME OF MAIN
    printf("LeftForward State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE TO KEEP STEPPING\n");
    printf("PRESS YELLOW TO BRING FEET TOGETHER\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    std::cout << "LFWD STATE Robot object address: " << OWNER->robot << endl;
}
void LeftForward::during(void)
{
}
void LeftForward::exit(void)
{
    printf("LeftForward State Exited at Time %d\n", OWNER->mark);
}
