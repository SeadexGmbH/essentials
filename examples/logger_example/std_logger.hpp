// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).

#ifndef STD_LOGGER_D7E31E40_47C8_4184_96E1_9854E851B5AD
#define STD_LOGGER_D7E31E40_47C8_4184_96E1_9854E851B5AD


#include <iostream>

#include "essentials/log/i_logger.hpp"


namespace sxe::test
{

class std_logger
	: public virtual sxe::i_logger
{
public:
	std_logger();
	virtual ~std_logger() noexcept override = default;
	SXE_NO_COPY( std_logger )

	virtual void log( const std::string& _file, const int _line, const sxe::log_level _log_level,
		const std::string& _message ) override;
};

}


#endif
