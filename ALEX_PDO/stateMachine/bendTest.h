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
    void toyUpdate(void);
    void initRobot( Robot *rb );
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
    
   std::vector<double> posTrajectories{
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
    std::vector<double>  negTrajectories {
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
    // Robot interface to be used by states to interact with hardware
    Robot * robot;
};


#endif //EXO_BENDTEST_H
