/**
 * The <code>Drive</code> class is used to interface with a CANOpen motor drive. 
 * 
 * This class enables low level functions to the system. It does limited error 
 * checking. 
 *
 * Version 0.1
 * Date: 07/04/2020
 */
#ifndef DRIVE_H_INCLUDED
#define DRIVE_H_INCLUDED

// Constants representing the control mode of the drive
enum ControlMode{
    UNCONFIGURED = 0,
    POSITION_CONTROL = 1,
    VELOCITY_CONTROL = 2,
    TORQUE_CONTROL = 3,
    ERROR = -1
};

class Drive{
    protected:
        int NodeID;

    private: 
        int status;
        int error;

        ControlMode controlMode = UNCONFIGURED;

        //Object dictionary/ state map
  
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
         * Initialises the drive (SDO start message)
         * 
         * @return True if successful, False if not
         */ 
        virtual bool Init()= 0;

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
        virtual bool initVelControl()= 0;

        /**
         * Sets the drive to Torque control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return true if successful
         * @return false if not
         */ 
        virtual bool initTorqControl()= 0;

        /**
         * Updates the internal representation of the state of the drive 
         * 
         * @return true if successful
         * @return false if not
         */ 
        virtual bool updateDriveStatus()= 0;

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
        virtual bool setVel(int velocity)= 0;

        /**
         * Writes the desired torque to the Target Torque of the motor drive (0x6071)
         * 
         * @return true if successful
         * @return false if not
         */ 
        virtual bool setTorque(int torque)= 0;

        /**
         * Returns the current position from the motor drive (0x6064)
         * 
         * @return Position from the motor drive
         */ 
        virtual int getPos()= 0;

        /**
         * Returns the current velocity from the motor drive (0x606C)
         * 
         * @return Velocity from the motor drive
         */ 
        virtual int getVel()= 0;

         /**
         * Returns the current torque from the motor drive (0x6077)
         * 
         * @return Torque from the motor drive
         */ 
        virtual int getTorque()= 0;

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
        virtual bool readyToSwitchOn()= 0;

        /**
         * @brief Sets the state of the drive to "enabled"
         * 
         * This is equivalent to setting bits 0, 1, 2, 3 of the control word (0x06064) to 1
         * See also the CANopen Programmer's Manual (from Copley Controls)
         * 
         * @return true if operation successful
         * @return false if operation unsuccessful
         */
        virtual bool enable()= 0;

        /**
         * @brief sets the state of the drive to "disabled"
         * 
         * This is equivalent to setting the control word (0x06064) to 0
         * See also the CANopen Programmer's Manual (from Copley Controls)
         * 
         * @return true if operation successful
         * @return false if operation unsuccessful
         */
        virtual bool disable()= 0;

        // CANOpen
        /**
         * @brief Get returns the CanNode ID
         * 
         * @return int the Node ID 
         */
        int getNodeID();
};

#endif