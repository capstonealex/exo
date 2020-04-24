//
// Created by William Campbell on 2019-09-24.
//

#ifndef EXO_STATEMACHINE_H
#define EXO_STATEMACHINE_H
#include "State.h"
#include "Robot.h"
#include <cstddef>
/* Forward declarations*/
class State;

class StateMachine
{
public:
    /* State machine constructors*/
    // No input arguments.
    StateMachine(void);
    // Set initial state to input of constructor
    StateMachine(State *i);
    // Set the pointer of the initial state
    void initialize(State *i);
    State *getCurState(void);
    // methods
    void init(void);
    void uninit(void);
    void activate(void);
    void deactivate(void);
    void update(void);

    // Robot interface to be used by states to interact with hardware
    Robot *robot;
    int mark;

private:
    // pointers to the initial state and the current state
    State *currentState;
};

/*Macros to quickly define states. statemachines, events and transitions*/

// useage: EventObject ( MyEvent ) * myEvent;
#define EventObject(_name_)             \
    class _name_;                       \
    friend class _name_;                \
    class _name_ : public Event         \
    {                                   \
                                        \
    public:                             \
        _name_(StateMachine *m,         \
               const char *name = NULL) \
            : Event(m, name){};         \
        bool check(void);               \
    };                                  \
    _name_
#define NewTransition(_from_, _event_, _to_) \
    _from_->addArc(new Transition(_to_, _event_))

#endif //EXO_STATEMACHINE_H
