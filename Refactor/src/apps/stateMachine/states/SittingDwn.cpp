#include "TestMachine.h"
////////// STATE ////////////////////
//-------  Sitting Down ------------/////
////////////////////////////////////
void SittingDwn::entry(void) {
    std::cout << "Sitting Down State Entered " << endl
              << "===================" << endl
              << " GREEN -> SIT DOWN " << endl
              << "===================" << endl;
    OWNER->robot->initPositionControl();
    OWNER->robot->setSpecificTrajectory(RobotMode::SITDWN);
    OWNER->trajComplete = false;
}
void SittingDwn::during(void) {
    std::cout << "sitting down state" << endl;
    // OWNER->trajComplete = OWNER->robot->moveThroughTraj();
    OWNER->trajComplete = true;
}
void SittingDwn::exit(void) {
    std::cout
        << "Sitting Down State Exited " << endl;
}