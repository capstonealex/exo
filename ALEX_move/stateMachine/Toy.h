
//
// Created by William Campbell on 2019-09-26.
//

#ifndef EXO_TOY_H
#define EXO_TOY_H

#include "StateMachine.h"
#include "Robot.h"

//class StateOne;

class Toy : public StateMachine
{

public:
    Toy(void);
    void init(void);
    void activate(void);
    void deactivate(void);
    void toyUpdate(void);
    void initRobot( Robot *rb );

private:
    // events
    EventObject(EventOne) * eventOne;
    //
    //    // states
    StateObject(StateOne) * stateOne;
    StateObject(StateTwo) * stateTwo;

    // data
    double mark;
    Robot * robot;
};

#endif //EXO_TOY_H
