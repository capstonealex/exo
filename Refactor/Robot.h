/**
*  The <code>Robot</code> class is a abstract class which is a software representation of a Robot
 * with a flexible representation in terms of number of joints, number of sensors and type of I/O 
 * the real world or virtual robot has. The class specificall represents a robot with an underlying
 * bus network connecting components to a master node, being the robots computer or processor.
 * Implementations have been designed <code>ExoRobot<code> under CANOpen protocol, however others
 * may be implemented by future developers.
 * 
 * Version 0.1
 * Date: 07/04/2020
 * 
 */
/**
 * The <code>Robot</code> class is a abstract class which represents a joint in a
 * <code>Robot</code> objec. This class implements the Joint class, and specifically 
 * represents a joint which is actuated. This therefore requires a Drive object
 * which will be used to interact with the physical hardware.  
 * 
 *
 * Version 0.1
 * Date: 07/04/2020
 */

/*Header Guard*/
#ifndef ROBOT_H
#define ROBOT_H
#include "Joint.h"
#include "TrajectoryGenerator.h"
#include "Buttons.h"
#include <vector>
using namespace std;

class Robot
{
private:
public:
  //Setup
  /**
 * @brief Default <code>Robot</code> constructor.
 */
  Robot();
  ~Robot();
  /**
     * @brief Initialize memory for the designed <code>Robot<code> classes specific
     * <code>Joint<code> objects + sensors (if available) using the pure virtual initialiseJoints()
     * implemented by the robot designer. Based on the given Joints, initNetwork() will configure 
     * these joints for CAN PDO messaging and Load the specififed Controller, by default set to Positio.
     * 
     * 
     * @return true 
     * @return false 
     */
  bool initialise();
  /**
     * @brief Pure Virtual function, implemeted by robot designer with specified number of each concrete joint classes
     * for the robot hardware desired.
     * 
     */
  virtual bool initialiseJoints() = 0;
  /**
     * @brief Fore the given designed robot layout, initialise CANopen network messaging.
     * 
     * @return true 
     * @return false 
     */
  bool initialiseNetwork();

  //Robot objects
  /**
 * @brief Vector of pointers to Abstract <class>Joint<class> Objects, number and type must be specified by 
 * Software design in <class>Robot<class> Implementation.
 * Note: Use pointers to the joint objects here, so that the derived objects are not cast to Joint, truncating
 * any of their explicit implementations.
 * 
 */
  vector<Joint *> joints;
  /**
 * @brief Trajectory Object 
 * 
 */
  TrajectoryGenerator trajectoryGenerator;
  Buttons buttons;

  //Core  functions
  /**
 * @brief Update all of this <code>Robot<code> software joint positions 
 * from object dictionary entries.
 * 
 */
  void updateRobot();
  /**
 * @brief print out status of robot and all of its joints
 * 
 */
  void getStatus();
  /**
 * @brief print out status of <code>Joint<code> J_i
 * 
 */
  void getJointStatus(Joint J_i);

  ////Movement
  /**
 * @brief pure virtual function, must be designed by the robot developer to load correct 
 * trajectory paramaters from some developer determined value. E.g. button value or Object Dictionary entry.
 */

  virtual void setTrajectory() = 0; //TODO: Make this an abstract function call - currently in exoROBOT

  ////Logging
  /**
 * @brief Initialises Logging to specified file
 * 
 */
  void initialiseLog();
  /**
 * @brief Log input data point to currently open log file
 * 
 */
  void logDataPoint(std::string data);
  /**
 * @brief Save and close any currently open logging files
 * 
 */
  bool closeLog();
};

#endif //ROBOT_H
