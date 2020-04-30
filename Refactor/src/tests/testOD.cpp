

#include <iostream>

#include "CANopen.h"
#include "CopleyDrive.h"
#include "Drive.h"

/* Helper functions ***********************************************************/
void CO_errExit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

/* send CANopen generic emergency message */
void CO_error(const uint32_t info) {
    CO_errorReport(CO->em, CO_EM_GENERIC_SOFTWARE_ERROR, CO_EMC_SOFTWARE_INTERNAL, info);
    fprintf(stderr, "canopend generic error: 0x%X\n", info);
}

using namespace std;
int main() {
    // Create a Drive Object
    std::cout << "1. Construct a CopleyDrive Object (which implements Drive Class), with NODE ID = 100 \n";
    Drive *testDrive = new CopleyDrive(2);

    std::cout << "2. Read form OD and change OD\n";
    cout << "currnet OD position : " << testDrive->getPos();
    testDrive->setPos(10);
    cout << "currnet OD position : " << testDrive->getPos();
}
