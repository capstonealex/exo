//
// Created by William Campbell on 2019-07-23.
//

#include "Robot.h"
#include <string.h>

Robot::Robot(){
    cout<<"Setting Robot joint initial conditions...\n";
    // Set joint IDs
    joints[0].setId(1);
    joints[1].setId(2);
    joints[2].setId(3);
    joints[3].setId(4);
    // Set joint Intial positions.
    joints[0].applyPos(30);
    joints[1].applyPos(60);
    joints[2].applyPos(30);
    joints[3].applyPos(60);

};
void Robot::printInfo() {
    cout<<"This is an X2 robot with: \n";
    for (auto i=0; i<4 ;i++) {
        joints[i].printInfo();
    }
}
// Creates a socket connection to canopend using a pointer to int socket
