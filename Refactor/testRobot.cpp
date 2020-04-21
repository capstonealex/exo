/// Testing ExoRobot new classes

#include "ExoRobot.h"
using namespace std;

int main(void) {
    //TODO add curser initializer to initiRobot.
    /*Initialize curses*/
    initscr();
    /*read one character at a time to into getch*/
    cbreak();
    /*prevents keyboard input echo*/
    noecho();
    /*nonblocking getChar*/
    nodelay(stdscr, TRUE)
        clear();
    // Create Exo object + initialise derived Joints + trajectory Generator
    cout << ">>> Creating ExoRobot" << endl;
    ExoRobot exo;
    // print joint positions
    cout << ">>> Current Robot Position (expected value: all joints 0) >>>" << endl;
    exo.getStatus();
    //print trajectoryGenerator params

    cout << ">>> Print Trajectory Parameters (Expected Value 0.2, 0)>>>" << endl;
    exo.printTrajectoryParam();
    //Load new trajParams and print out
    cout << ">>> Load new Trajectory Parameters >>>" << endl;
    exo.setTrajectory();
    cout << ">>> Print Trajectory Parameters (Expected Value ???? ) >>>" << endl;
    exo.printTrajectoryParam();

    //Try to move through trajectory without being in correct mode
    cout << ">>> Moving Through Trajectory (Expected Result: False) >>>" << endl
         << exo.moveThroughTraj() << endl;

    // Initialise Position Control
    cout << ">>> Initialsing Position Control >>> \n"
         << exo.initPositionControl() << endl;

    cout << ">>> Moving Through Trajectory  (Expected Result: True) >>>" << endl
         << exo.moveThroughTraj() << endl;

    cout << ">>> Current Robot Position (expected value: all joints 0) >>>" << endl;
    exo.getStatus();

    cout << ">>> Updating all Joint Values >>>" << endl;
    exo.updateRobot();

    cout << ">>> Current Robot Position (expected value: all joints 100 + Joint ID) >>>" << endl;
    exo.getStatus();

    ///Testing keyboard input
    do {
        cout << "get keyboard input until q is typed" << endl;
        exo.keyboard.setStates();
        exo.keyboard.printPressed();
    } while (!exo.keyboard.getQ());
    endwin();
    exit(0);
}