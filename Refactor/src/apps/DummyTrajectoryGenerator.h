/**
 * @file DummyTrajectoryGenerator.h
 * @author Justin Fong
 * @brief A trajectory generator to be used for testing purposes
 * @version 0.1
 * @date 2020-05-04
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef DUMMYTRAJECTORYGENERATOR_H_INCLUDED
#define DUMMYTRAJECTORYGENERATOR_H_INCLUDED

#include <cmath>

#include "TrajectoryGenerator.h"

#define deg2rad(deg) ((deg)*M_PI / 180.0)
#define rad2deg(rad) ((rad)*180.0 / M_PI)

enum Trajectory {
    SIT = 0,
    STAND = 1,
};

class DummyTrajectoryGenerator : public TrajectoryGenerator {
   private:
    std::vector<double[2]> endPoints;
    Trajectory currTraj = SIT;
    double trajTime = 2;
    int numJoints = 6;

   public:
    DummyTrajectoryGenerator(int NumOfJoints);
    /**
     * @brief Implementation of the initialiseTrajectory method in TrajectoryGenerator
     * 
     * @return true 
     * @return false 
     */
    bool initialiseTrajectory();

    /**
     * @brief 
     * 
     */
    bool initialiseTrajectory(Trajectory traj, double time);

    /**
     * @brief Implementation of the getSetPoint method in TrajectoryGenerator
     * @param time The time corresponding to the point. 
     * 
     * @return vector<double> 
     */
    std::vector<double> getSetPoint(double time);
};

#endif