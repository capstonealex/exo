/**
 * The <code>ActuatedJoint</code> class is a abstract class which represents a joint in a
 * <code>Robot</code> objec. This class implements the Joint class, and specifically 
 * represents a joint which is actuated. This therefore requires a Drive object
 * which will be used to interact with the physical hardware.  
 * 
 *
 * Version 0.1
 * Date: 07/04/2020
 */

#ifndef ACTUATEDJOINT_H_DEFINED
#define ACTUATEDJOINT_H_DEFINED
#include "Joint.h"
#include "Drive.h"

/**
 * The <code>setMovementReturnCode_t<code> is used to determine whether the movement was a
 * success, or whether an error occurred in its application. 
 */ 
enum setMovementReturnCode_t{
    SUCCESS = 1, 
    OUTSIDE_LIMITS = -1,
    INCORRECT_MODE = -2,
    UNKNOWN_ERROR = -100
};

class ActuatedJoint: public Joint
{
    private:
        /**
         * @brief Contains a Drive object, which is a CANOpen device which is used to control the
         * physical hardware. 
         * 
         */
        Drive drive;

        /**
         * @brief Converts from the joint value to the equivalent value for the drive
         * 
         * Notes:
         * - The drive value is always an integer (due to the CANOpen specification)
         *      and the joint value is always a double (data type of q)
         * - This may be a linear relationship (e.g. degrees to encoder counts) or a more
         *      complicated one (e.g. linear actuator position to degrees) depending on the 
         *      structure of the device and system.
         * 
         * 
         * @param jointValue The joint value to be converted
         * @return int The equivalent drive value for the given joint value
         */
        virtual int toDriveUnits(double jointValue)=0;

         /**
         * @brief Converts from the drive value to the equivalent value for the joint
         * 
         * Notes:
         * - The drive value is always an integer (due to the CANOpen specification)
         *      and the joint value is always a double (data type of q)
         * - This may be a linear relationship (e.g. degrees to encoder counts) or a more
         *      complicated one (e.g. linear actuator position to degrees) depending on the 
         *      structure of the device and system.
         * 
         * @param driveValue The drive value to be converted
         * @return The equivalent joint value for the given drive value
         */
        virtual double fromDriveUnits(int driveValue)=0;

    public:
        /**
         * @brief Construct a new Actuated Joint object
         * 
         * @param jointID Unique ID representing the joint (not checked in this class)
         * @param jointMin Minimum allowable value for the joint
         * @param jointMax Maximum allowable value for the joint
         */
        ActuatedJoint(int jointID, double jointMin, double jointMax, Drive drive);
        
        /**
         * @brief Set the mode of the device (nominally, position, velocity or torque control)
         * 
         * @param driveMode The mode to be used if possible
         * @return ControlMode Configured Drive Mode, -1 if unsuccessful
         */
        ControlMode setMode(ControlMode driveMode);

        /**
         * @brief Set the Position object
         * 
         * @param desQ The desired set position
         * @return setMovementReturnCode_t The result of the setting
         */
        setMovementReturnCode_t setPosition(double desQ);

        /**
         * @brief Sets a velocity set point (in joint units)
         * 
         * @param velocity The desired set position
         * @return setMovementReturnCode_t The result of the setting
         */
        setMovementReturnCode_t setVelocity(double velocity);

        /**
         * @brief Set the torque set point
         * 
         * @param torque The desired set position
         * @return setMovementReturnCode_t The result of the setting
         */
        setMovementReturnCode_t setTorque(double torque);

};

#endif