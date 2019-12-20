// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <gtest/gtest.h>

#include "essentials/enhanced_enum.hpp"


SXE_ENHANCED_ENUM( Keys, MACRO, ENUM, LOG, CONVERTER, EXCEPTION, WRAPPER, HELPER_FUNCTION )
SXE_ENHANCED_ENUM_NUMERIC( Software, YASMINE, 3, ESSENTIALS, 6, PANDEMIC, 7, HERMES, 13, GENESIS, 4, YARCH, 8 )
SXE_ENHANCED_ENUM_NUMERIC( Dummy_enum, ENUM_1, 1, ENUM_2, 2, ENUM_3, 3, ENUM_4, 4, ENUM_5, 5, ENUM_6, 6, ENUM_7, 7, ENUM_8, 8, ENUM_9, 9, ENUM_10, 10,
	ENUM_11, 11, ENUM_12, 12, ENUM_13, 13, ENUM_14, 14, ENUM_15, 15, ENUM_16, 16, ENUM_17, 17, ENUM_18, 18, ENUM_19, 19, ENUM_20, 20,
	ENUM_21, 21, ENUM_22, 22, ENUM_23, 23, ENUM_24, 24, ENUM_25, 25, ENUM_26, 26, ENUM_27, 27, ENUM_28, 28, ENUM_29, 29, ENUM_30, 30,
	ENUM_31, 31, ENUM_32, 32, ENUM_33, 33, ENUM_34, 34, ENUM_35, 35, ENUM_36, 36, ENUM_37, 37, ENUM_38, 38, ENUM_39, 39, ENUM_40, 40,
	ENUM_41, 41, ENUM_42, 42, ENUM_43, 43, ENUM_44, 44, ENUM_45, 45, ENUM_46, 46, ENUM_47, 47, ENUM_48, 48, ENUM_49, 49,
	ENUM_50, 50 )


TEST( essentials_enhanced_enum_test, sx_enum_test_max )
{
	Dummy_enum key2( "ENUM_50" );
	EXPECT_EQ( Dummy_enum( Dummy_enum::ENUM_50 ), key2 );
}


TEST( essentials_enhanced_enum_test, sx_enum_test )
{
	Keys key( Keys::EXCEPTION );
	EXPECT_EQ( key.to_string(), "EXCEPTION" );
	EXPECT_EQ( key, Keys( Keys::EXCEPTION ) );
}


TEST( essentials_enhanced_enum_test, sx_enum_test_to_string )
{
	Software software( "PANDEMIC" );
	EXPECT_EQ( software.to_string(), "PANDEMIC" );
	EXPECT_EQ( Software( Software::PANDEMIC ).to_string(), "PANDEMIC" );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_from_string )
{
	EXPECT_EQ( Software::YARCH, Software().from_string( "YARCH" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_from_string_throw )
{
	EXPECT_THROW( { Software().from_string( "NON_EXISTING" ); }, Software::exception);
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_from_string_no_throw )
{
	EXPECT_EQ( Software::HERMES, Software().from_string_no_throw( "HERMES" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_from_int )
{
	EXPECT_EQ( Software::GENESIS, Software().from_int( 4 ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_from_int_throw )
{
	EXPECT_THROW( { Software().from_int( 12 ); }, Software::exception );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_equal )
{
	EXPECT_TRUE( Software::GENESIS == Software().from_string( "GENESIS" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_numeric_test_operator_equal )
{
	EXPECT_TRUE( Software( Software::GENESIS ) == Software( Software().from_string( "GENESIS" ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_smaller )
{
	EXPECT_TRUE( Software::ESSENTIALS < Software().from_string( "HERMES" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_smaller_or_equal )
{
	EXPECT_TRUE( Software::HERMES <= Software().from_string( "HERMES" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_smaller_or_equal_2)
{
	EXPECT_TRUE( Software::ESSENTIALS <= Software().from_string( "HERMES" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_smaller_enum )
{
	EXPECT_TRUE( Software( Software::ESSENTIALS ) < Software( Software().from_string( "HERMES" ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_smaller_enum_2 )
{
	EXPECT_TRUE( Software::ESSENTIALS < Software::HERMES );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_smaller_or_equal_enum )
{
	EXPECT_TRUE( Software( Software::ESSENTIALS ) <= Software( Software().from_string( "ESSENTIALS" ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_smaller_or_equal_2_enum )
{
	EXPECT_TRUE( Software( Software::ESSENTIALS ) <= Software( Software().from_string( "HERMES" ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_greater )
{
	EXPECT_TRUE( Software::ESSENTIALS > Software().from_string( "GENESIS" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_greater_or_equal )
{
	EXPECT_TRUE( Software::GENESIS >= Software().from_string( "GENESIS" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_greater_or_equal_2 )
{
	EXPECT_TRUE( Software::ESSENTIALS >= Software().from_string( "GENESIS" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_greater_enum )
{
	EXPECT_TRUE( Software( Software::ESSENTIALS ) > Software( Software().from_string( "GENESIS" ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_greater_enum_2 )
{
	EXPECT_TRUE( Software::ESSENTIALS > Software::GENESIS );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_greater_or_equal_enum )
{
	EXPECT_TRUE( Software( Software::ESSENTIALS ) >= Software( Software().from_string( "ESSENTIALS" ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_greater_or_equal_2_enum )
{
	EXPECT_TRUE( Software( Software::HERMES ) >= Software( Software().from_string( "ESSENTIALS" ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_not_equal )
{
	EXPECT_TRUE( Software::GENESIS != Software().from_string( "PANDEMIC" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_not_equal_enum )
{
	EXPECT_TRUE( Software( Software::GENESIS ) != Software( Software().from_string( "PANDEMIC" ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_input )
{
	Software software( "PANDEMIC" );
	std::ostringstream string_enum;
	string_enum << software;
	EXPECT_TRUE( Software( Software::GENESIS ) != Software( Software().from_string( string_enum.str() ) ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_test_operator_value )
{
	Software software( "PANDEMIC" );

	switch( software )
	{
	case Software::ESSENTIALS:
		EXPECT_TRUE( false );
		break;
	case Software::PANDEMIC:
		EXPECT_TRUE( software == Software( Software::PANDEMIC ) );
		break;
	default:
		EXPECT_TRUE( false );
		break;
	}
}


TEST( essentials_enhanced_enum_test, enhanced_enum_numeric_test_is_valid_representation_string )
{
	EXPECT_TRUE( Software().is_valid_representation( "GENESIS" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_numeric_test_is_valid_representation_string_false )
{
	EXPECT_FALSE( Software().is_valid_representation( "_GENESIS_" ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_numeric_test_is_valid_representation_int )
{
	EXPECT_TRUE( Software().is_valid_representation( 3 ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_numeric_test_is_valid_representation_int_false )
{
	EXPECT_FALSE( Software().is_valid_representation( 12 ) );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_constructor )
{
	const auto software = Software( Software::PANDEMIC ) ;
	EXPECT_EQ( software.to_string(), "PANDEMIC" );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_constructor_2 )
{
	const auto software_original = Software( Software::GENESIS);
	const auto software = Software( software_original );
	EXPECT_EQ( software.to_string(), "GENESIS" );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_constructor_3 )
{
	const auto software = Software( "GENESIS" );
	EXPECT_EQ( software.to_string(), "GENESIS" );
}


TEST( essentials_enhanced_enum_test, enhanced_enum_constructor_4 )
{
	const auto software = Software( 4 );
	EXPECT_EQ( software.to_string(), "GENESIS" );
}

