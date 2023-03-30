// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef LOG_6A83F606_1620_11EC_9621_0242AC130002
#define LOG_6A83F606_1620_11EC_9621_0242AC130002

#include "essentials/log/logger_manager.hpp"
#include "essentials/log/logger.hpp"
#include "essentials/preprocessor/macro_helpers.hpp"

//!\def SXE_LOG( level, ... )
//!\brief Macro to create a log line. Line and file are auto-detected. The level and the message are user provided.
#define SXE_LOG( level, ... ) sxe::logger_manager::get_instance().get_logger().log( __FILE__, __LINE__, level, fmt::format( __VA_ARGS__ ) )

//!\def SXE_LOG_LOCATED( level, ... )
//!\brief Macro to create a log line. All data is user provided.
#define SXE_LOG_LOCATED( level, file, line, ... ) sxe::logger_manager::get_instance().get_logger().log( file, line, level, fmt::format( __VA_ARGS__ ) )

//!\def SXE_LOG_HEX( level, object, title )
//!\brief Macro to log HEX values.
#define SXE_LOG_HEX( level, object, title ) SXE_LOG( level, "{}: {:a}", title, spdlog::to_hex( object, 16 ) )


#ifdef _WIN32


#undef min
#undef max

// deactivate macro 'GetObject' from wingdi.h
#undef GetObject

#endif


#endif
