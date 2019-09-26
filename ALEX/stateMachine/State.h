//
// Created by William Campbell on 2019-09-24.
//

#ifndef EXO_STATE_H
#define EXO_STATE_H

#include "Transition.h"
#include "StateMachine.h"
#include <cstddef>
#include <iostream>
#define MAXARCS 20

/* Forward declarations*/
class Transition;
class StateMachine;
class State
{

    friend class StateMachine;
    // A State machine class can access the private and protected members of a robot class  */
public:
    State(StateMachine *p, const char n[] = NULL)
    {
        owner = p;
        numarcs = 0;
        name = n; // name of state
        std::cout << "State created\n";
    };
    // Arc creating and accessing functions
    bool addArc(Transition *t);
    Transition *getActiveArc(void);
    // Virtual functions, must be implemented by implented states (inherited classes)
    virtual void entry(void) = 0;
    virtual void during(void) = 0;
    virtual void exit(void) = 0;

    const char *getName(void);
    StateMachine *owner; // Pointer to the owner state machine for this State

private:
    int numarcs;
    Transition *arclist[MAXARCS];
    const char *name; // Pointer to the name of this State
};

#endif //EXO_STATE_H
