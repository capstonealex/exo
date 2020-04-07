/**
 * The <code>ExoRobot</code> class represents an ExoSkeleton Robot
 * in terms of its representation of the Alex exoskeleton hardware whose memory
 * is managed in this class.
 *
 */
#include "Robot.h"

class ExoRobot : public Robot
{
private:
    /**
   * Map between OD.nextmotion dictionary values to trajectory paramater 
   * structs defined for use in designed trajectory generation.
   *
   * @param[in] int OD.nextmotion entry
   */
    // TODO:: ADD IN CORRECT PARAMS FOR 4-7
    std::map<int, Trajectory::trajectory_parameters> movementTrajectoryMap;
    /**
   * Exoskeleton model paramaters for use in Trajectory generation
   *
   * @param
   */
    //TODO: exoParams or name Brad Params?
    Trajectory::pilot_parameters exoParamaters = {
        .lowerleg_length = 0.44,
        .upperleg_length = 0.44,
        .ankle_height = 0.12,
        .foot_length = 0.30,
        .hip_width = 0.43,
        .torso_length = 0.4,
        .buttocks_height = 0.05};

public:
    /**
   * Construct an exoSkeleton Robot object
   *
   * @param
   */
    ExoRobot();
    /** 
   * For each joint, move through Currently generated trajectories. 
   *
   */
    void moveThroughTraj();
    /** 
   * Determine if the currently generated trajectory is complete.
   *@return bool
   */
    bool isTrajFinished();
    /** 
   * Getter method for exoSkeleton defined Paramaters
   *@return Trajectory::pilot_paramaters
   */
    bool getExoParamaters();
}