/**
 *
 * Created for ALEX exoskeleton on 2019-10-02.
 *
 * State Machine: Sit Stand task
 *
 *              isPressed        isCal              isPressed
 *  uncalibrated +--> calibrating  +--> idle(standing)  +--> sitingDown
 *       ^---------------+                 ^                   +
 *             calFail          isStanding |                   | isSitting
 *                                         |                   |
 *                                         standingUp<--+ sitting
 *                                                     isPressed
 * ALL states can also leave to error state as well, which holds the current pos
 * unitl another button is pressed and then goes to uncalibrated (LIMP)
 *
 * TODO: Ask lenny what he wants
 *
 */


#include "SitStand.h"

#define OWNER ((bendTest *)owner)
#define NOFLIP (100)
#define BITHIGH (1)
#define BITLOW (0)

//Node ID for the 4 joints
#define LHIP (1)
#define LKNEE (2)
#define RHIP (3)
#define RKNEE (4)
//Knee motor reading and corresponding angle. Used for mapping between degree and motor values.
#define KNEE_MOTOR_POS1 (250880)
#define KNEE_MOTOR_DEG1 (90)
#define KNEE_MOTOR_POS2 (0)
#define KNEE_MOTOR_DEG2 (0)
//Hip motor reading and corresponding angle. Used for mapping between degree and motor values.
#define HIP_MOTOR_POS1 (250880)
#define HIP_MOTOR_DEG1 (90)
#define HIP_MOTOR_POS2 (0)
#define HIP_MOTOR_DEG2 (180)
// State Machine Constructors ----------------------------------------------------------
bendTest::SitStand(void) {
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine Events
    isPressed = new IsPressed(this);
    isCal = new IsCal(this);
    calFail = new CalFail(this);
    isStanding = new IsStanding(this);
    isSitting = new IsSitting(this);
    // error event
//    isErrorPressed = new IsErrorPressed(this);

    // State Machine States
    uncalibrated = new Uncalibrated(this);
    calibrating = new Calibrating(this);
    idle = new Idle(this);
    siting = new Siting(this);
    standingUp = new StandingUp(this);
    sittingDwn = new SittingDwn(this);

    // Error state
//    errorState = new ErrorState(this);

    // Create Trasitions between states and events which trigger them
    NewTransition(uncalibrated, isPressed, calibrating);
    NewTransition(calibrating, isCal, idle);
    NewTransition(calibrating, calFail, uncalibrated);
    NewTransition(idle, isPressed, sittingDwn);
    NewTransition(sittingDwn, isSitting, sitting);
    NewTransition(sitting, isPressed, standingUp);
    NewTransition(standingUp, isStanding, idle);

    // Safely transition to error state from idle, sitting, sit and standing states.
    // state ->(isErrorPressed) -->error state (LOCK JOINTS WHERE THEY ARE) -> (isErrorPressed) -> uncalibrated
    //    NewTransition(sittingDwn, isError, errorState);
    // Initialize the state machine with first state
    StateMachine::initialize(uncalibrated);
    robot = NULL;
    bitFlipState = NOFLIP;
}
// State Machine: Sit Stand methods ----------------------------------------------------------
void SitStand::init(void)
{
    /* Initialize timer mark of 0
     * TODO: Change to real state Machine timer of RT loop
     * */
    mark = 0;
    std::cout << "Starting sitStand State Machine"
              << "\n";
    StateMachine::init();
}
void SitStand::activate(void)
{
    StateMachine::activate();
}
void SitStand::deactivate(void)
{
    StateMachine::deactivate();
}

// State Methods ----------------------------------------------------------
// Moving states
// Positive bending control machine
void SitStand::StandingUp::entry(void)
{
    //READ TIME OF MAIN
    printf("Bending Positive State  Entered at Time %f\n", OWNER->mark);
    // Set arrayIndex to zero
    OWNER->arrayIndex = 0;


}
void SitStand::StandingUp::during(void) {
    //// DO FOR EACH JOINT
    ///for (auto i = 0; i < 4; i++) {
    // Make sure not to move array index past last member of array
    if (OWNER->arrayIndex != OWNER->posTrajectories.size()) {
        // Get position to send to joint based on current arrayIndex, send off and increment index
        float desiredPos = OWNER->posTrajectories[OWNER->arrayIndex];
        /*SINGLE JOINT FUNCTIONALITY TEST*/
        // check if last last position reached -> go to next position
        if (OWNER->robot->joints[1].getPos() == OWNER->posTrajectories[OWNER->arrayIndex - 1]) {
            OWNER->robot->joints[1].applyPos(desiredPos);
            // set state machine bitFlip to LOW state.
            OWNER->bitFlipState = BITLOW;
            printf("Bending to pos %f\n", desiredPos);
            OWNER->arrayIndex++;
            // Do first bit flip
            // change stateMachine bit flip value to first one
        }
        /*ALL JOINT MOTION*/
        // check if last last position reached -> go to next position
//        for (auto i = 0; i < 4; i++) {
//            //// TODO: CHANGE arrayIndex and Trajectories to be owned by each joint for easier, indexing and addressing
//            if (OWNER->robot->joints[i].getPos() == OWNER->posTrajectories[OWNER->arrayIndex - 1]) {
//                OWNER->robot->joints[i].applyPos(desiredPos);
//                // set state machine bitFlip to LOW state.
//                OWNER->bitFlipState = BITLOW;
//                printf("Bending to pos %f\n", desiredPos);
//                OWNER->arrayIndex++;
//                // Do first bit flip
//                // change stateMachine bit flip value to first one
//            }
//        }
    }
    else{
        // change 1 to i after single joint works
        if(OWNER->robot->joints[1].getPos() == OWNER->posTrajectories[OWNER->arrayIndex-1]) {
            printf("Final position of joint %d reached\n,",OWNER->robot->joints[1].getID())
        }
        else{
            printf("Joint %d Still going to final position\n",OWNER->robot->joints[1].getID() );
        }
    }
    // BITFLIP FUNCTION to trigger low and high bit flip needed for motor motion
    OWNER.bitflip();

}
void SitStand::StandingUp::exit(void)
{

    printf("Bending Positive State Exited at Time %f\n", OWNER->mark);
}

// Robot interface methods ----------------------------------------------------------
void bendTest::initRobot( Robot *rb ) {

    if ( robot != NULL ) {
        printf("Robot object already selected");
    }
    robot = rb;
    // Perform proper initialization
    robot->printInfo();
};

// Update button state, loop counter (mark) and joints from
void bendTest::hwStateUpdate(void)
{
    /*BUTON CODE*/
    // Once working Turn button into its own class and object: call button.getState() return 0 or 1, Statemachines have a button or an event could even
    static char *BUTTON1 = "P9_23";
    int holder;
    GPIO::GPIOManager *gp = GPIO::GPIOManager::getInstance();
    int pin = GPIO::GPIOConst::getInstance()->getGpioByKey(BUTTON1);
    gp->setDirection(pin, GPIO::INPUT);
    holder = gp->getValue(pin);
    this->button = holder;
    gp->~GPIOManager();

    // Update loop time counter
    mark = mark + 1;
    // Update Joint angle from register
//    robot->joints[1].updateJoint();
    // Update all the robots joint values.
    robot.updateJoints();

}

/*
 * bitFlip returns true if the second bit flip has occured, signalling a movement, else returns flase
 *
 *
 *
*/
bool bendTest::bitFlip(void){
    // DO BIT FLIPS FOR EACH joiny
    // for loop for all joints and bitFipState[0] to 3 for each joint
    if(bitFlipState == BITLOW){
        // Do first bit flip
        // print error if bit not flipped
        if(!robot->joints[1].bitflipLow;){
            printf("Error in changing object dictionary entry");
            return false;
        }
        else{
            // success, change bit flip state to high
            bitFlipState = BITHIGH;
            return false;
        }

    }
    else if(bitFlipState == BITHIGH){
        // Do second bit flip
        if(!robot->joints[1].bitflipHigh;){
            printf("Error in changing object dictionary entry");
            return false;
        }
        else{
            // bitflipHigh successful, change bitFlip state to unengaged and retrun true
            bitFlipState = NOFLIP;
            printf("Last sent command to motor %d sent\n",robot->joints[1]->id);
            return true;
        }

    }
    else {
        // Do nothing
    }

}