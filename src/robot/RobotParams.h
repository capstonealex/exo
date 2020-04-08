
#ifndef ROBOT_PARAMS_H
#define ROBOT_PARAMS_H
#include <map>
#include "Robot.h"

// Next MOTION Map values
#define INITIAL 0
#define NORMALWALK 1
#define UPSTAIR 2
#define DWNSTAIR 3
#define TILTUP 4
#define TILTDWN 5
#define FTTG 6
#define BKSTEP 7
#define SITDWN 8
#define STNDUP 9
#define UNEVEN 10
/**
   * Map between OD.nextmotion dictionary values to trajectory paramater 
   * structs defined for use in designed trajectory generation.
   *
   * @param[in] int OD.nextmotion entry
   * @return trajectory paramater object
   */

#endif /*ROBOT_PARAMS_H*/