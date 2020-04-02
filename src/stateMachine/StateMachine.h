/**
 * @file StateMachine.h
 * @author William Campbell
 * @brief State Machine base class for a designer to implement an event driven finite state machine.
 * @version 1.0
 * @date 2019-07-12
 * 
 * 
 */

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
    StateMachine(void);
    StateMachine(State *i);
    void initialize(State *i);
    State *getCurState(void);
    void init(void);
    void uninit(void);
    void activate(void);
    void deactivate(void);
    void update(void);

    // Robot interface : used by states to interact with hardware
    Robot *robot;
    int mark;

private:
    State *currentState;
};

/*Macros to quickly define events and transitions between states*/

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
