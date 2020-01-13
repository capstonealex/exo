//
// Created by William Campbell on 2019-07-24.
//
#include "CANopen.h"
#include "Joint.h"
#include <stdlib.h>
#include <string>
#include <math.h>

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
//Ankle motor reading and corresponding angle. Used for mapping between degree and motor values.
#define ANKLE_MOTOR_POS1 (0)
#define ANKLE_MOTOR_DEG1 (90)
#define ANKLE_MOTOR_POS2 (-800000)
#define ANKLE_MOTOR_DEG2 (115)

const int STRING_LENGTH = 50;
// For control word bitFlip functions
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)

Joint::Joint()
{
    //Default constructor - SHOULD THROW AN ERROR
    q = 0;
    qd = 0;
    id = 0;
    
    // THESE MUST BE HARD SET AT OBJECT INITIALIZATION
    maxq = KNEE_MOTOR_POS1*1.5;
    minq = 0;
    
    maxdq = 2000000;
    mindq = 0;
    
    // set position arrayIndex to 0;
    bitFlipState = NOFLIP;
}

Joint::Joint(double q_init, int ID)
{
    cout << "Initializing joint WITH INPUTS \n";
    q = q_init;
    id = ID;
    
    if (this->id == LEFT_KNEE || this->id == RIGHT_KNEE){
        maxq = KNEE_MOTOR_POS1*1.5;
        minq = 0;
    } else if  (this->id == LEFT_HIP || this->id == RIGHT_HIP){
        maxq = KNEE_MOTOR_POS1*1.5;
        minq = 0;
    } else if (this->id == LEFT_ANKLE || this->id == RIGHT_ANKLE){
        maxq = 800000;
        minq = -800000;
    }
}

/*Helper functions for motor deg to command conversion*/
// TODO -> don't use this and only use trajectory function
//Used to convert position array from degrees to motors counts as used in CANopen
void Joint::motorPosConverter(double origDeg, long * newMotorCmnd, int nodeid)
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
    if (nodeid == RIGHT_ANKLE || nodeid == LEFT_ANKLE)
    {
        calcAB(ANKLE_MOTOR_POS1, ANKLE_MOTOR_DEG1, ANKLE_MOTOR_POS2, ANKLE_MOTOR_DEG2, &A, &B);
    }
    (*newMotorCmnd) = (long)(A * origDeg + B);
}

double Joint::motorPosToDegConverter(long motorCmdAngle, int nodeid)
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
    if (nodeid == RIGHT_ANKLE || nodeid == LEFT_ANKLE)
    {
        calcAB(ANKLE_MOTOR_POS1, ANKLE_MOTOR_DEG1, ANKLE_MOTOR_POS2, ANKLE_MOTOR_DEG2, &A, &B);
    }

    return (motorCmdAngle - B)/A;
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
    //printf("Joint ID: %d, %3f, %ld \n", this->id, qd,  qd_long);
    applyPos(qd_long);
}

void Joint::applyPos(long qd)
{
    //Safety checks.
    // Is joint where we think it is? or within safe range of it?
    // are we trying to move to a pos within the joints limits?
    ///// Testing for PDOs
    //printf("apply pos of %ld issued\n", qd);
    if (qd >= minq && qd <= maxq)
    {
        Joint::setPos(qd);
    }
    else
    {
        printf("Positions outside of joint limits, JID: %d, Pos: %d , %d, %d \n", this->id, qd, minq, maxq);
    }
}
void Joint::setPos(long qd)
// TODO: 1. generalize to create .motor<motorID> dynamically
{
    this->qd = qd;
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
    else if (this->id == 5)
    {
        CO_OD_RAM.targetMotorPositions.motor5 = qd;
    }
    else if (this->id == 6)
    {
        CO_OD_RAM.targetMotorPositions.motor6 = qd;
    }
}
void Joint::disable()
// TODO: 1. generalize to create .motor<motorID> dynamically
{
    // Set target motor position -> will send out to motors
    if (this->id == 1)
    {
        CO_OD_RAM.controlWords.motor1 = 0;
    }
    else if (this->id == 2)
    {
        CO_OD_RAM.controlWords.motor2 = 0;
    }
    else if (this->id == 3)
    {
        CO_OD_RAM.controlWords.motor3 = 0;
    }
    else if (this->id == 4)
    {
        CO_OD_RAM.controlWords.motor4 = 0;
    }
    else if (this->id == 5)
    {
        CO_OD_RAM.controlWords.motor5 = 0;
    }
    else if (this->id == 6)
    {
        CO_OD_RAM.controlWords.motor6 = 0;
    }
}

void Joint::readyToSwitchOn()
// TODO: 1. generalize to create .motor<motorID> dynamically
{
    // Set target motor position -> will send out to motors
    if (this->id == 1)
    {
        CO_OD_RAM.controlWords.motor1 = 6;
    }
    else if (this->id == 2)
    {
        CO_OD_RAM.controlWords.motor2 = 6;
    }
    else if (this->id == 3)
    {
        CO_OD_RAM.controlWords.motor3 = 6;
    }
    else if (this->id == 4)
    {
        CO_OD_RAM.controlWords.motor4 = 6;
    }
    else if (this->id == 5)
    {
        CO_OD_RAM.controlWords.motor5 = 6;
    }
    else if (this->id == 6)
    {
        CO_OD_RAM.controlWords.motor6 = 6;
    }
}

void Joint::enable()
// TODO: 1. generalize to create .motor<motorID> dynamically
{
    // Set target motor position -> will send out to motors
    if (this->id == 1)
    {
        CO_OD_RAM.controlWords.motor1 = 15;  // 0x0F
    }
    else if (this->id == 2)
    {
        CO_OD_RAM.controlWords.motor2 = 15;
    }
    else if (this->id == 3)
    {
        CO_OD_RAM.controlWords.motor3 = 15;
    }
    else if (this->id == 4)
    {
        CO_OD_RAM.controlWords.motor4 = 15;
    }
    else if (this->id == 5)
    {
        CO_OD_RAM.controlWords.motor5 = 15;
    }
    else if (this->id == 6)
    {
        CO_OD_RAM.controlWords.motor6 = 15;
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
    else if (this->id == 5)
    {
        CO_OD_RAM.targetMotorVelocities.motor5 = dqd;
    }
    else if (this->id == 6)
    {
        CO_OD_RAM.targetMotorVelocities.motor6 = dqd;
    }
}
void Joint::setId(int ID)
{
    id = ID;
    
    if (this->id == LEFT_KNEE || this->id == RIGHT_KNEE){
        maxq = KNEE_MOTOR_POS1*1.5;
        minq = 0;
    } else if  (this->id == LEFT_HIP || this->id == RIGHT_HIP){
        maxq = KNEE_MOTOR_POS1*1.5;
        minq = -27870;
    } else if (this->id == LEFT_ANKLE || this->id == RIGHT_ANKLE){
        maxq = 800000;
        minq = -800000;
    }
}

int Joint::getId()
{
    return id;
}
int Joint::getPos()
{
    return q;
}

double Joint::getPosDeg()
{
    // Convert q to degrees
    double qdeg = motorPosToDegConverter(q, this->id);
    return qdeg;
}

double Joint::getDesPosDeg()
{
    // Convert q to degrees
    double qddeg = motorPosToDegConverter(qd, this->id);
    return qddeg;
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
    else if (this->id == 5)
    {
        q = CO_OD_RAM.actualMotorPositions.motor5;
    }
    else if (this->id == 6)
    {
        q = CO_OD_RAM.actualMotorPositions.motor6;
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
        else if (this->id == 5)
        {
            CO_OD_RAM.controlWords.motor5 = 63;
        }
        else if (this->id == 6)
        {
            CO_OD_RAM.controlWords.motor6 = 63;
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
        else if (this->id == 5)
        {
            CO_OD_RAM.controlWords.motor5 = 47;
        }
        else if (this->id == 6)
        {
            CO_OD_RAM.controlWords.motor6 = 47;
        }
        bitFlipState = BITHIGH;
        return true;
    }
    else{
        printf("FALTY DIRECTION TO BITFLIPLOW\n");
        return false;
    }
}

int Joint::getBitFlipState(){
    return bitFlipState;
}
void Joint::setBitFlipState(int bit){
    bitFlipState = bit;
}

int Joint::getStatus(){
    int retVal = 0;
     if (this->id == 1)
    {
        retVal = CO_OD_RAM.statusWords.motor1;
    }
    else if (this->id == 2)
    {
        retVal = CO_OD_RAM.statusWords.motor2;
    }
    else if (this->id == 3)
    {
        retVal = CO_OD_RAM.statusWords.motor3;
    }
    else if (this->id == 4)
    {
        retVal = CO_OD_RAM.statusWords.motor4;
    }
    else if (this->id == 5)
    {
        retVal = CO_OD_RAM.statusWords.motor5;
    }
    else if (this->id == 6)
    {
        retVal = CO_OD_RAM.statusWords.motor6;
    }
    return retVal;
}
double Joint::getActualTorque(){
    double retVal = 0;
     if (this->id == 1)
    {
        retVal = CO_OD_RAM.actualMotorTorques.motor1/10;
    }
    else if (this->id == 2)
    {
        retVal = CO_OD_RAM.actualMotorTorques.motor2/10;
    }
    else if (this->id == 3)
    {
        retVal = CO_OD_RAM.actualMotorTorques.motor3/10;
        //printf("Motor 3: %3f \n", retVal);
    }
    else if (this->id == 4)
    {
        retVal = CO_OD_RAM.actualMotorTorques.motor4/10;
        //printf("Motor 4: %3f \n", retVal);
    }
    else if (this->id == 5)
    {
        retVal = 0;
    }
    else if (this->id == 6)
    {
        retVal = 0;
    }
    return retVal;
}