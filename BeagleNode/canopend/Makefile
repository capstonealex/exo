# Makefile for CANopend.
# Test Comment

STACKDRV_SRC =  ../CANopenNode/stack/socketCAN
STACK_SRC =     ../CANopenNode/stack
CANOPEN_SRC =   ../CANopenNode
CANOPEND_SRC =  ./src
OBJ_DICT_SRC =  ./objDict
APP_SRC =       ./app
ROBOT_SRC = 	../robot


LINK_TARGET  =  $(APP_SRC)/canopend


INCLUDE_DIRS = -I$(STACKDRV_SRC) \
               -I$(STACK_SRC)    \
               -I$(CANOPEN_SRC)  \
               -I$(CANOPEND_SRC) \
               -I$(OBJ_DICT_SRC) \
               -I$(ROBOT_SRC)    \
               -I$(APP_SRC)


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
                $(OBJ_DICT_SRC)/CO_OD.c             

SOURCESCPP = 	$(CANOPEND_SRC)/main.cpp            \
                $(APP_SRC)/application.cpp          \
		$(ROBOT_SRC)/Joint.cpp              \
	        $(ROBOT_SRC)/GPIOConst.cpp          \
	        $(ROBOT_SRC)/GPIOManager.cpp	    
 

# canopend is three-threaded application: nonblocking mainline, nonblocking
# rt-thread and blocking command interface thread.
# If there is a need to compile canopend as a single-threaded application, then:
#   - Command interface is not possible, so remove CO_command.c,
#     CO_comm_helpers.c, CO_master.c (and CO_SDOmaster.c) from SOURCES.
#   - Add flag -DCO_SINGLE_THREAD to the CFLAGS.
#   - Remove flag -pthread from LDFLAGS.
# Flag -lrt in LDFLAGS is necessary only with older kernels.


OBJS = $(SOURCES:%.c=%.o)
OBJSCPP = $(SOURCESCPP:%.cpp=%.o)

CC = g++
CFLAGS =  -std=c++11  -g $(INCLUDE_DIRS)
LDFLAGS = -lrt -pthread


.PHONY: all clean

all: clean $(LINK_TARGET)

clean:
	rm -f $(OBJS) $(OBJSCPP) $(LINK_TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(LINK_TARGET): $(OBJS) $(OBJSCPP)
	$(CC) $(LDFLAGS) $^ -o $@