//
// Created by William Campbell on 2019-07-30.
//

#ifndef CANOPENBEAGLE_JOINT_H
#define CANOPENBEAGLE_JOINT_H

//#include <mutex>  // For std::unique_lock
//#include <shared_mutex>
//#include <thread>
#include <iostream>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>

using namespace std;

class Joint
{
    //Private members
    int id;
    float q;
    float maxq, minq;
    void setPos(float qd);
    //Will: Add other vars after initial test implimentation up and running
    // qd, qdd,T, mode. limts, Transformation, Reduction Ratio(CONST)

public:
    //    CanDevice copley;// pointer to this joints candevice, the motor driver (COPLEY DRIVER)
    Joint();
    Joint(float q_init, int ID);
    void setId(int ID);
    int getId();
    void applyPos(float qd);
    int getPos();
    void printInfo();
    void updateJoint();
    void testWrite();
    bool bitflipHigh();
    bool bitflipLow();
};

#endif //CAPSTONE_JOINT_H
