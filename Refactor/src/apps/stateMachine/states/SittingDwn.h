#include "State.h"
#include "StateMachine.h"
#include "Robot.h"
#include <time.h>
// forward declaration
class sitStand;
class SittingDwn : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
    SittingDwn(StateMachine *m, const char *name = NULL) : State(m, name){};
};