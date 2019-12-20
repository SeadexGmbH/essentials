// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "std_logger.hpp"


namespace sxe::test
{


std_logger::std_logger()
{
	// Nothing to do...
}


void std_logger::log( const std::string& _file, const int _line, const sxe::log_level _log_level,
	const std::string& _message )
{
	std::cout << "[" << _file << "]  [" << _line << "] [" << sxe::get_log_level_name( _log_level ) << "] : " << _message << "\n";
}

}
