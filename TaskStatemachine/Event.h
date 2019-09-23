//
// Created by William Campbell on 2019-09-24.
//

#ifndef EXO_EVENT_H
#define EXO_EVENT_H


class Event {

public:
    StateMachine * owner;  // Pointer to the owner state machine for this event
    Event ( StateMachine * p, const char n[] = NULL ){
        owner = p;
        name = n;
    };
    /*Virtual check function Must be implemented for each event.*/
    virtual bool check ( void ) = 0;
    const char * getName( void );
private:

    const char *name;      // Pointer to the name of this event
};


#endif //EXO_EVENT_H
