# Makefile for Tests
#Define header directories

#Define Compiler (could be modified to run on Windows PC if desired)
CXX = arm-linux-gnueabihf-g++
CXXFLAGS = -std=c++11 

# List of Objects to be defined for the testing
OBJOINT = testJoints.o Drive.o Joint.o ActuatedJoint.o CopleyDrive.o DummyActJoint.o
OBROBOT = testRobot.o Robot.o ExoRobot.o TrajectoryGenerator.o Drive.o Joint.o ActuatedJoint.o CopleyDrive.o Buttons.o DummyActJoint.o
OBDRIVE = testDrives.o Drive.o CopleyDrive.o

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

testJoints: $(OBJOINT)
	$(CXX) -o $@ $^ 
testRobot: $(OBROBOT)
	$(CXX) -o $@ $^ 
testDrives: $(OBDRIVE)
	$(CXX) -o $@ $^ 
	
.PHONY: clean all

clean:
	rm -f $(OBJOINT) $(OBROBOT) $(OBDRIVE)
