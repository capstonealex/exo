# Makefile for Tests

#Define Compiler (could be modified to run on Windows PC if desired)
CXX = arm-linux-gnueabihf-g++

# List of Objects to be defined for the testing
OBJ = testJoints.o Drive.o Joint.o ActuatedJoint.o CopleyDrive.o TestActJoint.o

%.o: %.cpp 
	$(CXX) -c -o $@ $< 

testJoints: $(OBJ)
	$(CXX) -o $@ $^ 
	
.PHONY: clean all

clean:
	rm -f $(OBJ)
