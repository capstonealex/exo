#include "exoStateMachine.h"
////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void Standing::entry(void)
{
    printf("Standing State Entered at Time %d\n", OWNER->mark);
    std::cout << "Standing STATE Robot object address: " << OWNER->robot << endl;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS YELLOW TO START Sitting DOWN\n");
    printf("PRESS BLUE BUTTON TO STEP LEFT LEG FORWARD\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void Standing::during(void)
{
    // Press yellow button to leave state
}
void Standing::exit(void)
{
    printf("Standing State Exited at Time %d\n", OWNER->mark);
}
