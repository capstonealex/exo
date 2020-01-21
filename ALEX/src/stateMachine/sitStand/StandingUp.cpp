#include "StandingUp.h"

// Negative bending control machine
void StandingUp::entry(void)
{
    printf("Standing Up State Entered at Time %d\n", owner->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    owner->robot->startNewTraj();
}

void StandingUp::during(void)
{
    // if the green button is pressed move. Or do nothing
    owner->robot->moveThroughTraj(owner->robot->standUpTrajFunc, SITSTANDTIME);
}
void StandingUp::exit(void)
{
    printf("Standing up motion State Exited at Time %d\n", owner->mark);
}