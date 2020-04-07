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

#include "Joint.h"
#include "Drive.h"

// Return values the execute movements of the drive
const enum setMovementReturnCode_t{
    SUCCESS = 1, 
    OUTSIDE_LIMITS = -1,
    INCORRECT_MODE = -2,
    UNKNOWN_ERROR = -100
};

class ActuatedJoint: public Joint
{
    private:
        /**
         * Contains a Drive object, which is a CANOpen device which is used to control the
         * physical hardware. 
         */
        const Drive drive;

        /**
         * Converts from the joint value to the equivalent value for the drive
         * 
         * Notes:
         * - The drive value is always an integer (due to the CANOpen specification)
         *      and the joint value is always a double (data type of q)
         * - This may be a linear relationship (e.g. degrees to encoder counts) or a more
         *      complicated one (e.g. linear actuator position to degrees) depending on the 
         *      structure of the device and system.
         * 
         * @param jointValue The joint value to be converted
         * @return The equivalent drive value for the given joint value
         */
        virtual int toDriveUnits(double jointValue);

         /**
         * Converts from the drive value to the equivalent value for the joint
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
        virtual double fromDriveUnits(int driveValue);

    public:
        /**
         * Default <code>Joint</code> constructor. Note that it requires an ID, and minimum
         * and maximum joint limits. These limits will be used to check for errors. 
         */
        ActuatedJoint(int jointID, double jointMin, double jointMax);
        /**
         * Set Mode - sets the mode of the device (nominally, position, velocity or torque control)
         * 
         * @param driveMode The mode to be used if possible
         * @return Configured Drive Mode, -1 if unsuccessful
         */ 
        ControlMode setMode(ControlMode driveMode);

        /** 
         * Sets a position set point (in joint units)  
         * 
         * @param pos The desired set position
         * @return The result of the setting
         */
        setMovementReturnCode_t setPosition(double desQ);

        /** 
         * Sets a velocity set point (in joint units)
         * 
         * @param velocity The desired set position
         * @return The result of the setting
         */
        setMovementReturnCode_t SetVelocity(double velocity);

        /** 
         * Sets a torque set point
         * 
         * @param torque The desired set position
         * @return The result of the setting
         */
        setMovementReturnCode_t SetTorque(double torque);

};