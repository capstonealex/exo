/**
 * The <code>Drive</code> class is used to interface with a CANOpen motor drive. According to the CiA402 standard
 * 
 * This class enables low level functions to the system. It does limited error 
 * checking. 
 *
 * Version 0.1
 * Date: 07/04/2020
 */
#ifndef DRIVE_H_INCLUDED
#define DRIVE_H_INCLUDED

#include <string.h>

#include <map>
#include <sstream>
#include <vector>

// Constant for a CAN Message
#define CANMESSAGELENGTH 100

// Constants representing the control mode of the drive
enum ControlMode {
    UNCONFIGURED = 0,
    POSITION_CONTROL = 1,
    VELOCITY_CONTROL = 2,
    TORQUE_CONTROL = 3,
    ERROR = -1
};

/**
 * @brief Commonly-used entries defined in the Object Dictionary for CiA402 Drives
 * 
 */
enum OD_Entry_t {
    STATUS_WORD = 0,
    ACTUAL_POS = 1,
    ACTUAL_VEL = 2,
    ACTUAL_TOR = 3,
    TARGET_POS = 11,
    TARGET_VEL = 12
};

/**
 * @brief Map between the Commonly-used OD entries and their addresses
 *        NOTE: These are written in hexadecimal
 * 
 */
static std::map<OD_Entry_t, int> OD_Addresses = {
    {STATUS_WORD, 0x6041},
    {ACTUAL_POS, 0x6064},
    {ACTUAL_VEL, 0x606C},
    {ACTUAL_TOR, 0x6077},
    {TARGET_POS, 0x607A},
    {TARGET_VEL, 0x60FF},
};

/**
 * @brief Map between the Commonly-used OD entries and their data lengths
 *        NOTE: These are written in hexadecimal
 * 
 */
static std::map<OD_Entry_t, int> OD_Data_Size = {
    {STATUS_WORD, 0x0010},
    {ACTUAL_POS, 0x0020},
    {ACTUAL_VEL, 0x0020},
    {ACTUAL_TOR, 0x0010},
    {TARGET_POS, 0x0020},
    {TARGET_VEL, 0x0020},
};

class Drive {
   protected:
    /**
           * @brief The CAN Node ID used to address this particular drive on the CAN bus
           * 
           */
    int NodeID;

    /**
           * @brief Generates the list of commands required to configure TPDOs on the drives
           * 
           * @param items A list of OD_Entry_t items which are to be configured with this TPDO
           * @param PDO_Num The number/index of this PDO
           * @param SyncRate The rate at which this PDO transmits (e.g. number of Sync Messages. 0xFF represents internal trigger event)
           * @return std::string 
           */
    std::vector<std::string> generateTPDOConfigSDO(std::vector<OD_Entry_t> items, int PDO_Num, int SyncRate);

    /**
           * @brief Generates the list of commands required to configure RPDOs on the drives
           * 
           * @param items A list of OD_Entry_t items which are to be configured with this RPDO
           * @param PDO_Num The number/index of this PDO
           * @param UpdateTiming 0-240 represents hold until next sync message, 0xFF represents immediate update
           * @return std::string 
           */
    std::vector<std::string> generateRPDOConfigSDO(std::vector<OD_Entry_t> items, int PDO_Num, int UpdateTiming);

    /**
       * @brief Sends messages across the CAN bus using CANComm_socketFree
       * 
       * @param messages Properly formatted SDO Messages
       * @return int number of messages successfully processed (return OK)
       */
    int sendSDOMessages(std::vector<std::string> messages);

   private:
    int status;
    int error;

    ControlMode controlMode = UNCONFIGURED;

   public:
    /**
           * @brief Construct a new Drive object
           * 
           */
    Drive();

    /**
           * @brief Construct a new Drive object
           * 
           * @param NodeID the CANopen Node ID of this drive
           */
    Drive(int NodeID);

    /**
           * @brief Destroy the Drive object
           * 
           */
    virtual ~Drive(){};

    /**
           * @brief Initialises the drive (SDO start message)
           * 
           * @return True if successful, False if not
           */
    virtual bool Init() = 0;

    /**
           * @brief Initialises a standard set of PDOs for the use of the drive. These are:
           * 
           *   TPDO1: COB-ID 180+{NODE-ID}: Status Word (0x6041), Send on Internal Event Trigger
           *   TPDO2: COB-ID 280+{NODE-ID}: Actual Position (0x6064), Actual Velocity (0x606C), Sent every SYNC Message
           *   TPDO3: COB-ID 380+{NODE-ID}: Actual Torque (0x607C), Sent every SYNC MEssage
           * 
           *   RPDO1: COB-ID 300+{NODE-ID}: Target Position (0x607A), Applied immediately when received
           *   RPDO2: COB-ID 400+{NODE-ID}: Target Velocity (0x60FF), Applied immediately when received
           * 
           * @return true 
           * @return false 
           */
    virtual bool initPDOs();

    /**
           * Sets the drive to Position control with default parameters (through SDO messages)
           * 
           * Note: Should be overloaded to allow parameters to be set
           * 
           * @return true if successful
           * @return false if not
           */
    virtual bool initPosControl() = 0;

    /**
           * Sets the drive to Velocity control with default parameters (through SDO messages)
           * 
           * Note: Should be overloaded to allow parameters to be set
           * 
           * @return true if successful
           * @return false if not
           */
    virtual bool initVelControl() = 0;

    /**
           * Sets the drive to Torque control with default parameters (through SDO messages)
           * 
           * Note: Should be overloaded to allow parameters to be set
           * 
           * @return true if successful
           * @return false if not
           */
    virtual bool initTorqControl() = 0;

    /**
           * Updates the internal representation of the state of the drive 
           * 
           * @return true if successful
           * @return false if not
           */
    virtual bool updateDriveStatus() = 0;

    /**
           * Writes the desired position to the Target Position of the motor drive (0x607A)
           * 
           * @return true if successful
           * @return false if not
           */
    virtual bool setPos(int position) = 0;

    /**
           * Writes the desired velocity to the Target Velocity of the motor drive (0x60FF)
           * 
           * @return true if successful
           * @return false if not
           */
    virtual bool setVel(int velocity) = 0;

    /**
           * Writes the desired torque to the Target Torque of the motor drive (0x6071)
           * 
           * @return true if successful
           * @return false if not
           */
    virtual bool setTorque(int torque) = 0;

    /**
           * Returns the current position from the motor drive (0x6064)
           * 
           * @return Position from the motor drive
           */
    virtual int getPos() = 0;

    /**
           * Returns the current velocity from the motor drive (0x606C)
           * 
           * @return Velocity from the motor drive
           */
    virtual int getVel() = 0;

    /**
           * Returns the current torque from the motor drive (0x6077)
           * 
           * @return Torque from the motor drive
           */
    virtual int getTorque() = 0;

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
    virtual bool readyToSwitchOn() = 0;

    /**
           * @brief Sets the state of the drive to "enabled"
           * 
           * This is equivalent to setting bits 0, 1, 2, 3 of the control word (0x06064) to 1
           * See also the CANopen Programmer's Manual (from Copley Controls)
           * 
           * @return true if operation successful
           * @return false if operation unsuccessful
           */
    virtual bool enable() = 0;

    /**
           * @brief sets the state of the drive to "disabled"
           * 
           * This is equivalent to setting the control word (0x06064) to 0
           * See also the CANopen Programmer's Manual (from Copley Controls)
           * 
           * @return true if operation successful
           * @return false if operation unsuccessful
           */
    virtual bool disable() = 0;

    // CANOpen
    /**
           * @brief Get returns the CanNode ID
           * 
           * @return int the Node ID 
           */
    int getNodeID();
};

#endif