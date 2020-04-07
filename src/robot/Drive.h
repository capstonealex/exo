/**
 * The <code>Drive</code> class is used to interface with a CANOpen motor drive. 
 * 
 * This class enables low level functions to the system. It does limited error 
 * checking. 
 *
 * Version 0.1
 * Date: 07/04/2020
 */




// Constants representing the control mode of the drive
const enum ControlMode{
    UNCONFIGURED = 0,
    POSITION_CONTROL = 1,
    VELOCITY_CONTROL = 2,
    TORQUE_CONTROL = 3,
    ERROR = -1
};

class Drive{
    private: 

        int status;
        int Error;
        int NodeID;

        ControlMode controlMode = UNCONFIGURED;

        //Object dictionary/ state map
  
    public:
        // Initialisation

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
         * @return True if successful, False if not
         */ 
        bool initPosControl();

        /**
         * Sets the drive to Velocity control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return True if successful, False if not
         */
        bool initVelControl();

        /**
         * Sets the drive to Torque control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return True if successful, False if not
         */ 
        bool initTorqControl();

        /**
         * Updates the internal representation of the state of the drive 
         * 
         * @return True if successful, False if not
         */ 
        bool updateDriveStatus();

        // Execution
        bool setPos(int position);
        bool setVel(int velocity);
        bool setTorque(int torque);

        int getPos();
        int getVel();
        int getTorque();

        // Drive State Modifiers
        bool readyToSwitchOn();
        bool enable();
        bool disable();

        // CANOpen
        int getNodeID();
}