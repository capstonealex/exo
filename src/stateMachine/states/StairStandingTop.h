#include "State.h"
#include "StateMachine.h"
#include <time.h>
#include "Robot.h"
// forward declaration
class sitStand;
class StairStandingTop : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
	StairStandingTop(StateMachine *m, const char *name = NULL) : State(m, name){};
};