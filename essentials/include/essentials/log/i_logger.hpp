// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef I_LOG_F6936964_2F14_4B9C_964D_184D8D9C9FAE
#define I_LOG_F6936964_2F14_4B9C_964D_184D8D9C9FAE


#include <string>

#include "essentials/non_copyable.hpp"
#include "essentials/log/log_level.hpp"


namespace sxe
{


//!\interface i_logger
//!\brief Interface used by the logger manager to call the log function.
class i_logger
{
public:
	//!\brief Constructor.
	i_logger()
	{
		// Nothing to do...
	}


	virtual ~i_logger() noexcept
	{
		// Nothing to do...
	}


	SXE_NO_COPY( i_logger )

	//!\brief Function to log a message.
	//!\param _file File to be logged.
	//!\param _line Line to be logged.
	//!\param _log_level Log level of the log.
	//!\param _message Message to be logged.
	virtual void log( const std::string& _file, const int _line, const sxe::log_level _log_level,
		const std::string& _message ) = 0;
};


}


#endif
