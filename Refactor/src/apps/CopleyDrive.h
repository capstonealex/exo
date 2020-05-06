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
typedef struct motorProfile {
    int profileVelocity;
    int profileAccelreation;
    int profileDeceleration;
} motorProfile;
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
    /**
       *     @brief  Generates the list of commands required to configure Position control in CANopen motor drive
       * 
       *     @param Profile Velocity, value used by position mode motor trajectory generator.
       *            Units: 0.1 counts/sec
       *            Range:0 - 500,000,000
       *      @param Profile Acceleration, value position mode motor trajectory generator will attempt to achieve.
       *            Units: 10 counts/sec^2
       *            Range:0 - 200,000,000
       *      @param Profile Deceleration, value position mode motor trajectory generator will use at end of trapezoidal profile.
       *             see programmers manual for other profile types use.
       *            Units: 10 counts/sec^2
       *            Range:0 - 200,000,000
       * 
       *     NOTE: More details on params and profiles can be found in the CANopne CiA 402 series specifications:
       *           https://www.can-cia.org/can-knowledge/canopen/cia402/
       */
    std::vector<std::string> generatePosControlConfigSDO(motorProfile positionProfile);
    /**
     * @brief motor drive position control profile paramaters
     * 
     */
    motorProfile copleyMotorProfile{4000000, 240000, 240000};
};

#endif