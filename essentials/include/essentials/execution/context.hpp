// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef CONTEXT_09CD24EC_148E_11EC_82A8_0242AC130003
#define CONTEXT_09CD24EC_148E_11EC_82A8_0242AC130003


#include <thread>
#include <queue>
#include <future>
#include <mutex>
#include <condition_variable>

#include "essentials/compatibility/compatibility.hpp"
#include "essentials/execution/context_user_configuration.hpp"
#include "essentials/execution/context_configuration.hpp"


namespace sxe
{

//!\class context
//!\brief A class that manages the context thread.
class context final
{
public:
	SXE_EXCEPTION( execution_failed )
	SXE_EXCEPTION( enqueue_failed )

	//!\typedef logic_function
	//!\brief Alias for the std::function< void() >.
	using logic_function = std::function< void() >;
	//!\typedef future
	//!\brief Alias for the std::future< void >.
	using future = std::future< void >;

	//!\brief Constructor.
	//!\param _name The name of the context.
	//!\param _configuration Context configuration.
	context( const std::string& _name, const context_configuration& _configuration = context_configuration() );
	~context() noexcept = default;
	SXE_NO_COPY( context )

	//!\brief Start the thread run.
	void start();

	//!\brief Stop the thread run.
	void stop();

	//!\brief Join the thread run.
	void join();

	//!\brief Add a user configuration.
	//!\param _configuration Context user configuration.
	void add_user_configuration( const context_user_configuration& _configuration );

	//!\brief Execute the given function asynchronously.
	//!\param f The function to execute.
	//!\return future
	future execute_async( logic_function&& f ) const;

	//!\brief Execute the given function synchronously.
	//!\param f The function to execute.
	void execute_sync( logic_function&& f ) const;


private:
	using promise = std::promise< void >;
	using thread_ptr = std::unique_ptr< std::thread >;
	using command = std::function< void() >;
	using command_sptr = std::shared_ptr< command >;
	using queue = std::queue< command_sptr >;
	using hooks = std::vector< context_user_configuration::hook >;


	void enqueue( promise& _promise, command_sptr _command ) const;
	bool wait_predicate() const;
	void run();
	void execute_hooks( const hooks& _hooks );


	const std::string name_;
	const context_configuration configuration_;
	bool run_;
	thread_ptr context_thread_;
	mutable std::mutex context_mutex_;
	mutable std::condition_variable context_condition_;
	mutable queue command_queue_;
	hooks init_hooks_;
	hooks post_execute_hooks_;
	hooks cleanup_hooks_;
};


}


#endif
