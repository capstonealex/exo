/* Header file for calculating trajectory,
*/

#ifndef TRAJECTORY_H_INCLUDED
#define TRAJECTORY_H_INCLUDED

using namespace std;
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
class TrajectoryGenerator {
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
    // Next MOTION Map values
    // enum movemtnMap {
    //     INITIAL = 0,
    //     NORMALWALK = 1,
    //     UPSTAIR = 2,
    //     DWNSTAIR = 3,
    //     TILTUP = 4,
    //     TILTDWN = 5,
    //     FTTG = 6,
    //     BKSTEP = 7,
    //     SITDWN = 8,
    //     STNDUP = 9,
    //     UNEVEN = 10
    // };

   public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * Structs                                                                                                           *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    typedef double time_tt;  // time_t is already used
    typedef enum class Foot {
        Left,
        Right
    } Foot;
    typedef enum class Movement {
        Walk,
        Sit,
        Stand,
        Stair,
        Ramp,
        Back,
        Sitting,
        Uneven,
        DownStair
    } Movement;

    typedef struct trajectory_parameters {
        time_tt step_duration;
        double step_height, step_length, hip_height_slack;
        double torso_forward_angle, swing_ankle_down_angle;
        Foot stance_foot;
        Movement movement;                           //type of movement
        double seat_height;                          // sit-stand
        double step_end_height;                      // stairs and uneven ground
        double slope_angle;                          // tilted path
        bool left_foot_on_tilt, right_foot_on_tilt;  // whether the foot is on tilted ground
    } trajectory_parameters;

    typedef struct pilot_parameters {
        double lowerleg_length, upperleg_length, ankle_height, foot_length, hip_width, torso_length;
        double buttocks_height;  // sit-stand
    } pilot_parameters;
    trajectory_parameters trajectoryParameter;
    pilot_parameters pilotParameter;
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * Function Declarations                                                                                             *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    TrajectoryGenerator();

    /**********************************************************************

	Getter and setter

	**********************************************************************/
    //setter for the parameters
    void setTrajectoryParameter(time_tt step_duration, double step_height, double step_length, double hip_height_slack, double torso_forward_angle, double swing_ankle_down_angle,
                                Foot stance_foot, Movement movement, double seat_height, double step_end_height, double slope_angle, bool left_foot_on_tilt, bool right_foot_on_tilt);
    void setTrajectoryParameter(trajectory_parameters trajectoryParameter);
    void setPilotParameter(double lowerleg_length, double upperleg_length, double ankle_height, double foot_length,
                           double hip_width, double torso_length, double buttocks_height);
    void setPilotParameter(pilot_parameters pilotParameter);
};
#endif
