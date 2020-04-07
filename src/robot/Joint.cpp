/**
 * The <code>Joint</code> class is a abstract class which represents a joint in a
 * <code>Robot</code> objec. This class can be used to represent all types of joints,
 * including actuated, non-actuated, revolute, prismatic, etc.
 * 
 *
 * Version 0.1
 * Date: 07/04/2020
 * 
 */
#include "Joint.h"

/**
 * Default <code>Joint</code> constructor. Note that it requires an ID, and minimum
 * and maximum joint limits. These limits will be used to check for errors. 
 */
Joint::Joint(int jointID, double jointMin, double jointMax) :
id(jointID), qMin(jointMin), qMax(jointMax)
{
    q = 0;
}

/**
 * Return the ID of the joint
 */
int Joint::getId(){
    return id;
}

/**
 * Default method to return the value of the joint. Note that this may be
 * overwritten to check.
 */
double Joint::getQ(){
    return q;
}