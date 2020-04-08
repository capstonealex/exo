#include "exoStateMachine.h"

void TestState::entry(void)
{
    std::cout
        << "TEST STATE" << endl;
}
void TestState::during(void)
{
    OWNER->robot->setTrajectory();
    OWNER->robot->printTrajectoryParam();
    OWNER->robot->setTrajectory();
    OWNER->robot->printTrajectoryParam();
    // Test comment
}
void TestState::exit(void)
{
}
