// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <gtest/gtest.h>

#include "essentials/conversion.hpp"


TEST( conversion_test, convertion_test_string_to_int )
{
	int result = 0;
	const bool converted = sxe::string_to_integer( "64", result );

	EXPECT_EQ( result, 64 );
	EXPECT_EQ( converted, true );
}


TEST( conversion_test, convertion_test_empty_string_to_int )
{
	int result = 0;
	const bool converted = sxe::string_to_integer( "", result );

	EXPECT_EQ( result, 0 );
	EXPECT_EQ( converted, false );
}


TEST( conversion_test, convertion_test_float_string_to_int )
{
	int result = 0;
	const bool converted = sxe::string_to_integer( "64,59", result );

	EXPECT_EQ( result, 64 );
	EXPECT_EQ( converted, false );
}


TEST( conversion_test, convertion_test_to_upper_1 )
{
	const std::string converted = sxe::to_upper( "hello essentials Lib 1.2.0" );
	EXPECT_EQ( converted, "HELLO ESSENTIALS LIB 1.2.0" );
}


TEST( conversion_test, convertion_test_to_upper_2 )
{
	const std::string converted = sxe::to_upper( "heLLo EsSeNtIaLs Lib 1.2.0" );
	EXPECT_EQ( converted, "HELLO ESSENTIALS LIB 1.2.0" );
}


TEST( conversion_test, convertion_test_to_lower_1 )
{
	const std::string converted = sxe::to_lower( "HELLO ESSENTIALS LIB 1.2.0" );
	EXPECT_EQ( converted, "hello essentials lib 1.2.0" );
}


TEST( conversion_test, convertion_test_to_lower_2 )
{
	const std::string converted = sxe::to_lower( "HELLO ESSENTIALS LIB 1.2.0 TesT_2" );
	EXPECT_EQ( converted, "hello essentials lib 1.2.0 test_2" );
}
