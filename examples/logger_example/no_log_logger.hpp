// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef NO_LOG_LOGGER_EDB6CD25_51C1_4040_A202_4EDB8FEB7459
#define NO_LOG_LOGGER_EDB6CD25_51C1_4040_A202_4EDB8FEB7459


#include "essentials/log/i_logger.hpp"


namespace sxe::test
{


class no_log_logger
	: public virtual sxe::i_logger
{
public:
	no_log_logger();
	virtual ~no_log_logger() noexcept override = default;
	SXE_NO_COPY( no_log_logger )

	virtual void log( [[maybe_unused]] const std::string& _file, [[maybe_unused]] const int _line, 
		[[maybe_unused]] const sxe::log_level _log_level, 
		[[maybe_unused]] const std::string& _message ) override;
};


}


#endif
