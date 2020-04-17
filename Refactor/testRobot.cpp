/// Testing ExoRobot new classes

#include "ExoRobot.h"

int main(void) {
    // Create Exo object + initialise derived Joints + trajectory Generator
    std::cout << ">>> Creating ExoRobot" << std::endl;
    ExoRobot exo;
    // print joint positions
    std::cout << ">>> Current Robot Position (expected value: all joints 0) >>>" << std::endl;
    exo.getStatus();
    //print trajectoryGenerator params

    std::cout << ">>> Print Trajectory Parameters (Expected Value 0.2, 0)>>>" << std::endl;
    exo.printTrajectoryParam();
    //Load new trajParams and print out
    std::cout << ">>> Load new Trajectory Parameters >>>" << std::endl;
    exo.setTrajectory();
    std::cout << ">>> Print Trajectory Parameters (Expected Value ???? ) >>>" << std::endl;
    exo.printTrajectoryParam();

    //Try to move through trajectory without being in correct mode
    std::cout << ">>> Moving Through Trajectory (Expected Result: False) >>>" << std::endl << exo.moveThroughTraj() << std::endl;

    // Initialise Position Control
    std::cout << ">>> Initialsing Position Control >>> \n" << exo.initPositionControl() << std::endl;

    std::cout << ">>> Moving Through Trajectory  (Expected Result: True) >>>"  << std::endl << exo.moveThroughTraj() << std::endl;

    std::cout << ">>> Current Robot Position (expected value: all joints 0) >>>" << std::endl;
    exo.getStatus();

    std::cout << ">>> Updating all Joint Values >>>" << std::endl;
    exo.updateRobot();

    std::cout << ">>> Current Robot Position (expected value: all joints 100 + Joint ID) >>>" << std::endl;
    exo.getStatus();
}