# Makefile for CANopend.
# This version of the Makefile compiles c code anc pp seperatly and links them with g++

STACKDRV_SRC =  ../CANopenNode/stack/socketCAN
STACK_SRC =     ../CANopenNode/stack
CANOPEN_SRC =   ../CANopenNode
CANOPEND_SRC =  ./src
OBJ_DICT_SRC =  ./objDict
APP_SRC =       ./app
ALEX_SRC = ./
ROBOT_SRC = ./robot

LINK_TARGET  =  $(APP_SRC)/canopend


INCLUDE_DIRS = -I$(STACKDRV_SRC) \
               -I$(STACK_SRC)    \
               -I$(CANOPEN_SRC)  \
               -I$(CANOPEND_SRC) \
               -I$(OBJ_DICT_SRC) \
               -I$(APP_SRC)

CPP_INCLUDE_DIRS = -I$(ROBOT_SRC)

SOURCES =       $(STACKDRV_SRC)/CO_driver.c         \
                $(STACKDRV_SRC)/CO_OD_storage.c     \
                $(STACKDRV_SRC)/CO_Linux_tasks.c    \
                $(STACK_SRC)/crc16-ccitt.c          \
                $(STACK_SRC)/CO_SDO.c               \
                $(STACK_SRC)/CO_Emergency.c         \
                $(STACK_SRC)/CO_NMT_Heartbeat.c     \
                $(STACK_SRC)/CO_SYNC.c              \
                $(STACK_SRC)/CO_PDO.c               \
                $(STACK_SRC)/CO_HBconsumer.c        \
                $(STACK_SRC)/CO_SDOmaster.c         \
                $(STACK_SRC)/CO_trace.c             \
                $(CANOPEN_SRC)/CANopen.c            \
                $(CANOPEND_SRC)/CO_command.c        \
                $(CANOPEND_SRC)/CO_comm_helpers.c   \
                $(CANOPEND_SRC)/CO_master.c         \
                $(CANOPEND_SRC)/CO_time.c           \
                $(CANOPEND_SRC)/main.c              \
                $(OBJ_DICT_SRC)/CO_OD.c             \
                $(APP_SRC)/application.c

CCSOURCES =     $(ROBOT_SRC)/Robot.cpp              \
                $(ROBOT_SRC)/Joint.cpp


# canopend is three-threaded application: nonblocking mainline, nonblocking
# rt-thread and blocking command interface thread.
# If there is a need to compile canopend as a single-threaded application, then:
#   - Command interface is not possible, so remove CO_command.c,
#     CO_comm_helpers.c, CO_master.c (and CO_SDOmaster.c) from SOURCES.
#   - Add flag -DCO_SINGLE_THREAD to the CFLAGS.
#   - Remove flag -pthread from LDFLAGS.
# Flag -lrt in LDFLAGS is necessary only with older kernels.


OBJS = $(SOURCES:%.c=%.o) $(CCSOURCES:%.cpp=%.o)
CC?= g++
CFLAGS = -Wall -g $(INCLUDE_DIRS)
#To specify a directory to search for include files (different from libraries!) you use -#I:

CXXFLAGS = -Wall -g -std=c++14 $(CPP_INCLUDE_DIRS)
LDFLAGS = -lrt -pthread


.PHONY: all clean

all: clean $(LINK_TARGET)

clean:
	rm -f $(OBJS) $(LINK_TARGET)

# Compile only, C source
%.o: %.c, %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
#	$(CC) -c -o $@ $ < $(CFLAGS)

# Compile only, C++ source
#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LINK_TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@
#$(LINK_TARGET): $(OBJS)
#	$(CC) $(LDFLAGS) $^ -o $@

