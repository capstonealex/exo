#include "TestMachine.h"
////////// STATE ////////////////////
//-------  Sitting Down ------------/////
////////////////////////////////////
void SittingDwn::entry(void) {
    std::cout << "Sitting Down State Entered " << endl
              << "===================" << endl
              << " GREEN -> SIT DOWN " << endl
              << "===================" << endl;
}
void SittingDwn::during(void) {
    std::cout << "sitting down state" << endl;
    // OWNER->robot->moveThroughTraj();
}
void SittingDwn::exit(void) {
    std::cout
        << "Sitting Down State Exited " << endl;
}