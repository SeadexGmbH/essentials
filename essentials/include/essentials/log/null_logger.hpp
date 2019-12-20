// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef NULL_LOGGER_D08A7146_A2DC_4952_8325_98C0B227FE9C
#define NULL_LOGGER_D08A7146_A2DC_4952_8325_98C0B227FE9C


#include <cassert>


#include "essentials/log/i_logger.hpp"


namespace sxe
{


//!\class null_logger
//!\brief Singleton class that does nothing on log calls.
class null_logger
	: public virtual i_logger
{
public:
	//!\brief Get the instance of the singleton.
	static null_logger& get_instance();

	//!\brief An inherited function that does nothing with the given parameters.
	virtual void log( [[maybe_unused]] const std::string& _file, [[maybe_unused]] const int _line, 
		[[maybe_unused]] const sxe::log_level _log_level, [[maybe_unused]] const std::string& _message ) override;


private:
	null_logger();
	virtual ~null_logger() noexcept override = default;
	SXE_NO_COPY( null_logger )
};

}


#endif
