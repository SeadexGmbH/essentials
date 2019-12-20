// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef CONTEXT_USER_CONFIGURATION_18A6F1CA_1491_11EC_82A8_0242AC130003
#define CONTEXT_USER_CONFIGURATION_18A6F1CA_1491_11EC_82A8_0242AC130003


#include <string>
#include <memory>
#include <functional>

#include "essentials/exception_template.hpp"
#include "essentials/non_copyable.hpp"


namespace sxe 
{


//!\class context_user_configuration
//!\brief User configuration for the context structure.
class context_user_configuration final
{
public:
	//!\typedef hook
	//!\brief Alias for the std::function< void() >.
	using hook = std::function< void() >;

	//!\brief Constructor.
	//!\param _init_hook Function to execute before the thread execution.
	//!\param _post_execute_hook Function to execute after the thread execution.
	//!\param _cleanup_hook Function to execute on cleanup.
	context_user_configuration( const hook& _init_hook, const hook& _post_execute_hook, const hook& _cleanup_hook );
	~context_user_configuration() noexcept = default;
	SXE_NO_COPY( context_user_configuration )

	//!\brief Get the initial hook.
	//!\return hook Function to execute before the thread execution.
	const hook& get_init_hook() const;

	//!\brief Get the post-execution hook.
	//!\return hook Function to execute after the thread execution.
	const hook& get_post_execute_hook() const;

	//!\brief Get the cleanup hook.
	//!\return hook Function to execute on cleanup.
	const hook& get_cleanup_hook() const;


private:
	const hook init_hook_;
	const hook post_execute_hook_;
	const hook cleanup_hook_;
};


}


#endif
