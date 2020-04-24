// Init State Class publically inheriting State

#include "State.h"
#include "Robot.h"
#include <time.h>

class InitState : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
    InitState(StateMachine *m, const char *name = NULL) : State(m, name){};
};