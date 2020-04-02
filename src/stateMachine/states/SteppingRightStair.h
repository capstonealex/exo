#include "State.h"
#include "Robot.h"
#include <time.h>
// forward declaration
class sitStand;
class SteppingRightStair : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
    SteppingRightStair(StateMachine *m, const char *name = NULL) : State(m, name){};
};