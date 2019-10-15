//
// Created by William Campbell on 2019-09-30.
//

#ifndef EXO_BENDTEST_H
#define EXO_BENDTEST_H

#include "StateMachine.h"
#include "Robot.h"
#include "GPIOManager.h"
#include "GPIOConst.h"
#include <vector> 

class bendTest: public StateMachine{
public:
    bendTest(void);
    void init(void);
    void activate(void);
    void deactivate(void);
    void hwStateUpdate(void);
    void initRobot( Robot *rb );
    void bitFlip();
private:
    // Events
    EventObject(IsBentP) * isBentP;
    EventObject(IsBentN) * isBentN;
    EventObject(IsPressed) * isPressed;

    // States
    StateObject(BendingP) * bendingP;
    StateObject(BendingN) * bendingN;
    StateObject(Bent) * bent;
    StateObject(Idle) * idle;

    // Data
    double mark;
    int button;
    int arrayIndex;
    int bitFlipState;
    
   std::vector<double> posTrajectoriesDeg{
            0,
            10,
            20,
            30,
            40,
            50,
            60,
            70,
            80,
            90
    };
    std::vector<double>  negTrajectoriesDeg{
            90,
            80,
            70,
            60,
            50,
            40,
            30,
            20,
            10,
            0
    };
    std::vector<long> posTrajectories;
    std::vector<long> negTrajectories;
    // Robot interface to be used by states to interact with hardware
    Robot * robot;
};


#endif //EXO_BENDTEST_H
