// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/essentials_version.hpp"

#include <iostream>
#include <fmt/format.h>


namespace sxe
{


namespace version
{


namespace
{


const std::uint16_t VERSION_MAJOR( 2 );
const std::uint16_t VERSION_MINOR( 1 );
const std::uint16_t VERSION_PATCH( 2 );


}


// cppcheck-suppress unusedFunction
void log_version()
{
	std::cout << fmt::format( "essentials library version {}.{}.{}.", get_major_version(),
		get_minor_version(), get_patch_version() ) << std::endl;
}


std::uint16_t get_major_version()
{
	return( VERSION_MAJOR );
}


std::uint16_t get_minor_version()
{
	return( VERSION_MINOR );
}


std::uint16_t get_patch_version()
{
	return( VERSION_PATCH );
}


}


}
