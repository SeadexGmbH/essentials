// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <string>
#include <gtest/gtest.h>
#include <iostream>

#include "essentials/type_wrapper.hpp"


SXE_CREATE_TYPE_IN_NAMESPACE( test, sx_string, std::string );
SXE_CREATE_TYPE_IN_NAMESPACE( test, sx_number, int);
SXE_CREATE_TYPE_IN_NAMESPACE( test, sx_double, double );
SXE_CREATE_TYPE_IN_NAMESPACE( test, sx_float, float );
SXE_CREATE_TYPE_IN_NAMESPACE( test, sx_bool, bool );


TEST( essentials_test, type_wrapper_test_string ) 
{
	const std::string product_strg = "essentials";
	const std::string company = ( "Seadex GmbH" );
	const std::string complete_name = ( "essentials from Seadex GmbH" );

	auto essentials = test::sx_string( product_strg );
	EXPECT_EQ( essentials.get_raw(), product_strg );

	essentials.set_raw( company );
	EXPECT_EQ( essentials.get_raw(), company );

	const auto company2 = test::sx_string( company );
	EXPECT_TRUE( essentials == company2 );
}


TEST( essentials_test, type_wrapper_test_int ) 
{
	const int a = 10;
	const int b = 2010;

	auto essentials = test::sx_number( a );
	EXPECT_EQ( essentials.get_raw(), a );

	essentials.set_raw( b );
	EXPECT_EQ( essentials.get_raw(), b );

	const auto company_id_2 = test::sx_number( b );
	EXPECT_TRUE( essentials == company_id_2 );
}


TEST( essentials_test, type_wrapper_test_double ) 
{
	const double a = 10.10;
	const double b = 2010.01;

	auto essentials = test::sx_double( a );
	EXPECT_EQ( essentials.get_raw(), a );

	essentials.set_raw( b );
	EXPECT_EQ( essentials.get_raw(), b );

	const auto company_id_2 = test::sx_double( b );
	EXPECT_TRUE( essentials == company_id_2 );
}


TEST( essentials_test, type_wrapper_test_float ) 
{
	const float a = 10.10f;
	const float b = 2010.01f;

	auto essentials = test::sx_float( a );
	EXPECT_EQ( essentials.get_raw(), a );

	essentials.set_raw( b );
	EXPECT_EQ( essentials.get_raw(), b );

	const auto company_id_2 = test::sx_float( b );
	EXPECT_TRUE( essentials == company_id_2 );
}


TEST( essentials_test, type_wrapper_test_logical_and )
{
	test::sx_bool var_1( false );
	test::sx_bool var_2( false );
	test::sx_bool var_3( true );
	test::sx_bool var_4( true );

	EXPECT_FALSE( var_1 && var_2 );
	EXPECT_TRUE( var_3 && var_4 );
	EXPECT_FALSE( var_3 && var_1 );
	EXPECT_FALSE( var_2 && var_4 );	
}


TEST( essentials_test, type_wrapper_test_logical_or )
{
	test::sx_bool var_1( false );
	test::sx_bool var_2( false );
	test::sx_bool var_3( true );

	EXPECT_FALSE( var_1 || var_2 );
	EXPECT_TRUE( var_1 || var_3 );
	EXPECT_TRUE( var_3 || var_2 );
}


TEST( essentials_test, type_wrapper_test_logical_not )
{
	test::sx_bool var_1( false );
	test::sx_bool var_2( true );
	test::sx_bool var_3( false );
	test::sx_bool var_4( true );

	auto result_1 = !var_1;
	auto result_2 = !var_2;

	EXPECT_EQ( result_1, var_2 );
	EXPECT_EQ( result_2, var_1 );
	EXPECT_EQ( var_1, var_3 );
	EXPECT_EQ( var_2, var_4 );
}
