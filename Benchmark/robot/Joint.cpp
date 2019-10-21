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
const int STRING_LENGTH = 50;
Joint::Joint()
{
    //Default constructor - SHOULD THROW AN ERROR
    q = 0;
    id = 0;
    // THESE MUST BE HARD SET AT OBJECT INITIALIZATION
    maxq = KNEE_MOTOR_POS1 * 4;
    minq = 0;
    // set position arrayIndex to 0;
    arrayIndex = 0;
    // Populate posTrajectoriesDeg and negtrajectories
    double posTrajectoriesDeg[NUM_TRAJ_POINTS] = {
        0,
        10,
        20,
        30,
        40,
        50,
        60,
        70,
        80,
        90};

    double negTrajectoriesDeg[NUM_TRAJ_POINTS] = {
        90,
        80,
        70,
        60,
        50,
        40,
        30,
        20,
        10,
        0};

    motorPosArrayConverter(posTrajectoriesDeg, posTrajectories, NUM_TRAJ_POINTS, LKNEE);
    motorPosArrayConverter(negTrajectoriesDeg, negTrajectories, NUM_TRAJ_POINTS, LKNEE);
    // printf("INITIALIZED POSTRAJECTORIES IN MOTOR COMMAND LAND TO: \n");
    // for (int i = 0; i < NUM_TRAJ_POINTS; i++)
    // {
    //     printf("%ld, ",posTrajectories[i]);
    // }
}
Joint::Joint(float q_init, int ID)
{
    cout << "Initializing joint WITH INPUTS \n";
    q = q_init;
    id = ID;
}
void Joint::incrementIndex()
{
    arrayIndex++;
    printf("ARRAY INDEX NOW %d\n", arrayIndex);
}
void Joint::zeroIndex()
{
    arrayIndex = 0;
    printf("ARRAY INDEX zeroed and now: %d", arrayIndex);
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

    if (nodeid == 1 || nodeid == 3)
    {
        calcAB(HIP_MOTOR_POS1, HIP_MOTOR_DEG1, HIP_MOTOR_POS2, HIP_MOTOR_DEG2, &A, &B);
    }

    if (nodeid == 2 || nodeid == 4)
    {
        calcAB(KNEE_MOTOR_POS1, KNEE_MOTOR_DEG1, KNEE_MOTOR_POS2, KNEE_MOTOR_DEG2, &A, &B);
    }
    for (int i = 0; i < arrSize; i++)
    {
        long solution = lround(origArr[i] * A + B);
        newArr[i] = solution;
    }
}
void Joint::motorPosConverter(double origDeg, long newMotorCmnd, int nodeid)
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

    newMotorCmnd = (long)(A * origDeg + B);
}

//calculate A and B in the formula y=Ax+B. Use by motorPosArrayConverter()
void Joint::calcAB(long y1, long x1, long y2, long x2, double *A, double *B)
{
    *A = 1.0 * (y2 - y1) / (x2 - x1);
    // printf("A is %f\n", *A);
    *B = 1.0 * (y1 * x2 - y2 * x1) / (x2 - x1);
    // printf("B is %f\n", *B);
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
    CO_OD_RAM.targetMotorPositions.motor2 = qd;
    // virtual joint motiom=n
    cout << "Joint move to command sent and is @ " << CO_OD_RAM.actualMotorPositions.motor2 << "\n";
}

void Joint::setVel(long qdotd)
{
    CO_OD_RAM.targetMotorVelocities.motor2 = qdotd;
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

float Joint::getVel(){
    return qdot;
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
    // Construct obj dictionary entry message for this motor id
    //CO_OD_RAM.actualMotorPositions.motor<id_goes_here>
    q = CO_OD_RAM.actualMotorPositions.motor2;
    qdot = CO_OD_RAM.actualMotorVelocities.motor2;
}
/*
 * bitflip High changes the specified control Word for this joints motor to HIGH
 * Returns true if successfull or false if not 
*/
bool Joint::bitflipHigh()
{
    //TODO: 1. Set up cases for position, velocity and Torque controlWorkds
    //      2. generalize to create .motor<motorID> dynamically
    //      3. error check control word has been changed in the actual motor.
    CO_OD_RAM.controlWords.motor2 = 31;
    return true;
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
    CO_OD_RAM.controlWords.motor2 = 15;
    return true;
}

void Joint::testWrite()
{
    double pos = CO_OD_RAM.actualMotorPositions.motor2;
    std::cout << "that worked actualMotorPos is:" << pos << "\n";
    CO_OD_RAM.actualMotorPositions.motor2 = pos + 1;
}
