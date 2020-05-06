#include "TestMachine.h"
////////// STATE ////////////////////
//-------  Sitting ------------/////
////////////////////////////////////
void Sitting::entry(void) {
    //READ TIME OF MAIN
    std::cout << "Sitting State Entered at Time:" << endl
              << "=======================" << endl
              << " HIT W to begin standing up" << endl
              << "=======================" << endl
              << endl;
}
void Sitting::during(void) {
    // OWNER->robot->moveThroughTraj();
}
void Sitting::exit(void) {
    std::cout
        << "Sitting State Exited" << endl;
}