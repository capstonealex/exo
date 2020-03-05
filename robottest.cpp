//
//Test function for running trajectory before testing it on the exo
//It will run all the trajectory combination, if there is a trajectory output
//that is a Nan, it will show a warning
//By Samuel Wong


#include "Trajectory.h"
#include "time.h"
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>
// For logging
#include <iostream>
#include <fstream>

/**
 * Author: Dillon Chong
 * Date: 29 Sep 2019
 *
 * Editor: Samuel Wong
 * Date: 09/02/2020
 * compiled using make or arm-linux-gnueabihf-g++ -I eigen -std=c++11 robottest.cpp trajectory.cpp -o SAM_TEST
 * Trajectory Generator for walking State Machine (for now)
 * Please refer to the notes on Trajectory.cpp
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

#include <iomanip>

double fRand(double fMin, double fMax);
bool plotPoints(std::ofstream& logfile, Trajectory trajectoryObject);

int main(int argc, char** argv) {

	ofstream logfile;

	cout << "hello world" << endl;
	cout << "Begin Trajectory Generation." << endl;

	cout << "Argument count: " << argc << endl
		<< "Arguments: {" << endl;
	for (int i = 0; i < argc; i++)
		cout << argv[i] << endl;
	cout << "}" << endl;

	// setting the precision for better layout
	std::cout << std::setprecision(3);
	Trajectory trajectoryObject;
	vector<Trajectory::jointspace_state_ex> trajectory;
	Trajectory::jointspace_state walkJointspaceState;
	Trajectory::jointspace_state sitJointspaceState;
	Trajectory::jointspace_state standJointspaceState;	
	Trajectory::jointspace_state unevenJointspaceState;

	double previousPosArray[NO_JOINTS];

	bool isProblem = false;
	//	trajectory =
	//		trajectoryObject.compute_discrete_trajectory(walk_parameters, brad_parameters, currentJointspaceState);
	//}
	Trajectory::trajectory_parameters step_together_parameters = {
	.step_duration = 1,
	.step_height = STEPHEIGHT,
	.step_length = 0,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Right,
	.movement = Trajectory::Movement::Walk,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.0, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};
	Trajectory::trajectory_parameters walk_parameters = {
	.step_duration = 1,
	.step_height = STEPHEIGHT,
	.step_length = STEPLENGTH,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Right,
	.movement = Trajectory::Movement::Walk,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.0, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};
	Trajectory::trajectory_parameters stand_parameters = {
	.step_duration = 1,
	.step_height = STEPHEIGHT,
	.step_length = STEPLENGTH,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Right,
	.movement = Trajectory::Movement::Stand,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.0, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};
	Trajectory::trajectory_parameters sit_parameters = {
	.step_duration = 1,
	.step_height = STEPHEIGHT,
	.step_length = STEPLENGTH,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Right,
	.movement = Trajectory::Movement::Sit,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.0, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};
	Trajectory::trajectory_parameters long_walk_parameters = {
	.step_duration = 1,
	.step_height = STEPHEIGHT,
	.step_length = LONGSTEPLENGTH,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Right,
	.movement = Trajectory::Movement::Walk,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.0, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};

	Trajectory::trajectory_parameters half_walk_parameters = {
	.step_duration = 1,
	.step_height = STEPHEIGHT,
	.step_length = HALFSTEPLENGTH,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Right,
	.movement = Trajectory::Movement::Walk,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.0, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};

	Trajectory::trajectory_parameters high_walk_parameters = {
	.step_duration = 1,
	.step_height = STEPHIGH,
	.step_length = STEPLENGTH,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Right,
	.movement = Trajectory::Movement::Walk,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.0, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};

	Trajectory::trajectory_parameters back_parameters = {
	.step_duration = 1,
	.step_height = STEPHEIGHT,
	.step_length = BACKLENGTH,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Left,
	.movement = Trajectory::Movement::Back,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.0, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};
	Trajectory::trajectory_parameters backstand_parameters = {
		.step_duration = 1,
		.step_height = STEPHEIGHT,
		.step_length = 0,
		.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
		.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
		.swing_ankle_down_angle = 0,
		.stance_foot = Trajectory::Foot::Left,
		.movement = Trajectory::Movement::Back,
		.seat_height = 0.42, // sit-stand
		.step_end_height = 0.0, // stairs
		.slope_angle = 0.0,   // tilted path
		.left_foot_on_tilt = false,
		.right_foot_on_tilt = false
	};
	Trajectory::trajectory_parameters uneven_parameters = {
		.step_duration = UNEVENSTEPTIME,
		.step_height = STEPHEIGHT,
		.step_length = UNEVENSTEP,
		.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
		.torso_forward_angle = UNEVENTORSO, // TODO: make this a vector/array?
		.swing_ankle_down_angle = 0,
		.stance_foot = Trajectory::Foot::Left,
		.movement = Trajectory::Movement::Uneven,
		.seat_height = 0.42, // sit-stand
		.step_end_height = 0.0, // stairs
		.slope_angle = 0.0,   // tilted path
		.left_foot_on_tilt = false,
		.right_foot_on_tilt = false
	};
	Trajectory::trajectory_parameters stair_parameters = {
	.step_duration = 1,
	.step_height = STEPHEIGHT,
	.step_length = STEPLENGTH,
	.hip_height_slack = LEGSLACK, // never make this zero, or else it'll probably make a trig/pythag give NaN due to invalid triangle
	.torso_forward_angle = TORSOANGLE, // TODO: make this a vector/array?
	.swing_ankle_down_angle = 0,
	.stance_foot = Trajectory::Foot::Right,
	.movement = Trajectory::Movement::Stair,
	.seat_height = 0.42, // sit-stand
	.step_end_height = 0.17, // stairs
	.slope_angle = 0.0,   // tilted path
	.left_foot_on_tilt = false,
	.right_foot_on_tilt = false
	};
	Trajectory::pilot_parameters brad_parameters = {
		.lowerleg_length = 0.43,
		.upperleg_length = 0.46,
		.ankle_height = 0.12,
		.foot_length = 0.26,
		.hip_width = 0.43,
		.torso_length = 0.4,
		.buttocks_height = 0.05
	};

	trajectoryObject.setPilotParameter(brad_parameters);
	trajectoryObject.setTrajectoryParameter(walk_parameters);

	walkJointspaceState = {
		.q = { deg2rad(186),
				deg2rad(5.06),
				deg2rad(156),
				deg2rad(14.3),
				deg2rad(106),
				deg2rad(85.2)},
			.time = 0
	};
	 sitJointspaceState = {
		.q = { deg2rad(75),
				deg2rad(99.1),
				deg2rad(75.1),
				deg2rad(99),
				deg2rad(89.1),
				deg2rad(89.1)},
			.time = 0
	};

	 standJointspaceState = {
	.q = { deg2rad(179),
			deg2rad(1.72),
			deg2rad(179),
			deg2rad(1.72),
			deg2rad(89.1),
			deg2rad(89.1)},
			.time = 0
	};
	 unevenJointspaceState = {
	.q = { deg2rad(155.5),
			deg2rad(30),
			deg2rad(200),
			deg2rad(0.02),
			deg2rad(105),
			deg2rad(105)},
			.time = 0
	 };
	 stairJointspaceState = {
	.q = { deg2rad(155.5),
		deg2rad(30),
		deg2rad(200),
		deg2rad(0.02),
		deg2rad(105),
		deg2rad(105)},
		.time = 0
	 };
	//cout << "walk to stand" << endl;
	//logfile.open("TrajectoryCSV/walk to stand.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(step_together_parameters);
	//trajectoryObject.compute_discrete_trajectory(step_together_parameters, brad_parameters, walkJointspaceState);
	//trajectoryObject.generateAndSaveSpline(walkJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);


	cout << "walk to walk" << endl;
	logfile.open("TrajectoryCSV/walk to walk.csv");
	trajectoryObject.setPilotParameter(brad_parameters);
	trajectoryObject.setTrajectoryParameter(walk_parameters);
	trajectoryObject.compute_discrete_trajectory(walk_parameters, brad_parameters, walkJointspaceState);
	trajectoryObject.generateAndSaveSpline(walkJointspaceState);


 isProblem = plotPoints(logfile, trajectoryObject);


	//cout << "stand to walk" << endl;
	//logfile.open("TrajectoryCSV/stand to walk.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(walk_parameters);
	//trajectoryObject.compute_discrete_trajectory(walk_parameters, brad_parameters, standJointspaceState);
	//trajectoryObject.generateAndSaveSpline(standJointspaceState);
	//
	//isProblem = plotPoints(logfile, trajectoryObject);


	//cout << "stand to sit" << endl;
	//logfile.open("TrajectoryCSV/stand to sit.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(sit_parameters);
	//trajectoryObject.compute_discrete_trajectory(sit_parameters, brad_parameters, standJointspaceState);
	//trajectoryObject.generateAndSaveSpline(standJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);


	//cout << "sit to stand" << endl;
	//logfile.open("TrajectoryCSV/sit to stand.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(stand_parameters);
	//trajectoryObject.compute_discrete_trajectory(stand_parameters, brad_parameters, sitJointspaceState);
	//trajectoryObject.generateAndSaveSpline(sitJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);


	//cout << "walk to long walk" << endl;
	//logfile.open("TrajectoryCSV/walk to long walk.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(long_walk_parameters);
	//trajectoryObject.compute_discrete_trajectory(long_walk_parameters, brad_parameters, walkJointspaceState);
	//trajectoryObject.generateAndSaveSpline(walkJointspaceState);


 //isProblem = plotPoints(logfile, trajectoryObject);


	//cout << "walk to half walk" << endl;
	//logfile.open("TrajectoryCSV/walk to half walk.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(half_walk_parameters);
	//trajectoryObject.compute_discrete_trajectory(half_walk_parameters, brad_parameters, walkJointspaceState);
	//trajectoryObject.generateAndSaveSpline(walkJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);


	//cout << "walk to high walk" << endl;
	//logfile.open("TrajectoryCSV/walk to high walk.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(high_walk_parameters);
	//trajectoryObject.compute_discrete_trajectory(high_walk_parameters, brad_parameters, walkJointspaceState);
	//trajectoryObject.generateAndSaveSpline(walkJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);


	//cout << "walk to back" << endl;
	//logfile.open("TrajectoryCSV/walk to back.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(back_parameters);
	//trajectoryObject.compute_discrete_trajectory(back_parameters, brad_parameters, walkJointspaceState);
	//trajectoryObject.generateAndSaveSpline(walkJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);


	//cout << "stand to back" << endl;
	//logfile.open("TrajectoryCSV/stand to back.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(back_parameters);
	//trajectoryObject.compute_discrete_trajectory(back_parameters, brad_parameters, standJointspaceState);
	//trajectoryObject.generateAndSaveSpline(standJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);

	//cout << "back to stand" << endl;
	//logfile.open("TrajectoryCSV/back to stand.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(backstand_parameters);
	//trajectoryObject.compute_discrete_trajectory(backstand_parameters, brad_parameters, walkJointspaceState);
	//trajectoryObject.generateAndSaveSpline(walkJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);

	//cout << "walk to uneven" << endl;
	//logfile.open("TrajectoryCSV/walk to uneven.csv");
	//trajectoryObject.setPilotParameter(brad_parameters);
	//trajectoryObject.setTrajectoryParameter(uneven_parameters);
	//trajectoryObject.compute_discrete_trajectory(uneven_parameters, brad_parameters, unevenJointspaceState);
	//trajectoryObject.generateAndSaveSpline(unevenJointspaceState);

 //isProblem = plotPoints(logfile, trajectoryObject);

	cout << "walk to stair" << endl;
	logfile.open("TrajectoryCSV/walk to stair.csv");
	trajectoryObject.setPilotParameter(brad_parameters);
	trajectoryObject.setTrajectoryParameter(stair_parameters);
	trajectoryObject.compute_discrete_trajectory(stair_parameters, brad_parameters, walkJointspaceState);
	trajectoryObject.generateAndSaveSpline(walkJointspaceState);


isProblem = plotPoints(logfile, trajectoryObject);
	if (isProblem == true) {
		cout << "THERE IS A PROBLEM!!!! " << endl;
		cout << "THERE IS A PROBLEM!!!! " << endl;
		cout << "THERE IS A PROBLEM!!!! " << endl;
		cout << "THERE IS A PROBLEM!!!! " << endl;
		cout << "THERE IS A PROBLEM!!!! " << endl;

	}
	//for (double time = 0; time < 1.01; time += 0.05) {
	//	trajectoryObject.calcPosition(time, positionArray);
	//	trajectoryObject.calcPosition(time-0.05, previousPosArray);
	//	cout << "[get velocity values from saved spline]: time " << time << " ";
	//	for (int i = 0; i < NO_JOINTS; i++) {
	//		cout << rad2deg(positionArray[i] - previousPosArray[i]) << "\t";
	//	}
	//	cout << endl;
	//}

	
	logfile.close();


	return 0;
}
double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
bool plotPoints(std::ofstream& logfile, Trajectory trajectoryObject) {
	bool isProblem = false;
	double positionArray[NO_JOINTS];
	for (double time = 0; time < 1.01; time += 0.05) {
		trajectoryObject.calcPosition(time, positionArray);
		cout << "[get position values from saved spline]: time " << time << " ";
		logfile << time << ",";
		for (auto pos : positionArray) {
			cout << rad2deg(pos) << "\t";
			logfile << rad2deg(pos) << ",";
			if (isnan(pos)) {
				isProblem = true;
			}
		}
		cout << endl;
		logfile << endl;
	}
	logfile.close();
	return isProblem;
}