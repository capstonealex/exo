##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=exo
ConfigurationName      :=Debug
WorkspacePath          :=C:/Github/ALEX/ALEX
ProjectPath            :=C:/Github/ALEX/exo/exo
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=fongj1
Date                   :=24/10/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/mingw32/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/mingw32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="exo.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/mingw32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/mingw32/bin/ar.exe rcu
CXX      := C:/MinGW/mingw32/bin/g++.exe
CC       := C:/MinGW/mingw32/bin/gcc.exe
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(ObjectSuffix) 

Objects2=$(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(ObjectSuffix) 

Objects3=$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(ObjectSuffix) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) \
	$(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) 



Objects=$(Objects0) $(Objects1) $(Objects2) $(Objects3) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	@echo $(Objects2) >> $(ObjectsFileList)
	@echo $(Objects3) >> $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_OD_storage.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/socketCAN/CO_OD_storage.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_OD_storage.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_OD_storage.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_driver.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/socketCAN/CO_driver.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_driver.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_driver.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_OD_storage.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/socketCAN/CO_OD_storage.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_OD_storage.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_OD_storage.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_Linux_tasks.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_Linux_tasks.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_OD_storage.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_OD_storage.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_OD_storage.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_OD_storage.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_OD_storage.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/socketCAN/CO_OD_storage.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_OD_storage.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_OD_storage.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_driver.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/socketCAN/CO_driver.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_driver.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_driver.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_Linux_tasks.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/socketCAN/CO_Linux_tasks.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_OD_storage.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/socketCAN/CO_OD_storage.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_OD_storage.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/socketCAN/CO_OD_storage.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_socketCAN_CO_OD_storage.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/socketCAN/CO_OD_storage.c

$(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(ObjectSuffix): ../Sit_stand/canopend/app/application.cpp $(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/app/application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(DependSuffix): ../Sit_stand/canopend/app/application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(DependSuffix) -MM ../Sit_stand/canopend/app/application.cpp

$(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(PreprocessSuffix): ../Sit_stand/canopend/app/application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_app_application.cpp$(PreprocessSuffix) ../Sit_stand/canopend/app/application.cpp

$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(ObjectSuffix): ../Sit_stand/canopend/objDict/CO_ODtest.c $(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/objDict/CO_ODtest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(DependSuffix): ../Sit_stand/canopend/objDict/CO_ODtest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(DependSuffix) -MM ../Sit_stand/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(PreprocessSuffix): ../Sit_stand/canopend/objDict/CO_ODtest.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODtest.c$(PreprocessSuffix) ../Sit_stand/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(ObjectSuffix): ../Sit_stand/canopend/src/CO_command.c $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/src/CO_command.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(DependSuffix): ../Sit_stand/canopend/src/CO_command.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(DependSuffix) -MM ../Sit_stand/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(PreprocessSuffix): ../Sit_stand/canopend/src/CO_command.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_command.c$(PreprocessSuffix) ../Sit_stand/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(ObjectSuffix): ../Sit_stand/canopend/src/main.cpp $(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(DependSuffix): ../Sit_stand/canopend/src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(DependSuffix) -MM ../Sit_stand/canopend/src/main.cpp

$(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(PreprocessSuffix): ../Sit_stand/canopend/src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_src_main.cpp$(PreprocessSuffix) ../Sit_stand/canopend/src/main.cpp

$(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(ObjectSuffix): ../Sit_stand/canopend/src/pinread.cpp $(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/src/pinread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(DependSuffix): ../Sit_stand/canopend/src/pinread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(DependSuffix) -MM ../Sit_stand/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(PreprocessSuffix): ../Sit_stand/canopend/src/pinread.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_src_pinread.cpp$(PreprocessSuffix) ../Sit_stand/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/CO_Emergency.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/CO_Emergency.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/CO_Emergency.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/CO_Emergency.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/CO_NMT_Heartbeat.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/CO_NMT_Heartbeat.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/CO_NMT_Heartbeat.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/CO_NMT_Heartbeat.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/CO_PDO.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/CO_PDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/CO_PDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/CO_PDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/CO_SDO.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/CO_SDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/CO_SDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/CO_SDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/CO_trace.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/CO_trace.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/CO_trace.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/CO_trace.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_trace.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/crc16-ccitt.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/crc16-ccitt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/crc16-ccitt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/crc16-ccitt.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_driver.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_driver.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_driver.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_driver.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(ObjectSuffix): ../BeagleNode/canopend/src/CO_comm_helpers.c $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/src/CO_comm_helpers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(DependSuffix): ../BeagleNode/canopend/src/CO_comm_helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(DependSuffix) -MM ../BeagleNode/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(PreprocessSuffix): ../BeagleNode/canopend/src/CO_comm_helpers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_comm_helpers.c$(PreprocessSuffix) ../BeagleNode/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(ObjectSuffix): ../BeagleNode/canopend/src/CO_master.c $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/src/CO_master.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(DependSuffix): ../BeagleNode/canopend/src/CO_master.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(DependSuffix) -MM ../BeagleNode/canopend/src/CO_master.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(PreprocessSuffix): ../BeagleNode/canopend/src/CO_master.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_master.c$(PreprocessSuffix) ../BeagleNode/canopend/src/CO_master.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(ObjectSuffix): ../BeagleNode/canopend/src/main.cpp $(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(DependSuffix): ../BeagleNode/canopend/src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(DependSuffix) -MM ../BeagleNode/canopend/src/main.cpp

$(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(PreprocessSuffix): ../BeagleNode/canopend/src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_src_main.cpp$(PreprocessSuffix) ../BeagleNode/canopend/src/main.cpp

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/CO_Emergency.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/CO_Emergency.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/CO_Emergency.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/CO_Emergency.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(ObjectSuffix): ../Sit_stand/canopend/objDict/CO_OD.c $(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/objDict/CO_OD.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(DependSuffix): ../Sit_stand/canopend/objDict/CO_OD.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(DependSuffix) -MM ../Sit_stand/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(PreprocessSuffix): ../Sit_stand/canopend/objDict/CO_OD.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_OD.c$(PreprocessSuffix) ../Sit_stand/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/CO_HBconsumer.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/CO_HBconsumer.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/CO_HBconsumer.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/CO_HBconsumer.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/CO_SDO.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/CO_SDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/CO_SDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/CO_SDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/CO_SYNC.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/CO_SYNC.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/CO_SYNC.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/CO_SYNC.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/CO_HBconsumer.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/CO_HBconsumer.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/CO_HBconsumer.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/CO_HBconsumer.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/app/application.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/app/application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(DependSuffix): ../Single_joint_Vel_Control/canopend/app/application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/app/application.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/app/application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_app_application.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/app/application.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_OD.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/objDict/CO_OD.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(DependSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_OD.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_OD.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_OD.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_ODorig.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/objDict/CO_ODorig.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(DependSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_ODorig.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_ODorig.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODorig.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/src/CO_command.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/src/CO_command.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(DependSuffix): ../Single_joint_Vel_Control/canopend/src/CO_command.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/src/CO_command.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_command.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/src/CO_comm_helpers.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/src/CO_comm_helpers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(DependSuffix): ../Single_joint_Vel_Control/canopend/src/CO_comm_helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/src/CO_comm_helpers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_comm_helpers.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/CO_SYNC.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/CO_SYNC.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/CO_SYNC.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/CO_SYNC.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/src/main.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(DependSuffix): ../Single_joint_Vel_Control/canopend/src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/src/main.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_main.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/src/main.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/src/pinread.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/src/pinread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(DependSuffix): ../Single_joint_Vel_Control/canopend/src/pinread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/src/pinread.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_pinread.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(ObjectSuffix): ../Sit_stand/canopend/objDict/CO_ODorig.c $(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/objDict/CO_ODorig.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(DependSuffix): ../Sit_stand/canopend/objDict/CO_ODorig.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(DependSuffix) -MM ../Sit_stand/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(PreprocessSuffix): ../Sit_stand/canopend/objDict/CO_ODorig.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_objDict_CO_ODorig.c$(PreprocessSuffix) ../Sit_stand/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_Emergency.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/CO_Emergency.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_Emergency.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_Emergency.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_NMT_Heartbeat.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/CO_NMT_Heartbeat.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_NMT_Heartbeat.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_NMT_Heartbeat.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDO.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/CO_SDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_trace.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/CO_trace.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_trace.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_trace.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_trace.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(ObjectSuffix): ../Benchmark/canopend/app/application.cpp $(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/app/application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(DependSuffix): ../Benchmark/canopend/app/application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(DependSuffix) -MM ../Benchmark/canopend/app/application.cpp

$(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(PreprocessSuffix): ../Benchmark/canopend/app/application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_app_application.cpp$(PreprocessSuffix) ../Benchmark/canopend/app/application.cpp

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_driver.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/socketCAN/CO_driver.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_driver.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_driver.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SYNC.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/CO_SYNC.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SYNC.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SYNC.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(ObjectSuffix): ../Benchmark/canopend/objDict/CO_ODtest.c $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/objDict/CO_ODtest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(DependSuffix): ../Benchmark/canopend/objDict/CO_ODtest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(DependSuffix) -MM ../Benchmark/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(PreprocessSuffix): ../Benchmark/canopend/objDict/CO_ODtest.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODtest.c$(PreprocessSuffix) ../Benchmark/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(ObjectSuffix): ../Benchmark/canopend/src/CO_comm_helpers.c $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/src/CO_comm_helpers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(DependSuffix): ../Benchmark/canopend/src/CO_comm_helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(DependSuffix) -MM ../Benchmark/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(PreprocessSuffix): ../Benchmark/canopend/src/CO_comm_helpers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_comm_helpers.c$(PreprocessSuffix) ../Benchmark/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(ObjectSuffix): ../Benchmark/canopend/src/CO_time.c $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/src/CO_time.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(DependSuffix): ../Benchmark/canopend/src/CO_time.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(DependSuffix) -MM ../Benchmark/canopend/src/CO_time.c

$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(PreprocessSuffix): ../Benchmark/canopend/src/CO_time.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_time.c$(PreprocessSuffix) ../Benchmark/canopend/src/CO_time.c

$(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(ObjectSuffix): ../Benchmark/canopend/src/main.cpp $(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(DependSuffix): ../Benchmark/canopend/src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(DependSuffix) -MM ../Benchmark/canopend/src/main.cpp

$(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(PreprocessSuffix): ../Benchmark/canopend/src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_src_main.cpp$(PreprocessSuffix) ../Benchmark/canopend/src/main.cpp

$(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(ObjectSuffix): ../Benchmark/canopend/src/pinread.cpp $(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/src/pinread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(DependSuffix): ../Benchmark/canopend/src/pinread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(DependSuffix) -MM ../Benchmark/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(PreprocessSuffix): ../Benchmark/canopend/src/pinread.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_src_pinread.cpp$(PreprocessSuffix) ../Benchmark/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/CO_Emergency.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/CO_Emergency.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(DependSuffix): ../Benchmark/CANopenNode/stack/CO_Emergency.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/CO_Emergency.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(ObjectSuffix): ../BeagleNode/TaskStatemachine/StateMachine.cpp $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/TaskStatemachine/StateMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(DependSuffix): ../BeagleNode/TaskStatemachine/StateMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(DependSuffix) -MM ../BeagleNode/TaskStatemachine/StateMachine.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(PreprocessSuffix): ../BeagleNode/TaskStatemachine/StateMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_StateMachine.cpp$(PreprocessSuffix) ../BeagleNode/TaskStatemachine/StateMachine.cpp

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_Linux_tasks.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/socketCAN/CO_Linux_tasks.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(ObjectSuffix): ../BeagleNode/robot/GPIOConst.cpp $(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/robot/GPIOConst.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(DependSuffix): ../BeagleNode/robot/GPIOConst.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(DependSuffix) -MM ../BeagleNode/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(PreprocessSuffix): ../BeagleNode/robot/GPIOConst.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_robot_GPIOConst.cpp$(PreprocessSuffix) ../BeagleNode/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(ObjectSuffix): ../Benchmark/canopend/objDict/CO_OD.c $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/objDict/CO_OD.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(DependSuffix): ../Benchmark/canopend/objDict/CO_OD.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(DependSuffix) -MM ../Benchmark/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(PreprocessSuffix): ../Benchmark/canopend/objDict/CO_OD.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_OD.c$(PreprocessSuffix) ../Benchmark/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(ObjectSuffix): ../Benchmark/canopend/src/CO_command.c $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/src/CO_command.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(DependSuffix): ../Benchmark/canopend/src/CO_command.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(DependSuffix) -MM ../Benchmark/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(PreprocessSuffix): ../Benchmark/canopend/src/CO_command.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_command.c$(PreprocessSuffix) ../Benchmark/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(ObjectSuffix): ../Single_joint/canopencomm/CANopenCommand.c $(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopencomm/CANopenCommand.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(DependSuffix): ../Single_joint/canopencomm/CANopenCommand.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(DependSuffix) -MM ../Single_joint/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(PreprocessSuffix): ../Single_joint/canopencomm/CANopenCommand.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopencomm_CANopenCommand.c$(PreprocessSuffix) ../Single_joint/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(ObjectSuffix): ../BeagleNode/TaskStatemachine/toytest.cpp $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/TaskStatemachine/toytest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(DependSuffix): ../BeagleNode/TaskStatemachine/toytest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(DependSuffix) -MM ../BeagleNode/TaskStatemachine/toytest.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(PreprocessSuffix): ../BeagleNode/TaskStatemachine/toytest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_toytest.cpp$(PreprocessSuffix) ../BeagleNode/TaskStatemachine/toytest.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopencomm/CANopenCommand.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopencomm/CANopenCommand.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(DependSuffix): ../Single_joint_Vel_Control/canopencomm/CANopenCommand.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopencomm/CANopenCommand.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencomm_CANopenCommand.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(ObjectSuffix): ../Sit_stand/robot/Joint.cpp $(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/robot/Joint.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(DependSuffix): ../Sit_stand/robot/Joint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(DependSuffix) -MM ../Sit_stand/robot/Joint.cpp

$(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(PreprocessSuffix): ../Sit_stand/robot/Joint.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_robot_Joint.cpp$(PreprocessSuffix) ../Sit_stand/robot/Joint.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/robot/GPIOConst.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/robot/GPIOConst.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(DependSuffix): ../Single_joint_Vel_Control/robot/GPIOConst.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/robot/GPIOConst.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOConst.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/robot/Joint.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/robot/Joint.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(DependSuffix): ../Single_joint_Vel_Control/robot/Joint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/robot/Joint.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/robot/Joint.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Joint.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/robot/Joint.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/robot/Robot.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/robot/Robot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(DependSuffix): ../Single_joint_Vel_Control/robot/Robot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/robot/Robot.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/robot/Robot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_Robot.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/robot/Robot.cpp

$(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(ObjectSuffix): ../Benchmark/stateMachine/bendTest.cpp $(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/stateMachine/bendTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(DependSuffix): ../Benchmark/stateMachine/bendTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(DependSuffix) -MM ../Benchmark/stateMachine/bendTest.cpp

$(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(PreprocessSuffix): ../Benchmark/stateMachine/bendTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_stateMachine_bendTest.cpp$(PreprocessSuffix) ../Benchmark/stateMachine/bendTest.cpp

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/CO_NMT_Heartbeat.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/CO_NMT_Heartbeat.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix): ../Single_joint/CANopenNode/stack/CO_NMT_Heartbeat.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/CO_NMT_Heartbeat.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(ObjectSuffix): ../BeagleNode/TaskStatemachine/Transition.cpp $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/TaskStatemachine/Transition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(DependSuffix): ../BeagleNode/TaskStatemachine/Transition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(DependSuffix) -MM ../BeagleNode/TaskStatemachine/Transition.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(PreprocessSuffix): ../BeagleNode/TaskStatemachine/Transition.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Transition.cpp$(PreprocessSuffix) ../BeagleNode/TaskStatemachine/Transition.cpp

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/CO_PDO.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/CO_PDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/CO_PDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/CO_PDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/src/CO_time.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/src/CO_time.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(DependSuffix): ../Single_joint_Vel_Control/canopend/src/CO_time.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/src/CO_time.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/src/CO_time.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_time.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/src/CO_time.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(ObjectSuffix): ../BeagleNode/canopend/src/CO_command.c $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/src/CO_command.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(DependSuffix): ../BeagleNode/canopend/src/CO_command.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(DependSuffix) -MM ../BeagleNode/canopend/src/CO_command.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(PreprocessSuffix): ../BeagleNode/canopend/src/CO_command.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_command.c$(PreprocessSuffix) ../BeagleNode/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/stateMachine/Event.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/stateMachine/Event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(DependSuffix): ../Single_joint_Vel_Control/stateMachine/Event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/stateMachine/Event.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/stateMachine/Event.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Event.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/stateMachine/Event.cpp

$(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(ObjectSuffix): ../BeagleNode/canopencomm/CANopenCommand.c $(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopencomm/CANopenCommand.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(DependSuffix): ../BeagleNode/canopencomm/CANopenCommand.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(DependSuffix) -MM ../BeagleNode/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(PreprocessSuffix): ../BeagleNode/canopencomm/CANopenCommand.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopencomm_CANopenCommand.c$(PreprocessSuffix) ../BeagleNode/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/crc16-ccitt.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/crc16-ccitt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/crc16-ccitt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/crc16-ccitt.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/stateMachine/Transition.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/stateMachine/Transition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(DependSuffix): ../Single_joint_Vel_Control/stateMachine/Transition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/stateMachine/Transition.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/stateMachine/Transition.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_Transition.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/stateMachine/Transition.cpp

$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(ObjectSuffix): ../BeagleNode/canopend/objDict/CO_ODtest.c $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/objDict/CO_ODtest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(DependSuffix): ../BeagleNode/canopend/objDict/CO_ODtest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(DependSuffix) -MM ../BeagleNode/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(PreprocessSuffix): ../BeagleNode/canopend/objDict/CO_ODtest.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODtest.c$(PreprocessSuffix) ../BeagleNode/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/stateMachine/bendTest.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/stateMachine/bendTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(DependSuffix): ../Single_joint_Vel_Control/stateMachine/bendTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/stateMachine/bendTest.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/stateMachine/bendTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_bendTest.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/stateMachine/bendTest.cpp

$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(ObjectSuffix): ../Benchmark/canopend/objDict/CO_ODorig.c $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/objDict/CO_ODorig.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(DependSuffix): ../Benchmark/canopend/objDict/CO_ODorig.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(DependSuffix) -MM ../Benchmark/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(PreprocessSuffix): ../Benchmark/canopend/objDict/CO_ODorig.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_objDict_CO_ODorig.c$(PreprocessSuffix) ../Benchmark/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(ObjectSuffix): ../Benchmark/canopencomm/CANopenCommand.c $(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopencomm/CANopenCommand.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(DependSuffix): ../Benchmark/canopencomm/CANopenCommand.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(DependSuffix) -MM ../Benchmark/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(PreprocessSuffix): ../Benchmark/canopencomm/CANopenCommand.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopencomm_CANopenCommand.c$(PreprocessSuffix) ../Benchmark/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(ObjectSuffix): ../BeagleNode/robot/GPIOManager.cpp $(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/robot/GPIOManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(DependSuffix): ../BeagleNode/robot/GPIOManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(DependSuffix) -MM ../BeagleNode/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(PreprocessSuffix): ../BeagleNode/robot/GPIOManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_robot_GPIOManager.cpp$(PreprocessSuffix) ../BeagleNode/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/CANopen.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/CANopen.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/CANopen.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/CANopen.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_CANopen.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(ObjectSuffix): ../Benchmark/CANopenNode/CANopen.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/CANopen.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(DependSuffix): ../Benchmark/CANopenNode/CANopen.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(DependSuffix) -MM ../Benchmark/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(PreprocessSuffix): ../Benchmark/CANopenNode/CANopen.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_CANopen.c$(PreprocessSuffix) ../Benchmark/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/CO_PDO.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/CO_PDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(DependSuffix): ../Benchmark/CANopenNode/stack/CO_PDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/CO_PDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(ObjectSuffix): ../BeagleNode/CANopenNode/CANopen.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/CANopen.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(DependSuffix): ../BeagleNode/CANopenNode/CANopen.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/CANopen.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_CANopen.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(ObjectSuffix): ../Benchmark/canopencgi/CANopenCGI.c $(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopencgi/CANopenCGI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(DependSuffix): ../Benchmark/canopencgi/CANopenCGI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(DependSuffix) -MM ../Benchmark/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(PreprocessSuffix): ../Benchmark/canopencgi/CANopenCGI.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopencgi_CANopenCGI.c$(PreprocessSuffix) ../Benchmark/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(ObjectSuffix): ../Single_joint/stateMachine/StateMachine.cpp $(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/stateMachine/StateMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(DependSuffix): ../Single_joint/stateMachine/StateMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(DependSuffix) -MM ../Single_joint/stateMachine/StateMachine.cpp

$(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(PreprocessSuffix): ../Single_joint/stateMachine/StateMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_stateMachine_StateMachine.cpp$(PreprocessSuffix) ../Single_joint/stateMachine/StateMachine.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/stateMachine/State.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/stateMachine/State.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(DependSuffix): ../Single_joint_Vel_Control/stateMachine/State.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/stateMachine/State.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/stateMachine/State.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_State.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/stateMachine/State.cpp

$(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(ObjectSuffix): ../BeagleNode/canopend/app/application.cpp $(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/app/application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(DependSuffix): ../BeagleNode/canopend/app/application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(DependSuffix) -MM ../BeagleNode/canopend/app/application.cpp

$(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(PreprocessSuffix): ../BeagleNode/canopend/app/application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_app_application.cpp$(PreprocessSuffix) ../BeagleNode/canopend/app/application.cpp

$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(ObjectSuffix): ../BeagleNode/canopend/src/CO_time.c $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/src/CO_time.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(DependSuffix): ../BeagleNode/canopend/src/CO_time.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(DependSuffix) -MM ../BeagleNode/canopend/src/CO_time.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(PreprocessSuffix): ../BeagleNode/canopend/src/CO_time.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_src_CO_time.c$(PreprocessSuffix) ../BeagleNode/canopend/src/CO_time.c

$(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(ObjectSuffix): ../Single_joint/stateMachine/State.cpp $(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/stateMachine/State.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(DependSuffix): ../Single_joint/stateMachine/State.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(DependSuffix) -MM ../Single_joint/stateMachine/State.cpp

$(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(PreprocessSuffix): ../Single_joint/stateMachine/State.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_stateMachine_State.cpp$(PreprocessSuffix) ../Single_joint/stateMachine/State.cpp

$(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(ObjectSuffix): ../Benchmark/robot/GPIOConst.cpp $(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/robot/GPIOConst.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(DependSuffix): ../Benchmark/robot/GPIOConst.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(DependSuffix) -MM ../Benchmark/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(PreprocessSuffix): ../Benchmark/robot/GPIOConst.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_robot_GPIOConst.cpp$(PreprocessSuffix) ../Benchmark/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(ObjectSuffix): ../Benchmark/robot/Robot.cpp $(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/robot/Robot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(DependSuffix): ../Benchmark/robot/Robot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(DependSuffix) -MM ../Benchmark/robot/Robot.cpp

$(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(PreprocessSuffix): ../Benchmark/robot/Robot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_robot_Robot.cpp$(PreprocessSuffix) ../Benchmark/robot/Robot.cpp

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/CO_NMT_Heartbeat.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/CO_NMT_Heartbeat.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/CO_NMT_Heartbeat.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/CO_NMT_Heartbeat.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(ObjectSuffix): ../BeagleNode/robot/TESTING.cpp $(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/robot/TESTING.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(DependSuffix): ../BeagleNode/robot/TESTING.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(DependSuffix) -MM ../BeagleNode/robot/TESTING.cpp

$(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(PreprocessSuffix): ../BeagleNode/robot/TESTING.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_robot_TESTING.cpp$(PreprocessSuffix) ../BeagleNode/robot/TESTING.cpp

$(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(ObjectSuffix): ../Benchmark/robot/GPIOManager.cpp $(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/robot/GPIOManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(DependSuffix): ../Benchmark/robot/GPIOManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(DependSuffix) -MM ../Benchmark/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(PreprocessSuffix): ../Benchmark/robot/GPIOManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_robot_GPIOManager.cpp$(PreprocessSuffix) ../Benchmark/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(ObjectSuffix): ../Sit_stand/stateMachine/StateMachine.cpp $(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/stateMachine/StateMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(DependSuffix): ../Sit_stand/stateMachine/StateMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(DependSuffix) -MM ../Sit_stand/stateMachine/StateMachine.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(PreprocessSuffix): ../Sit_stand/stateMachine/StateMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_stateMachine_StateMachine.cpp$(PreprocessSuffix) ../Sit_stand/stateMachine/StateMachine.cpp

$(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(ObjectSuffix): ../Sit_stand/canopencomm/CANopenCommand.c $(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopencomm/CANopenCommand.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(DependSuffix): ../Sit_stand/canopencomm/CANopenCommand.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(DependSuffix) -MM ../Sit_stand/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(PreprocessSuffix): ../Sit_stand/canopencomm/CANopenCommand.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopencomm_CANopenCommand.c$(PreprocessSuffix) ../Sit_stand/canopencomm/CANopenCommand.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/CO_NMT_Heartbeat.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/CO_NMT_Heartbeat.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix): ../Benchmark/CANopenNode/stack/CO_NMT_Heartbeat.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/CO_NMT_Heartbeat.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_NMT_Heartbeat.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/CO_NMT_Heartbeat.c

$(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(ObjectSuffix): ../Sit_stand/robot/GPIOManager.cpp $(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/robot/GPIOManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(DependSuffix): ../Sit_stand/robot/GPIOManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(DependSuffix) -MM ../Sit_stand/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(PreprocessSuffix): ../Sit_stand/robot/GPIOManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_robot_GPIOManager.cpp$(PreprocessSuffix) ../Sit_stand/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(ObjectSuffix): ../Single_joint/stateMachine/Transition.cpp $(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/stateMachine/Transition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(DependSuffix): ../Single_joint/stateMachine/Transition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(DependSuffix) -MM ../Single_joint/stateMachine/Transition.cpp

$(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(PreprocessSuffix): ../Single_joint/stateMachine/Transition.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_stateMachine_Transition.cpp$(PreprocessSuffix) ../Single_joint/stateMachine/Transition.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(ObjectSuffix): ../Sit_stand/stateMachine/bendTest.cpp $(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/stateMachine/bendTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(DependSuffix): ../Sit_stand/stateMachine/bendTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(DependSuffix) -MM ../Sit_stand/stateMachine/bendTest.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(PreprocessSuffix): ../Sit_stand/stateMachine/bendTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_stateMachine_bendTest.cpp$(PreprocessSuffix) ../Sit_stand/stateMachine/bendTest.cpp

$(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(ObjectSuffix): ../Single_joint/robot/Robot.cpp $(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/robot/Robot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(DependSuffix): ../Single_joint/robot/Robot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(DependSuffix) -MM ../Single_joint/robot/Robot.cpp

$(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(PreprocessSuffix): ../Single_joint/robot/Robot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_robot_Robot.cpp$(PreprocessSuffix) ../Single_joint/robot/Robot.cpp

$(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(ObjectSuffix): ../Single_joint/robot/GPIOConst.cpp $(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/robot/GPIOConst.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(DependSuffix): ../Single_joint/robot/GPIOConst.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(DependSuffix) -MM ../Single_joint/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(PreprocessSuffix): ../Single_joint/robot/GPIOConst.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_robot_GPIOConst.cpp$(PreprocessSuffix) ../Single_joint/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(ObjectSuffix): ../Single_joint/robot/Joint.cpp $(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/robot/Joint.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(DependSuffix): ../Single_joint/robot/Joint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(DependSuffix) -MM ../Single_joint/robot/Joint.cpp

$(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(PreprocessSuffix): ../Single_joint/robot/Joint.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_robot_Joint.cpp$(PreprocessSuffix) ../Single_joint/robot/Joint.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(ObjectSuffix): ../Sit_stand/stateMachine/Event.cpp $(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/stateMachine/Event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(DependSuffix): ../Sit_stand/stateMachine/Event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(DependSuffix) -MM ../Sit_stand/stateMachine/Event.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(PreprocessSuffix): ../Sit_stand/stateMachine/Event.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_stateMachine_Event.cpp$(PreprocessSuffix) ../Sit_stand/stateMachine/Event.cpp

$(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(ObjectSuffix): ../Benchmark/robot/Joint.cpp $(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/robot/Joint.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(DependSuffix): ../Benchmark/robot/Joint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(DependSuffix) -MM ../Benchmark/robot/Joint.cpp

$(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(PreprocessSuffix): ../Benchmark/robot/Joint.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_robot_Joint.cpp$(PreprocessSuffix) ../Benchmark/robot/Joint.cpp

$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(ObjectSuffix): ../Sit_stand/canopend/src/CO_master.c $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/src/CO_master.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(DependSuffix): ../Sit_stand/canopend/src/CO_master.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(DependSuffix) -MM ../Sit_stand/canopend/src/CO_master.c

$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(PreprocessSuffix): ../Sit_stand/canopend/src/CO_master.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_master.c$(PreprocessSuffix) ../Sit_stand/canopend/src/CO_master.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopencgi/CANopenCGI.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopencgi/CANopenCGI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(DependSuffix): ../Single_joint_Vel_Control/canopencgi/CANopenCGI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopencgi/CANopenCGI.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopencgi_CANopenCGI.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDOmaster.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/CO_SDOmaster.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDOmaster.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDOmaster.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(ObjectSuffix): ../Sit_stand/canopencgi/CANopenCGI.c $(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopencgi/CANopenCGI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(DependSuffix): ../Sit_stand/canopencgi/CANopenCGI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(DependSuffix) -MM ../Sit_stand/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(PreprocessSuffix): ../Sit_stand/canopencgi/CANopenCGI.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopencgi_CANopenCGI.c$(PreprocessSuffix) ../Sit_stand/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/CO_SDOmaster.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/CO_SDOmaster.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix): ../Benchmark/CANopenNode/stack/CO_SDOmaster.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/CO_SDOmaster.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(ObjectSuffix): ../Sit_stand/canopend/src/CO_time.c $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/src/CO_time.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(DependSuffix): ../Sit_stand/canopend/src/CO_time.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(DependSuffix) -MM ../Sit_stand/canopend/src/CO_time.c

$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(PreprocessSuffix): ../Sit_stand/canopend/src/CO_time.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_time.c$(PreprocessSuffix) ../Sit_stand/canopend/src/CO_time.c

$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(ObjectSuffix): ../BeagleNode/canopend/objDict/CO_ODorig.c $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/objDict/CO_ODorig.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(DependSuffix): ../BeagleNode/canopend/objDict/CO_ODorig.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(DependSuffix) -MM ../BeagleNode/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(PreprocessSuffix): ../BeagleNode/canopend/objDict/CO_ODorig.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_ODorig.c$(PreprocessSuffix) ../BeagleNode/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(ObjectSuffix): ../Single_joint/CANopenNode/CANopen.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/CANopen.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(DependSuffix): ../Single_joint/CANopenNode/CANopen.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(DependSuffix) -MM ../Single_joint/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(PreprocessSuffix): ../Single_joint/CANopenNode/CANopen.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_CANopen.c$(PreprocessSuffix) ../Single_joint/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/CO_trace.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/CO_trace.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/CO_trace.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/CO_trace.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_trace.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(ObjectSuffix): ../Single_joint/canopencgi/CANopenCGI.c $(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopencgi/CANopenCGI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(DependSuffix): ../Single_joint/canopencgi/CANopenCGI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(DependSuffix) -MM ../Single_joint/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(PreprocessSuffix): ../Single_joint/canopencgi/CANopenCGI.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopencgi_CANopenCGI.c$(PreprocessSuffix) ../Single_joint/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/CO_trace.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/CO_trace.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(DependSuffix): ../Benchmark/CANopenNode/stack/CO_trace.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/CO_trace.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_trace.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(ObjectSuffix): ../BeagleNode/canopend/objDict/CO_OD.c $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/objDict/CO_OD.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(DependSuffix): ../BeagleNode/canopend/objDict/CO_OD.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(DependSuffix) -MM ../BeagleNode/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(PreprocessSuffix): ../BeagleNode/canopend/objDict/CO_OD.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_objDict_CO_OD.c$(PreprocessSuffix) ../BeagleNode/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/CO_SDOmaster.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/CO_SDOmaster.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/CO_SDOmaster.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/CO_SDOmaster.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(ObjectSuffix): ../BeagleNode/robot/Robot.cpp $(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/robot/Robot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(DependSuffix): ../BeagleNode/robot/Robot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(DependSuffix) -MM ../BeagleNode/robot/Robot.cpp

$(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(PreprocessSuffix): ../BeagleNode/robot/Robot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_robot_Robot.cpp$(PreprocessSuffix) ../BeagleNode/robot/Robot.cpp

$(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(ObjectSuffix): ../Sit_stand/robot/Robot.cpp $(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/robot/Robot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(DependSuffix): ../Sit_stand/robot/Robot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(DependSuffix) -MM ../Sit_stand/robot/Robot.cpp

$(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(PreprocessSuffix): ../Sit_stand/robot/Robot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_robot_Robot.cpp$(PreprocessSuffix) ../Sit_stand/robot/Robot.cpp

$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(ObjectSuffix): ../Benchmark/canopend/src/CO_master.c $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/canopend/src/CO_master.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(DependSuffix): ../Benchmark/canopend/src/CO_master.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(DependSuffix) -MM ../Benchmark/canopend/src/CO_master.c

$(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(PreprocessSuffix): ../Benchmark/canopend/src/CO_master.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_canopend_src_CO_master.c$(PreprocessSuffix) ../Benchmark/canopend/src/CO_master.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_Linux_tasks.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/socketCAN/CO_Linux_tasks.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/stateMachine/StateMachine.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/stateMachine/StateMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(DependSuffix): ../Single_joint_Vel_Control/stateMachine/StateMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/stateMachine/StateMachine.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/stateMachine/StateMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_stateMachine_StateMachine.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/stateMachine/StateMachine.cpp

$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(ObjectSuffix): ../Single_joint/canopend/objDict/CO_ODtest.c $(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/objDict/CO_ODtest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(DependSuffix): ../Single_joint/canopend/objDict/CO_ODtest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(DependSuffix) -MM ../Single_joint/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(PreprocessSuffix): ../Single_joint/canopend/objDict/CO_ODtest.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODtest.c$(PreprocessSuffix) ../Single_joint/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(ObjectSuffix): ../BeagleNode/canopend/src/pinread.cpp $(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopend/src/pinread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(DependSuffix): ../BeagleNode/canopend/src/pinread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(DependSuffix) -MM ../BeagleNode/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(PreprocessSuffix): ../BeagleNode/canopend/src/pinread.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopend_src_pinread.cpp$(PreprocessSuffix) ../BeagleNode/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(ObjectSuffix): ../BeagleNode/TaskStatemachine/State.cpp $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/TaskStatemachine/State.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(DependSuffix): ../BeagleNode/TaskStatemachine/State.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(DependSuffix) -MM ../BeagleNode/TaskStatemachine/State.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(PreprocessSuffix): ../BeagleNode/TaskStatemachine/State.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_State.cpp$(PreprocessSuffix) ../BeagleNode/TaskStatemachine/State.cpp

$(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(ObjectSuffix): ../Benchmark/stateMachine/State.cpp $(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/stateMachine/State.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(DependSuffix): ../Benchmark/stateMachine/State.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(DependSuffix) -MM ../Benchmark/stateMachine/State.cpp

$(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(PreprocessSuffix): ../Benchmark/stateMachine/State.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_stateMachine_State.cpp$(PreprocessSuffix) ../Benchmark/stateMachine/State.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(ObjectSuffix): ../BeagleNode/TaskStatemachine/Event.cpp $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/TaskStatemachine/Event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(DependSuffix): ../BeagleNode/TaskStatemachine/Event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(DependSuffix) -MM ../BeagleNode/TaskStatemachine/Event.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(PreprocessSuffix): ../BeagleNode/TaskStatemachine/Event.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Event.cpp$(PreprocessSuffix) ../BeagleNode/TaskStatemachine/Event.cpp

$(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(ObjectSuffix): ../BeagleNode/robot/Joint.cpp $(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/robot/Joint.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(DependSuffix): ../BeagleNode/robot/Joint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(DependSuffix) -MM ../BeagleNode/robot/Joint.cpp

$(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(PreprocessSuffix): ../BeagleNode/robot/Joint.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_robot_Joint.cpp$(PreprocessSuffix) ../BeagleNode/robot/Joint.cpp

$(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(ObjectSuffix): ../Benchmark/stateMachine/StateMachine.cpp $(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/stateMachine/StateMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(DependSuffix): ../Benchmark/stateMachine/StateMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(DependSuffix) -MM ../Benchmark/stateMachine/StateMachine.cpp

$(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(PreprocessSuffix): ../Benchmark/stateMachine/StateMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_stateMachine_StateMachine.cpp$(PreprocessSuffix) ../Benchmark/stateMachine/StateMachine.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(ObjectSuffix): ../BeagleNode/TaskStatemachine/ToyMachine.cpp $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/TaskStatemachine/ToyMachine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(DependSuffix): ../BeagleNode/TaskStatemachine/ToyMachine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(DependSuffix) -MM ../BeagleNode/TaskStatemachine/ToyMachine.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(PreprocessSuffix): ../BeagleNode/TaskStatemachine/ToyMachine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_ToyMachine.cpp$(PreprocessSuffix) ../BeagleNode/TaskStatemachine/ToyMachine.cpp

$(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(ObjectSuffix): ../Single_joint/stateMachine/Event.cpp $(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/stateMachine/Event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(DependSuffix): ../Single_joint/stateMachine/Event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(DependSuffix) -MM ../Single_joint/stateMachine/Event.cpp

$(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(PreprocessSuffix): ../Single_joint/stateMachine/Event.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_stateMachine_Event.cpp$(PreprocessSuffix) ../Single_joint/stateMachine/Event.cpp

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(ObjectSuffix): ../Sit_stand/CANopenNode/CANopen.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/CANopen.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(DependSuffix): ../Sit_stand/CANopenNode/CANopen.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/CANopen.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_CANopen.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/CANopen.c

$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(ObjectSuffix): ../Sit_stand/canopend/src/CO_comm_helpers.c $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/canopend/src/CO_comm_helpers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(DependSuffix): ../Sit_stand/canopend/src/CO_comm_helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(DependSuffix) -MM ../Sit_stand/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(PreprocessSuffix): ../Sit_stand/canopend/src/CO_comm_helpers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_canopend_src_CO_comm_helpers.c$(PreprocessSuffix) ../Sit_stand/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(ObjectSuffix): ../Sit_stand/stateMachine/Transition.cpp $(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/stateMachine/Transition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(DependSuffix): ../Sit_stand/stateMachine/Transition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(DependSuffix) -MM ../Sit_stand/stateMachine/Transition.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(PreprocessSuffix): ../Sit_stand/stateMachine/Transition.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_stateMachine_Transition.cpp$(PreprocessSuffix) ../Sit_stand/stateMachine/Transition.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(ObjectSuffix): ../Sit_stand/stateMachine/State.cpp $(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/stateMachine/State.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(DependSuffix): ../Sit_stand/stateMachine/State.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(DependSuffix) -MM ../Sit_stand/stateMachine/State.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(PreprocessSuffix): ../Sit_stand/stateMachine/State.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_stateMachine_State.cpp$(PreprocessSuffix) ../Sit_stand/stateMachine/State.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_PDO.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/CO_PDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_PDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_PDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/CO_Emergency.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/CO_Emergency.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(DependSuffix): ../Single_joint/CANopenNode/stack/CO_Emergency.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/CO_Emergency.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_Emergency.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/CO_Emergency.c

$(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(ObjectSuffix): ../Benchmark/stateMachine/Transition.cpp $(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/stateMachine/Transition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(DependSuffix): ../Benchmark/stateMachine/Transition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(DependSuffix) -MM ../Benchmark/stateMachine/Transition.cpp

$(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(PreprocessSuffix): ../Benchmark/stateMachine/Transition.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_stateMachine_Transition.cpp$(PreprocessSuffix) ../Benchmark/stateMachine/Transition.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(ObjectSuffix): ../Sit_stand/stateMachine/sitStand.cpp $(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/stateMachine/sitStand.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(DependSuffix): ../Sit_stand/stateMachine/sitStand.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(DependSuffix) -MM ../Sit_stand/stateMachine/sitStand.cpp

$(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(PreprocessSuffix): ../Sit_stand/stateMachine/sitStand.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_stateMachine_sitStand.cpp$(PreprocessSuffix) ../Sit_stand/stateMachine/sitStand.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/src/CO_master.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/src/CO_master.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(DependSuffix): ../Single_joint_Vel_Control/canopend/src/CO_master.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/src/CO_master.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/src/CO_master.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_src_CO_master.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/src/CO_master.c

$(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(ObjectSuffix): ../Sit_stand/robot/GPIOConst.cpp $(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/robot/GPIOConst.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(DependSuffix): ../Sit_stand/robot/GPIOConst.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(DependSuffix) -MM ../Sit_stand/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(PreprocessSuffix): ../Sit_stand/robot/GPIOConst.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_robot_GPIOConst.cpp$(PreprocessSuffix) ../Sit_stand/robot/GPIOConst.cpp

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_Linux_tasks.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/socketCAN/CO_Linux_tasks.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/socketCAN/CO_Linux_tasks.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_socketCAN_CO_Linux_tasks.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/socketCAN/CO_Linux_tasks.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/crc16-ccitt.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/crc16-ccitt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(DependSuffix): ../Single_joint/CANopenNode/stack/crc16-ccitt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/crc16-ccitt.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/crc16-ccitt.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/crc16-ccitt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/crc16-ccitt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/crc16-ccitt.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/CO_trace.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/CO_trace.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(DependSuffix): ../Single_joint/CANopenNode/stack/CO_trace.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/CO_trace.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_trace.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/CO_trace.c

$(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(ObjectSuffix): ../Single_joint/stateMachine/bendTest.cpp $(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/stateMachine/bendTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(DependSuffix): ../Single_joint/stateMachine/bendTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(DependSuffix) -MM ../Single_joint/stateMachine/bendTest.cpp

$(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(PreprocessSuffix): ../Single_joint/stateMachine/bendTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_stateMachine_bendTest.cpp$(PreprocessSuffix) ../Single_joint/stateMachine/bendTest.cpp

$(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(ObjectSuffix): ../Single_joint/canopend/src/main.cpp $(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(DependSuffix): ../Single_joint/canopend/src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(DependSuffix) -MM ../Single_joint/canopend/src/main.cpp

$(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(PreprocessSuffix): ../Single_joint/canopend/src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_src_main.cpp$(PreprocessSuffix) ../Single_joint/canopend/src/main.cpp

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix): ../BeagleNode/CANopenNode/stack/CO_SDOmaster.c $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/CANopenNode/stack/CO_SDOmaster.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix): ../BeagleNode/CANopenNode/stack/CO_SDOmaster.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix) -MM ../BeagleNode/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix): ../BeagleNode/CANopenNode/stack/CO_SDOmaster.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix) ../BeagleNode/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/CO_SDOmaster.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/CO_SDOmaster.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix): ../Single_joint/CANopenNode/stack/CO_SDOmaster.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/CO_SDOmaster.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDOmaster.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/CO_SDOmaster.c

$(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(ObjectSuffix): ../Benchmark/stateMachine/Event.cpp $(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/stateMachine/Event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(DependSuffix): ../Benchmark/stateMachine/Event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(DependSuffix) -MM ../Benchmark/stateMachine/Event.cpp

$(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(PreprocessSuffix): ../Benchmark/stateMachine/Event.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_stateMachine_Event.cpp$(PreprocessSuffix) ../Benchmark/stateMachine/Event.cpp

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/CO_SYNC.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/CO_SYNC.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(DependSuffix): ../Single_joint/CANopenNode/stack/CO_SYNC.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/CO_SYNC.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/CO_HBconsumer.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/CO_HBconsumer.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix): ../Benchmark/CANopenNode/stack/CO_HBconsumer.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/CO_HBconsumer.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/CO_SDO.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/CO_SDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(DependSuffix): ../Single_joint/CANopenNode/stack/CO_SDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/CO_SDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(ObjectSuffix): ../Single_joint_Vel_Control/robot/GPIOManager.cpp $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/robot/GPIOManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(DependSuffix): ../Single_joint_Vel_Control/robot/GPIOManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(DependSuffix) -MM ../Single_joint_Vel_Control/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(PreprocessSuffix): ../Single_joint_Vel_Control/robot/GPIOManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_robot_GPIOManager.cpp$(PreprocessSuffix) ../Single_joint_Vel_Control/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/CO_PDO.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/CO_PDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(DependSuffix): ../Single_joint/CANopenNode/stack/CO_PDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/CO_PDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_PDO.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/CO_PDO.c

$(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(ObjectSuffix): ../Single_joint/robot/GPIOManager.cpp $(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/robot/GPIOManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(DependSuffix): ../Single_joint/robot/GPIOManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(DependSuffix) -MM ../Single_joint/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(PreprocessSuffix): ../Single_joint/robot/GPIOManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_robot_GPIOManager.cpp$(PreprocessSuffix) ../Single_joint/robot/GPIOManager.cpp

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix): ../Single_joint/CANopenNode/stack/CO_HBconsumer.c $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/CANopenNode/stack/CO_HBconsumer.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix): ../Single_joint/CANopenNode/stack/CO_HBconsumer.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix) -MM ../Single_joint/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix): ../Single_joint/CANopenNode/stack/CO_HBconsumer.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix) ../Single_joint/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(ObjectSuffix): ../Single_joint/canopend/src/pinread.cpp $(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/src/pinread.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(DependSuffix): ../Single_joint/canopend/src/pinread.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(DependSuffix) -MM ../Single_joint/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(PreprocessSuffix): ../Single_joint/canopend/src/pinread.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_src_pinread.cpp$(PreprocessSuffix) ../Single_joint/canopend/src/pinread.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(ObjectSuffix): ../BeagleNode/TaskStatemachine/Supervisor.cpp $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/TaskStatemachine/Supervisor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(DependSuffix): ../BeagleNode/TaskStatemachine/Supervisor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(DependSuffix) -MM ../BeagleNode/TaskStatemachine/Supervisor.cpp

$(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(PreprocessSuffix): ../BeagleNode/TaskStatemachine/Supervisor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_TaskStatemachine_Supervisor.cpp$(PreprocessSuffix) ../BeagleNode/TaskStatemachine/Supervisor.cpp

$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(ObjectSuffix): ../Single_joint/canopend/objDict/CO_ODorig.c $(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/objDict/CO_ODorig.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(DependSuffix): ../Single_joint/canopend/objDict/CO_ODorig.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(DependSuffix) -MM ../Single_joint/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(PreprocessSuffix): ../Single_joint/canopend/objDict/CO_ODorig.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_ODorig.c$(PreprocessSuffix) ../Single_joint/canopend/objDict/CO_ODorig.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_HBconsumer.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/CANopenNode/stack/CO_HBconsumer.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_HBconsumer.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(DependSuffix) -MM ../Single_joint_Vel_Control/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix): ../Single_joint_Vel_Control/CANopenNode/stack/CO_HBconsumer.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_CANopenNode_stack_CO_HBconsumer.c$(PreprocessSuffix) ../Single_joint_Vel_Control/CANopenNode/stack/CO_HBconsumer.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(ObjectSuffix): ../Single_joint/canopend/src/CO_time.c $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/src/CO_time.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(DependSuffix): ../Single_joint/canopend/src/CO_time.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(DependSuffix) -MM ../Single_joint/canopend/src/CO_time.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(PreprocessSuffix): ../Single_joint/canopend/src/CO_time.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_time.c$(PreprocessSuffix) ../Single_joint/canopend/src/CO_time.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(ObjectSuffix): ../Single_joint/canopend/src/CO_master.c $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/src/CO_master.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(DependSuffix): ../Single_joint/canopend/src/CO_master.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(DependSuffix) -MM ../Single_joint/canopend/src/CO_master.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(PreprocessSuffix): ../Single_joint/canopend/src/CO_master.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_master.c$(PreprocessSuffix) ../Single_joint/canopend/src/CO_master.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_driver.c $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Sit_stand/CANopenNode/stack/socketCAN/CO_driver.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_driver.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(DependSuffix) -MM ../Sit_stand/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix): ../Sit_stand/CANopenNode/stack/socketCAN/CO_driver.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Sit_stand_CANopenNode_stack_socketCAN_CO_driver.c$(PreprocessSuffix) ../Sit_stand/CANopenNode/stack/socketCAN/CO_driver.c

$(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(ObjectSuffix): ../BeagleNode/canopencgi/CANopenCGI.c $(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/BeagleNode/canopencgi/CANopenCGI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(DependSuffix): ../BeagleNode/canopencgi/CANopenCGI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(DependSuffix) -MM ../BeagleNode/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(PreprocessSuffix): ../BeagleNode/canopencgi/CANopenCGI.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_BeagleNode_canopencgi_CANopenCGI.c$(PreprocessSuffix) ../BeagleNode/canopencgi/CANopenCGI.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(ObjectSuffix): ../Single_joint/canopend/src/CO_comm_helpers.c $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/src/CO_comm_helpers.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(DependSuffix): ../Single_joint/canopend/src/CO_comm_helpers.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(DependSuffix) -MM ../Single_joint/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(PreprocessSuffix): ../Single_joint/canopend/src/CO_comm_helpers.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_comm_helpers.c$(PreprocessSuffix) ../Single_joint/canopend/src/CO_comm_helpers.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(ObjectSuffix): ../Single_joint/canopend/src/CO_command.c $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/src/CO_command.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(DependSuffix): ../Single_joint/canopend/src/CO_command.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(DependSuffix) -MM ../Single_joint/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(PreprocessSuffix): ../Single_joint/canopend/src/CO_command.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_src_CO_command.c$(PreprocessSuffix) ../Single_joint/canopend/src/CO_command.c

$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(ObjectSuffix): ../Single_joint/canopend/objDict/CO_OD.c $(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/objDict/CO_OD.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(DependSuffix): ../Single_joint/canopend/objDict/CO_OD.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(DependSuffix) -MM ../Single_joint/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(PreprocessSuffix): ../Single_joint/canopend/objDict/CO_OD.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_objDict_CO_OD.c$(PreprocessSuffix) ../Single_joint/canopend/objDict/CO_OD.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/crc16-ccitt.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/crc16-ccitt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(DependSuffix): ../Benchmark/CANopenNode/stack/crc16-ccitt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/crc16-ccitt.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_crc16-ccitt.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/crc16-ccitt.c

$(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(ObjectSuffix): ../Single_joint/canopend/app/application.cpp $(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint/canopend/app/application.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(DependSuffix): ../Single_joint/canopend/app/application.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(DependSuffix) -MM ../Single_joint/canopend/app/application.cpp

$(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(PreprocessSuffix): ../Single_joint/canopend/app/application.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_canopend_app_application.cpp$(PreprocessSuffix) ../Single_joint/canopend/app/application.cpp

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/CO_SYNC.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/CO_SYNC.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(DependSuffix): ../Benchmark/CANopenNode/stack/CO_SYNC.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/CO_SYNC.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SYNC.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/CO_SYNC.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(ObjectSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_ODtest.c $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Single_joint_Vel_Control/canopend/objDict/CO_ODtest.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(DependSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_ODtest.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(DependSuffix) -MM ../Single_joint_Vel_Control/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(PreprocessSuffix): ../Single_joint_Vel_Control/canopend/objDict/CO_ODtest.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Single_joint_Vel_Control_canopend_objDict_CO_ODtest.c$(PreprocessSuffix) ../Single_joint_Vel_Control/canopend/objDict/CO_ODtest.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(ObjectSuffix): ../Benchmark/CANopenNode/stack/CO_SDO.c $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Github/ALEX/exo/Benchmark/CANopenNode/stack/CO_SDO.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(DependSuffix): ../Benchmark/CANopenNode/stack/CO_SDO.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(DependSuffix) -MM ../Benchmark/CANopenNode/stack/CO_SDO.c

$(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix): ../Benchmark/CANopenNode/stack/CO_SDO.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_Benchmark_CANopenNode_stack_CO_SDO.c$(PreprocessSuffix) ../Benchmark/CANopenNode/stack/CO_SDO.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


