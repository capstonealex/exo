//
// Created by William Campbell on 2019-09-30.
//

#ifndef EXO_BENDTEST_H
#define EXO_BENDTEST_H

#include "StateMachine.h"
#include "Robot.h"
#include "GPIOManager.h"
#include "GPIOConst.h"

class bendTest : public StateMachine
{
public:
    bendTest(void);
    void init(void);
    void activate(void);
    void deactivate(void);
    void hwStateUpdate(void);
    void initRobot(Robot *rb);
    bool bitFlip();

private:
    // events
    EventObject(IsBentP) * isBentP;
    EventObject(IsBentN) * isBentN;
    EventObject(IsPressed) * isPressed;

    //
    //    // states
    StateObject(BendingP) * bendingP;
    StateObject(BendingN) * bendingN;
    StateObject(Bent) * bent;
    StateObject(Idle) * idle;

    // data
    double mark;
    int button;
    int arrayIndex;
    int bitFlipState;
    // enum
    // {
    //     NUM_TRAJ_POINTS = 10
    // };

    // double posTrajectoriesDeg[] = {
    //     0,
    //     10,
    //     20,
    //     30,
    //     40,
    //     50,
    //     60,
    //     70,
    //     80,
    //     90};

    // double negTrajectoriesDeg[] = {
    //     90,
    //     80,
    //     70,
    //     60,
    //     50,
    //     40,
    //     30,
    //     20,
    //     10,
    //     0};
    // // Make two arrays for coresponding motor commands for trajectorues
    // static int arrSize = sizeof(posTrajectoriesDeg) / sizeof(posTrajectoriesDeg[0]);
    // long posTrajectories[arrSize];
    // long negTrajectories[arrSize];
    // Robot interface to be used by states to interact with hardware
    Robot *robot;
};

#endif //EXO_BENDTEST_H
