

#include <iostream>

#include "CopleyDrive.h"
#include "Drive.h"
using namespace std;
int main() {
    // Create a Drive Object
    std::cout << "1. Construct a CopleyDrive Object (which implements Drive Class), with NODE ID = 100 \n";
    Drive *testDrive = new CopleyDrive(100);

    std::cout << "2. Read form OD and change OD\n";
    cout << "currnet OD position : " << testDrive->getPos();
    testDrive->setPos(10);
    cout << "currnet OD position : " << testDrive->getPos();
}
