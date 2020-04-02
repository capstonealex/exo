#include "State.h"
#include "Robot.h"
#include <time.h>
// forward declaration
class sitStand;
class SteppingLeftStair : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
	SteppingLeftStair(StateMachine *m, const char *name = NULL) : State(m, name){};
};