#include <TrajectoryParams.h>

#include <fstream>
#include <iomanip>
#include <iostream>;
//TODO: (1) convert from JSON to "arbitrary type" trajectory paramaters
//      (2) Read in trajparam.json into trajectory param single object
//      (3) Read in multiple into traj param map

int main() {
    std::ifstream file("testParamD.json");
    if (!file) {
        throw std::runtime_error{"Unable to open robot config json: "};
    }

    nlohmann::json config;
    file >> config;
    // write prettified JSON to another file
    // std::ofstream o("pretty.json");
    // o << std::setw(4) << j << std::endl;
    std::vector<std::unique_ptr<TrajectoryParams>> t_params;
    for (auto const& paramJSON : config.at("movements")) {
        t_params.push_back(std::make_unique<TrajectoryParams>(paramJSON));
    }

    TrajectoryParams test = config;
    std::cout << "TrajectoryParams from parsed JSON into new object ";
    test.printTraj();
    // nlohmann::json tp = s;
    // std::cout << "TrajectoryParams from object: ";
    // s.printTraj();
    // std::cout << tp << std::endl;
    // //String
    // std::string jSt = tp.dump();  //{"id":0,"name":"x"}
    // TrajectoryParams s2 = tp;
    // TrajectoryParams s3 = nlohmann::json::parse(jSt);
    // std::cout << "TrajectoryParams from parsed JSON into new object ";
    // s2.printTraj();
    // convert json -> traj params.....
}
