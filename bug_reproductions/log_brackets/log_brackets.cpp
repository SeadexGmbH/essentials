// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <iostream>

#include "fmt/format.h"

#include "essentials/log/log.hpp"
#include "essentials/assert.hpp"



int main()
{
    std::cout << "Hello World!\n";

		sxe::logger::get_instance().set_log_level( LL_TRACE );
		sxe::logger::get_instance().add_std_out_sink();

		auto text = "Some text with no curly bracket.";
		auto formated_text = fmt::format( text );
		std::cout << formated_text << "\n";
		SXE_LOG( LL_TRACE, text );

		text = "Some text with no open curly bracket and with a parameter '{}'.";
		auto param = "hello world";
		formated_text = fmt::format( text, "hello world" );
		std::cout << formated_text << "\n";
		SXE_LOG( LL_TRACE, text, param );

		text = "Some text with open curly bracket {{.";
		formated_text = fmt::format( text );
		std::cout << formated_text << "\n";
		SXE_LOG( LL_TRACE, text );

		text = "Some text with open curly bracket {{ and with a parameter '{}'.";
		formated_text = fmt::format( text, param );
		std::cout << formated_text << "\n";
		SXE_LOG( LL_TRACE, text, param );

		text = "Some text with parameter '{}'.";
		param = "foo { bar";
		formated_text = fmt::format( text, param );
		std::cout << formated_text << "\n";
		SXE_LOG( LL_TRACE, text, param );


		std::cout << fmt::format( "'{}'!", "!#$%&'()+,-.@`_}~.bin" ) << "\n";
		SXE_LOG( LL_TRACE, "'{}'!", "!#$%&'()+,-.@`_}~.bin" );
		const int a = 2;
		SXE_ASSERT( a == 2, "this is false!");
}
