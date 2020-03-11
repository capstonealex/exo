/**
 * Utilities for logging.
 *
 * @file        logUtilities.h
 * @author      Mihai Blaga
 * @copyright   2020 Mihai Blaga
 * 
 */

#ifndef CO_APPLICATION_H
#define CO_APPLICATION_H

//relevant for logging
#include <iostream>
#include <string.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

/*
* Function is used to abstract away the log creation process
*/
std::shared_ptr<spdlog::logger> createLogger(std::string logID, std::string fileLocation);

/*
* Sets the style of the logs to the default previously defined
*/
void setLoggerStyle(std::shared_ptr<spdlog::logger> logger);

#endif
