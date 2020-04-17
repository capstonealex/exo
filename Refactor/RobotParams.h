
#ifndef ROBOT_PARAMS_H
#define ROBOT_PARAMS_H

#define _NOANKLES  //w / o ankles
#ifndef _NOANKLES
#define NUM_JOINTS 6
#else
#define NUM_JOINTS 4
#endif
// Macros
#define deg2rad(deg) ((deg)*M_PI / 180.0)
#define rad2deg(rad) ((rad)*180.0 / M_PI)
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

//step parameters
#define STANDTIME 3
#define SITTIME 3
#define STEPTIME 2.0
#define STAIRTIME 3
#define UNEVENSTEPTIME 4
#define UNEVENTORSO deg2rad(10)
#define STEPLENGTH 0.33
#define HALFSTEPLENGTH STEPLENGTH / 2
#define LONGSTEPLENGTH STEPLENGTH * 1.5
#define BACKLENGTH 0.3
#define STEPHEIGHT 0.4
#define STEPHIGH 0.7
#define STEPTGTLENGTH 0.0
#define LEGSLACK 0.0001
#define TORSOANGLE deg2rad(5)

#endif /*ROBOT_PARAMS_H*/