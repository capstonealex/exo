/*
 * Application interface for CANopenSocket.
 *
 * @file        application.c
 * @author      Janez Paternoster
 * @copyright   2016 Janez Paternoster
 *
 * This file is part of CANopenSocket, a Linux implementation of CANopen
 * stack with master functionality. Project home page is
 * <https://github.com/CANopenNode/CANopenSocket>. CANopenSocket is based
 * on CANopenNode: <https://github.com/CANopenNode/CANopenNode>.
 *
 * CANopenSocket is free and open source software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "logUtilities.h"

//setting the style of the logger to only hold the data without any metadata.
void setLoggerStyle(std::shared_ptr<spdlog::logger> logger)
{
	logger->set_pattern("%v");
}

/******************************************************************************/
//creating a logger at a designated fileLocation.
std::shared_ptr<spdlog::logger> createLogger(std::string logID, std::string fileLocation)
{
	try
	{
		auto logger = spdlog::basic_logger_mt(logID, fileLocation);
		setLoggerStyle(logger);
		return logger;
	}
	catch (const spdlog::spdlog_ex &ex)
	{
		std::cout << "Failed to create log: " << ex.what() << std::endl;
	}
}