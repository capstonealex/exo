#include "ExoRobot.h"

ExoRobot::ExoRobot()
{
    // Load in trajectory object paramaters
    trajectoryObj.setPilotParameter(exoParamaters);
    trajectoryObj.setTrajectoryParameter(initial_trajectory_parameters);
}

void ExoRobot::setTrajectory()
{
    //TODO: LOAD FROM CURRENTMOTION variable or from OD access?
    int currentMotion = SITDWN;
    trajectoryObj.setTrajectoryParameter(TrajParamMap[currentMotion]);
}
void ExoRobot::setTrajectoryS()
{
    int currentMotion = TILTUP;
    trajectoryObj.setTrajectoryParameter(TrajParamMap[currentMotion]);
}
void ExoRobot::printTrajectory()
{
    std::cout << "Step height:" << trajectoryObj.trajectoryParameter.step_height << std::endl;
    std::cout << "Slop_angle: " << trajectoryObj.trajectoryParameter.slope_angle << std::endl;
}
