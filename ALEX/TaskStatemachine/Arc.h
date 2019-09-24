//
// Created by William Campbell on 2019-09-24.
//

#ifndef EXO_ARCH_H
#define EXO_ARCH_H

#include "StateMachine.h"
#include "Event.h"

class Arc {
    friend class State;
    friend class StateMachine;
public:
    /* Constructor: set state this arc targets (points towards) and the event which triggers it */
    Arc ( State * targ, Event * e ) {
        target = targ;
        ev = e;
    };
    State * getTarget ( void );
private:
    Event * ev;
    State * target;

};
#endif //EXO_ARCH_H
