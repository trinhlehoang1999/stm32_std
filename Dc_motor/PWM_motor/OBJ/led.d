// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#ifndef OPENCV_LOGGER_HPP
#define OPENCV_LOGGER_HPP

#include <iostream>
#include <sstream>
#include <limits.h> // INT_MAX

#include "logger.defines.hpp"
#include "logtag.hpp"

//! @addtogroup core_logging
// This section describes OpenCV logging utilities.
//
//! @{

namespace cv {
namespace utils {
namespace logging {

/** Set global logging level
@return previous logging level
*/
CV_EXPORTS LogLevel setLogLevel(LogLevel logLevel);
/** Get global logging level */
CV_EXPORTS LogLevel getLogLevel();

CV_EXPORTS void registerLogTag(cv::utils::logging::LogTag* plogtag);

CV_EXPORTS void setLogTagLevel(const char* tag, cv::utils::logging::LogLevel level);

CV_EXPORTS cv::utils::logging::LogLevel getLogTagLevel(const char* tag);

namespace internal {

/** Get global log tag */
CV_EXPORTS cv::utils::logging::LogTag* getGlobalLogTag();

/** Write log message */
CV_EXPORTS void writeLogMessage(LogLevel logLevel, const char* message);

/** Write log message */
CV_EXPORTS void writeLogMessageEx(LogLevel logLevel, const char* tag, const char* file, int line, const char* func, const char* message);

} // namespace

struct LogTagAuto
    : public LogTag
{
    inline LogTagAuto(const char* _name, LogLevel _level)
        : LogTag(_name, _level)
    {
        registerLogTag(this);
    }
};

/**
 * \def CV_LOG_STRIP_LEVEL
 *
 * Define CV_LOG_STRIP_LEVEL=CV_LOG_LEVEL_[DEBUG|INFO|WARN|ERROR|FATAL|SIL