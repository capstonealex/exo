#include "TestMachine.h"

void InitState::entry(void) {
    std::cout
        << "==============" << endl
        << " WELCOME TO THE TEST STATE MACHINE" << endl
        << "==============" << endl
        << endl
        << "========================" << endl
        << " PRESS S to start program" << endl
        << "========================" << endl;
}
void InitState::during(void) {
    std::cout << "INITI STATE" << endl;
}
void InitState::exit(void) {
    std::cout << "Initialise State Exited at Time: " << OWNER->mark << endl;
}
