#include "exoStateMachine.h"
////////// STATE ////////////////////
// Error State
///////////////////////////////////////////////

void ErrorState::entry(void)
{
    //READ TIME OF MAIN
    printf("Error State Entered at Time %d\n", OWNER->mark);
    std::cout << "ERROR STATE Robot object address: " << OWNER->robot << endl;
    // logfile.close();
    // printf("File Closed \n");
    printf("Reset with Red + Green \n");

    // Set Drives to Disabled mode
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].disable();
    }
}

void ErrorState::during(void)
{
}

void ErrorState::exit(void)
{
    printf("Error State Exited");
}
