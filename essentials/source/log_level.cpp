// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/log/log_level.hpp"

#include <map>


#include "essentials/assert.hpp"


namespace sxe
{


namespace 
{


const std::string LL_NAME_SPAM = "SPAM";
const std::string LL_NAME_TRACE = "TRACE";
const std::string LL_NAME_DEBUG = "DEBUG";
const std::string LL_NAME_INFO = "INFO";
const std::string LL_NAME_WARN = "WARN";
const std::string LL_NAME_ERROR = "ERROR";
const std::string LL_NAME_FATAL = "FATAL";
const std::string LL_NAME_DIAG = "DIAG";


const std::map< std::string, log_level > LL_NAME_TO_LL = 
{
	{ LL_NAME_SPAM, LL_TRACE },
	{ LL_NAME_TRACE, LL_TRACE },
	{ LL_NAME_DEBUG, LL_DEBUG },
	{ LL_NAME_INFO, LL_INFO },
	{ LL_NAME_WARN, LL_WARN },
	{ LL_NAME_ERROR, LL_ERROR },
	{ LL_NAME_FATAL, LL_FATAL },
	{ LL_NAME_DIAG, LL_FATAL }
};


const std::map< log_level, std::string > LL_TO_LL_NAME =
{
	{ LL_TRACE, LL_NAME_TRACE },
	{ LL_DEBUG, LL_NAME_DEBUG },
	{ LL_INFO, LL_NAME_INFO },
	{ LL_WARN, LL_NAME_WARN },
	{ LL_ERROR, LL_NAME_ERROR },
	{ LL_FATAL, LL_NAME_FATAL },
	{ LL_FATAL, LL_NAME_DIAG }
};


}


// cppcheck-suppress unusedFunction
std::string get_log_level_name( const log_level& _log_level )
{
	auto result = LL_NAME_ERROR;
	const auto log_level_to_log_level_name_it = LL_TO_LL_NAME.find( _log_level );
	SXE_ASSERT( log_level_to_log_level_name_it != LL_TO_LL_NAME.end(), "Log level not found!" );
	result = log_level_to_log_level_name_it->second;
	return( result );
}


// cppcheck-suppress unusedFunction
log_level get_log_level_by_name( const std::string& _log_level_name )
{
	auto result = LL_ERROR;
	const auto log_level_by_name_it = LL_NAME_TO_LL.find( _log_level_name );
	if( log_level_by_name_it != LL_NAME_TO_LL.end() )
	{
		result = log_level_by_name_it->second;
	}
	else
	{
		throw exception( "There is no log level with the name '{}'!", _log_level_name );
	}
	
	return( result );
}


}
