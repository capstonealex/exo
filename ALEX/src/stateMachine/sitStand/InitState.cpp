#include "InitState.h"

void InitState::entry(void)
{
    printf("Init State Entered at Time %d\n", ((StateMachine *)owner)->mark);
    std::cout << "Inits OWNER: " << ((StateMachine *)owner) << endl;
    std::cout << "Inits OWNERs robot pointer: " << robot << endl;

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS BLUE + YELLOW  TO START PROGRAM\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    robot->resetTrackingError();
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
    // ss = dynamic_cast<sitStand *>(owner);

    printf("Init state during entered\n");
    std::cout << "Robot object address: " << robot << endl;
    robot->printInfo();
    // Do nothing in this state
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        robot->joints[i].readyToSwitchOn();
    }
}
void InitState::exit(void)
{

    printf("Initialise State Exited at Time %d\n", owner->mark);
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        robot->joints[i].enable();
    }
}
void InitState::initRobot(Robot *rb)
{
    robot = rb;
    robot->printInfo();
    std::cout << "Robot object address: " << robot
              << endl;
}