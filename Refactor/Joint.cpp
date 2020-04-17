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

#include <iostream>
Joint::Joint(int jointID, double jointMin, double jointMax) : id(jointID), qMin(jointMin), qMax(jointMax) {
    q = 0;
}

Joint::Joint(int jointID, double jointMin, double jointMax, double q0) : id(jointID), qMin(jointMin), qMax(jointMax) {
    q = q0;
}
Joint::~Joint() {
    std::cout << " Joint object deleted" << std::endl;
}
int Joint::getId() {
    return id;
}

double Joint::getQ() {
    return q;
}

void Joint::getStatus() {
    std::cout << "Joint id number " << id << " @ pos " << getQ() << "deg" << std::endl;
}