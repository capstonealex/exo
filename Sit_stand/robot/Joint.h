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
    long maxq, minq;
    long maxdq, mindq;

    void setPos(long qd);
    void setVel(long dqd);
    void motorPosArrayConverter(double origArr[], long newArr[], int arrSize, int nodeid);
    void motorPosConverter(double origDeg, long * newMotorCmnd, int nodeid);
    void calcAB(long y1, long x1, long y2, long x2, double *A, double *B);
    int arrayIndex;
    int bitFlipState;
    // TODO: Add other vars after initial test implimentation up and running
    // qd, qdd,T, mode. limts, Transformation, Reduction Ratio(CONST)

public:
    //    CanDevice copley;// pointer to this joints candevice, the motor driver (COPLEY DRIVER)
    //static const int NUM_TRAJ_POINTS = 11;
    //static const int NUM_TRAJ_POINTS_STEPPING = 4;
    Joint();
    Joint(float q_init, int ID);
    void setId(int ID);
    int getId();
    void applyPos(long qd);
    void applyPosDeg(double qd);
    void applyVel(long dqd);

    int getPos();
    void printInfo();
    void updateJoint();
    void setTrajectories(double leftHipTraj[], double rightHipTraj[], double leftKneeTraj[], double rightKneeTraj[], int numPoints);
    //void setFirstLeftTrajectories();
    void testWrite();
    bool bitflipHigh();
    bool bitflipLow();
    void incrementIndex();
    int getIndex();
    void zeroIndex();
    void getTrajectorie();
    int getBitFlipState();
    void setBitFlipState(int bit);

    // Make two arrays for coresponding motor commands for trajectorues
    long trajectories[4];
//    long negTrajectories[NUM_TRAJ_POINTS];
};

#endif //CAPSTONE_JOINT_H
