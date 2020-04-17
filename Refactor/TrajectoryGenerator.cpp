/**
 * Author: Dillon Chong
 * Date: 29 Sep 2019
 *
 * Editor: Samuel Wong
 * Date: 09/02/2020
 * compiled using cmd g++ -I eigen -std=c++11 *.cpp -o mai
 *
*/

#include "TrajectoryGenerator.h"
using namespace std;
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function Definitions                                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TrajectoryGenerator::TrajectoryGenerator(void) {
}
/***********************************************************************

Getter and setter

***********************************************************************/

void TrajectoryGenerator::setTrajectoryParameter(time_tt step_duration, double step_height, double step_length, double hip_height_slack, double torso_forward_angle, double swing_ankle_down_angle,
                                                 Foot stance_foot, Movement movement, double seat_height, double step_end_height, double slope_angle, bool left_foot_on_tilt, bool right_foot_on_tilt) {
    trajectoryParameter.step_duration = step_duration;
    trajectoryParameter.step_height = step_height;
    trajectoryParameter.step_length = step_length;
    trajectoryParameter.hip_height_slack = hip_height_slack;
    trajectoryParameter.torso_forward_angle = torso_forward_angle;
    trajectoryParameter.swing_ankle_down_angle = swing_ankle_down_angle;
    trajectoryParameter.stance_foot = stance_foot;
    trajectoryParameter.movement = movement;
    trajectoryParameter.seat_height = seat_height;
    trajectoryParameter.step_end_height = step_end_height;
    trajectoryParameter.slope_angle = slope_angle;
    trajectoryParameter.left_foot_on_tilt = left_foot_on_tilt;
    trajectoryParameter.right_foot_on_tilt = right_foot_on_tilt;
}
void TrajectoryGenerator::setTrajectoryParameter(trajectory_parameters trajectoryParameter) {
    this->trajectoryParameter = trajectoryParameter;
}
void TrajectoryGenerator::setPilotParameter(double lowerleg_length, double upperleg_length, double ankle_height, double foot_length,
                                            double hip_width, double torso_length, double buttocks_height) {
    pilotParameter.lowerleg_length = lowerleg_length;
    pilotParameter.upperleg_length = upperleg_length;
    pilotParameter.ankle_height = ankle_height;
    pilotParameter.foot_length = foot_length;
    pilotParameter.hip_width = hip_width;
    pilotParameter.torso_length = torso_length;
    pilotParameter.buttocks_height = buttocks_height;
}

void TrajectoryGenerator::setPilotParameter(pilot_parameters pilotParameter) {
    this->pilotParameter = pilotParameter;
}
