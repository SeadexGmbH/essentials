// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef CONTEXT_CONFIGURATION_02D338C2_2030_11EC_9621_0242AC130002
#define CONTEXT_CONFIGURATION_02D338C2_2030_11EC_9621_0242AC130002


#include <functional>

#include "essentials/log/log.hpp"
#include "essentials/exception_utils.hpp"


namespace sxe
{


//!\struct context_configuration
//!\brief Context configuration structure.
struct context_configuration
{
	//!\typedef unhandled_exception_handler
	//!\brief Alias for the unhandled exception handler function.
	using unhandled_exception_handler = std::function< void( const std::exception_ptr, const std::string& ) >;

	//!\brief Unhandled exception handler function.
	unhandled_exception_handler unhandled_exception_handler_ = [] ( const std::exception_ptr _exception, const std::string& _name )
	{
		SXE_LOG( LL_FATAL, "Caught unhandled exception in context {}!", _name );
		SXE_LOG( LL_FATAL, "{}", what( _exception ) );
		std::abort();
	};
};


}

#endif
