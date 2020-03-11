/*
 * Logging interface for ALEX exoskeleton.
 *
 * @file        logUtilities.cpp
 * @author      Mihai Blaga
 * @copyright   2020 Mihai Blaga
 *
 * Written to provide robust logging functionality to the ALEX exoskeleton.
 * 
 * USAGE: when a logger is set up, publish logs to the desired location by calling
 * loggerName->message_priority(desired_message);
 * 
 * Message Priorities:
 * logger->info();
 * logger->error();
 * logger->warn();
 * logger->critical();
 * logger->debugger();
 * 
 * For more information, refer to <https://github.com/gabime/spdlog> 
 */
#include "logUtilities.h"

const char* DEFAULT_LOGGER_STYLE = "%v";

/******************************************************************************/
//creating a logger at a designated fileLocation.
std::shared_ptr<spdlog::logger> createLogger(std::string logID, std::string fileLocation)
{
	try
	{
		auto logger = spdlog::basic_logger_mt(logID, fileLocation);
		logger->set_pattern(DEFAULT_LOGGER_STYLE);
		return logger;
	}
	catch (const spdlog::spdlog_ex &ex)
	{
		std::cout << "Failed to create log: " << logID << std::endl << ex.what() << std::endl;
	}
}