//hi
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
 * ALL states can also leave to xferror state as well, which holds the current pos
 * unitl another button is pressed and then goes to uncalibrated (LIMP)
 *
 */
#include "TestMachine.h"

/**********ALSO HAVE TO SET NUMJOINTS to 6 *************/
//#define _TESTMODE
/////////////////////////////////////////////////////////

#define OWNER ((TestMachine *)owner)

/////////////////////////////////////////////////////////
// State Machine TestMachine methods ----------------------------------------------------------
/////////////////////////////////////////////////////////

TestMachine::TestMachine(void) {
    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    isAPressed = new IsAPressed(this);
    endTraj = new EndTraj(this);
    startButtonsPressed = new StartButtonsPressed(this);
    startExo = new StartExo(this);
    startSit = new StartSit(this);
    startStand = new StartStand(this);
    initState = new InitState(this);
    standing = new Standing(this);
    sitting = new Sitting(this);
    standingUp = new StandingUp(this);
    sittingDwn = new SittingDwn(this);

    // Trajectory Transitions
    NewTransition(initState, startExo, sitting);
    NewTransition(sitting, startStand, standingUp);
    NewTransition(standingUp, endTraj, standing);
    NewTransition(standing, startSit, sittingDwn);
    NewTransition(sittingDwn, endTraj, sitting);
    // Initialize the state machine with first state
    StateMachine::initialize(initState);
    robot = NULL;
}

void TestMachine::init(void) {
    StateMachine::init();
    running = 1;
}
void TestMachine::activate(void) {
    StateMachine::activate();
}
void TestMachine::deactivate(void) {
    StateMachine::deactivate();
}
void TestMachine::update(void) {
    StateMachine::update();
}

////////////////////////////////////////////////////////////////
// Events ------------------------------------------------------------
///////////////////////////////////////////////////////////////
bool TestMachine::EndTraj::check(void) {
    if (OWNER->trajComplete) {
        return true;
    } else
        return false;
}
///KEYBOARD AS BUTTON///
//////////// BUTTON PRESS CHECKS //////////////
bool TestMachine::IsAPressed::check(void) {
    if (OWNER->robot->keyboard.getA() == true) {
        return true;
    }
    return false;
}
bool TestMachine::StartButtonsPressed::check(void) {
    if (OWNER->robot->keyboard.getW() == true) {
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////////////////////
//Crutch new Motion Paramater Events ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
/// TODO: CHANGE TO KEYBOARD INPUT
bool TestMachine::StartExo::check(void) {
    if (OWNER->robot->keyboard.getS() == true) {
        std::cout << "LEAVING INIT and entering Sitting" << endl;
        return true;
    }
    return false;
}
bool TestMachine::StartStand::check(void) {
    if (OWNER->robot->keyboard.getW() == true) {
        return true;
    }
    return false;
}

bool TestMachine::StartSit::check(void) {
    if (OWNER->robot->keyboard.getW()) {
        return true;
    }
    return false;
}

//////////////////////////////////////////////////////////////////////
// Robot interface methods ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
void TestMachine::initRobot(ExoRobot *rb) {
    if (robot != NULL) {
        printf("Robot object already selected");
    }
    robot = rb;
    robot->start();
    // TODOany init of input runs here
    // robot->buttons.initButtons();
};

// Update button state, loop counter (mark) and joints
void TestMachine::hwStateUpdate(void) {
    robot->updateRobot();
}
