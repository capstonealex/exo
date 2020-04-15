#include "ExoRobot.h"

ExoRobot::ExoRobot()
{
    initialiseJoints();
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
    //long lastTarget = 0;
    struct timeval tv;
    struct timeval tv_diff;
    struct timeval tv_changed;
    gettimeofday(&tv, NULL);
    timersub(&tv, &last_tv, &tv_diff);
    last_tv = tv;

    //uint32_t difftime =  tv_diff.tv_sec*1000000+tv_diff.tv_usec;
    long movingMicro = moving_tv.tv_sec * 1000000 + moving_tv.tv_usec;

    double trajTimeUS = trajectoryGenerator.trajectoryParameter.step_duration * 1000000;
    fracTrajProgress = movingMicro / trajTimeUS;

    // if Green Button is pressed, move through trajetory. Otherwise stay where you are
    if (buttons.getGButtonState())
    {
        // std::cout << fracTrajProgress << std::endl;
        timeradd(&moving_tv, &tv_diff, &tv_changed);
        moving_tv = tv_changed;
        //array for position and velocity profile
        double positionArray[NUM_JOINTS];
        //printInfo();

#ifndef _NOACTUATION
        // Send a new trajectory point
        // Get Trajectory point for this joint based on current time
        trajectoryGenerator.calcPosition(fracTrajProgress, positionArray);
        for (int i = 0; i < NUM_JOINTS; i++)
        {
            if (joints[i].getBitFlipState() == NOFLIP)
            {
                int j = joints[i].getId();
                cout << " applied position on joint " << joints[i].getId() << " is " << rad2deg(positionArray[j - 1]) << endl;
                joints[i].applyPosDeg(rad2deg(positionArray[j - 1]));

                // set state machine bitFlip to LOW state.
                joints[i].bitflipLow();
            }
            else
            {
                joints[i].bitflipHigh();
            }
        }
#endif
    }
    else
    {
        timeradd(&stationary_tv, &tv_diff, &tv_changed);
        stationary_tv = tv_changed;
    }
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
        joints.push_back(new ActuatedJoint(id, jointMinMap(id), jointMaxMap(id)));
    }
    return true;
}
