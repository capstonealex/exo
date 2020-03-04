#include "exoStateMachine.h"

void InitState::entry(void)
{
    std::cout
        << "==============" << endl
        << " WELCOME BRAD" << endl
        << "==============" << endl
        << endl
        << "========================" << endl
        << " BLUE + YELLOW -> START " << endl
        << "========================" << endl;
    OWNER->robot->resetTrackingError();
    // CO_OD_RAM.currentState = intToStateODMap[this.getName()]
    CO_OD_RAM.currentState = OWNER->stateToIntODMap["Init"];
    // Set up the logging file
    // time_t rawtime;
    // struct tm * timeinfo;

    // time (&rawtime);
    // timeinfo = localtime (&rawtime);

    // strftime (filename,80,"ALEXLOG_%Y%m%e_%H%M.csv",timeinfo);
    // printf("File Created: %s\n", filename);

    // logfile.open (filename);
}
void InitState::during(void)
{
    std::cout << "NEXT MOVEMENT" << CO_OD_RAM.nextMovement << endl;
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].readyToSwitchOn();
    }
}
void InitState::exit(void)
{

    std::cout << "Initialise State Exited at Time: " << OWNER->mark << endl;
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        OWNER->robot->joints[i].enable();
    }
}
