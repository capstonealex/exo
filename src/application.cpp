/*
 * Application interface for Alex Exoskeleton Software
 *
 * @file        application.c
 * @author      William Campbell
 *

 */
#include "application.h"
//#include <spdlog/spdlog.h>
//#include <spdlog/sinks/basic_file_sink.h>

//// Data logger helper functions
//void fileLoggerBinary();
//void fileLogHeader();
//void fileLogger();
//void strreverse(char *begin, char *end);
//void itoa(int value, char *str, int base);

/* File has been modified by Mihai Blaga on 24/10 to implement more robust
 * logging through the implementation of spdlog.
 */
/*auto* createLogger(std::string logID, std::string fileLocation);
//Path to the file in which all of the log files are stored.
const std::string logFolder = "\logs\";
*/

/*For master-> node SDO message sending*/
#define CO_COMMAND_SDO_BUFFER_SIZE 100000
#define STRING_BUFFER_SIZE (CO_COMMAND_SDO_BUFFER_SIZE * 4 + 100)
#include <string.h>
char buf[STRING_BUFFER_SIZE];
char ret[STRING_BUFFER_SIZE];

ExoRobot exo;
exoStateMachine exoMachine;

/******************************************************************************/
void app_programStart(void)
{
	printf("app_Program Start \n");
	exoMachine.initRobot(&exo);
	exoMachine.init();
	exoMachine.activate();
}
/******************************************************************************/
void app_communicationReset(void)
{
}
/******************************************************************************/
void app_programEnd(void)
{
	printf("app_programEnd \n");
}
/******************************************************************************/
void app_programAsync(uint16_t timer1msDiffy)
{
}
//setting the style of the logger to only hold the data without any extra information.
/*void setLoggerStyle(spdlog::logger logger){
    logger->set_pattern("%v");

}*/

/******************************************************************************/
//creating a logger at a designated fileLocation.
/*    spdlog::logger createLogger(std::string logID, std::string fileLocation) {
        try {
            auto logger = spdlog::basic_logger_mt(logID, fileLocation);
            setLoggerStyle(logger);
            return logger;
        } catch (const spdlog::spdlog_ex &ex) {
            std::cout << "Failed to create log: " << ex.what() << std::endl;
        }
    }
    
*/
/******************************************************************************/
void app_program1ms(void)
{
	// std::cout << "BEAGLE NEXT MOVE:" << CO_OD_RAM.nextMovement << std::endl;
	//auto mainLogger = createLogger("parent", logFolder + "X2_log.txt");
	//spdlog::set_default_logger(mainLogger);

	//fileLoggerBinary(mainLogger);'
	if (exoMachine.running != 0)
	{
		//printf("Before hwstateupdate \n");
		exoMachine.hwStateUpdate();
		//printf("Before update \n");

		exoMachine.update();
		//printf("After update \n");
	}
	//auto mainLogger = createLogger("parent", logFolder + "X2_log.txt");
	//spdlog::set_default_logger(mainLogger);
	//fileLoggerBinary(mainLogger);
}
/******************************************************************************/
/*void itoa(int value, char *str, int base)
{
    static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *wstr = str;
    int sign;
    // Validate base
    if (base < 2 || base > 35)
    {
        *wstr = '\0';
        return;
    }
    // Take care of sign
    if ((sign = value) < 0)
        value = -value;
    // Conversion. Number is reversed.
    do
        *wstr++ = num[value % base];
    while (value /= base);
    if (sign < 0)
        *wstr++ = '-';
    *wstr = '\0';
    // Reverse string
    strreverse(str, wstr - 1);
}*/
/******************************************************************************/
/*void strreverse(char *begin, char *end)
{
    char aux;
    while (end > begin)
        aux = *end, *end-- = *begin, *begin++ = aux;
}*/
/******************************************************************************/
/*void fileLogger(auto* logger){
    //printf("fileLogger beggining\n");
	
    // Generate whatever you want logged here, "data" is just an example
    	char position [50];
	char timestamp [50];
    	char torque[50];
    	char comma[] = ", ";
	
	//Getting timestamp
	//printf("time(s): %lu, (us): %lu\n",tv.tv_sec, tv.tv_usec);
    	//itoa(timer1msDiff, position, 10);
	struct timeval tv;
	gettimeofday(&tv,NULL);
	itoa(tv.tv_sec, timestamp, 10);
	
	mainLogger->info("{}, ", timestamp);
	
	itoa(tv.tv_usec, timestamp, 10);
	
	mainLogger->info("{}, ", timestamp);
	
	uint32_t motorpos[4];
	uint16_t motorTor[4];
	
	motorpos[0] = CO_OD_RAM.actualMotorPositions.motor1;
	motorpos[1] = CO_OD_RAM.actualMotorPositions.motor2;
	motorpos[2] = CO_OD_RAM.actualMotorPositions.motor3;
	motorpos[3] = CO_OD_RAM.actualMotorPositions.motor4;
	
	motorTor[0] = CO_OD_RAM.statusWords.motor1;
	motorTor[1] = CO_OD_RAM.statusWords.motor2;
	motorTor[2] = CO_OD_RAM.statusWords.motor3;
	motorTor[3] = CO_OD_RAM.statusWords.motor4;*/

/* Motor 1: Left Hip
	 * Motor 2: Left Knee
	 * Motor 3: Right Hip
	 * Motor 4: Right Knee
	 */

/*	std::stringstream output;
	
	for (int i = 0; i<4; i++){
		itoa(motorpos[i], position, 10);
		itoa(motorTor[i], torque, 10);
		
		output << position << ", " << torque << ", ";
	}
	
	output << "\n";
	
	logger->info(output.str());
	
}
void fileLogHeader(auto* logger){
   	mainLogger = createLogger("parent", logFolder + "X2_log.txt");
	spdlog::set_default_logger(mainLogger);
	
	std::stringstream header;
	
    	header << "======================================\n";
    	header << "X2 exoskeleton torque and position log\n";
    	header << "======================================\n";
    	header << "Time(s), time(ms) LHPos, LHT, LKPos, LKT, RHPos, RHT, RKPos, RKT\n";
    
	logger->info(header.str());
}

void fileLoggerBinary(auto* logger){
    	mainLogger = createLogger("parent", logFolder + "parent.txt");
	spdlog::set_default_logger(mainLogger);

    	struct timeval tv;
    	gettimeofday(&tv,NULL);

	uint32_t motorpos[4];
	uint16_t motorTor[4];

	motorpos[0] = CO_OD_RAM.actualMotorPositions.motor1;
	motorpos[1] = CO_OD_RAM.actualMotorPositions.motor2;
	motorpos[2] = CO_OD_RAM.actualMotorPositions.motor3;
	motorpos[3] = CO_OD_RAM.actualMotorPositions.motor4;
	
	motorTor[0] = CO_OD_RAM.statusWords.motor1;
	motorTor[1] = CO_OD_RAM.statusWords.motor2;
	motorTor[2] = CO_OD_RAM.statusWords.motor3;
	motorTor[3] = CO_OD_RAM.statusWords.motor4;
	
    	long long timesec=tv.tv_sec;
    	long timeusec=tv.tv_usec;

	logger->info("{}", timesec);
	logger->info("{}", timeusec);
	
	for(int i = 0; i<4; i++){
		mainLogger->info("{}", &motorpos[i]);
		mainLogger->info("{}", &motorTor[i]);
	}
}
*/
