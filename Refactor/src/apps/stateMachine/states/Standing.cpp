#include "TestMachine.h"
////////// STATE ////////////////////
//-------  Standing ------------/////
////////////////////////////////////
void Standing::entry(void) {
    std::cout
        << "======================" << endl
        << " HIT W -> Sit DOWN" << endl

        << "======================" << endl;
}
void Standing::during(void) {
    cout << "Standing state" << endl;
}
void Standing::exit(void) {
    std::cout
        << "Standing State Exited at Time: " << OWNER->mark << endl;
}
