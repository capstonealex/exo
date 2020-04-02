#include "exoStateMachine.h"
////////// STATE ////////////////////
// Error State
///////////////////////////////////////////////

void ErrorState::entry(void)
{
    //READ TIME OF MAIN
    std::cout
        << "==================" << endl
        << " ERROR STATE !!!!" << endl
        << "==================" << endl
        << "Reset -> Red + Green" << endl
        << "==================" << endl;
    // logfile.close();
    // printf("File Closed \n");

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
