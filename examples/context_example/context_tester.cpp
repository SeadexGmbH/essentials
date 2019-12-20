// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "context_tester.hpp"

#include "essentials/execution/context_macros.hpp"
#include "essentials/log/log.hpp"


namespace sxe
{


context_tester::context_tester( context& _context, const std::string& _name ) :
	context_( _context )
{
	const auto user_configuration = sxe::context_user_configuration(
		[ _name ] () { SXE_LOG( LL_DEBUG, "Hello from init hook of {}!", _name ); },
		[ _name ] () { SXE_LOG( LL_DEBUG, "Hello from execute hook of {}!", _name ); },
		[ _name ] () { SXE_LOG( LL_DEBUG, "Hello from cleanup hook of {}!", _name ); } );

	context_.add_user_configuration( user_configuration );
}


void context_tester::foo() const
{
	SXE_CONTEXT_OPEN()
	SXE_LOG( LL_DEBUG, "foo hi!" );
	std::this_thread::sleep_for( std::chrono::milliseconds( 25 ) );
	SXE_LOG( LL_DEBUG, "foo by!" );
	SXE_CONTEXT_NAME_CLOSE_SYNC( context_ )
}


void context_tester::bar() const
{
	SXE_CONTEXT_OPEN()
	SXE_LOG( LL_DEBUG, "bar hi!" );
	std::this_thread::sleep_for( std::chrono::milliseconds( 35 ) );
	SXE_LOG( LL_DEBUG, "bar by!" );
	SXE_CONTEXT_NAME_CLOSE_SYNC( context_ )
}


void context_tester::say_hello( const std::string& _name ) const
{
	SXE_CONTEXT_OPEN( _name )
	SXE_LOG( LL_DEBUG, "__ Hello {}! __", _name );
	std::this_thread::sleep_for( std::chrono::milliseconds( 45 ) );
	SXE_LOG( LL_DEBUG, "__ Bye bye {}! __", _name );
	SXE_CONTEXT_NAME_CLOSE_SYNC( context_ )
}


}