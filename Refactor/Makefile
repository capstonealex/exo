# Makefile for Tests
#Define header directories

#Define Compiler (could be modified to run on Windows PC if desired)
CXX = arm-linux-gnueabihf-g++
CXXFLAGS = -std=c++11 -O3 

# List of Objects to be defined for the testing
OBJOINT = testJoints.o Drive.o Joint.o ActuatedJoint.o CopleyDrive.o DummyActJoint.o
OBROBOT = testRobot.o Robot.o ExoRobot.o TrajectoryGenerator.o spline.o Drive.o Joint.o ActuatedJoint.o CopleyDrive.o TestActJoint.o
%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

testJoints: $(OBJOINT)
	$(CXX) -o $@ $^ 
testRobot: $(OBROBOT)
	$(CXX) -o $@ $^ 
	
.PHONY: clean all

clean:
	rm -f $(OBJOINT) $(OBROBOT)
