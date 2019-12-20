// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "no_log_logger.hpp"

namespace sxe::test
{


no_log_logger::no_log_logger()
{
	// Nothing to do...
}


void no_log_logger::log( [[maybe_unused]] const std::string& _file, 
	[[maybe_unused]] const int _line, [[maybe_unused]] const sxe::log_level _log_level,
	[[maybe_unused]] const std::string& _message )
{
	// Nothing to do...
}


}
