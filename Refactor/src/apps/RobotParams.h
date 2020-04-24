
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
enum robotJoints {
    LEFT_HIP = 0,
    LEFT_KNEE = 1,
    RIGHT_HIP = 2,
    RIGHT_KNEE = 3,
    LEFT_ANKLE = 4,
    RIGHT_ANKLE = 5
};
enum movemtnMap {
    INITIAL = 0,
    NORMALWALK = 1,
    UPSTAIR = 2,
    DWNSTAIR = 3,
    TILTUP = 4,
    TILTDWN = 5,
    FTTG = 6,
    BKSTEP = 7,
    SITDWN = 8,
    STNDUP = 9,
    UNEVEN = 10
};

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

#endif /*ROBOT_PARAMS_H*/