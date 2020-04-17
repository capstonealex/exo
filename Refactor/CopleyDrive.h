/**
/**
 * @brief An implementation of the Drive Object, specifically for the Copley Drive
 * 
 * @version 0.1
 * @date 2020-04-09
 */
#ifndef COPLEYDRIVE_H_INCLUDED
#define COPLEYDRIVE_H_INCLUDED
#include "Drive.h"

class CopleyDrive : public Drive {
   public:
    /**
         * @brief Construct a new Copley Drive object
         * 
         * @param NodeID CANopen Node ID
         */
    CopleyDrive(int NodeID);

    /**
         * @brief Destroy the Copley Drive object
         * 
         */
    ~CopleyDrive();
    /**
         * Initialises the drive (SDO start message)
         * 
         * @return True if successful, False if not
         */
    bool Init();

    /**
         * Sets the drive to Position control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return true if successful
         * @return false if not
         */
    bool initPosControl();

    /**
         * Sets the drive to Velocity control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return true if successful
         * @return false if not
         */
    bool initVelControl();

    /**
         * Sets the drive to Torque control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return true if successful
         * @return false if not
         */
    bool initTorqControl();

    /**
         * Updates the internal representation of the state of the drive 
         * 
         * @return true if successful
         * @return false if not
         */
    bool updateDriveStatus();

    /**
         * Writes the desired position to the Target Position of the motor drive (0x607A)
         * 
         * @return true if successful
         * @return false if not
         */
    bool setPos(int position);

    /**
         * Writes the desired velocity to the Target Velocity of the motor drive (0x60FF)
         * 
         * @return true if successful
         * @return false if not
         */
    bool setVel(int velocity);

    /**
         * Writes the desired torque to the Target Torque of the motor drive (0x6071)
         * 
         * @return true if successful
         * @return false if not
         */
    bool setTorque(int torque);

    /**
         * Returns the current position from the motor drive (0x6064)
         * 
         * @return Position from the motor drive
         */
    int getPos();

    /**
         * Returns the current velocity from the motor drive (0x606C)
         * 
         * @return Velocity from the motor drive
         */
    int getVel();

    /**
         * Returns the current torque from the motor drive (0x6077)
         * 
         * @return Torque from the motor drive
         */
    int getTorque();

    // Drive State Modifiers
    /**
         * @brief Changes the state of the drive to "ready to switch on". 
         * 
         * This is equivalent to setting bits 2 and 3 of Control Word (0x6064) to 1.
         * See also the CANopen Programmer's Manual (from Copley Controls)
         * 
         * @return true if operation successful
         * @return false if operation unsuccessful
         */
    bool readyToSwitchOn();

    /**
         * @brief Sets the state of the drive to "enabled"
         * 
         * This is equivalent to setting bits 0, 1, 2, 3 of the control word (0x06064) to 1
         * See also the CANopen Programmer's Manual (from Copley Controls)
         * 
         * @return true if operation successful
         * @return false if operation unsuccessful
         */
    bool enable();

    /**
         * @brief sets the state of the drive to "disabled"
         * 
         * This is equivalent to setting the control word (0x06064) to 0
         * See also the CANopen Programmer's Manual (from Copley Controls)
         * 
         * @return true if operation successful
         * @return false if operation unsuccessful
         */
    bool disable();
};

#endif