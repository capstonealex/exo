#include "ExoRobot.h"

ExoRobot::ExoRobot()
{
    if (initialise())
    {
        cout << "exoRobot object created" << endl;
        trajectoryGenerator.setPilotParameter(exoParams);
        trajectoryGenerator.setTrajectoryParameter(movementTrajMap[INITIAL]);
    }
    else
    {
        cout << "exoRobot failed to initialise" << endl;
    }
}
ExoRobot::~ExoRobot()
{
    std::cout << "delete exoRobot object begins" << std::endl;
    for (auto p : joints)
    {
        std::cout << "delete joint pointer...";
        delete p;
        std::cout << "deleted " << std::endl;
    }
    joints.clear();
    for (auto p : copleyDrive)
    {
        std::cout << "delete driver pointer...";
        delete p;
        std::cout << "deleted " << std::endl;
    }
    copleyDrive.clear();
    cout << "exoRobot deleted" << endl;
};
void ExoRobot::startNewTraj()
{
    printf("Start New Traj \n");
}
void ExoRobot::moveThroughTraj()
{
    std::cout << "Moving through Trajectory" << std::endl;
}

///Trajectory methods
void ExoRobot::setTrajectory()
{
    //TODO: LOAD FROM CURRENTMOTION variable or from OD access?
    int currentMotion = NORMALWALK;
    trajectoryGenerator.setTrajectoryParameter(movementTrajMap[currentMotion]);
}
void ExoRobot::printTrajectoryParam()
{
    std::cout << "Step height:" << trajectoryGenerator.trajectoryParameter.step_height << std::endl;
    std::cout << "Slop_angle: " << trajectoryGenerator.trajectoryParameter.slope_angle << std::endl;
}
bool ExoRobot::initialiseJoints()
{
    for (int id = 0; id < NUM_JOINTS; id++)
    {
        copleyDrive.push_back(new CopleyDrive(id + 1));
        joints.push_back(new TestActJoint(id, jointMinMap[id], jointMaxMap[id], *copleyDrive[id]));
    }
    return true;
}

// void ExoRobot::delete_pointed_to(T *const ptr)
// {
//     delete ptr;
// }
