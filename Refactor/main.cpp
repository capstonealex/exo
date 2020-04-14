/// Testing ExoRobot new classes

#include "ExoRobot.h"

int main(void)
{
    ExoRobot exo;
    exo.setTrajectory();
    exo.printTrajectory();
    exo.setTrajectoryS();
    exo.printTrajectory();
}