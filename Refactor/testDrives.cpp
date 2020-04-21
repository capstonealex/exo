/**
 * @file testDrives.cpp
 * @author Justin Fong
 * @brief A script to test the functionality of the Drive Objects
 * @version 0.1
 * @date 2020-04-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>

#include "Drive.h"
#include "CopleyDrive.h"

int main(){
    // Create a Drive Object
    std::cout << "1. Construct a CopleyDrive Object (which implements Drive Class), with NODE ID = 100 \n";
    Drive *testDrive = new CopleyDrive(1);

    std::cout << "2. Try to run the InitPDO() Function \n" << testDrive->initPDOs();

}