// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef LOG_SINK_TYPE_9F4DB3AE_1620_11EC_9621_0242AC130002
#define LOG_SINK_TYPE_9F4DB3AE_1620_11EC_9621_0242AC130002


#include "essentials/enhanced_enum.hpp"


namespace sxe
{

//!\brief Sink enumerator.
SXE_ENHANCED_ENUM( log_sink_type, STD_SINK, SYSLOG_SINK, FILE_SINK, ANDROID_SINK )

}


#endif
