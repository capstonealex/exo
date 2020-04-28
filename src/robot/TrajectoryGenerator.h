/* Header file for calculating trajectory,
*/

#ifndef TRAJECTORY_H_INCLUDED
#define TRAJECTORY_H_INCLUDED
#define _USE_MATH_DEFINES

using namespace std;
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
class TrajectoryGenerator {
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* Macros                                                                                                            *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#define NUM_CUBIC_COEFFICIENTS (4)
#define NO_JOINTS (6)
#define deg2rad(deg) ((deg)*M_PI / 180.0)
#define rad2deg(rad) ((rad)*180.0 / M_PI)
#define Q_STANDING            \
    {                         \
        M_PI_2, 0, 0, 0, 0, 0 \
    }
#define Q_SITTING_SIMPLE                            \
    {                                               \
        M_PI_2, M_PI_2, -M_PI_2, M_PI_2, -M_PI_2, 0 \
    }
//Node ID for the 4 joints
#define LEFT_HIP 0
#define LEFT_KNEE 1
#define RIGHT_HIP 2
#define RIGHT_KNEE 3
#define LEFT_ANKLE 4
#define RIGHT_ANKLE 5

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

   public:
    // Hardware angle limiation in Radians
    const double Q_MIN_MAX[12]{deg2rad(70), deg2rad(210),
                               0, deg2rad(120),
                               deg2rad(70), deg2rad(210),
                               0, deg2rad(120),
                               deg2rad(75), deg2rad(105),
                               deg2rad(75), deg2rad(105)};

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * Structs                                                                                                           *
	 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    //typedef long time_tt;
    typedef double time_tt;  // time_t is already used

    typedef enum class Foot {
        Left,
        Right
    } Foot;

    typedef struct point {
        double x, y, z;
    } point;

    // struct for taskspace and jointspace
    typedef struct taskspace_state {
        point left_ankle_position, hip_position, right_ankle_position;
        double torso_forward_angle;     // torso angle forward from vertical
        double swing_ankle_down_angle;  // swing_ankle angle down from the horizontal; 0 => horizontal swing_foot
        Foot stance_foot;               // Foot::Left or Foot::Right
        time_tt time;
    } taskspace_state;

    typedef struct jointspace_state {
        double q[NO_JOINTS];
        time_tt time;
    } jointspace_state;

    typedef struct jointspace_state_ex {  // extended to include velocity and acceleration
        double q[NO_JOINTS], qd[NO_JOINTS], qdd[NO_JOINTS];
        time_tt time;
    } jointspace_state_ex;

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

    typedef struct TrajectoryParameters {
        time_tt step_duration;
        double step_height, step_length, hip_height_slack;
        double torso_forward_antrajectory_parametersn_angle;
        Foot stance_foot;
        Movement movement;                           //type of movement
        double seat_height;                          // sit-stand
        double step_end_height;                      // stairs and uneven ground
        double slope_angle;                          // tilted path
        bool left_foot_on_tilt, right_foot_on_tilt;  // whether the foot is on tilted ground
    } TrajectoryParameters;

    typedef struct pilot_parameters {
        double lowerleg_length, upperleg_length, ankle_height, foot_length, hip_width, torso_length;
        double buttocks_height;  // sit-stand
    } pilot_parameters;

    typedef struct cubic_polynomial {
        double coefficients[NUM_CUBIC_COEFFICIENTS];  // starting from const term.
    } cubic_polynomial;

    typedef struct jointspace_spline {
        vector<cubic_polynomial> polynomials[NO_JOINTS];  // polynomial[0] is a vector of cubic polynomialstrajectory_parameterstor<time_tt> times;                            // Start/end times of the polynomials (#times = #polynomials+1)
    } jointspace_spline;

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	* Class Variables																									 *
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
   public:
    jointspace_spline trajectoryJointSpline;

   public:
    TrajectoryParameters trajectoryParameter;
    pilot_parameters pilotParameter;
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	 * Function Declarations                                                                                             *
	 * * * * * * * * * *trajectory_parameters * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
   public:
    //Initializer
    TrajectoryGenerator();

    /**************************************trajectory_parameters************

	Functions for taskspace and joint space conversion

	**********************************************************************/

    // Generates key taskspace states from gait parameters
    vector<taskspace_state> generate_key_taskspace_states(tatrajectory_parameterslTaskspaceState,
                                                          const TrajectoryParameters &trajectoryParameters, const pilot_parameters &pilotParameters);

    // Generates discrete trajectory from parametetrajectory_parameters system
    void compute_discrete_trajectory(const TrajectoryParameters &trajectoryParameters,
                                     const pilot_parameters &pilotParameters, jointspace_state initialJointspaceState);

    // Converts jointspace to taskspace (Forward Kinematics)
    taskspace_state jointspace_state_to_taskspace_state(jointspace_state jointspaceState, trajectory_parameters trajectoryParameters,
                                                        pilot_parameters pilotParameters);

    // Converts taskspace to jointspace (Inverse Kinematics)
    jointspace_state taskspace_state_to_jointspace_state(taskspace_state taskspaceState, TrajectoryParameters trajectoryParameters,
                                                         pilot_parameters pilotParameters);

    // Converts a vector of taskspace states to jointspace (Inverse Kinematics)
    vector<jointspace_state> taskspace_states_to_jointspace_states(jointspace_state initialJointspaceState,
                                                                   const vector<taskspace_state> &taskspaceStates, TrajectoryParameters trajectoryParameters, pilot_parameters pilotParameters);

    // Helper function for Inverse Kinematics
    vector<double> triangle_inverse_kinematics(double xAnkle, double zAnkle, double xHip, double zHip, double Llower,
                                               double Lupper);
    /**********************************************************************

	Functions for Splines

	**********************************************************************/
    // Splines a set of 2D points as an array of polynomials between the points
    vector<cubic_polynomial> cubic_spline(double x[], time_tt t[], int numPoints);

    // Evaluate cubic polynomial at a given time
    double evaluate_cubic_polynomial(cubictrajectory_parametersynomial, time_tt time);
    double evaluate_cubic_polynomial_first_derivative(cubic_polynomial cubicPolynomial, time_tt time);
    double evaluate_cubic_polynomial_second_derivative(cubic_polynomial cubicPolynomial, time_tt time);

    // Spline the jointspace states (the q's)
    jointspace_spline cubic_spline_jointspace_states(vector<jointspace_state> states);

    //Generate and store the trajectory spline into the trajectory object
    void generateAndSaveSpline(jointspace_state initialJointspaceState);

    /**********************************************************************

	Functions for Controller

	***********************************************************************/
    // Generates trajectory spline from parameters to use in control system
    jointspace_spline compute_trajectory_spline(const trajectory_parameters &trajectoryParameters,
                                                const pilot_parameters &pilotParameters, jointspace_state initialJointspaceState);

    // Compare the provided position to the supposedly spline position
    // A positive values mean the exo is leading/ spline value is lagging
    jointspace_state compute_position_trajectory_difference(jointspace_spline jointspaceSpline,
                                                            jointspace_state currentJointspaceStates);

    // Limiting the velocity control to not pushing against angle limit
    // use AFTER the current velocity is added to the control velocity
    void limit_velocity_against_angle_boundary(
        jointspace_state currentJointspaceStates,
        double *velocitySignal);

    //limiting the position array in trajectory class
    void limit_position_against_angle_boundary(double positionArray[]);

    // Input the time, current joint position array
    // gives a velocity array output
    void getVelocityAfterPositionCorrection(time_tt time, double *robotPositionArray, double *velocityArray);

    //calculate the velocity at any given time
    void calcVelocity(time_tt time, double *velocityArray);

    //calculate the position at any given time
    void calcPosition(time_tt time, double *positionArray);

    /**********************************************************************

	Getter and setter

	**********************************************************************/
    //setter for the parameters
    void setTrajectoryParameter(time_tt step_duration, double step_height, double step_length, double hip_height_slack, double torso_forward_angle, double swing_ankle_down_angle,
                                Foot stance_foot, Movement movement, double seat_height, double step_end_height, double slope_angle, bool left_foot_on_tilt, bool right_foot_on_tilt);
    void setTrajectoryParameter(TrajectoryParameters trajectoryParameter);
    void setTrajectoryStanceRight();
    void setTrajectoryStanceLeft();

    void setPilotParameter(double lowerleg_length, double upperleg_length, double ankle_height, double foot_length,
                           double hip_width, double torso_length, double buttocks_height);
    void setPilotParameter(pilot_parameters pilotParameter);

    double getStepDuration();
};
#endif
