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
#include "ExoTestMachine.h"

/**********ALSO HAVE TO SET NUMJOINTS to 6 *************/
//#define _TESTMODE
/////////////////////////////////////////////////////////

#define OWNER ((ExoTestMachine *)owner)

/////////////////////////////////////////////////////////
// State Machine TestMachine methods ----------------------------------------------------------
/////////////////////////////////////////////////////////

ExoTestMachine::ExoTestMachine() {
    // All the Robot Initialisation Stuff Happens here
    trajectoryGenerator = new DummyTrajectoryGenerator(4);  // Pilot Parameters would be set in constructor here
    robot = new ExoRobot(trajectoryGenerator);

    // Create PRE-DESIGNED State Machine events, states and transitions
    // StateMachine events
    isAPressed = new IsAPressed(this);
    endTraj = new EndTraj(this);
    startButtonsPressed = new StartButtonsPressed(this);
    startExo = new StartExo(this);
    startSit = new StartSit(this);
    startStand = new StartStand(this);

    // State Machine States
    initState = new InitState(this, robot, trajectoryGenerator);
    standing = new Standing(this, robot, trajectoryGenerator);
    sitting = new Sitting(this, robot, trajectoryGenerator);
    standingUp = new StandingUp(this, robot, trajectoryGenerator);
    sittingDwn = new SittingDwn(this, robot, trajectoryGenerator);

    // Trajectory Transitions
    NewTransition(initState, startExo, sitting);
    NewTransition(sitting, startStand, standingUp);
    NewTransition(standingUp, endTraj, standing);
    NewTransition(standing, startSit, sittingDwn);
    NewTransition(sittingDwn, endTraj, sitting);

    // Initialize the state machine with first state
    StateMachine::initialize(initState);

    //robot.start();
}

void ExoTestMachine::init() {
    StateMachine::init();
    running = 1;
}

////////////////////////////////////////////////////////////////
// Events ------------------------------------------------------------
///////////////////////////////////////////////////////////////
bool ExoTestMachine::EndTraj::check() {
    if (OWNER->trajComplete) {
        return true;
    } else
        return false;
}
///KEYBOARD AS BUTTON///
//////////// BUTTON PRESS CHECKS //////////////
bool ExoTestMachine::IsAPressed::check(void) {
    if (OWNER->robot->keyboard.getA() == true) {
        return true;
    }
    return false;
}
bool ExoTestMachine::StartButtonsPressed::check(void) {
    if (OWNER->robot->keyboard.getW() == true) {
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////////////////////
//Crutch new Motion Paramater Events ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////
/// TODO: CHANGE TO KEYBOARD INPUT
bool ExoTestMachine::StartExo::check(void) {
    if (OWNER->robot->keyboard.getS() == true) {
        std::cout << "LEAVING INIT and entering Sitting" << endl;
        return true;
    }
    return false;
}
bool ExoTestMachine::StartStand::check(void) {
    if (OWNER->robot->keyboard.getW() == true) {
        return true;
    }
    return false;
}

bool ExoTestMachine::StartSit::check(void) {
    if (OWNER->robot->keyboard.getW()) {
        return true;
    }
    return false;
}

//////////////////////////////////////////////////////////////////////
// Robot interface methods ----------------------------------------------------------
/////////////////////////////////////////////////////////////////////

// Update button state, loop counter (mark) and joints
void ExoTestMachine::hwStateUpdate(void) {
    robot->updateRobot();
}
