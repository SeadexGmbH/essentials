// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "context_tester.hpp"

#include "essentials/log/log.hpp"
#include "essentials/exception.hpp"
#include "essentials/execution/context_configuration.hpp"


void worker_1( sxe::context_tester& _tester )
{
	SXE_LOG( LL_DEBUG, "Worker 1" );

	for( int i = 0; i < 10; ++i )
	{
		try
		{
			_tester.foo();
			_tester.bar();
			_tester.say_hello( "John Doe" );
		}
		catch( const sxe::context::execution_failed& _exception ) {
			SXE_LOG( LL_FATAL, "Thread 1: Exception: {}", _exception.what() );
		}

		std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );
	}

	SXE_LOG( LL_DEBUG, "Worker 1" );
}


void worker_2( sxe::context_tester& _tester )
{
	SXE_LOG( LL_DEBUG, "Worker 2" );

	for( int i = 0; i < 10; ++i )
	{
		try
		{
			_tester.foo();
			_tester.say_hello( "Max Mustermann" );
			_tester.bar();
		}
		catch( const sxe::context::execution_failed& _exception )
		{
			SXE_LOG( LL_FATAL, "Thread 2: Exception: {}", _exception.what() );
		}

		std::this_thread::sleep_for( std::chrono::milliseconds( 120 ) );
	}

	SXE_LOG( LL_DEBUG, "Worker 2" );
}


namespace sxe
{


SXE_EXCEPTION( context_exception )


}


int main()
{
	auto& logger = sxe::logger::get_instance();
	logger.set_log_level( LL_TRACE );
	logger.add_std_out_sink();

	const sxe::context_configuration config;
	sxe::context context( "SxTestContext", config );

	sxe::context_tester tester( context, "tester");
	sxe::context_tester tester_2( context, "tester_2");

	context.start();

	std::thread thread_1( [ &tester ] () { worker_1( tester ); } );
	std::thread thread_2( [ &tester_2 ] () { worker_2( tester_2 ); } );

	thread_1.join();
	thread_2.join();

	context.stop();
	context.join();
}
