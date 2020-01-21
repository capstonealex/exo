#include "State.h"
#include "StateMachine.h"
#include "Robot.h"
#include <time.h>
// forward declaration
class sitStand;
class SteppingLastLeft : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
    SteppingLastLeft(StateMachine *m, const char *name = NULL) : State(m, name){};
};