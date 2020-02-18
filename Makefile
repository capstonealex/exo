robotTestMake: ALEX/src/robot/trajectory.cpp robottest.cpp
	arm-linux-gnueabihf-g++ -I  ALEX/src/robot/eigen -I ALEX/src/robot -std=c++11 ALEX/src/robot/trajectory.cpp  robottest.cpp -o SAM_TEST	