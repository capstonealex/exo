/// Testing ExoRobot new classes

#include "ExoRobot.h"

int main(void)
{
    // Create Exo object + initialise derived Joints + trajectory Generator
    ExoRobot exo;
    // print joint positions
    exo.getStatus();
    //print trajectoryGenerator params
    exo.printTrajectoryParam();
    //Load new trajParams and print out
    exo.setTrajectory();
    exo.printTrajectoryParam();
}