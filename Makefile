# Makefile for ALEX_APP.

#SSH parameters
SSH_IP_ADDR=192.168.7.2
SSH_USER=debian

# Source Folders
SRC_DIR =  src
CAN_DIR = src/CANopenNode
STACK_DIR = src/CANopenNode/stack
SOCKETCAN_DIR = src/CANopenNode/stack/socketCAN
OD_DIR = src/objDict
ROBOT_DIR = src/robot
SM_DIR = src/stateMachine
EIGEN_DIR0 = src/robot/Eigen
STATE_DIR= src/stateMachine/states


TARGET_FOLDER = bin/
LINK_TARGET  =  $ EXO_APP

INCLUDE_DIRS = 	-I$(SRC_DIR) \
				-I$(CAN_DIR)    \
				-I$(STACK_DIR)  \
				-I$(SOCKETCAN_DIR)  \
				-I$(OD_DIR) \
				-I$(ROBOT_DIR) \
				-I$(SM_DIR)	\
				-I$(EIGEN_DIR0) \
				-I$(STATE_DIR)

SOURCES =   $(wildcard src/*.c) $(wildcard src/*/*.c) $(wildcard src/*/*/*.c) $(wildcard src/*/*/*/*.c)
CPPSOURCES =  $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp)

# canopend is three-threaded application: nonblocking mainline, nonblocking
# rt-thread and blocking command interface thread.
# If there is a need to compile canopend as a single-threaded application, then:
#   - Command interface is not possible, so remove CO_command.c,
#     CO_comm_helpers.c, CO_master.c (and CO_SDOmaster.c) from SOURCES.
#   - Add flag -DCO_SINGLE_THREAD to the CFLAGS.
#   - Remove flag -pthread from LDFLAGS.
# Flag -lrt in LDFLAGS is necessary only with older kernels.

OBJS = $(SOURCES:%.c=%.o) $(CPPSOURCES:%.cpp=%.o)

#CC = g++
#CFLAGS =  -std=c++11  -g $(INCLUDE_DIRS)
#LDFLAGS = -lrt -pthread
#O3 is optimization v3 flag -> for EIGEN calculations
CC = arm-linux-gnueabihf-gcc
CXX = arm-linux-gnueabihf-g++
CXXFLAGS = -std=c++11 -O3 $(INCLUDE_DIRS)
LDFLAGS = -lpthread 

$(LINK_TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean all

all: clean $(LINK_TARGET)

clean:
	rm -f $(OBJS) $(OBJSCPP) $(LINK_TARGET)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
upload: $(LINK_TARGET)
	scp $(LINK_TARGET) $(SSH_USER)@$(SSH_IP_ADDR):~/$(LINK_TARGET)

	