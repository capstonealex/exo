#include "State.h"
#include "StateMachine.h"
#include <time.h>
#include "Robot.h"
// forward declaration
class sitStand;
class StairLeftLegUp2 : public State
{
    friend class sitStand;

public:
    void entry(void);
    void during(void);
    void exit(void);
	StairLeftLegUp2(StateMachine *m, const char *name = NULL) : State(m, name){};
};