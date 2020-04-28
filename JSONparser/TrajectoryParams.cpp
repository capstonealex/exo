#include "TrajectoryParams.h"

#include <iostream>
#include <string>

TrajectoryParams::TrajectoryParams() {
}

// TrajectoryParams::TrajectoryParams(Movement mv, time_tt stp_dur, double step_h, Foot stance) {
//     test.movement = mv;
//     test.step_duration = stp_dur;
//     test.step_height = step_h;
//     test.stance_foot = stance;
// }

int TrajectoryParams::getId() const {
    return this->m_id;
}

void TrajectoryParams::setId(int newId) {
    m_id = newId;
}

std::string TrajectoryParams::getName() const {
    return this->m_name;
}

void TrajectoryParams::setName(const std::string &newName) {
    this->m_name = newName;
}
void TrajectoryParams::printTraj() {
    std::cout << "step height: " << std::endl
              << test.step_height << std::endl
              << " step dur: " << test.step_duration << std::endl;
}