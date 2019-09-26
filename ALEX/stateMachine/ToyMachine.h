//
// Created by William Campbell on 2019-09-24.
//
#ifndef _TOYMACHINE_H
#define _TOYMACHINE_H

#include "StateMachine.h"
class EventOne: public Event{
    // ToyMachine has full acess to to events members.
    friend class ToyMachine;

public:

    EventOne( StateMachine * m, const char *name = NULL  ) : owner(m), name(name) {};
    bool check ( void );
    int count;
}EventOne;

// State one
class StateOne : public State {
    friend class ToyMachine ;
public:

    StateOne ( StateMachine *m const char *name = NULL ) : State ( m, name ) {};
    void entry ( void );
    void during ( void );
    void exit ( void );

}StateOne;
// State two
class StateTwo : public State {
    friend class ToyMachine ;
public:
    StateTwo ( StateMachine *m const char *name = NULL ) : State ( m, name ) {};
    void entry ( void );
    void during ( void );
    void exit ( void );
}StateTwo;

class ToyMachine : public StateMachine {

public:
    ToyMachine(void);
    /*class destructor*/
    ~ToyMachine(void);
    void init(void);
    void activate(void);
    void deactivate(void);

private:
    eventOne eventOne;
    stateOne SateOne;
    stateTwo StateTwo;
};


#endif