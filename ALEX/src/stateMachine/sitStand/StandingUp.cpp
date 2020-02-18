#include "sitStand.h"

// Negative bending control machine
void StandingUp::entry(void)
{
    printf("Standing Up State Entered at Time %d\n", OWNER->mark);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("PRESS GREEN TO BEGIN STANDING UP\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    OWNER->robot->startNewTraj();
}

void StandingUp::during(void)
{
    // if the green button is pressed move. Or do nothing
    OWNER->robot->moveThroughTraj(OWNER->robot->standUpTrajFunc, SITSTANDTIME);
}
void StandingUp::exit(void)
{
    printf("Standing up motion State Exited at Time %d\n", OWNER->mark);
}