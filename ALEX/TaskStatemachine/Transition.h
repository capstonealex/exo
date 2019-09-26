//
// Created by William Campbell on 2019-09-24.
//

#ifndef EXO_TRANSITION_H
#define EXO_TRANSITION_H

#include "StateMachine.h"
#include "Event.h"
#include "State.h"

/* Forward declarations*/
class State;
class Event;

class Transition {
    friend class State;
    friend class StateMachine;
public:
    /* Constructor: set state this arc targets (points towards) and the event which triggers it */
    Transition ( State * targ, Event * e ) {
        target = targ;
        ev = e;
    };
    State * getTarget ( void );
private:
    Event * ev;
    State * target;

};
#endif //EXO_TRANSITION_H
