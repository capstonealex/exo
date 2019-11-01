//
// Created by William Campbell on 2019-07-24.
//
#include "CANopen.h"
#include "Joint.h"
#include <stdlib.h>
#include <string>
#include <math.h>

//Node ID for the 4 joints
#define LHIP (1)
#define LKNEE (2)
#define RHIP (3)
#define RKNEE (4)
//Knee motor reading and corresponding angle. Used for mapping between degree and motor values.
#define KNEE_MOTOR_POS1 (250880)
#define KNEE_MOTOR_DEG1 (90)
#define KNEE_MOTOR_POS2 (0)
#define KNEE_MOTOR_DEG2 (0)
//Hip motor reading and corresponding angle. Used for mapping between degree and motor values.
#define HIP_MOTOR_POS1 (250880)
#define HIP_MOTOR_DEG1 (90)
#define HIP_MOTOR_POS2 (0)
#define HIP_MOTOR_DEG2 (180)

#define LEFT_HIP (1)
#define LEFT_KNEE (2)
#define RIGHT_HIP (3)
#define RIGHT_KNEE (4)

const int STRING_LENGTH = 50;
// For control word bitFlip functions
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)

Joint::Joint()
{
    //Default constructor - SHOULD THROW AN ERROR
    q = 0;
    id = 0;
    // THESE MUST BE HARD SET AT OBJECT INITIALIZATION
    maxq = KNEE_MOTOR_POS1*2;
    minq = 0;
    
    maxdq = 2000000;
    mindq = 0;
    // set position arrayIndex to 0;
    arrayIndex = 0;
    bitFlipState = NOFLIP;
}

Joint::Joint(float q_init, int ID)
{
    cout << "Initializing joint WITH INPUTS \n";
    q = q_init;
    id = ID;
}

void Joint::setTrajectories(double leftHipTraj[], double rightHipTraj[], double leftKneeTraj[], double rightKneeTraj[], int numPoints)
{
    if (this->id == LEFT_KNEE)
    {
        motorPosArrayConverter(leftKneeTraj, this->trajectories, numPoints, this->id);
    }
    else if(this->id == RIGHT_KNEE)
    {
        motorPosArrayConverter(rightKneeTraj, this->trajectories, numPoints, this->id);
    }
    else if (this->id == LEFT_HIP)
    {
        motorPosArrayConverter(leftHipTraj, this->trajectories, numPoints, this->id);
    }
    else if (this->id == RIGHT_HIP)
    {
        motorPosArrayConverter(rightHipTraj, this->trajectories, numPoints, this->id);

    }
}

void Joint::getTrajectorie()
{
    printf("~~~~~~~~~~~~~~~~~\n");
    printf("Trajectories for joint %d", this->id);

    for (int i = 0; i < 4; i++)
    {
        printf(" Trajectory %d: %lu", i, this->trajectories[i]);
    }
}
void Joint::incrementIndex()
{
    arrayIndex++;
}
void Joint::zeroIndex()
{
    arrayIndex = 0;
}
int Joint::getIndex()
{
    return arrayIndex;
}
/*Helper functions for motor deg to command conversion*/
// TODO -> don't use this and only use trajectory function
//Used to convert position array from degrees to motors counts as used in CANopen
void Joint::motorPosArrayConverter(double origArr[], long newArr[], int arrSize, int nodeid)
{
    double A = 0;
    double B = 0;

    if (nodeid == RIGHT_HIP || nodeid == LEFT_HIP)
    {
        calcAB(HIP_MOTOR_POS1, HIP_MOTOR_DEG1, HIP_MOTOR_POS2, HIP_MOTOR_DEG2, &A, &B);
    }

    if (nodeid == RIGHT_KNEE || nodeid == LEFT_KNEE)
    {
        calcAB(KNEE_MOTOR_POS1, KNEE_MOTOR_DEG1, KNEE_MOTOR_POS2, KNEE_MOTOR_DEG2, &A, &B);
    }
    for (int i = 0; i < arrSize; i++)
    {
        long solution = lround(origArr[i] * A + B);
        newArr[i] = solution;
    }
}
void Joint::motorPosConverter(double origDeg, long * newMotorCmnd, int nodeid)
{
    double A = 0;
    double B = 0;

    if (nodeid == 1 || nodeid == 3)
    {
        calcAB(HIP_MOTOR_POS1, HIP_MOTOR_DEG1, HIP_MOTOR_POS2, HIP_MOTOR_DEG2, &A, &B);
    }
    if (nodeid == 2 || nodeid == 4)
    {
        calcAB(KNEE_MOTOR_POS1, KNEE_MOTOR_DEG1, KNEE_MOTOR_POS2, KNEE_MOTOR_DEG2, &A, &B);
    }

    (*newMotorCmnd) = (long)(A * origDeg + B);
}

//calculate A and B in the formula y=Ax+B. Use by motorPosArrayConverter()
void Joint::calcAB(long y1, long x1, long y2, long x2, double *A, double *B)
{
    *A = 1.0 * (y2 - y1) / (x2 - x1);
    // printf("A is %f\n", *A);
    *B = 1.0 * (y1 * x2 - y2 * x1) / (x2 - x1);
    // printf("B is %f\n", *B);
}
void Joint::applyPosDeg(double qd)
{
    //Safety checks.
    // Is joint where we think it is? or within safe range of it?
    // are we trying to move to a pos within the joints limits?
    ///// Testing for PDOs
    long qd_long = 0;
    motorPosConverter(qd, &qd_long, this->id);
    printf("Joint ID: %d, %3f, %ld \n", this->id, qd,  qd_long);
    applyPos(qd_long);
}

void Joint::applyPos(long qd)
{
    //Safety checks.
    // Is joint where we think it is? or within safe range of it?
    // are we trying to move to a pos within the joints limits?
    ///// Testing for PDOs
    printf("apply pos of %ld issued\n", qd);
    if (qd >= minq && qd <= maxq)
    {
        Joint::setPos(qd);
    }
    else
    {
        cout << "Positions outside of joint limits"
             << "\n";
    }
}
void Joint::setPos(long qd)
// TODO: 1. generalize to create .motor<motorID> dynamically
{
    // Set target motor position -> will send out to motors
    if (this->id == 1)
    {
        CO_OD_RAM.targetMotorPositions.motor1 = qd;
    }
    else if (this->id == 2)
    {
        CO_OD_RAM.targetMotorPositions.motor2 = qd;
    }
    else if (this->id == 3)
    {
        CO_OD_RAM.targetMotorPositions.motor3 = qd;
    }
    else if (this->id == 4)
    {
        CO_OD_RAM.targetMotorPositions.motor4 = qd;
    }
}

void Joint::applyVel(long dqd)
{
    printf("apply vel of %ld issued\n", dqd);
    if (dqd >= mindq && dqd <= maxdq)
    {
        Joint::setVel(dqd);
    }
    else
    {
        cout << "Positions outside of joint limits"
             << "\n";
    }
}


void Joint::setVel(long dqd)
// TODO: 1. generalize to create .motor<motorID> dynamically
{
    // Set target motor position -> will send out to motors
    if (this->id == 1)
    {
        CO_OD_RAM.targetMotorVelocities.motor1 = dqd;
    }
    else if (this->id == 2)
    {
        CO_OD_RAM.targetMotorVelocities.motor2 = dqd;
    }
    else if (this->id == 3)
    {
        CO_OD_RAM.targetMotorVelocities.motor3 = dqd;
    }
    else if (this->id == 4)
    {
        CO_OD_RAM.targetMotorVelocities.motor4 = dqd;
    }
}
void Joint::setId(int ID)
{
    id = ID;
}
int Joint::getId()
{
    return id;
}
int Joint::getPos()
{
    return q;
}

void Joint::printInfo()
{
    cout << "Joint id number " << id << " @ pos " << q << "\n";
}
//// Robot motion and state update functions
void Joint::updateJoint()
{
    /// Update current joint position from object dictionary
    /// This should be internally mapped from object dictionary
    // TODO: Construct obj dictionary entry message for this motor id
    //CO_OD_RAM.actualMotorPositions.motor<id_goes_here>
    if (this->id == 1)
    {
        q = CO_OD_RAM.actualMotorPositions.motor1;
    }
    else if (this->id == 2)
    {
        q = CO_OD_RAM.actualMotorPositions.motor2;
    }
    else if (this->id == 3)
    {
        q = CO_OD_RAM.actualMotorPositions.motor3;
    }
    else if (this->id == 4)
    {
        q = CO_OD_RAM.actualMotorPositions.motor4;
    }
}
/*
 * bitflip High changes the specified control Word for this joints motor to HIGH
 * Returns true if successfull or false if not 
*/
bool Joint::bitflipHigh()
{
    //TODO: 1. Set up caseses for position, velocity and Torque controlWorkds
    //      2. generalize to create .motor<motorID> dynamically
    //      3. error check control word has been changed in the actual motor.
    if(bitFlipState == BITHIGH){
        if (this->id == 1)
        {
            CO_OD_RAM.controlWords.motor1 = 63;
        }
        else if (this->id == 2)
        {
            CO_OD_RAM.controlWords.motor2 = 63;
        }
        else if (this->id == 3)
        {
            CO_OD_RAM.controlWords.motor3 = 63;
        }
        else if (this->id == 4)
        {
            CO_OD_RAM.controlWords.motor4 = 63;
        }
        bitFlipState = NOFLIP;
        return true;
    }
    else{
        printf("FALTY DIRECTION TO BITFLIPHIGH\n");
        return false;
    }
}
/*
 * bitflip Low changes the specified control Word for this joints motor to HIGH
 * Returns true if successfull or false if not 
*/
bool Joint::bitflipLow()
{
    //TODO: 1. Set up caseses for position, velocity and Torque controlWorkds
    //      2. generalize to create .motor<motorID> dynamically
    //      3. error check control word has been changed in the actual motor.
    if(bitFlipState == BITLOW||bitFlipState == NOFLIP){
        if (this->id == 1)
        {
            CO_OD_RAM.controlWords.motor1 = 47;
        }
        else if (this->id == 2)
        {
            CO_OD_RAM.controlWords.motor2 = 47;
        }
        else if (this->id == 3)
        {
            CO_OD_RAM.controlWords.motor3 = 47;
        }
        else if (this->id == 4)
        {
            CO_OD_RAM.controlWords.motor4 = 47;
        }
        bitFlipState = BITHIGH;
        return true;
    }
    else{
        printf("FALTY DIRECTION TO BITFLIPLOW\n");
        return false;
    }
}

void Joint::testWrite()
{
    double pos = CO_OD_RAM.actualMotorPositions.motor2;
    std::cout << "that worked actualMotorPos is:" << pos << "\n";
    CO_OD_RAM.actualMotorPositions.motor2 = pos + 1;
}

int Joint::getBitFlipState(){
    return bitFlipState;
}
void Joint::setBitFlipState(int bit){
    bitFlipState = bit;
}