// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef CONTEXT_TESTER_497C9148_1BB6_11EC_9621_0242AC130002
#define CONTEXT_TESTER_497C9148_1BB6_11EC_9621_0242AC130002


#include "essentials/non_copyable.hpp"
#include "essentials/execution/context.hpp"


namespace sxe
{


class context_tester final
{
public:
	context_tester( sxe::context& _context, const std::string& _name );
	~context_tester() noexcept = default;
	SXE_NO_COPY( context_tester )
	void foo() const;
	void bar() const;
	void say_hello( const std::string& _name ) const;


private:
	context& context_;
};


}


#endif
