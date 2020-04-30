/// Testing ExoRobot new classes

#include "ExoRobot.h"
//using namespace std;

int main(void) {
    //TODO add keyboard initializer to initiRobot.
    //INITINPUT
    // Create Exo object + initialise derived Joints + trajectory Generator
    cout << ">>> Creating ExoRobot" << endl;
    ExoRobot exo;
    // print joint positions
    cout << ">>> Current Robot Position (expected value: all joints 0) >>>" << endl;
    exo.printStatus();
    //print trajectoryGenerator params

    cout << ">>> Print Trajectory Parameters (Expected Value 0.2, 0)>>>" << endl;
    exo.printTrajectoryParam();
    //Load new trajParams and print out
    cout << ">>> Load new Trajectory Parameters >>>" << endl;
    exo.setTrajectory();
    cout << ">>> Print Trajectory Parameters (Expected Value ???? ) >>>" << endl;
    exo.printTrajectoryParam();

    //Try to move through trajectory without being in correct mode
    /* cout << ">>> Moving Through Trajectory (Expected Result: False) >>>" << endl
         << exo.moveThroughTraj() << endl;*/

    // Initialise Position Control
    cout << ">>> Initialsing Position Control >>> \n"
         << exo.initPositionControl() << endl;

    /* cout << ">>> Moving Through Trajectory  (Expected Result: True) >>>" << endl
         << exo.moveThroughTraj() << endl;*/

    cout << ">>> Current Robot Position (expected value: all joints 0) >>>" << endl;
    exo.printStatus();

    cout << ">>> Updating all Joint Values >>>" << endl;
    exo.updateRobot();

    cout << ">>> Current Robot Position (expected value: all joints 100 + Joint ID) >>>" << endl;
    exo.printStatus();

    // NON BLOCKING KEYBOARD INPUT - quits when q is pressed
    cout << "Test keyboard input w/ w,a,s,d,x. Type q to exit keyboard test" << endl;
    while (!exo.keyboard.getQ()) {
        usleep(500000);
        exo.updateRobot();
        if (exo.keyboard.getA()) {
            exo.moveThroughTraj();
        }
        if (exo.keyboard.getS()) {
            exo.startNewTraj();
            exo.setSpecificTrajectory(RobotMode::SITDWN);
        }
        if (exo.keyboard.getW()) {
            exo.setSpecificTrajectory(RobotMode::NORMALWALK);
        }
        //exo.printTrajectoryParam();
        //exo.keyboard.clearCurrentStates();
        exo.printStatus();
    }

    // exit(0);
}