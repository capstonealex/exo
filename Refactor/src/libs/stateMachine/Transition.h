//
// Created by William Campbell on 2019-09-24.
//

#ifndef TRANSITION_H
#define TRANSITION_H

#include "Event.h"
#include "State.h"
#include "StateMachine.h"

/* Forward declarations*/
class State;
class Event;

/**
 * @brief Represents possible transitions linking two State objects with an Event. 
 * 
 */
class Transition {
    friend class State;
    friend class StateMachine;

   public:
    /* Constructor: set state this arc targets (points towards) and the event which triggers it */
    Transition(State* targ, Event* e) {
        target = targ;
        ev = e;
    };
    State* getTarget(void);

   private:
    Event* ev;
    State* target;
};
#endif  //EXO_TRANSITION_H
