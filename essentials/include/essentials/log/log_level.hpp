// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef LOG_LEVEL_7041E0BC_160C_11EC_9621_0242AC130002
#define LOG_LEVEL_7041E0BC_160C_11EC_9621_0242AC130002


#if defined( __linux__) || defined( __ANDROID__ )
#include <syslog.h>
#endif


#include <spdlog/spdlog.h>


namespace sxe
{


//!\typedef log_level
//!\brief Alias for the spdlog::level::level_enum.
using log_level = spdlog::level::level_enum;

//!\brief Function to get the log level name of the given log level as a string.
//!\param _log_level Log level.
//!\return std::string Log level name as a string.
std::string get_log_level_name( const log_level& _log_level );

//!\brief Function to get the log level by the given string name.
//!\param _log_level_name Log level name as a string.
//!\return log_level Log level.
log_level get_log_level_by_name( const std::string& _log_level_name );


}


//!\brief LL_TRACE - Trace log level.
constexpr sxe::log_level LL_TRACE = spdlog::level::trace;

//!\brief LL_DEBUG - Debug log level.
constexpr sxe::log_level LL_DEBUG = spdlog::level::debug;

//!\brief LL_INFO - Information log level.
constexpr sxe::log_level LL_INFO = spdlog::level::info;

//!\brief LL_WARN - Warning log level.
constexpr sxe::log_level LL_WARN = spdlog::level::warn;

//!\brief LL_ERROR - Error log level.
constexpr sxe::log_level LL_ERROR = spdlog::level::err;

//!\brief LL_FATAL - Fatal error log level.
constexpr sxe::log_level LL_FATAL = spdlog::level::critical;

//!\brief LL_OFF - OFF log level.
constexpr sxe::log_level LL_OFF = spdlog::level::off;


#endif
