#include "InitState.h"

void InitState::entry(void)
{
    printf("Initialise State Entered at Time %d\n", OWNER->mark);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE + YELLOW  TO START PROGRAM\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    OWNER->robot->resetTrackingError();
    // Set up the logging file
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(filename, 80, "ALEXLOG_%Y%m%e_%H%M.csv", timeinfo);
    printf("File Created: %s\n", filename);

    logfile.open(filename);
}
void InitState::during(void)
{
    // Do nothing in this state
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].readyToSwitchOn();
    }
}
void InitState::exit(void)
{

    printf("Initialise State Exited at Time %d\n", OWNER->mark);
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].enable();
    }
}
