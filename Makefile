robotTestMake: ALEX/src/robot/trajectory.cpp robottest.cpp
	arm-linux-gnueabihf-g++ -isystem  ALEX/src/robot/eigen -isystem   ALEX/src/robot -std=c++11 ALEX/src/robot/trajectory.cpp  robottest.cpp -o SAM_TEST	

gccmake : ALEX/src/robot/trajectory.cpp robottest.cpp
	g++ -isystem  ALEX/src/robot/eigen -isystem   ALEX/src/robot -std=c++11 ALEX/src/robot/trajectory.cpp  robottest.cpp -o SAM_TEST	
