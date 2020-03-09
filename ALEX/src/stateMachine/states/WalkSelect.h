#include "State.h"
#include "StateMachine.h"
#include <time.h>
#include "Robot.h"
// forward declaration
class sitStand;
class WalkSelect : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
	WalkSelect(StateMachine *m, const char *name = NULL) : State(m, name){};
};