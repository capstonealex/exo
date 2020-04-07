/**
 * The <code>ExoRobot</code> class represents an ExoSkeleton Robot in terms of its 
 * representation of the Alex exoskeleton hardware whose memory
 * is managed in this class.
 *
 */
#include "RobotParams.h"

class ExoRobot : public Robot
{
private:
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
    /** 
   * Getter method for currently loaded motion trajectory paramaters
   *@return Trajectory::trajectory_parameters
   */
    bool getTrajParamaters();

    //
    ////TEST CODE: MOVE TO ROBOT LEVEL ONCE WORKING

    /** 
   * Setter method for exoSkeleton Trajectory Paramaters
   * Set trajectory paramaters to those coresponding to the current Next Motion value from user
   *
   */
    void setTrajectory();
    void setTrajectoryS();
    void printTrajectory();
};