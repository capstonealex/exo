//
// Created by William Campbell on 2019-09-24.
//

#ifndef EXO_STATE_H
#define EXO_STATE_H

#include <cstddef>
#include <iostream>

//#include "Robot.h"
class StateMachine;
class Transition;

#include "StateMachine.h"
#include "Transition.h"
#define MAXARCS 20

/* Forward declarations*/
//class Transition;

class State {
    friend class StateMachine;
    // A State machine class can access the private and protected members of a state class  */
   public:
    StateMachine *owner;  // Pointer to the owner state machine for this State

    State(StateMachine *p, const char n[] = NULL) {
        owner = p;
        numarcs = 0;
        name = n;  // name of state
        // std::cout << "State created\n";
    };
    ~State();
    // Arc creating and accessing functions
    bool addArc(Transition *t);
    Transition *getActiveArc(void);
    // Virtual functions, must be implemented by implented states (inherited classes)
    virtual void entry(void) = 0;
    virtual void during(void) = 0;
    virtual void exit(void) = 0;

    const char *getName(void);
    void printName(void);

   private:
    Transition *arclist[MAXARCS];
    const char *name;  // Pointer to the name of this State
    int numarcs;
};

#endif  //EXO_STATE_H
