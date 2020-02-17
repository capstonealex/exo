// Init State Class publically inheriting State

#include "State.h"
#include "Robot.h"
#include <time.h>
// forward declaration
class sitStand;
// #define OWNER ((sitStand *)owner)

class InitState : public State
{
    friend class sitStand;
    // Robot *robot;

public:
    void entry(void);
    void during(void);
    void exit(void);
    InitState(StateMachine *m, const char *name = NULL) : State(m, name){};
    void initRobot(Robot *rb);
    // void setOwner(sitStand *machine);
};