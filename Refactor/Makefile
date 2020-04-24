# Makefile for Tests
# CXX - defines the compiler. 
# Currently uses the cross-compiler for the BBB (could be modified to run on Windows PC if desired)
CXX := arm-linux-gnueabihf-g++
LD  := arm-linux-gnueabihf-g++

# CXXFLAGS - flags for the compilation 
# -std=c++11 - uses C++11 standard
CXXFLAGS := -std=c++11 

# LINKFLAGS - flags for linking the objects
# -static used to include the libraries in the executable (originally added for GLIBCXX strings)
LINKFLAGS := -static

#Define header directories 
MODULES   := apps apps/stateMachine apps/stateMachine/states libs libs/inputDevice libs/robot libs/robot/joint libs/stateMachine

# automatically create list of module file paths NOT including executables
SRC_DIR	  := $(addprefix src/,$(MODULES))

# Objects from the sources, plus the executables
BUILD_DIR := $(addprefix build/,$(MODULES)) build/tests

# Expand all SRC files from SRC_DIR
SRC		  := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))

# Create list of all desired .o files from SRC files in listed MODULES (NOT including Executables)
OBJ       := $(patsubst src/%.cpp,build/%.o,$(SRC))

# List of Test Programs (Executables)
TESTS	:= testDrives testJoints testRobot testSM

# Test Program Objects and executables
TESTOBJS := $(addsuffix .o, $(addprefix build/tests/,$(TESTS))) 
TESTEXE := $(addprefix build/,$(TESTS))

# Tell compiler where to find all source files
INCLUDES  := $(addprefix -I,$(SRC_DIR))
VPATH = 

# Define a macro which defines a Make Rule for all files in all Source Directories 
define make-goal
$1/%.o: $(subst build,src,$1)/%.cpp
	$(CXX) $(CXXFLAGS)$(INCLUDES) -c $$< -o $$@	
endef

# Define a macro which defines a Make Rule to link tests together
define make-tests
$1: build/tests/$1.o $(OBJ)
	$(LD) $(LINKFLAGS) $$^  -o build/$$@
endef

# Call the previously defined macros
$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))
$(foreach test,$(TESTS),$(eval $(call make-tests,$(test))))

.PHONY: all checkdirs clean

all: checkdirs $(TESTS)

test:
	echo '$(BUILD_DIR)'

checkdirs: $(BUILD_DIR)

# On Windows - Substitute with command at end of file for UNIX-based systems
$(BUILD_DIR):
	@mkdir $(subst /,\\,$@)

clean:
	@rm -rf $(OBJ) $(TESTOBJS) $(TESTEXE) $(BUILD_DIR)


# On Linux
# $(BUILD_DIR):
	# @mkdir -p $@
