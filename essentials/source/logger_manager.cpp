// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/log/logger_manager.hpp"

#include "essentials/log/logger.hpp"
#include "essentials/log/null_logger.hpp"
#include "essentials/assert.hpp"


namespace sxe
{


logger_manager& logger_manager::get_instance()
{
	static logger_manager static_logger_manager;
	return( static_logger_manager );
}


void logger_manager::set_logger( i_logger& _logger )
{
	logger_ = &_logger;
}


i_logger& logger_manager::get_logger()
{
	SXE_ASSERT( logger_, "No logger!" );
	return( *logger_ );
}


logger_manager::logger_manager()
	: logger_()
{


#ifdef ESS_USE_NULL_LOGGER
	logger_ = &null_logger::get_instance();
#else
	logger_ = &logger::get_instance();
#endif


}


}
