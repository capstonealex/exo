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
        virtual bool Init();

        /**
         * Sets the drive to Position control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return True if successful, False if not
         */ 
        virtual bool initPosControl();

        /**
         * Sets the drive to Velocity control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return True if successful, False if not
         */
        virtual bool initVelControl();

        /**
         * Sets the drive to Torque control with default parameters (through SDO messages)
         * 
         * Note: Should be overloaded to allow parameters to be set
         * 
         * @return True if successful, False if not
         */ 
        virtual bool initTorqControl();

        /**
         * Updates the internal representation of the state of the drive 
         * 
         * @return True if successful, False if not
         */ 
        virtual bool updateDriveStatus();

        /**
         * Writes the desired position to the Target Position of the motor drive (0x607A)
         * 
         * @return True if successful, False if not
         */ 
        virtual bool setPos(int position);

        /**
         * Writes the desired velocity to the Target Velocity of the motor drive (0x60FF)
         * 
         * @return True if successful, False if not
         */ 
        virtual bool setVel(int velocity);

        /**
         * Writes the desired torque to the Target Torque of the motor drive (0x6071)
         * 
         * @return True if successful, False if not
         */ 
        virtual bool setTorque(int torque);

        /**
         * Returns the current position from the motor drive (0x6064)
         * 
         * @return Position from the motor drive
         */ 
        virtual int getPos();

        /**
         * Returns the current velocity from the motor drive (0x606C)
         * 
         * @return Velocity from the motor drive
         */ 
        virtual int getVel();

         /**
         * Returns the current torque from the motor drive (0x6077)
         * 
         * @return Torque from the motor drive
         */ 
        virtual int getTorque();

        // Drive State Modifiers
        virtual bool readyToSwitchOn();
        virtual bool enable();
        virtual bool disable();

        // CANOpen
        int getNodeID();
}