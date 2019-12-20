// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/execution/context_user_configuration.hpp"


namespace sxe 
{


context_user_configuration::context_user_configuration( const hook& _init_hook,
	const hook& _post_execute_hook, const hook& _cleanup_hook ) :
		init_hook_( _init_hook ), 
		post_execute_hook_( _post_execute_hook ), 
		cleanup_hook_( _cleanup_hook )
{
	// nothing to do...
}


const context_user_configuration::hook& context_user_configuration::get_init_hook() const
{
	return( init_hook_ );
}


const context_user_configuration::hook& context_user_configuration::get_post_execute_hook() const
{
	return( post_execute_hook_ );
}


const context_user_configuration::hook& context_user_configuration::get_cleanup_hook() const
{
	return( cleanup_hook_ );
}


}
