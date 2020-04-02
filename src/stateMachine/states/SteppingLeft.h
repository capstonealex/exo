#include "State.h"
#include "Robot.h"
#include <time.h>
// forward declaration
class sitStand;
class SteppingLeft : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
    SteppingLeft(StateMachine *m, const char *name = NULL) : State(m, name){};
};