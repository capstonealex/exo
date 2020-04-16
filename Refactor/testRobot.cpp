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
    
    // Try to move through trajectory without being in correct mode
    std::cout << "Moving Through Trajectory (Expected Result: False): " << exo.moveThroughTraj() << std::endl;


    // Initialise Position Control
    std::cout << "Initialsing Position Control: " << exo.initPositionControl() << std::endl;

    std::cout << "Moving Through Trajectory  (Expected Result: True): " << exo.moveThroughTraj() << std::endl;
 

    std::cout << "Current Robot Position (expected value: all joints 0)" << std::endl;
    exo.getStatus();

    std::cout << "Update all Joint Values " <<std::endl;
    exo.updateRobot();

    std::cout << "Current Robot Position (expected value: all joints 100)" << std::endl;
    exo.getStatus();

    exo.printTrajectoryParam();
}