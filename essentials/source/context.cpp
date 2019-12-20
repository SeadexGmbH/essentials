// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/execution/context.hpp"

#include "essentials/assert.hpp"
#include "essentials/log/log.hpp"


namespace sxe
{


context::context( const std::string& _name, const context_configuration& _configuration ) :
	name_( _name ),
	configuration_( _configuration ),
	run_( false ),
	context_thread_(),
	context_mutex_(),
	context_condition_(),
	command_queue_()
{
	// nothing to do...
}


void context::start()
{
	SXE_LOG( LL_DEBUG, "[context {}] Starting.", name_ );
	SXE_ASSERT( !context_thread_, "[context {}] There already is a context thread!", name_ );

	run_ = true;
	context_thread_ = sxe::make_unique< std::thread >( &context::run, this );

	SXE_LOG( LL_DEBUG, "[context {}] Started.", name_ );
}


void context::stop()
{
	SXE_LOG( LL_DEBUG, "[context {}] Requesting stop.", name_ );

	{
		std::lock_guard< std::mutex > lock( context_mutex_ );
		SXE_ASSERT( context_thread_, "[context {}] There's no context thread!", name_ );
		run_ = false;
	}
	context_condition_.notify_all();

	SXE_LOG( LL_DEBUG, "[context {}] Requested stop.", name_ );
}


void context::join()
{
	SXE_LOG( LL_DEBUG, "[context {}] Joining.", name_ );
	SXE_ASSERT( context_thread_, "[context {}] There's no context thread!", name_ );
	SXE_ASSERT( context_thread_->joinable(), "[context {}] Context thread is not joinable!", name_ );

	{
		std::lock_guard<std::mutex> lock( context_mutex_ );
		SXE_ASSERT( !run_, "[context {}] Still running!", name_ );
	}

	context_thread_->join();
	context_thread_.reset();

	SXE_ASSERT( command_queue_.empty(), "[context {}] Command queue is not empty!", name_ );
	SXE_LOG( LL_DEBUG, "[context {}] Joined.", name_ );
}


void context::add_user_configuration( const context_user_configuration& _configuration )
{
	if( _configuration.get_init_hook() )
	{
		init_hooks_.push_back( _configuration.get_init_hook() );
	}

	if( _configuration.get_post_execute_hook() )
	{
		post_execute_hooks_.push_back( _configuration.get_post_execute_hook() );
	}

	if( _configuration.get_cleanup_hook() )
	{
		cleanup_hooks_.push_back( _configuration.get_cleanup_hook() );
	}
}


context::future context::execute_async( logic_function&& _f ) const
{
	SXE_ASSERT( _f, "[context {}] No valid logic function!", name_ );

	std::shared_ptr< promise > _promise = std::make_shared< promise >();

	auto _command = std::make_shared< command >(
		[ this, _f, _promise ] ()
		{
			try
			{
				_f();
				_promise->set_value();
			}
			catch( const std::exception& _exception )
			{
				_promise->set_exception( std::make_exception_ptr( execution_failed( "[Contcontextext {}] Exception: {}",
					name_, _exception.what() ) ) );
			}
			catch( ... )
			{
				_promise->set_exception( std::make_exception_ptr( execution_failed( "[context {}] Unknown exception!", name_ ) ) );
			}
		}
	);

	enqueue( *_promise, _command );

	return( _promise->get_future() );
}


void context::execute_sync( logic_function&& _f ) const
{
	execute_async( std::move( _f ) ).get();
}


void context::enqueue( promise& _promise, command_sptr _command ) const
{
	std::lock_guard< std::mutex > lock( context_mutex_ );

	if( run_ )
	{
		command_queue_.push( _command );
		context_condition_.notify_one();
	}
	else
	{
		_promise.set_exception( std::make_exception_ptr( enqueue_failed( "[context {}] Enqueue failed!", name_ ) ) );
	}
}


bool context::wait_predicate() const
{
	return( !run_ || !command_queue_.empty() );
}


void context::run()
{
	SXE_LOG( LL_DEBUG, "[context {}] Thread is running.", name_ );

	try
	{
		execute_hooks( init_hooks_ );

		while( true )
		{
			command_sptr command;
			{
				std::unique_lock< std::mutex > lock( context_mutex_ );
				context_condition_.wait( lock, [this] () { return( wait_predicate() ); } );

				if( !run_ && command_queue_.empty() )
				{
					break;
				}

				if( !command_queue_.empty() )
				{
					command = command_queue_.front();
					command_queue_.pop();
				}
			}

			if( command )
			{
				( *command )( );
			}

			execute_hooks( post_execute_hooks_ );
		}
	}
	catch( const std::exception& _exception )
	{
		SXE_LOG( LL_FATAL, "[context {}] Unhandled std::exception: {}", name_, _exception.what() );
		run_ = false;
		configuration_.unhandled_exception_handler_( std::current_exception(), name_ );
	}
	catch( ... )
	{
		SXE_LOG( LL_FATAL, "[context {}] Unknown exception!", name_ );
		run_ = false;
		configuration_.unhandled_exception_handler_( std::current_exception(), name_ );
	}

	try
	{
		execute_hooks( cleanup_hooks_ );
	}
	catch( const std::exception& _exception )
	{
		SXE_LOG( LL_FATAL, "[context {}] Unhandled std::exception: {}", name_, _exception.what() );
		run_ = false;
		configuration_.unhandled_exception_handler_( std::current_exception(), name_ );
	}
	catch( ... )
	{
		SXE_LOG( LL_FATAL, "[context {}] Unknown exception!", name_ );
		run_ = false;
		configuration_.unhandled_exception_handler_( std::current_exception(), name_ );
	}

	SXE_LOG( LL_DEBUG, "[context {}] Thread stopped.", name_ );
}


void context::execute_hooks( const hooks& _hooks )
{
	for( const auto& hook : _hooks )
	{
		hook();
	}
}


}
