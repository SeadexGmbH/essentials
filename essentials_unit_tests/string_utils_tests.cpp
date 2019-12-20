// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <gtest/gtest.h>

#include "essentials/string_utils.hpp"


TEST( string_utils_test, string_utils_test_replace_1 )
{
	const std::string data = "abc def ghi jkl";
	const auto result = sxe::replace_all( data, " ", "_" );
	const std::string expected = "abc_def_ghi_jkl";

	EXPECT_EQ( result, expected );
}


TEST( string_utils_test, string_utils_test_replace_2 )
{
	const std::string data = "abc_def_ghi_jkl";
	const auto result = sxe::replace_all( data, "_", " " );
	const std::string expected = "abc def ghi jkl";

	EXPECT_EQ( result, expected );
}


TEST( string_utils_test, string_utils_test_split_1 )
{
	const std::string data = "abc_def_ghi_jkl";
	const std::vector< std::string > result = sxe::split( data, "_");
	const std::vector< std::string > expected = { "abc", "def", "ghi", "jkl" };

	EXPECT_EQ( result.size(), expected.size() );
	EXPECT_EQ( result.at( 0 ), expected.at( 0 ) );
	EXPECT_EQ( result.at( 1 ), expected.at( 1 ) );
	EXPECT_EQ( result.at( 2 ), expected.at( 2 ) );
	EXPECT_EQ( result.at( 3 ), expected.at( 3 ) );
}


TEST( string_utils_test, string_utils_test_split_2 )
{
	const std::string data = "abc def ghi jkl abc abc";
	const std::vector< std::string > result = sxe::split( data, " " );
	const std::vector< std::string > expected = { "abc", "def", "ghi", "jkl", "abc", "abc" };

	EXPECT_EQ( result.size(), expected.size() );
	EXPECT_EQ( result.at( 0 ), expected.at( 0 ) );
	EXPECT_EQ( result.at( 1 ), expected.at( 1 ) );
	EXPECT_EQ( result.at( 2 ), expected.at( 2 ) );
	EXPECT_EQ( result.at( 3 ), expected.at( 3 ) );
	EXPECT_EQ( result.at( 4 ), expected.at( 4 ) );
	EXPECT_EQ( result.at( 5 ), expected.at( 5 ) );
}
