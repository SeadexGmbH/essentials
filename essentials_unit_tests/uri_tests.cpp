// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <gtest/gtest.h>

#include "essentials/uri.hpp"


TEST( essentials_uri_test, essentials_uri_test_1 ) 
{

	const auto compatibility_hpp_path = sxe::uri( "essentials/compatibilit/compatibility.hpp" );
	EXPECT_EQ( compatibility_hpp_path.size(), 3 );
	EXPECT_EQ( compatibility_hpp_path.get_front(), "essentials" );
	EXPECT_FALSE( compatibility_hpp_path.is_empty() );
}


TEST( essentials_uri_test, essentials_uri_test_2 )
{
	const std::string essentials_product_path = "home/products/c++/libraries/essentials";
	const auto essentials_path = sxe::uri( essentials_product_path );
	EXPECT_EQ( essentials_path.size(), 5 );
	EXPECT_EQ( essentials_path.get_front(), "home" );
	EXPECT_FALSE( essentials_path.is_empty() );
}


TEST( essentials_uri_test, essentials_uri_test_3 )
{
	const std::string empty_path = "";
	const auto tested_path = sxe::uri( empty_path );
	EXPECT_EQ( tested_path.size(), 0 );
	EXPECT_TRUE( tested_path.is_empty() );
}


TEST( essentials_uri_test, essentials_uri_test_4 )
{
	sxe::uri root_uri( "home/products/c++" );
	const sxe::uri branch_uri( "libraries/essentials" );
	const sxe::uri essentials_product_uri( "home/products/c++/libraries/essentials" );

	root_uri.push_back( branch_uri );
	EXPECT_EQ( root_uri.size(), 5 );
	EXPECT_EQ( root_uri.get_front(), "home" );
	EXPECT_EQ( root_uri.get_back(), "essentials" );
	EXPECT_EQ( root_uri.to_string(), essentials_product_uri.to_string() );
	EXPECT_FALSE( root_uri.is_empty() );
}


TEST( essentials_uri_test, essentials_uri_test_5 )
{
	sxe::uri root_uri( "home/products/c++" );
	const sxe::uri branch_uri( "libraries/essentials" );
	const sxe::uri essentials_product_uri( "home/products/c++/libraries/essentials" );

	root_uri = root_uri / branch_uri;
	EXPECT_EQ( root_uri.size(), 5 );
	EXPECT_EQ( root_uri.get_front(), "home" );
	EXPECT_EQ( root_uri.get_back(), "essentials" );
	EXPECT_EQ( root_uri.to_string(), essentials_product_uri.to_string() );
	EXPECT_FALSE( root_uri.is_empty() );
}


TEST( essentials_uri_test, essentials_uri_test_6 )
{
	sxe::uri root_uri( "home/products/c++" );
	const std::string branch_uri( "libraries/essentials" );
	const sxe::uri essentials_product_uri( "home/products/c++/libraries/essentials" );

	root_uri = root_uri / branch_uri;
	EXPECT_EQ( root_uri.size(), 5 );
	EXPECT_EQ( root_uri.get_front(), "home" );
	EXPECT_EQ( root_uri.get_back(), "essentials" );
	EXPECT_EQ( root_uri.to_string(), essentials_product_uri.to_string() );
	EXPECT_FALSE( root_uri.is_empty() );
}


TEST( essentials_uri_test, essentials_uri_test_7 )
{
	sxe::uri root_uri( "home/products/c++" );
	const std::string branch_uri_1( "libraries" );
	const std::string branch_uri_2( "essentials" );
	const sxe::uri essentials_product_uri( "home/products/c++/libraries/essentials" );

	const auto result_uri = root_uri.push_back( branch_uri_1 ).push_back( branch_uri_2 );
	EXPECT_EQ( result_uri.size(), 5 );
	EXPECT_EQ( result_uri.get_front(), "home" );
	EXPECT_EQ( result_uri.get_back(), "essentials" );
	EXPECT_EQ( result_uri.to_string(), essentials_product_uri.to_string() );
	EXPECT_FALSE( result_uri.is_empty() );
}
