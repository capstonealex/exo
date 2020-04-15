
#ifndef ROBOT_PARAMS_H
#define ROBOT_PARAMS_H
// Libraries
#include <map>
#include <time.h>
#include <sys/time.h>
#include "Robot.h"
#include "TestActJoint.h"
#include "CopleyDrive.h"
// NUM JOINTS
#define _NOANKLES w / o ankles
#ifndef _NOANKLES
#define NUM_JOINTS 6
#else
#define NUM_JOINTS 4
#endif

//Node ID for the 6 joints
#define LEFT_HIP 0
#define LEFT_KNEE 1
#define RIGHT_HIP 2
#define RIGHT_KNEE 3
#define LEFT_ANKLE 4
#define RIGHT_ANKLE 5
//Params for specific robt
//Knee motor reading and corresponding angle. Used for mapping between degree and motor values.
#define KNEE_MOTOR_POS1 (250880)
#define KNEE_MOTOR_DEG1 (90)
#define KNEE_MOTOR_POS2 (0)
#define KNEE_MOTOR_DEG2 (0)
//Hip motor reading and corresponding angle. Used for mapping between degree and motor values.
#define HIP_MOTOR_POS1 (250880)
#define HIP_MOTOR_DEG1 (90)
#define HIP_MOTOR_POS2 (0)
#define HIP_MOTOR_DEG2 (180)
//Ankle motor reading and corresponding angle. Used for mapping between degree and motor values.
#define ANKLE_MOTOR_POS1 (0)
#define ANKLE_MOTOR_DEG1 (90)
#define ANKLE_MOTOR_POS2 (-800000)
#define ANKLE_MOTOR_DEG2 (115)

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

/**
 * @brief Joint Limit Map between Joint value and min Degrees possible
 * @param int Joint value
 * @return double minDeg 
//  */
// //TODO CHANGE FROM MOTOR COMMANDS TO DEGREES
// std::map<int, double> jointMinMap = {{LEFT_HIP, 0.0},
//                                      {RIGHT_HIP, 0.0},
//                                      {LEFT_KNEE, 0.0},
//                                      {RIGHT_KNEE, 0.0},
//                                      {LEFT_ANKLE, -800000},
//                                      {RIGHT_ANKLE, -800000}};
// /**
//  * @brief Joint Limit Map between Joint value and max Degrees possible
//  * @param int Joint value
//  * @return int maxDeg
//  */
// std::map<int, double> jointMaxMap = {{LEFT_HIP, (HIP_MOTOR_POS1 * 1.5)},
//                                      {RIGHT_HIP, (HIP_MOTOR_POS1 * 1.5)},
//                                      {LEFT_KNEE, (KNEE_MOTOR_POS1 * 1.5)},
//                                      {RIGHT_KNEE, (KNEE_MOTOR_POS1 * 1.5)},
//                                      {LEFT_ANKLE, -800000},
//                                      {RIGHT_ANKLE, -800000}};
#endif /*ROBOT_PARAMS_H*/