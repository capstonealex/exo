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

//Node ID for the 4 joints

#define LEFT_HIP 1
#define LEFT_KNEE 2
#define RIGHT_HIP 3
#define RIGHT_KNEE 4
#define LEFT_ANKLE 5
#define RIGHT_ANKLE 6

using namespace std;

class Joint
{
    //Private members
    int id;
    double q;
    double qd;
    long maxq, minq;
    long maxdq, mindq;
    double converterA, converterB;

    void setPos(long qd);
    void setVel(long dqd);
    void motorPosConverter(double origDeg, long *newMotorCmnd, int nodeid);
    double motorPosToDegConverter(long motorCmdAngle, int nodeid);
    void calcAB(long y1, long x1, long y2, long x2, double *A, double *B);
    int bitFlipState;
    // TODO: Add other vars after initial test implimentation up and running
    // qd, qdd,T, mode. limts, Transformation, Reduction Ratio(CONST)

public:
    //    CanDevice copley;// pointer to this joints candevice, the motor driver (COPLEY DRIVER)
    //static const int NUM_TRAJ_POINTS = 11;
    //static const int NUM_TRAJ_POINTS_STEPPING = 4;
    Joint();
    Joint(double q_init, int ID);
    void setId(int ID);
    int getId();
    void applyPos(long qd);
    void applyPosDeg(double qd);
    void applyVel(long dqd);

    void disable();
    void readyToSwitchOn();
    void enable();

    int getPos();
    double getPosDeg();
    double getDesPosDeg();

    void printInfo();
    void updateJoint();
    void testWrite();
    bool bitflipHigh();
    bool bitflipLow();
    int getStatus();
    int getActualTorque();
    int getBitFlipState();
    void setBitFlipState(int bit);

    // Make two arrays for coresponding motor commands for trajectorues
    long trajectories[4];
};

#endif //CAPSTONE_JOINT_H
