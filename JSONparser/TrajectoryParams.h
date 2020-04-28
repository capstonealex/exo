#ifndef TRAJECTORY_PARAMS_H
#define TRAJECTORY_PARAMS_H

#include <string>
#include <vector>

#include "json.hpp"

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
typedef double time_tt;

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

class TrajectoryParams {
   public:
    TrajectoryParams();
    int getId() const;
    void setId(int newId);
    trajectory_parameters test;
    // vector<trajectory_parameters> t_params;
    std::string
    getName() const;
    void setName(const std::string &newName);
    void printTraj();

   private:
    int m_id;
    std::string m_name;
};

//json serialization
inline void to_json(nlohmann::json &j, const TrajectoryParams &s) {
    j["name"] = s.getName();
    j["step_duration"] = s.test.step_duration;
    j["step_height"] = s.test.step_height;
    j["step_length"] = s.test.step_length;
    j["hip_height_slack"] = s.test.hip_height_slack;
    j["torso_forward_angle"] = s.test.torso_forward_angle;
    j["swing_ankle_down_angle"] = s.test.swing_ankle_down_angle;
    j["stance_foot"] = s.test.stance_foot;
    j["movement"] = s.test.movement;
    j["seat_height"] = s.test.seat_height;
    j["step_end_height"] = s.test.step_end_height;
    j["slope_angle"] = s.test.slope_angle;
    j["left_foot_on_tilt"] = s.test.left_foot_on_tilt;
    j["right_foot_on_tilt"] = s.test.right_foot_on_tilt;
}

inline void from_json(const nlohmann::json &j, TrajectoryParams &s) {
    // s.setId((j.at("id").get<int>()));
    s.setName(j.at("name").get<std::string>());
    j.at("step_duration").get_to(s.test.step_duration);
    j.at("step_height").get_to(s.test.step_height);
    j.at("step_length").get_to(s.test.step_length);
    j.at("hip_height_slack").get_to(s.test.hip_height_slack);
    j.at("torso_forward_angle").get_to(s.test.torso_forward_angle);
    j.at("swing_ankle_down_angle").get_to(s.test.swing_ankle_down_angle);
    j.at("stance_foot").get_to(s.test.stance_foot);
    j.at("movement").get_to(s.test.movement);
    j.at("seat_height").get_to(s.test.seat_height);
    j.at("step_end_height").get_to(s.test.step_end_height);
    j.at("slope_angle").get_to(s.test.slope_angle);
    j.at("left_foot_on_tilt").get_to(s.test.left_foot_on_tilt);
    j.at("right_foot_on_tilt").get_to(s.test.right_foot_on_tilt);
}
#endif  // STUDENT_H
