#include "exoStateMachine.h"

void TestState::entry(void)
{
    std::cout
        << "TEST STATE" << endl;
}
void TestState::during(void)
{
    OWNER->robot->setTrajectory();
    OWNER->robot->printTrajectory();
    OWNER->robot->setTrajectory();
    OWNER->robot->printTrajectory();
}
void TestState::exit(void)
{
}
