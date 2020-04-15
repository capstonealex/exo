#include "ExoRobot.h"

ExoRobot::ExoRobot()
{
    initialise();
    trajectoryGenerator.setPilotParameter(exoParams);
    trajectoryGenerator.setTrajectoryParameter(movementTrajMap[INITIAL]);
}

void ExoRobot::startNewTraj()
{
    // Set the bit flip state to zero
    for (auto i = 0; i < NUM_JOINTS; i++)
    {
        joints[i].setBitFlipState(NOFLIP);
    }

    // Index Resetting
    fracTrajProgress = 0;
    TrajectoryGenerator::jointspace_state startNewTrajJointspace;
    double robotJointspace[NUM_JOINTS];
    int i;
    for (i = 0; i < NUM_JOINTS; i++)
    {
        int j = joints[i].getId();
        robotJointspace[j - 1] = deg2rad(joints[i].getPosDeg());
    }
    cout << "joints position at start traj" << endl;
    printInfo();
    startNewTrajJointspace = {.q = {robotJointspace[0],
                                    robotJointspace[1],
                                    robotJointspace[2],
                                    robotJointspace[3],
                                    deg2rad(85),  //robotJointspace[4],
                                    deg2rad(85)}, //robotJointspace[5]},
                              .time = 0};

    trajectoryGenerator.generateAndSaveSpline(startNewTrajJointspace);

    // Reset the time
    timerclear(&moving_tv);
    timerclear(&stationary_tv);
    gettimeofday(&start_traj, NULL);
    last_tv = start_traj;

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
        CopleyDrive *testDrive = new CopleyDrive(id + 1);
        joints.push_back(new TestActJoint(id, jointMinMap[id], jointMaxMap[id], *testDrive));
    }
    return true;
}
