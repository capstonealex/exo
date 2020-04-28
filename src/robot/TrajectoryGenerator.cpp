/**
 * Author: Dillon Chong
 * Date: 29 Sep 2019
 *
 * Editor: Samuel Wong
 * Date: 09/02/2020
 * compiled using cmd g++ -I eigen -std=c++11 *.cpp -o mai
 *
 * TrajectoryGenerator Generator for walking State Machine (for now)
 * Other:
 * - sit-stand
 * - stand-sit
 * - stairs up
 * - stairs down
 * - tilted path up
 * - tilted path middle
 * - tiled path down

 * Notes and definitions:
 * - All angles typically in radians
 * - Swing foot/ankle is that of the foot that is moving in the air during a step
 * - Stance foot/ankle is that of the pivot foot planted on the ground during a step
 * - Joint configuration q's start from left ankle
 * - Polynomial definitions start from constant term
 *
 * Self-notes:
 * - struct, enum, class, etc. typedefs are implicit, but put them anyway https://stackoverflow.com/a/612350
 * - https://google.github.io/styleguide/cppguide.html#Naming
 * - https://shendrick.net/Coding%20Tips/2015/03/15/cpparrayvsvector.html
 * - #include <vector> = not fixed at compile time
 * - #include <array>  = like array - fixed at compile time
 * - For torso angle, Matlab uses backward angle, this uses forward angle
 *
 * TODO List:
 * - clarify x,y,z here with a reference to a diagram in the git repo;
 *    x points forward/right, y points left/into_page, z points up;
 *    TODO: currently it's the base of stance foot vertically below the ankle
 * - Stance Foot - dependent on currentJointspaceState? Assuming both feet are planted? Validate stance foot?
 *    If one feet is not planted -  e.g. when left foot lifted, not sure if left foot rising, or right foot falling?
 *    Also, validate swing_ankle_down_angle? (<- currently not implemented since the previous implementation is flawed)
 * - Clarify decision for when/if duration doesn't divide sample period exactly
 *    explicitly dependent on start time of that segment)
 * - For splining, use C++11's data() to get the array for the spline method, or just always use vectors not array?
 * - TODO: make a struct for triangle inv kin, instead of using an array?
 * - TODO: Key state generation, etc. - Are the struct/etc. assignments pass-by-value? well,
 *    the taskspace_state has no pointers, altho the jointspace_state does?
 * - Stance foot in taskspace_state struct may be a waste of memory
 * -  TODO: concerns about angles wrapping over the wrong 2pi range - figure out what ranges each joint or other angles should be,
 *	  then enforce them
 * * - TODO: Right now, walk/sit-stand/etc. is crammed into the initialjointspace state and generate keypoints method,
 *    until proper abtraction is done
 * - check the sqrt or trig to ensure that a 0/0/180 triangle won't cause issues?
 * - Sam Wong TODO list
 *   - Add a stance foot tilt angle to statespace and trajectory parameter
 *   - So that when we get angle from robot, forward kinematics can be used to convert to correct statespace
 *   - And when we convert from keypoints, correct angles from inverse trig with the consideration of tilted ground
 */

#include "TrajectoryGenerator.h"

#include <Eigen>  //Added "INCLUDE_DIRECTORIES ( "Eigen" )" to CMakeLists.txt //https://stackoverflow.com/questions/12249140/find-package-eigen3-for-cmake

using namespace std;
#include <iomanip>
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function Definitions                                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

TrajectoryGenerator::TrajectoryGenerator(void) {
}
/**********************************************************************

Functions for taskspace and joint space conversion

**********************************************************************/
vector<TrajectoryGenerator::taskspace_state> TrajectoryGenerator::generate_key_taskspace_states(
    TrajectoryGenerator::taskspace_state initialTaskspaceState,
    trajectory_parametersrameters &trajectoryParameters,
    const pilot_parameters &pilotParameters) {
    vector<taskspace_state> keyTaskspaceStates;
    double deltaFootDistance = 0.05;

    // Sit-stand
    if (trajectoryParameters.movement == Movement::Stand) {
        double seatHeight = trajectoryParameters.seat_height;
        double buttocksHeight = pilotParameters.buttocks_height;
        {
            taskspace_state state0 = initialTaskspaceState;  // init
            state0.time = 0.4;
            state0.left_ankle_position.x = 0;
            state0.right_ankle_position.x = 0;
            state0.left_ankle_position.z = pilotParameters.ankle_height;
            state0.right_ankle_position.z = pilotParameters.ankle_height;
            state0.hip_position.x = -sin(deg2rad(85)) * (pilotParameters.upperleg_length);
            state0.hip_position.z =
                pilotParameters.lowerleg_length + pilotParameters.ankle_height + cos(deg2rad(85)) * pilotParameters.upperleg_length;
            state0.torso_forward_angle = trajectoryParameters.torso_forward_angle * 5;
            state0.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(state0);
        }
        {
            taskspace_state state1 = initialTaskspaceState;  // init
            state1.time = 0.6;
            state1.left_ankle_position.x = 0;
            state1.right_ankle_position.x = 0;
            state1.left_ankle_position.z = pilotParameters.ankle_height;
            state1.right_ankle_position.z = pilotParameters.ankle_height;
            state1.hip_position.x = -sin(deg2rad(60)) * (pilotParameters.upperleg_length);
            state1.hip_position.z =
                pilotParameters.lowerleg_length + pilotParameters.ankle_height + cos(deg2rad(60)) * pilotParameters.upperleg_length;
            state1.torso_forward_angle = trajectoryParameters.torso_forward_angle * 5;
            state1.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(state1);
        }
        {
            taskspace_state state2 = initialTaskspaceState;  // init
            state2.time = 0.80;
            state2.left_ankle_position.x = 0;
            state2.right_ankle_position.x = 0;
            state2.left_ankle_position.z = pilotParameters.ankle_height;
            state2.right_ankle_position.z = pilotParameters.ankle_height;
            state2.hip_position.x = -sin(deg2rad(15)) * (pilotParameters.upperleg_length);
            state2.hip_position.z =
                pilotParameters.lowerleg_length + pilotParameters.ankle_height + cos(deg2rad(15)) * pilotParameters.upperleg_length;
            state2.torso_forward_angle = trajectoryParameters.torso_forward_angle * 3;
            state2.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(state2);
        }
        {
            taskspace_state stateEnd = initialTaskspaceState;  // init
            stateEnd.time = 1;
            stateEnd.left_ankle_position.x = 0;
            stateEnd.right_ankle_position.x = 0;
            stateEnd.left_ankle_position.z = pilotParameters.ankle_height;
            stateEnd.right_ankle_position.z = pilotParameters.ankle_height;
            stateEnd.hip_position.x =
                0;
            stateEnd.hip_position.z =
                pilotParameters.ankle_height + pilotParameters.upperleg_length + pilotParameters.lowerleg_length - trajectoryParameters.hip_height_slack;
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle * 1;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }

    // Stand-sit
    if (trajectoryParameters.movement == Movement::Sit) {
        double seatHeight = trajectoryParameters.seat_height;
        double buttocksHeight = pilotParameters.buttocks_height;

        {
            taskspace_state state1 = initialTaskspaceState;  // init
            state1.time = 0.8;
            state1.left_ankle_position.x = 0;
            state1.right_ankle_position.x = 0;
            state1.left_ankle_position.z = pilotParameters.ankle_height;
            state1.right_ankle_position.z = pilotParameters.ankle_height;

            state1.hip_position.x =
                -0.5 * (pilotParameters.upperleg_length);
            state1.hip_position.z =
                (seatHeight + buttocksHeight) + 0.6 * (pilotParameters.ankle_height + pilotParameters.upperleg_length + pilotParameters.lowerleg_length - trajectoryParameters.hip_height_slack - (seatHeight + buttocksHeight));  // how far away from seat height
            state1.torso_forward_angle = trajectoryParameters.torso_forward_angle * 5;
            state1.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(state1);
        }

        {
            taskspace_state stateEnd = initialTaskspaceState;  // init
            stateEnd.time = 1.0;
            stateEnd.left_ankle_position.x = 0;
            stateEnd.right_ankle_position.x = 0;
            stateEnd.left_ankle_position.z = pilotParameters.ankle_height;
            stateEnd.right_ankle_position.z = pilotParameters.ankle_height;

            stateEnd.hip_position.x =
                -1 * (pilotParameters.upperleg_length);
            stateEnd.hip_position.z =
                (seatHeight + buttocksHeight);
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle * 5;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }
    // Sitting
    if (trajectoryParameters.movement == Movement::Sitting) {
        double seatHeight = trajectoryParameters.seat_height;
        double buttocksHeight = pilotParameters.buttocks_height;

        {
            taskspace_state stateEnd = initialTaskspaceState;  // init
            stateEnd.time = 1;
            stateEnd.left_ankle_position.x = 0;
            stateEnd.right_ankle_position.x = 0;
            stateEnd.left_ankle_position.z = pilotParameters.ankle_height;
            stateEnd.right_ankle_position.z = pilotParameters.ankle_height;
            stateEnd.hip_position.x =
                -1 * (pilotParameters.upperleg_length);
            stateEnd.hip_position.z =
                seatHeight + buttocksHeight;
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }

    // Walk
    if (trajectoryParameters.movement == Movement::Walk) {
        Foot inferredStanceFoot = ((initialTaskspaceState.left_ankle_position.x > initialTaskspaceState.right_ankle_position.x)
                                       ? Foot::Left
                                       : Foot::Right);
        if (initialTaskspaceState.stance_foot != inferredStanceFoot)
            cout << "[generate_key_taskspace_states] Stance foot isn't in front of swing foot!?!!" << endl;
        double ankleDistance = abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x);
        double stepDisplacement = ankleDistance + trajectoryParameters.step_length;
        double legLengthSlacked = pilotParameters.lowerleg_length + pilotParameters.upperleg_length - trajectoryParameters.hip_height_slack;
        double hipHeight = pilotParameters.ankle_height + legLengthSlacked;
        double stanceFoot_x = max(initialTaskspaceState.left_ankle_position.x, initialTaskspaceState.right_ankle_position.x);

        // TrajectoryGenerator forming algorithm here
        //  All key states except initial state

        // Middle state
        {
            taskspace_state state1 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance;
                state1.left_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_height;
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state1.right_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.right_ankle_position.x;
            } else {
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance;
                state1.right_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_height;
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state1.left_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.left_ankle_position.x;
            }
            state1.hip_position.z = hipHeight;  // probably should deal with rounding error that makes hipheight slightly larger than leglength?
            state1.time = 0.4;
            state1.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            state1.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state1);
        }

        {
            taskspace_state state2 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                //if stand together
                if (trajectoryParameters.step_length < 0.1) {
                    state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance + 0.25;
                } else {
                    state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance + sqrt(pow(legLengthSlacked, 2.0) - pow(legLengthSlacked - trajectoryParameters.step_length * trajectoryParameters.step_height, 2.0));
                }
                state2.left_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height;
                state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state2.right_ankle_position.z = pilotParameters.ankle_height;
                state2.hip_position.x = initialTaskspaceState.right_ankle_position.x + trajectoryParameters.step_length / 3.0;
            } else {
                //if stand together
                if (trajectoryParameters.step_length < 0.1) {
                    state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance + 0.25;
                } else {
                    state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance + sqrt(pow(legLengthSlacked, 2.0) - pow(legLengthSlacked - trajectoryParameters.step_length * trajectoryParameters.step_height, 2.0));
                }
                state2.right_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height;
                state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state2.left_ankle_position.z = pilotParameters.ankle_height;
                state2.hip_position.x = initialTaskspaceState.left_ankle_position.x + trajectoryParameters.step_length / 3.0;
            }
            state2.hip_position.z = pilotParameters.ankle_height + 0.999 * (sqrt(pow(legLengthSlacked, 2.0) - pow(trajectoryParameters.step_length / 3.0, 2.0)));
            state2.time = 0.7;
            state2.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            state2.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state2);
        }

        // Final state
        {
            taskspace_state stateEnd = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + stepDisplacement;
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                stateEnd.hip_position.x = initialTaskspaceState.right_ankle_position.x + trajectoryParameters.step_length * 1.6 / 3.0;
            }

            else {
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + stepDisplacement;
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                stateEnd.hip_position.x = initialTaskspaceState.left_ankle_position.x + trajectoryParameters.step_length * 1.6 / 3.0;
            }
            stateEnd.left_ankle_position.z = pilotParameters.ankle_height;
            stateEnd.right_ankle_position.z = pilotParameters.ankle_height;
            //if stand together
            if (trajectoryParameters.step_length < 0.1) {
                stateEnd.hip_position.z = pilotParameters.ankle_height + legLengthSlacked;
            } else {
                stateEnd.hip_position.z = pilotParameters.ankle_height + 0.999 * (sqrt(pow(legLengthSlacked, 2.0) - pow(trajectoryParameters.step_length * 1.6 / 3.0, 2.0)));
            }
            stateEnd.time = 1;
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }

    // Back
    if (trajectoryParameters.movement == Movement::Back)

    {
        Foot backwardStanceFoot = ((initialTaskspaceState.left_ankle_position.x > initialTaskspaceState.right_ankle_position.x)
                                       ? Foot::Right
                                       : Foot::Left);
        if (initialTaskspaceState.stance_foot != backwardStanceFoot)
            cout << "[generate_key_taskspace_states] Backward stance foot isn't at the back!?!!" << endl;
        double ankleDistance = abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x);
        double stepDisplacement = ankleDistance + trajectoryParameters.step_length;
        double legLengthSlacked = pilotParameters.lowerleg_length + pilotParameters.upperleg_length - trajectoryParameters.hip_height_slack;
        double hipHeight = pilotParameters.ankle_height + legLengthSlacked;

        // TrajectoryGenerator forming algorithm here
        //  All key states except initial state

        // Middle state
        {
            taskspace_state state1 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Left)
            //||	abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x - ankleDistance;
                state1.right_ankle_position.z = initialTaskspaceState.right_ankle_position.z + trajectoryParameters.step_height;
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state1.left_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.left_ankle_position.x;
            } else {
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x - ankleDistance;
                state1.left_ankle_position.z = initialTaskspaceState.left_ankle_position.z + trajectoryParameters.step_height;
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state1.right_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.right_ankle_position.x;
            }
            state1.hip_position.z = hipHeight;  // probably should deal with rounding error that makes hipheight slightly larger than leglength?
            state1.time = 0.5;
            state1.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            state1.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state1);
        }
        //Post Middle step
        {
            taskspace_state state2 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Left) {
                //if stand together
                if (trajectoryParameters.step_length < 0.1) {
                    state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x - ankleDistance + 0.1;
                } else {
                    state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x - ankleDistance - trajectoryParameters.step_length / 2.0;
                }
                state2.right_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height;
                state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state2.left_ankle_position.z = pilotParameters.ankle_height;
                state2.hip_position.x = initialTaskspaceState.left_ankle_position.x - trajectoryParameters.step_length / 3.0;
            } else {
                //if stand together
                if (trajectoryParameters.step_length < 0.1) {
                    state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x - ankleDistance + 0.1;
                } else {
                    state2.left_ankle_position.x = initialTaskspaceState.right_ankle_position.x - ankleDistance - trajectoryParameters.step_length / 2.0;
                }
                state2.left_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height;
                state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state2.right_ankle_position.z = pilotParameters.ankle_height;
                state2.hip_position.x = initialTaskspaceState.right_ankle_position.x - trajectoryParameters.step_length / 3.0;
            }
            state2.hip_position.z = pilotParameters.ankle_height + 0.999 * (sqrt(pow(legLengthSlacked, 2.0) - pow(trajectoryParameters.step_length / 3.0, 2.0)));
            state2.time = 0.7;
            state2.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            state2.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state2);
        }
        // Final state
        {
            taskspace_state stateEnd = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Left)
            //||	abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x - stepDisplacement;
                stateEnd.hip_position.x = initialTaskspaceState.left_ankle_position.x - trajectoryParameters.step_length / 2.0;
            } else {
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x - stepDisplacement;
                stateEnd.hip_position.x = initialTaskspaceState.right_ankle_position.x - trajectoryParameters.step_length / 2.0;
            }
            stateEnd.left_ankle_position.z = pilotParameters.ankle_height;
            stateEnd.right_ankle_position.z = pilotParameters.ankle_height;
            stateEnd.hip_position.z = pilotParameters.ankle_height + sqrt(pow(legLengthSlacked, 2.0) - pow(trajectoryParameters.step_length / 2.0, 2.0));
            stateEnd.time = 1;
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }
    //stairs
    if (trajectoryParameters.movement == Movement::Stair) {
        Foot inferredStanceFoot = ((initialTaskspaceState.left_ankle_position.x > initialTaskspaceState.right_ankle_position.x)
                                       ? Foot::Left
                                       : Foot::Right);
        if (initialTaskspaceState.stance_foot != inferredStanceFoot)
            cout << "[generate_key_taskspace_states] Stance foot isn't in front of swing foot!?!!" << endl;
        double ankleDistance = abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x);
        double heightDistance = abs(initialTaskspaceState.left_ankle_position.z - initialTaskspaceState.right_ankle_position.z);
        double stepDisplacement = ankleDistance + trajectoryParameters.step_length;
        double legLengthSlacked = pilotParameters.lowerleg_length + pilotParameters.upperleg_length - trajectoryParameters.hip_height_slack;
        double hipHeight = pilotParameters.ankle_height + legLengthSlacked;
        double stanceFoot_x = max(initialTaskspaceState.left_ankle_position.x, initialTaskspaceState.right_ankle_position.x);

        // TrajectoryGenerator forming algorithm here
        //  All key states except initial state

        // Middle state
        {
            taskspace_state state1 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance;
                state1.left_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_height;
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state1.right_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.right_ankle_position.x;
            } else {
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance;
                state1.right_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_height;
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state1.left_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.left_ankle_position.x;
            }
            state1.hip_position.z = hipHeight;  // probably should deal with rounding error that makes hipheight slightly larger than leglength?
            state1.time = 0.4;
            state1.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            state1.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state1);
        }

        {
            taskspace_state state2 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                //if stand together
                if (trajectoryParameters.step_length < 0.1) {
                    state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance + 0.25;
                    state2.left_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height + trajectoryParameters.step_end_height;
                } else {
                    state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance + 0.7 * sqrt(pow(legLengthSlacked, 2.0) - pow(legLengthSlacked - trajectoryParameters.step_length * trajectoryParameters.step_height, 2.0));
                    state2.left_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height + trajectoryParameters.step_end_height;
                }
                state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state2.right_ankle_position.z = pilotParameters.ankle_height;
                state2.hip_position.x = initialTaskspaceState.right_ankle_position.x + trajectoryParameters.step_length * 0.0 / 3.0;
            } else {
                //if stand together
                if (trajectoryParameters.step_length < 0.1) {
                    state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance + 0.25;
                    state2.right_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height + trajectoryParameters.step_end_height;
                } else {
                    state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance + 0.7 * sqrt(pow(legLengthSlacked, 2.0) - pow(legLengthSlacked - trajectoryParameters.step_length * trajectoryParameters.step_height, 2.0));
                    state2.right_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height + trajectoryParameters.step_end_height;
                }
                state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state2.left_ankle_position.z = pilotParameters.ankle_height;
                state2.hip_position.x = initialTaskspaceState.left_ankle_position.x + trajectoryParameters.step_length * 0.0 / 3.0;
            }
            state2.hip_position.z = pilotParameters.ankle_height + 0.999 * (sqrt(pow(legLengthSlacked, 2.0) - pow(trajectoryParameters.step_length * 0.0 / 3.0, 2.0)));
            state2.time = 0.7;
            state2.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            state2.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state2);
        }

        // Final state
        {
            taskspace_state stateEnd = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + stepDisplacement;
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                stateEnd.hip_position.x = initialTaskspaceState.right_ankle_position.x + trajectoryParameters.step_length * 0.0 / 3.0;
                stateEnd.left_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_end_height;
                stateEnd.right_ankle_position.z = pilotParameters.ankle_height;
            }

            else {
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + stepDisplacement;
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                stateEnd.hip_position.x = initialTaskspaceState.left_ankle_position.x + trajectoryParameters.step_length * 0.0 / 3.0;
                stateEnd.left_ankle_position.z = pilotParameters.ankle_height;
                stateEnd.right_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_end_height;
            }
            //if stand together
            if (trajectoryParameters.step_length < 0.1) {
                stateEnd.hip_position.z = pilotParameters.ankle_height + legLengthSlacked;
            } else {
                stateEnd.hip_position.z = pilotParameters.ankle_height + 0.999 * (sqrt(pow(legLengthSlacked, 2.0) - pow(trajectoryParameters.step_length * 0.0 / 3.0, 2.0)));
            }
            stateEnd.time = 1;
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }
    //down stairs
    if (trajectoryParameters.movement == Movement::DownStair) {
        Foot inferredStanceFoot = ((initialTaskspaceState.left_ankle_position.x > initialTaskspaceState.right_ankle_position.x)
                                       ? Foot::Left
                                       : Foot::Right);
        if (initialTaskspaceState.stance_foot != inferredStanceFoot)
            cout << "[generate_key_taskspace_states] Stance foot isn't in front of swing foot!?!!" << endl;
        double ankleDistance = abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x);
        double heightDistance = abs(initialTaskspaceState.left_ankle_position.z - initialTaskspaceState.right_ankle_position.z);
        double stepDisplacement = ankleDistance + trajectoryParameters.step_length;
        double legLengthSlacked = pilotParameters.lowerleg_length + pilotParameters.upperleg_length - trajectoryParameters.hip_height_slack;
        double hipHeight = pilotParameters.ankle_height + legLengthSlacked;
        double stanceFoot_x = max(initialTaskspaceState.left_ankle_position.x, initialTaskspaceState.right_ankle_position.x);

        // TrajectoryGenerator forming algorithm here
        //  All key states except initial state

        // Middle state
        {
            taskspace_state state1 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x - ankleDistance;
                state1.left_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_height * .85;
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state1.right_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.right_ankle_position.x;
            } else {
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x - ankleDistance;
                state1.right_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_height * .85;
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state1.left_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.left_ankle_position.x;
            }
            state1.hip_position.z = hipHeight;  // probably should deal with rounding error that makes hipheight slightly larger than leglength?
            state1.time = 0.5;
            state1.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            state1.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state1);
        }

        // Final state
        {
            taskspace_state stateEnd = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x - stepDisplacement;
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                stateEnd.hip_position.x = stateEnd.left_ankle_position.x;
                stateEnd.left_ankle_position.z = pilotParameters.ankle_height - trajectoryParameters.step_end_height;
                stateEnd.right_ankle_position.z = pilotParameters.ankle_height;
                stateEnd.hip_position.z = stateEnd.left_ankle_position.z + legLengthSlacked;
            }

            else {
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x - stepDisplacement;
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                stateEnd.hip_position.x = stateEnd.right_ankle_position.x;
                stateEnd.left_ankle_position.z = pilotParameters.ankle_height;
                stateEnd.right_ankle_position.z = pilotParameters.ankle_height - trajectoryParameters.step_end_height;
                stateEnd.hip_position.z = stateEnd.right_ankle_position.z + legLengthSlacked;
            }
            stateEnd.time = 1;
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }

    //Ramp
    if (trajectoryParameters.movement == Movement::Ramp) {
        Foot inferredStanceFoot = ((initialTaskspaceState.left_ankle_position.x > initialTaskspaceState.right_ankle_position.x)
                                       ? Foot::Left
                                       : Foot::Right);
        if (initialTaskspaceState.stance_foot != inferredStanceFoot)
            cout << "[generate_key_taskspace_states] Stance foot isn't in front of swing foot!?!!" << endl;
        double ankleDistance = abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x);
        double heightDistance = abs(initialTaskspaceState.left_ankle_position.z - initialTaskspaceState.right_ankle_position.z);
        double stepDisplacementx = ankleDistance + trajectoryParameters.step_length * cos(trajectoryParameters.slope_angle);
        double stepDisplacementz = heightDistance + trajectoryParameters.step_length * sin(trajectoryParameters.slope_angle);
        double legLengthSlacked = pilotParameters.lowerleg_length + pilotParameters.upperleg_length - trajectoryParameters.hip_height_slack;
        double hipHeight = pilotParameters.ankle_height + legLengthSlacked;
        double stanceFoot_x = max(initialTaskspaceState.left_ankle_position.x, initialTaskspaceState.right_ankle_position.x);
        // Middle state
        {
            taskspace_state state1 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance;
                state1.left_ankle_position.z = initialTaskspaceState.left_ankle_position.z + trajectoryParameters.step_height + heightDistance;
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state1.right_ankle_position.z = initialTaskspaceState.right_ankle_position.z;
                state1.hip_position.x = initialTaskspaceState.right_ankle_position.x;
                state1.hip_position.z = initialTaskspaceState.right_ankle_position.z + hipHeight - pilotParameters.ankle_height;
            } else {
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance;
                state1.right_ankle_position.z = initialTaskspaceState.right_ankle_position.z + trajectoryParameters.step_height + heightDistance;
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state1.left_ankle_position.z = initialTaskspaceState.left_ankle_position.z;
                state1.hip_position.x = initialTaskspaceState.left_ankle_position.x;
                state1.hip_position.z = initialTaskspaceState.left_ankle_position.z + hipHeight - pilotParameters.ankle_height;
            }
            state1.time = 0.5;
            state1.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            state1.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state1);
        }
        // Final state
        {
            taskspace_state stateEnd = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + stepDisplacementx;
                stateEnd.left_ankle_position.z = initialTaskspaceState.left_ankle_position.z + stepDisplacementz;
                stateEnd.hip_position.x = initialTaskspaceState.right_ankle_position.x + trajectoryParameters.step_length / 2.0;
                stateEnd.hip_position.z = initialTaskspaceState.right_ankle_position.z + hipHeight - pilotParameters.ankle_height;
            }

            else {
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + stepDisplacementx;
                stateEnd.right_ankle_position.z = initialTaskspaceState.right_ankle_position.z + stepDisplacementz;
                stateEnd.hip_position.x = initialTaskspaceState.left_ankle_position.x + trajectoryParameters.step_length / 2.0;
                stateEnd.hip_position.z = initialTaskspaceState.left_ankle_position.z + hipHeight - pilotParameters.ankle_height;
            }
            stateEnd.time = 1;
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }

    //Uneven ground, basically a mixture of walk and stair
    if (trajectoryParameters.movement == Movement::Uneven) {
        Foot inferredStanceFoot = ((initialTaskspaceState.left_ankle_position.x > initialTaskspaceState.right_ankle_position.x)
                                       ? Foot::Left
                                       : Foot::Right);
        if (initialTaskspaceState.stance_foot != inferredStanceFoot)
            cout << "[generate_key_taskspace_states] Stance foot isn't in front of swing foot!?!!" << endl;
        double ankleDistance = abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x);
        double stepDisplacement = ankleDistance + trajectoryParameters.step_length;
        double legLengthSlacked = pilotParameters.lowerleg_length + pilotParameters.upperleg_length - trajectoryParameters.hip_height_slack;
        double hipHeight = pilotParameters.ankle_height + legLengthSlacked;
        double stanceFoot_x = max(initialTaskspaceState.left_ankle_position.x, initialTaskspaceState.right_ankle_position.x);

        // TrajectoryGenerator forming algorithm here
        //  All key states except initial state

        // Middle state
        {
            taskspace_state state1 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance;
                state1.left_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_height;
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state1.right_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.right_ankle_position.x;
            } else {
                state1.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + trajectory_parameters state1.right_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_height;
                state1.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state1.left_ankle_position.z = pilotParameters.ankle_height;
                state1.hip_position.x = initialTaskspaceState.left_ankle_position.x;
            }
            state1.hip_position.z = hipHeight;  // probably should deal with rounding error that makes hipheight slightly larger than leglength?
            state1.time = 0.4;
            state1.torso_forward_angle = trajectoryParameters.torso_forward_angle * 0;
            state1.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state1);
        }

        {
            taskspace_state state2 = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                //if stand together
                if (trajectoryParameters.step_length < 0.1) {
                    state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance + 0.3;
                } else {
                    state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + ankleDistance + sqrt(pow(legLengthSlacked, 2.0) - pow(legLengthSlacked - trajectoryParameters.step_length * trajectoryParameters.step_height, 2.0));
                }
                state2.left_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height + trajectoryParameters.step_end_height;
                state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                state2.right_ankle_position.z = pilotParameters.ankle_height;
                state2.hip_position.x = initialTaskspaceState.right_ankle_position.x + trajectoryParameters.step_length / 3.0;
            } else {
                //if stand together
                if (trajectoryParameters.step_length < 0.1) {
                    state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance + 0.3;
                } else {
                    state2.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + ankleDistance + sqrt(pow(legLengthSlacked, 2.0) - pow(legLengthSlacked - trajectoryParameters.step_length * trajectoryParameters.step_height, 2.0));
                }
                state2.right_ankle_position.z = pilotParameters.ankle_height + 0.5 * trajectoryParameters.step_height + trajectoryParameters.step_end_height;
                state2.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                state2.left_ankle_position.z = pilotParameters.ankle_height;
                state2.hip_position.x = initialTaskspaceState.left_ankle_position.x + trajectoryParameters.step_length / 3.0;
            }
            state2.hip_position.z = pilotParameters.ankle_height + 0.999 * (sqrt(pow(legLengthSlacked, 2.0) - pow(trajectoryParameters.step_length / 3.0, 2.0)));
            state2.time = 0.70;
            state2.torso_forward_angltrajectory_parametersters.torso_forward_angle;
            state2.swing_ankle_down_angle = 0.0;  // could be non-zero due to slight issues in forward kinematics/positioning, btu zero it out anyways
            keyTaskspaceStates.push_back(state2);
        }

        // Final state
        {
            taskspace_state stateEnd = initialTaskspaceState;
            if (initialTaskspaceState.stance_foot == Foot::Right)
            //|| abs(initialTaskspaceState.left_ankle_position.x - initialTaskspaceState.right_ankle_position.x) <= deltaFootDistance)
            {
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x + stepDisplacement;
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x;
                stateEnd.hip_position.x = initialTaskspaceState.right_ankle_position.x + trajectoryParameters.step_length * 1.6 / 3.0;
                stateEnd.right_ankle_position.z = pilotParameters.ankle_height;
                stateEnd.left_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_end_height;
            }

            else {
                stateEnd.right_ankle_position.x = initialTaskspaceState.right_ankle_position.x + stepDisplacement;
                stateEnd.left_ankle_position.x = initialTaskspaceState.left_ankle_position.x;
                stateEnd.hip_position.x = initialTaskspaceState.left_ankle_position.x + trajectoryParameters.step_length * 1.6 / 3.0;
                stateEnd.left_ankle_position.z = pilotParameters.ankle_height;
                stateEnd.right_ankle_position.z = pilotParameters.ankle_height + trajectoryParameters.step_end_height;
            }

            //if stand together
            if (trajectoryParameters.step_length < 0.1) {
                stateEnd.hip_position.z = pilotParameters.ankle_height + legLengthSlacked;
            } else {
                stateEnd.hip_position.z = pilotParameters.ankle_height + 0.999 * (sqrt(pow(legLengthSlacked, 2.0) - pow(trajectoryParameters.step_length * 1.6 / 3.0, 2.0)));
            }
            stateEnd.time = 1;
            stateEnd.torso_forward_angle = trajectoryParameters.torso_forward_angle;
            stateEnd.swing_ankle_down_angle = 0.0;
            keyTaskspaceStates.push_back(stateEnd);
        }
    }
    return keyTaskspaceStates;
}

// Generates discrete trajectory from parameters to use in control system
void TrajectoryGenerator::compute_discrete_trajectory(
    const TrajectoryParameters &trajectoryParameters,
    const pilot_parameters &pilotParameters,
    jointspace_state initialJointspaceState) {
    Foot stanceFoot = trajectoryParameters.stance_foot;
    taskspace_state initialTaskspaceState;
    vector<taskspace_state> taskspaceStates;
    vector<jointspace_state> jointspaceStates;
    jointspace_spline jointspaceSpline;

    initialTaskspaceState = jointspace_state_to_taskspace_state(initialJointspaceState, trajectoryParameters, pilotParameters);

    // Obtain key ttrajectory_parameters //  (output excludes initial state which is already known in jointspace)
    taskspaceStates = generate_key_taskspace_states(initialTaskspaceState, trajectoryParameters, pilotParameters);
    //printing the initial taskspace state
    cout << "[compute_trajectory]: Keypoints (taskspace):" << endl;
    cout << "[compute_trajectory]:"
         << "\t"
         << "time | left_ankle_position | hip_position | right_ankle_position | torso_forward_angle | swing_ankle_down_angle"
         << endl;
    cout << "[compute_trajectory]:"
         << "\t"
         << initialTaskspaceState.time << "\t"
         << " | "
         << initialTaskspaceState.left_ankle_position.x << "\t"
         << initialTaskspaceState.left_ankle_position.y << "\t"
         << initialTaskspaceState.left_ankle_position.z << "\t"
         << " | "
         << initialTaskspaceState.hip_position.x << "\t"
         << initialTaskspaceState.hip_position.y << "\t"
         << initialTaskspaceState.hip_position.z << "\t"
         << " | "
         << initialTaskspaceState.right_ankle_position.x << "\t"
         << initialTaskspaceState.right_ankle_position.y << "\t"
         << initialTaskspaceState.right_ankle_position.z << "\t"
         << " | "
         << initialTaskspaceState.torso_forward_angle << "\t"
         << " | "
         << initialTaskspaceState.swing_ankle_down_angle
         << endl;
    //printing the middle and last task space states
    for (auto currentState : taskspaceStates) {
        cout << "[compute_trajectory]:"
             << "\t"
             << currentState.time << "\t"
             << "|"
             << currentState.left_ankle_position.x << "\t"
             << currentState.left_ankle_position.y << "\t"
             << currentState.left_ankle_position.z << "\t"
             << "|"
             << currentState.hip_position.x << "\t"
             << currentState.hip_position.y << "\t"
             << currentState.hip_position.z << "\t"
             << "|"
             << currentState.right_ankle_posittrajectory_parameters << currentState.right_ankle_position.y << "\t"
             << currentState.right_ankle_position.z << "\t"
             << "|"
             << currentState.torso_forward_angle << "\t"
             << "|"
             << currentState.swing_ankle_down_angle
             << endl;
    }

    // Convert key states to jointspace (prepend known initial jointspace state)
    jointspaceStates = taskspace_states_to_jointspace_states(initialJointspaceState, taskspaceStates, trajectoryParameters, pilotParameters);

    cout << "[compute_trajectory]: Keypoints (jointspace):"
         << "LEFT_HIP"
         << "\t"
         << "LEFT_KNEE"
         << "\t"
         << "RIGHT_HIP"
         << "\t"
         << "RIGHT_KNEE"
         << "\t"
         << "LEFT_ANKLE"
         << "\t"
         << "RIGHT_ANKLE" << endl;
    for (auto state : jointspaceStates) {
        cout << "[compute_trajectory]:\t" << state.time << "\t\t\t";
        for (int i = 0; i < NO_JOINTS; i++)
            cout << rad2deg(state.q[i]) << "\t  ";
        cout << endl;
    }
}
TrajectoryGenerator::taskspace_state TrajectoryGenerator::jointspace_state_to_taskspace_state(
    jointspace_state jointspaceState,
    TrajectoryParameters trajectoryParameters,
    pilot_parameters pilotParameters) {
    taskspace_state taskspaceState{};

    // q's in a reference frame - imagine a 6link thing positioned with all angles at '0' (horizontal), then only PI is
    //  needed to be added at hip/right_leg to get exo
    double *q = jointspaceState.q;  // for readability; will be optimised out by compiler?
    //calculate the torso forward angle from left joints, which is repsect to world space vertical up
    double torso_forward_angle = M_PI_2 + q[LEFT_ANKLE] - q[LEFT_KNEE] - q[LEFT_HIP];
    // Perform Forward Kinematics
    //  Put origin at base of Stance foot, vertically below the ankle
    //  Assume hip has zero width for now
    taskspaceState.left_ankle_position.x = 0.0;
    taskspaceState.left_ankle_position.y = 0.0;
    taskspaceState.left_ankle_position.z = pilotParameters.ankle_height;
    if (trajectoryParameters.left_foot_on_tilt) {
        taskspaceState.hip_position.x = taskspaceState.left_ankle_position.x - pilotParameters.lowerleg_length * (cos(q[LEFT_ANKLE] + deg2rad(trajectoryParameters.slope_angle))) - pilotParameters.upperleg_length * (cos(q[LEFT_ANKLE] + deg2rad(trajectoryParameters.slope_angle - q[LEFT_KNEE])));
        taskspaceState.hip_position.y = 0.0;
        taskspaceState.hip_position.z = taskspaceState.left_ankle_position.z + pilotParameters.lowerleg_length * (sin(q[LEFT_ANKLE] + deg2rad(trajectoryParameters.slope_angle))) + pilotParameters.upperleg_length * (sin(q[LEFT_ANKLE] + deg2rad(trajectoryParameters.slope_angle - q[LEFT_KNEE])));
    } else {
        taskspaceState.hip_position.x = taskspaceState.left_ankle_position.x - pilotParameters.lowerleg_length * (cos(q[LEFT_ANKLE])) - pilotParameters.upperleg_length * (cos(q[LEFT_ANKLE] - q[LEFT_KNEE]));
        taskspaceState.hip_position.y = 0.0;
        taskspaceState.hip_position.z = taskspaceState.left_ankle_position.z + pilotParameters.lowerleg_length * (sin(q[LEFT_ANKLE])) + pilotParameters.upperleg_length * (sin(q[LEFT_ANKLE] - q[LEFT_KNEE]));
    }
    taskspaceState.right_ankle_position.x = taskspaceState.hip_position.x + pilotParameters.upperleg_length * (sin(M_PI - q[RIGHT_HIP] - torso_forward_angle)) - pilotParameters.lowerleg_length * (cos(M_PI_2 + M_PI - q[RIGHT_HIP] - torso_forward_angle - q[RIGHT_KNEE]));
    taskspaceState.right_ankle_position.y = 0.0;
    taskspaceState.right_ankle_position.z = taskspaceState.hip_position.z - pilotParameters.upperleg_length * (cos(M_PI - q[RIGHT_HIP] - torso_forward_angle)) - pilotParameters.lowerleg_length * (sin(M_PI_2 + M_PI - q[RIGHT_HIP] - torso_forward_angle - q[RIGHT_KNEE]));
    taskspaceState.torso_forward_angle = torso_forward_angle;
    taskspaceState.swing_ankle_down_angle = 0;  //TODO: this is called when converting from robot to trajectory calculation. Do i need this information?
    taskspaceState.stance_foot = trajectoryParameters.stance_foot;
    taskspaceState.time = jointspaceState.time;

    return taskspaceState;
}

TrajectoryGenerator::jointspace_state TrajectoryGenerator::taskspace_state_to_jointspace_state(
    taskspace_state taskspaceState,
    TrajectoryParameters trajectoryParameters,
    pilot_parameters pilotParameters) {
    jointspace_state jointspaceState{};

    // Do the bulk of the computations based on each leg
    vector<double> LeftTempAngles = triangle_inverse_kinematics(
        taskspaceState.left_ankle_position.x,
        taskspaceState.left_ankle_position.z,
        taskspaceState.hip_position.x,
        taskspaceState.hip_position.z,
        pilotParameters.lowerleg_length,
        pilotParameters.upperleg_length);
    vector<double> RightTempAngles = triangle_inverse_kinematics(
        taskspaceState.right_ankle_position.x,
        taskspaceState.right_ankle_position.z,
        taskspaceState.hip_position.x,
        taskspaceState.hip_position.z,
        pilotParameters.lowerleg_length,
        pilotParameters.upperleg_length);
    //[0] angleAtHip,  // CCW angle of upper leg from vertical down
    //[1] angleAtKnee, // CCW angle of upper leg from straight leg config
    //[2] angleAtAnkle //  CW angle of lower leg from vertical up

    jointspaceState.time = taskspaceState.time;
    if (trajectoryParameters.left_foot_on_tilt) {
        jointspaceState.q[LEFT_ANKLE] = M_PI_2 + LeftTempAngles.at(2) - trajectoryParameters.slope_angle;
    } else {
        jointspaceState.q[LEFT_ANKLE] = M_PI_2 + LeftTempAngles.at(2);
    }
    jointspaceState.q[LEFT_ANKLE] = M_PI_2 + LeftTempAngles.at(2);
    jointspaceState.q[LEFT_KNEE] = LeftTempAngles.at(1);
    jointspaceState.q[LEFT_HIP] = M_PI - LeftTempAngles.at(0) - taskspaceState.torso_forward_angle;
    jointspaceState.q[RIGHT_HIP] = M_PI - RightTempAngles.at(0) - taskspaceState.torso_forward_angle;
    jointspaceState.q[RIGHT_KNEE] = RightTempAngles.at(1);
    if (trajectoryParameters.right_foot_on_tilt) {
        jointspaceState.q[RIGHT_ANKLE] = M_PI_2 + RightTempAngles.at(2) - trajectoryParameters.slope_angle;
    } else {
        jointspaceState.q[RIGHT_ANKLE] = M_PI_2 + RightTempAngles.at(2);
    }
    return jointspaceState;
}

vector<TrajectoryGenerator::jointspace_state> TrajectoryGenerator::taskspace_states_to_jointspace_states(
    jointspace_state initialJointspaceState,
    const vector<taskspace_state> &taskspaceStates,
    TrajectoryParameters trajectoryParameters,
    pilot_parameters pilotParameters) {
    vector<jointspace_state> jointspaceStates;

    jointspaceStates.push_back(initialJointspaceState);
    // convert every taskspace state to a jointspace state
    for (const auto &taskspaceState : taskspaceStates) {
        joitrajectory_parametersack(taskspace_state_to_jointspace_state(taskspaceState, trajectoryParameters, pilotParameters));
    }

    return jointspaceStates;
}

vector<double> TrajectoryGenerator::triangle_inverse_kinematics(
    const double xAnkle,
    const double zAnkle,
    const double xHip,
    const double zHip,
    const double Llower,
    const double Lupper) {
    // x is right, z is up; we're looking at the exo from the right side, so it walks rightwards

    const double L = sqrtf((xAnkle - xHip) * (xAnkle - xHip) + (zAnkle - zHip) * (zAnkle - zHip));
    const double angleLAcuteFromVertical = atan2f((xAnkle - xHip), (zHip - zAnkle));
    const double angleInternalHip = acos((Lupper * Lupper + L * L - Llower * Llower) / (2.0 * Lupper * L));
    //const double angleInternalAnkle = asin(sin(angleInternalHip)*Lupper/Llower);
    //const double angleInternalAnkle = acos((Llower * Llower + L * L - Lupper * Lupper) / (2.0 * Llower * L));
    const double angleInternalAnkle = asin(sin(angleInternalHip) * Lupper / Llower);
    const double angleInternalKnee = M_PI - angleInternalHip - angleInternalAnkle;

    const double angleAtHip = angleLAcuteFromVertical + angleInternalHip;
    const double angleAtKnee = M_PI - angleInternalKnee;
    const double angleAtAnkle = angleInternalAnkle - angleLAcuteFromVertical;

    return {
        angleAtHip,   // CCW angle of upper leg from vertical down
        angleAtKnee,  // CCW angle of upper leg from straight leg config
        angleAtAnkle  //  CW angle of lower leg from vertical up
    };
}

/**********************************************************************

Functions for Splines

**********************************************************************/
vector<TrajectoryGenerator::cubic_polynomial> TrajectoryGenerator::cubic_spline(
    double x[],
    TrajectoryGenerator::time_tt t[],
    int numPoints) {
    vector<TrajectoryGenerator::cubic_polynomial> cubicSplinePolynomials;

    //cout << "[cubic_spline]: x's: ";
    //for (int i=0; i<numPoints; i++) cout << x[i] << "\t";
    //cout << endl;

    // Cubic spline
    // Assume boundary vel and acc are zero.
    const int numPointsm1 = numPoints - 1;
    const int numPolynomials = numPointsm1;
    const int numVias = numPoints - 2;
    const int numPolynomialCoefficients = NUM_CUBIC_COEFFICIENTS;
    const int numUnknowns = numPolynomialCoefficients * numPolynomials;

    Eigen::MatrixXf A = Eigen::MatrixXf::Zero(numUnknowns, numUnknowns);
    Eigen::MatrixXf B = Eigen::MatrixXf::Zero(numUnknowns, 1);
    int offset = 0;
    A.block<2, numPolynomialCoefficients>(offset, 0)
        << 1,
        t[0], t[0] * t[0], t[0] * t[0] * t[0],
        0, 1, 2 * t[0], 3 * t[0] * t[0];
    B.block<2, 1>(offset, 0)
        << x[0],
        0;
    offset += 2;

    A.block<2, numPolynomialCoefficients>(offset, numUnknowns - numPolynomialCoefficients)
        << 1,
        t[numPointsm1], t[numPointsm1] * t[numPointsm1], t[numPointsm1] * t[numPointsm1] * t[numPointsm1],
        0, 1, 2 * t[numPointsm1], 3 * t[numPointsm1] * t[numPointsm1];
    B.block<2, 1>(offset, 0)
        << x[numPointsm1],
        0;
    offset += 2;

    for (int i = 0; i < numVias; i++) {
        int j = i + 1;
        A.block<1, numPolynomialCoefficients>(offset, i * numPolynomialCoefficients)
            << 1,
            t[j], t[j] * t[j], t[j] * t[j] * t[j];
        B.block<1, 1>(offset, 0)
            << x[j];
        offset += 1;
        A.block<1, numPolynomialCoefficients>(offset, j * numPolynomialCoefficients)
            << 1,
            t[j], t[j] * t[j], t[j] * t[j] * t[j];
        B.block<1, 1>(offset, 0)
            << x[j];
        offset += 1;
        A.block<2, 2 * numPolynomialCoefficients>(offset, i * numPolynomialCoefficients)
            << 0,
            1, 2 * t[j], 3 * t[j] * t[j], 0, -1, -2 * t[j], -3 * t[j] * t[j],
            0, 0, 2, 6 * t[j], 0, 0, -2, -6 * t[j];
        B.block<2, 1>(offset, 0)
            << 0,
            0;
        offset += 2;
    }

    Eigen::MatrixXf X = A.inverse() * B;

    //cout << "A:"  << endl << A           << endl;
    //cout << "A':" << endl << A.inverse() << endl;
    //cout << "B:"  << endl << B           << endl;
    //cout << "X:"  << endl << X           << endl;

    for (int i = 0; i < numPolynomials; i++) {
        // cubic (t)
        cubicSplinePolynomials.push_back({.coefficients = {
                                              X(NUM_CUBIC_COEFFICIENTS * i + 0, 0),
                                              X(NUM_CUBIC_COEFFICIENTS * i + 1, 0),
                                              X(NUM_CUBIC_COEFFICIENTS * i + 2, 0),
                                              X(NUM_CUBIC_COEFFICIENTS * i + 3, 0)}});
    }

    return cubicSplinePolynomials;
}

TrajectoryGenerator::jointspace_spline TrajectoryGenerator::cubic_spline_jointspace_states(vector<TrajectoryGenerator::jointspace_state> jointspaceStates) {
    TrajectoryGenerator::jointspace_spline jointspaceSpline;
    // Get times
    for (auto &jointspaceState : jointspaceStates)
        jointspaceSpline.times.push_back(jointspaceState.time);

    // Take spline for each q
    for (int i = 0, numPoints = jointspaceStates.size(); i < NO_JOINTS; i++) {
        double q[numPoints];
        for (int j = 0; j < numPoints; j++) {
            q[j] = jointspaceStates.at(j).q[i];
        }
        jointspaceSpline.polynomials[i] = TrajectoryGenerator::cubic_spline(q, jointspaceSpline.times.data(), numPoints);
    }

    return jointspaceSpline;
}

double TrajectoryGenerator::evaluate_cubic_polynomial(cubic_polynomial cubicPolynomial, time_tt time) {
    return cubicPolynomial.coefficients[0] + cubicPolynomial.coefficients[1] * time + cubicPolynomial.coefficients[2] * time * time + cubicPolynomial.coefficients[3] * time * time * time;
}
double TrajectoryGenerator::evaluate_cubic_polynomial_first_derivative(cubic_polynomial cubicPolynomial, time_tt time) {
    return cubicPolynomial.coefficients[1] + 2 * cubicPolynomial.coefficients[2] * time + 3 * cubicPolynomial.coefficients[3] * time * time;
}
double TrajectoryGenerator::evaluate_cubic_polynomial_second_derivative(cubic_polynomial cubicPolynomial, time_tt time) {
    return 2 * cubicPolynomial.coefficients[2] + 6 * cubicPolynomial.coefficients[3] * time;
}

//Generate and store the trajectory spline into the trajectory object
void TrajectoryGenerator::generateAndSaveSpline(jointspace_state initialJointspaceState) {
    trajectoryJointSpline = compute_trajectory_spline(trajectoryParameter, pilotParameter, initialJointspaceState);
}

/**********************************************************************

Functions for Controller

**********************************************************************/

/**
 *
 * @param initialTaskspaceState
 * @param trajectoryParameters
 * @param pilotParameters
 * @return Vector of key taskspace_states of the trajectory (excluding initial state)
 */

// Generates trajectory spline from parameters to use in control system
TrajectoryGenerator::jointspace_spline TrajectoryGenerator::compute_trajectory_spline(const TrajectoryParameters &trajectoryParameters,
                                                                                      const pilot_parameters &pilotParameters,
                                                                                      jointspace_state initialJointspaceState) {
    Foot stanceFoot = trajectoryParameters.stance_foot;
    taskspace_state initialTaskspaceState;
    vector<taskspace_state> taskspaceStates;
    vector<jointspace_state> jointspaceStates;
    jointspace_spline jointspaceSpline;

    initialTaskspaceState = jointspace_state_to_taskspace_state(initialJointspaceState, trajectoryParameters, pilotParameters);

    // Obtain key taskspace states
    //  (output excludes initial state which is already known in jointspace)
    taskspaceStates = generate_key_taskspace_states(initialTaskspaceState, trajectoryParameters, pilotParameters);

    // Convert key states to jointspace (prepend known initial jointspace state)
    jointspaceStates = taskspace_states_to_jointspace_states(initialJointspaceState, taskspaceStates, trajectoryParameters, pilotParameters);

    // Calculate the spline for the given jointspacestates
    jointspaceSpline = cubic_spline_jointspace_states(jointspaceStates);

    return jointspaceSpline;
}

//get the velocity at any given time
void TrajectoryGenerator::calcVelocity(time_tt time, double *velocityArray) {
    TrajectoryGenerator::time_tt startTime = trajectoryJointSpline.times.front();
    TrajectoryGenerator::time_tt endTime = trajectoryJointSpline.times.back();
    // Every sample time, compute the value of q1 to q6 based on the time segment / set of NO_JOINTS polynomials
    int numPoints = trajectoryJointSpline.times.size();
    int numPolynomials = numPoints - 1;
    cubic_polynomial currentPolynomial[NO_JOINTS];
    jointspace_state_ex temp{};
    for (int polynomial_index = 0; polynomial_index < numPolynomials; polynomial_index++) {
        //cout << "[discretise_spline]: pt " << polynomial_index << ":" << endl;
        //if the jointspaceState time is bounded by the section of spline
        if (time >= trajectoryJointSpline.times.at(polynomial_index) &&
            time <= trajectoryJointSpline.times.at(polynomial_index + 1)) {
            //cout << "time " << time << "\t" << trajectoryJointSpline.times.at(polynomial_index)  << endl;
            for (int i = 0; i < NO_JOINTS; i++) {
                currentPolynomial[i] = trajectoryJointSpline.polynomials[i].at(polynomial_index);
                temp.qd[i] = evaluate_cubic_polynomial_first_derivative(currentPolynomial[i], time);
                velocityArray[i] = temp.qd[i];
            }
            return;
        }
    }
    //cout << "[discretise_spline]:\t" << temp.time << "\t";
    //if the time point is outside range
    for (int i = 0; i < NO_JOINTS; i++) {
        currentPolynomial[i] = trajectoryJointSpline.polynomials[i].at(numPolynomials - 1);
        temp.qd[i] = evaluate_cubic_polynomial_first_derivative(currentPolynomial[i], endTime);
        velocityArray[i] = temp.qd[i];
    }
}

//get the position at any given time
void TrajectoryGenerator::calcPosition(time_tt time, double *positionArray) {
    //cout << "[discretise_spline]: Discretised TrajectoryGenerator:" << endl;

    // Discretise/Sample the spline

    TrajectoryGenerator::time_tt startTime = trajectoryJointSpline.times.front();
    TrajectoryGenerator::time_tt endTime = trajectoryJointSpline.times.back();
    // Every sample time, compute the value of q1 to q6 based on the time segment / set of NO_JOINTS polynomials
    int numPoints = trajectoryJointSpline.times.size();
    int numPolynomials = numPoints - 1;
    cubic_polynomial currentPolynomial[NO_JOINTS];
    //if the time point is inside range
    for (int polynomial_index = 0; polynomial_index < numPolynomials; polynomial_index++) {
        //cout << "[discretise_spline]: pt " << polynomial_index << ":" << endl;
        //if the jointspaceState time is bounded by the section of spline
        if (time >= trajectoryJointSpline.times.at(polynomial_index) &&
            time <= trajectoryJointSpline.times.at(polynomial_index + 1)) {
            //cout << "time " << time << "\t" << trajectoryJointSpline.times.at(polynomial_index)  << endl;trajectory_parametersnt i = 0; i < NO_JOINTS; i++) {
            {
                currentPolynomial[i] = trajectoryJointSpline.polynomials[i].at(polynomial_index);
                positionArray[i] = evaluate_cubic_polynomial(currentPolynomial[i], time);
            }
        }
        ////force ankles to be in the final position
        //currentPolynomial[LEFT_ANKLE] = trajectoryJointSpline.polynomials[LEFT_ANKLE].at(numPolynomials - 1);
        //positionArray[LEFT_ANKLE] = evaluate_cubic_polynomial(currentPolynomial[LEFT_ANKLE], endTime);
        //currentPolynomial[RIGHT_ANKLE] = trajectoryJointSpline.polynomials[RIGHT_ANKLE].at(numPolynomials - 1);
        //positionArray[RIGHT_ANKLE] = evaluate_cubic_polynomial(currentPolynomial[RIGHT_ANKLE], endTime);
        //make sure the angles are within boundary
        limit_position_against_angle_boundary(positionArray);
        return;
    }
}
//cout << "[discretise_spline]:\t" << temp.time << "\t";
//if the time point is outside range
for (int i = 0; i < NO_JOINTS; i++) {
    currentPolynomial[i] = trajectoryJointSpline.polynomials[i].at(numPolynomials - 1);
    positionArray[i] = evaluate_cubic_polynomial(currentPolynomial[i], endTime);
}
//make sure the angles are within boundary
limit_position_against_angle_boundary(positionArray);
}
TrajectoryGenerator::jointspace_state TrajectoryGenerator::compute_position_trajectory_difference(
    jointspace_spline jointspaceSpline,
    jointspace_state currentJointspaceStates) {
    jointspace_state position_diff;
    cubic_polynomial currentPolynomial[NO_JOINTS];
    int numPoints = jointspaceSpline.times.size();
    int numPolynomials = numPoints - 1;
    time_tt endTime = jointspaceSpline.times.back();
    jointspace_state splinePosition;

    // Get the target position based on time and spline
    // If the time is past the spline time range,
    // Calculate the diff based on last position in spline
    if (currentJointspaceStates.time >= jointspaceSpline.times.back()) {
        for (int i = 0; i < NO_JOINTS; i++) {
            currentPolynomial[i] = jointspaceSpline.polynomials[i].at(numPolynomials - 1);
        }
        // calculate the position difference at each joint
        for (int i = 0; i < NO_JOINTS; i++) {
            splinePosition.q[i] = evaluate_cubic_polynomial(currentPolynomial[i], endTime);
            position_diff.q[i] = currentJointspaceStates.q[i] - splinePosition.q[i];
        }
        position_diff.time = currentJointspaceStates.time;
        return position_diff;
    }
    // Else, find the relevant section in spline and calculate the position difference

    else {
        for (int polynomial_index = 0; polynomial_index < numPolynomials; polynomial_index++) {
            //cout << "[discretise_spline]: pt " << polynomial_index << ":" << endl;
            //if the jointspaceState time is bounded by the section of spline
            if (currentJointspaceStates.time >= jointspaceSpline.times.at(polynomial_index) &&
                currentJointspaceStates.time <= jointspaceSpline.times.at(polynomial_index + 1)) {
                // capture the polynomial for the current spline
                for (int i = 0; i < NO_JOINTS; i++) {
                    currentPolynomial[i] = jointspaceSpline.polynomials[i].at(polynomial_index);
                    splinePosition.q[i] = evaluate_cubic_polynomial(currentPolynomial[i], currentJointspaceStates.time);
                    position_diff.q[i] = currentJointspaceStates.q[i] - splinePosition.q[i];
                }
                //set up the position time to prevent weird behavior
                position_diff.time = currentJointspaceStates.time;
                return position_diff;
            }
        }
    }
    // return error if none of the above case return anything
    cout << "[compute_position_trajectory_difference] Error: Cannot find the time region in the spline" << endl;
    cout << "[compute_position_trajectory_difference] Assuming no position tracking error" << endl;
    for (int i = 0; i < NO_JOINTS; i++) {
        position_diff.q[i] = 0;
    }
    //set up the position time to prevent weird behavior
    position_diff.time = currentJointspaceStates.time;
    return position_diff;
}

// Limiting the velocity control to not pushing against angle limit
// use AFTER the current velocity is added to the control velocity
void TrajectoryGenerator::limit_velocity_against_angle_boundary(
    jointspace_state currentJointspaceStates,
    double *velocitySignal) {
    for (int i = 0; i < NO_JOINTS; i++) {
        int minIndex = i * 2;
        int maxIndex = i * 2 + 1;
        //if we near the boundary and velocity is pushing towards it
        if ((currentJointspaceStates.q[i] < Q_MIN_MAX[minIndex] &&
             velocitySignal < 0) ||
            (currentJointspaceStates.q[i] > Q_MIN_MAX[maxIndex] &&
             velocitySignal > 0)) {
            velocitySignal = 0;
        }
    }
}

//limiting the position array in trajectory class
void TrajectoryGenerator::limit_position_against_angle_boundary(double positionArray[]) {
    for (int i = 0; i < NO_JOINTS; i++) {
        int minIndex = i * 2;
        int maxIndex = i * 2 + 1;
        /*cout << "position is" << positionArray[i] << "Q MIN MAX ARE "
			<< Q_MIN_MAX[minIndex] << " " << Q_MIN_MAX[maxIndex] << endl;*/
        //if we at the boundary
        if (positionArray[i] < Q_MIN_MAX[minIndex]) {
            positionArray[i] = Q_MIN_MAX[minIndex];
        }
        if (positionArray[i] > Q_MIN_MAX[maxIndex]) {
            positionArray[i] = Q_MIN_MAX[maxIndex];
        }
        if (std::isnan(positionArray[i])) {
            cout << "ISNAN now " << endl;
            positionArray[i] = Q_MIN_MAX[maxIndex] + 10000;
        }
    }
}

void TrajectoryGenerator::getVelocityAfterPositionCorrection(
    time_tt time, double *robotPositionArray, double *velocityArray) {
    double splinePositionArray[NO_JOINTS];
    double positionDiff[NO_JOINTS];
    double positionFeedback[NO_JOINTS];
    const double FEEDBACKGAIN = 1;
    calcPosition(time, splinePositionArray);
    //the spline position array is in radian, trajectory object perspective jointspace
    //so the robot position array also needs to be converted to trajectory jointspace, numbering and radian
    for (int i = 0; i < NO_JOINTS; i++) {
        positionDiff[i] = splinePositionArray[i] - robotPositionArray[i];
    }
    //the feedback gain part
    calcVelocity(time, velocityArray);
    for (int i = 0; i < NO_JOINTS; i++) {
        velocityArray[i] += FEEDBACKGAIN * positionDiff[i];
    }
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
void TrajectoryGenerator::setTrajectoryStanceRight() {
    trajectoryParameter.stance_foot = Foot::Right;
}
void TrajectoryGenerator::setTrajectoryStanceLeft() {
    trajectoryParameter.stance_foot = Foot::Left;
}
void TrajectoryGenerator::setTrajectoryParameter(TrajectoryParameters trajectoryParameter) {
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

double TrajectoryGenerator::getStepDuration() {
    return trajectoryParameter.step_duration;
}
