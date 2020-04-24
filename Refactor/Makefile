# Makefile for Tests
# CXX - defines the compiler. 
# Currently uses the cross-compiler for the BBB (could be modified to run on Windows PC if desired)
CXX := arm-linux-gnueabihf-g++
LD  := arm-linux-gnueabihf-g++

# CXXFLAGS - flags for the compilation 
# -std=c++11 - uses C++11 standard (>>>>>>>WHY?>>>>>>>)
# -lncurses - used for keyboard input
# CXXFLAGS = $(INCLUDES) 
CXXFLAGS := -std=c++11 
# LINKFLAGS - flags for linking the objects
# Used to include the libraries in the executable (originally added for GLIBCXX strings)
LINKFLAGS := -static

#Define header directories 
# note: we use variable := imediate expansion.
MODULES   := apps apps/stateMachine apps/stateMachine/states tests libs libs/inputDevice libs/robot libs/robot/joint libs/stateMachine
# automatically create list of module file paths
SRC_DIR	  := $(addprefix src/,$(MODULES))
BUILD_DIR := $(addprefix build/,$(MODULES))
# Expand all SRC files from SRC_DIR
SRC		  := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
# Create list of all desired .o files from SRC files in listed MODULES
OBJ       := $(patsubst src/%.cpp,build/%.o,$(SRC))
# Tell compiler where to find all source files
INCLUDES  := $(addprefix -I,$(SRC_DIR))
TARGET   := program
VPATH =
# Provide search path to make for targets or prerequisites.
# List of Objects required in each testing program
# OBJOINT = testJoints.o Drive.o Joint.o ActuatedJoint.o CopleyDrive.o DummyActJoint.o
# OBROBOT = testRobot.o Robot.o ExoRobot.o TrajectoryGenerator.o Drive.o Joint.o ActuatedJoint.o CopleyDrive.o DummyActJoint.o InputDevice.o Keyboard.o
# OBDRIVE = testDrives.o Drive.o CopleyDrive.o
# how to make any filestem
define make-goal
$1/%.o: $(subst build,src,$1)/%.cpp
	$(CXX) $(CXXFLAGS)$(INCLUDES) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs build/test

build/test: $(OBJ)
	$(LD) $^ -o $@

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

# 
$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))

# all : testJoints testRobot testDrives

# testJoints: $(OBJ)
# 	$(CXX)  $(LINKFLAGS)  -o $@ $^ 
# testRobot: $(OBJ)
# 	$(CXX) $(LINKFLAGS)  -o $@ $^ 
# testDrives: $(OBJ)
# 	$(CXX) $(LINKFLAGS)  -o $@ $^ 

	
# .PHONY: clean all

# clean:
# 	rm -f $(OBJ) 