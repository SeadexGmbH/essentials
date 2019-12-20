// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <gtest/gtest.h>

#include "essentials/math.hpp"


TEST( math_test, math_test_round_double_1 )
{
	double start_value = 123.4567;
	const auto rounded = sxe::round( start_value, 0 );

	EXPECT_EQ( rounded, 123.0 );
}


TEST( math_test, math_test_round_double_2 )
{
	double start_value = 123.4567;
	const auto rounded = sxe::round( start_value, 1 );

	EXPECT_EQ( rounded, 123.5 );
}


TEST( math_test, math_test_round_double_3 )
{
	double start_value = 123.4567;
	const auto rounded = sxe::round( start_value, 2 );

	EXPECT_EQ( rounded, 123.46 );
}



TEST( math_test, math_test_round_double_4 )
{
	double start_value = 123.4567;
	const auto rounded = sxe::round( start_value, 3 );

	EXPECT_EQ( rounded, 123.457 );
}


TEST( math_test, math_test_round_double_5 )
{
	double start_value = 123.4567;
	const auto rounded = sxe::round( start_value, 4 );

	EXPECT_EQ( rounded, start_value );
}


TEST( math_test, math_test_round_double_6 )
{
	double start_value = -123.4567;
	const auto rounded = sxe::round( start_value, 4 );

	EXPECT_EQ( rounded, start_value );
}


TEST( math_test, math_test_round_double_7 )
{
	double start_value = -123.4567;
	const auto rounded = sxe::round( start_value, 3 );

	EXPECT_EQ( rounded, -123.457 );
}


TEST( math_test, math_test_round_double_8 )
{
	double start_value = -123.4567;
	const auto rounded = sxe::round( start_value, 2 );

	EXPECT_EQ( rounded, -123.46 );
}