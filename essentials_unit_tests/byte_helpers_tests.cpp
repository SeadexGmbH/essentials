// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).

#include <gtest/gtest.h>

#include "essentials/byte_helpers.hpp"
#include "essentials/file.hpp"


TEST( byte_helpers_tests, byte_to_bool_1 )
{
	std::uint8_t number_to_check = 0x36; // bits: 0011 0110

	bool bool_from_bit_0 = sxe::extract_bool_from_byte( 0, number_to_check );
	bool bool_from_bit_1 = sxe::extract_bool_from_byte( 1, number_to_check );
	bool bool_from_bit_2 = sxe::extract_bool_from_byte( 2, number_to_check );
	bool bool_from_bit_3 = sxe::extract_bool_from_byte( 3, number_to_check );
	bool bool_from_bit_4 = sxe::extract_bool_from_byte( 4, number_to_check );
	bool bool_from_bit_5 = sxe::extract_bool_from_byte( 5, number_to_check );
	bool bool_from_bit_6 = sxe::extract_bool_from_byte( 6, number_to_check );
	bool bool_from_bit_7 = sxe::extract_bool_from_byte( 7, number_to_check );

	EXPECT_FALSE( bool_from_bit_0 );
	EXPECT_TRUE( bool_from_bit_1 );
	EXPECT_TRUE( bool_from_bit_2 );
	EXPECT_FALSE( bool_from_bit_3 );
	EXPECT_TRUE( bool_from_bit_4 );
	EXPECT_TRUE( bool_from_bit_5 );
	EXPECT_FALSE( bool_from_bit_6 );
	EXPECT_FALSE( bool_from_bit_7 );
}


TEST( byte_helpers_tests, byte_to_bool_2 )
{
	std::uint8_t number_to_check = 0xF0; // bits: 1111 0000

	bool bool_from_bit_0 = sxe::extract_bool_from_byte( 0, number_to_check );
	bool bool_from_bit_1 = sxe::extract_bool_from_byte( 1, number_to_check );
	bool bool_from_bit_2 = sxe::extract_bool_from_byte( 2, number_to_check );
	bool bool_from_bit_3 = sxe::extract_bool_from_byte( 3, number_to_check );
	bool bool_from_bit_4 = sxe::extract_bool_from_byte( 4, number_to_check );
	bool bool_from_bit_5 = sxe::extract_bool_from_byte( 5, number_to_check );
	bool bool_from_bit_6 = sxe::extract_bool_from_byte( 6, number_to_check );
	bool bool_from_bit_7 = sxe::extract_bool_from_byte( 7, number_to_check );

	EXPECT_FALSE( bool_from_bit_0 );
	EXPECT_FALSE( bool_from_bit_1 );
	EXPECT_FALSE( bool_from_bit_2 );
	EXPECT_FALSE( bool_from_bit_3 );
	EXPECT_TRUE( bool_from_bit_4 );
	EXPECT_TRUE( bool_from_bit_5 );
	EXPECT_TRUE( bool_from_bit_6 );
	EXPECT_TRUE( bool_from_bit_7 );
}


TEST( byte_helpers_tests, byte_to_bool_3 )
{
	std::uint8_t number_to_check = 0xAA; // bits: 1010 1010

	bool bool_from_bit_0 = sxe::extract_bool_from_byte( 0, number_to_check );
	bool bool_from_bit_1 = sxe::extract_bool_from_byte( 1, number_to_check );
	bool bool_from_bit_2 = sxe::extract_bool_from_byte( 2, number_to_check );
	bool bool_from_bit_3 = sxe::extract_bool_from_byte( 3, number_to_check );
	bool bool_from_bit_4 = sxe::extract_bool_from_byte( 4, number_to_check );
	bool bool_from_bit_5 = sxe::extract_bool_from_byte( 5, number_to_check );
	bool bool_from_bit_6 = sxe::extract_bool_from_byte( 6, number_to_check );
	bool bool_from_bit_7 = sxe::extract_bool_from_byte( 7, number_to_check );

	EXPECT_FALSE( bool_from_bit_0 );
	EXPECT_TRUE( bool_from_bit_1 );
	EXPECT_FALSE( bool_from_bit_2 );
	EXPECT_TRUE( bool_from_bit_3 );
	EXPECT_FALSE( bool_from_bit_4 );
	EXPECT_TRUE( bool_from_bit_5 );
	EXPECT_FALSE( bool_from_bit_6 );
	EXPECT_TRUE( bool_from_bit_7 );
}


TEST( byte_helpers_tests, bool_to_byte_basic )
{
	EXPECT_EQ( 0x1, sxe::inject_bool_into_byte( 0, true, 0x0 ) );
	EXPECT_EQ( 0x2, sxe::inject_bool_into_byte( 1, true, 0x0 ) );
	EXPECT_EQ( 0x4, sxe::inject_bool_into_byte( 2, true, 0x0 ) );
	EXPECT_EQ( 0x8, sxe::inject_bool_into_byte( 3, true, 0x0 ) );
	EXPECT_EQ( 0x10, sxe::inject_bool_into_byte( 4, true, 0x0 ) );
	EXPECT_EQ( 0x20, sxe::inject_bool_into_byte( 5, true, 0x0 ) );
	EXPECT_EQ( 0x40, sxe::inject_bool_into_byte( 6, true, 0x0 ) );
	EXPECT_EQ( 0x80, sxe::inject_bool_into_byte( 7, true, 0x0 ) );
}


TEST( byte_helpers_tests, bool_to_byte_0xA )
{
	std::uint8_t source_byte = 0xA;
	EXPECT_EQ( 0xB, sxe::inject_bool_into_byte( 0, true, source_byte ) );
	EXPECT_EQ( 0xA, sxe::inject_bool_into_byte( 1, true, source_byte ) );
	EXPECT_EQ( 0xE, sxe::inject_bool_into_byte( 2, true, source_byte ) );
	EXPECT_EQ( 0xA, sxe::inject_bool_into_byte( 3, true, source_byte ) );
	EXPECT_EQ( 0x1A, sxe::inject_bool_into_byte( 4, true, source_byte ) );
	EXPECT_EQ( 0x2A, sxe::inject_bool_into_byte( 5, true, source_byte ) );
	EXPECT_EQ( 0x4A, sxe::inject_bool_into_byte( 6, true, source_byte ) );
	EXPECT_EQ( 0x8A, sxe::inject_bool_into_byte( 7, true, source_byte ) );
}


TEST( byte_helpers_tests, bool_to_byte_0xAA )
{
	std::uint8_t source_byte = 0xAA;
	EXPECT_EQ( 0xAB, sxe::inject_bool_into_byte( 0, true, source_byte ) );
	EXPECT_EQ( 0xAA, sxe::inject_bool_into_byte( 1, true, source_byte ) );
	EXPECT_EQ( 0xAE, sxe::inject_bool_into_byte( 2, true, source_byte ) );
	EXPECT_EQ( 0xAA, sxe::inject_bool_into_byte( 3, true, source_byte ) );
	EXPECT_EQ( 0xBA, sxe::inject_bool_into_byte( 4, true, source_byte ) );
	EXPECT_EQ( 0xAA, sxe::inject_bool_into_byte( 5, true, source_byte ) );
	EXPECT_EQ( 0xEA, sxe::inject_bool_into_byte( 6, true, source_byte ) );
	EXPECT_EQ( 0xAA, sxe::inject_bool_into_byte( 7, true, source_byte ) );
}


TEST( byte_helpers_tests, byte_to_int_0x1 )
{
	std::vector<std::uint8_t> all_data( { 0x01, 0x00 } );
	const auto result = sxe::bytes_to_int<std::uint16_t>( all_data.data() );

	EXPECT_EQ( result, 0x1 );
}


TEST( byte_helpers_tests, byte_to_int_0x100 )
{
	std::vector<std::uint8_t> all_data( { 0x00, 0x01 } );

	const auto result = sxe::bytes_to_int<std::uint16_t>( all_data.data() );

	EXPECT_EQ( result, 0x100 );
}


TEST( byte_helpers_tests, byte_to_int16_0x3C01 )
{
	std::vector< std::uint8_t > all_data( { 0x01, 0x3C } );
	const auto result = sxe::bytes_to_int< std::uint16_t >( all_data.data() );

	EXPECT_EQ( result, 0x3C01 );
}


TEST( byte_helpers_tests, byte_to_int16_0x1DAB )
{
	std::vector< std::uint8_t > all_data( { 0xAB, 0x1D } );
	const auto result = sxe::bytes_to_int< std::uint16_t >( all_data.data() );

	EXPECT_EQ( result, 0x1DAB );
}


TEST( byte_helpers_tests, byte_to_int16_0x1DAF )
{
	std::vector< std::uint8_t > all_data( { 0xAF, 0x1D } );
	const auto result = sxe::bytes_to_int< std::uint16_t >( all_data.data() );

	EXPECT_EQ( result, 0x1DAF );
}


TEST( byte_helpers_tests, byte_to_int32_0x1DABAEDF )
{
	std::vector< std::uint8_t > all_data( { 0xDF, 0xAE, 0xAB, 0x1D } );
	const auto result = sxe::bytes_to_int< std::uint32_t >( all_data.data() );

	EXPECT_TRUE( result == 0x1DABAEDF );
}


TEST( byte_helpers_tests, int_to_byte_0x1 )
{
	std::vector<std::uint8_t> all_data( 2, 0 );
	sxe::int_to_bytes<std::uint16_t>( all_data.data(), 0x1 );
	EXPECT_EQ( all_data[ 1 ], 0x00 );
	EXPECT_EQ( all_data[ 0 ], 0x01 );
}


TEST( byte_helpers_tests, int_to_byte_0x100 )
{
	std::vector<std::uint8_t> all_data( 2, 0 );
	sxe::int_to_bytes<std::uint16_t>( all_data.data(), 0x100 );
	EXPECT_EQ( all_data[ 1 ], 0x01 );
	EXPECT_EQ( all_data[ 0 ], 0x00 );
}


TEST( byte_helpers_tests, int_to_byte_0x3C01 )
{
	std::vector<std::uint8_t> all_data( 2, 0 );
	sxe::int_to_bytes<std::uint16_t>( all_data.data(), 0x3C01 );
	EXPECT_EQ( all_data[ 1 ], 0x3C );
	EXPECT_EQ( all_data[ 0 ], 0x01 );
}


TEST( byte_helpers_tests, int_to_byte_0x1DAB )
{
	std::vector<std::uint8_t> all_data( 2, 0 );
	sxe::int_to_bytes<std::uint16_t>( all_data.data(), 0x1DAB );
	EXPECT_EQ( all_data[ 1 ], 0x1D );
	EXPECT_EQ( all_data[ 0 ], 0xAB );
}


TEST( byte_helpers_tests, int_to_byte_0x1DAF )
{
	std::vector<std::uint8_t> all_data( 2, 0 );
	sxe::int_to_bytes<std::uint16_t>( all_data.data(), 0x1DAF );
	EXPECT_EQ( all_data[ 1 ], 0x1D );
	EXPECT_EQ( all_data[ 0 ], 0xAF );
}


TEST( byte_helpers_tests, int_32_to_byte_0x1DABAEDF )
{
	std::vector<std::uint8_t> all_data( 4, 0 );
	sxe::int_to_bytes<std::uint32_t>( all_data.data(), 0x1DABAEDF );
	EXPECT_EQ( all_data[ 3 ], 0x1D );
	EXPECT_EQ( all_data[ 2 ], 0xAB );
	EXPECT_EQ( all_data[ 1 ], 0xAE );
	EXPECT_EQ( all_data[ 0 ], 0xDF );
}


TEST( byte_helpers_tests, int_64_to_byte_0x1D1AABBAAFFF00CD )
{
	std::vector<std::uint8_t> all_data( 8, 0 );
	sxe::int_to_bytes<std::uint64_t>( all_data.data(), 0x1D1AABBAAFFF00CD );
	EXPECT_EQ( all_data[ 7 ], 0x1D );
	EXPECT_EQ( all_data[ 6 ], 0x1A );
	EXPECT_EQ( all_data[ 5 ], 0xAB );
	EXPECT_EQ( all_data[ 4 ], 0xBA );
	EXPECT_EQ( all_data[ 3 ], 0xAF );
	EXPECT_EQ( all_data[ 2 ], 0xFF );
	EXPECT_EQ( all_data[ 1 ], 0x00 );
	EXPECT_EQ( all_data[ 0 ], 0xCD );
}


TEST( byte_helpers_tests, bytes_to_double_3_1415 )
{
	std::vector<std::uint8_t> all_data( { 0x6F,0x12, 0x83, 0xC0, 0xCA, 0x21, 0x09, 0x40 } );
	const double result = sxe::bytes_to_double( all_data.data() );
	EXPECT_EQ( result, 3.1415 );
}


TEST( byte_helpers_tests, bytes_to_double_215_45698 )
{
	std::vector<std::uint8_t> all_data( { 0xA2, 0x5D, 0x85, 0x94, 0x9F, 0xEE, 0x6A, 0x40 } );
	const double result = sxe::bytes_to_double( all_data.data() );
	EXPECT_EQ( result, 215.45698 );
}


TEST( byte_helpers_tests, double_to_bytes_3_1415 )
{
	std::vector<std::uint8_t> all_data( 8, 0 );
	sxe::double_to_bytes( 3.1415, all_data.data() );
	
	EXPECT_EQ( all_data[ 7 ], 0x40 );
	EXPECT_EQ( all_data[ 6 ], 0x09 );
	EXPECT_EQ( all_data[ 5 ], 0x21 );
	EXPECT_EQ( all_data[ 4 ], 0xCA );
	EXPECT_EQ( all_data[ 3 ], 0xC0 );
	EXPECT_EQ( all_data[ 2 ], 0x83 );
	EXPECT_EQ( all_data[ 1 ], 0x12 );
	EXPECT_EQ( all_data[ 0 ], 0x6F );
}


TEST( byte_helpers_tests, double_to_bytes_215_45698 )
{
	std::vector<std::uint8_t> all_data( 8, 0 );
	sxe::double_to_bytes( 215.45698, all_data.data() );

	EXPECT_EQ( all_data[ 7 ], 0x40 );
	EXPECT_EQ( all_data[ 6 ], 0x6A );
	EXPECT_EQ( all_data[ 5 ], 0xEE );
	EXPECT_EQ( all_data[ 4 ], 0x9F );
	EXPECT_EQ( all_data[ 3 ], 0x94 );
	EXPECT_EQ( all_data[ 2 ], 0x85 );
	EXPECT_EQ( all_data[ 1 ], 0x5D );
	EXPECT_EQ( all_data[ 0 ], 0xA2 );
}


TEST( byte_helpers_tests, bytes_to_string_1 )
{
	const std::string all_data = "CJ_Recipe_A";
	std::vector<std::uint8_t> content( all_data.begin(), all_data.end() );
	const auto result = sxe::bytes_to_string( content.data(), 11 );
	EXPECT_EQ( result, "CJ_Recipe_A");
}


TEST( byte_helpers_tests, bytes_to_string_2 )
{
	const std::string all_data = "CJ_Recipe_B";
	std::vector<std::uint8_t> content( all_data.begin(), all_data.end() );
	const auto result = sxe::bytes_to_string( content.data(), 11 );
	EXPECT_EQ( result, "CJ_Recipe_B" );
}


TEST( byte_helpers_tests, string_bytes_1 )
{
	const std::string all_data = "CJ_Recipe_A";
	std::vector<std::uint8_t> content( 50, 0 );
	sxe::string_to_bytes( all_data, content.data(), 50 );
	const auto result = sxe::bytes_to_string( content.data(), 11 );
	EXPECT_EQ( result, "CJ_Recipe_A" );
}


TEST( byte_helpers_tests, string_bytes_2 )
{
	const std::string all_data = "CJ_Recipe_B";
	std::vector<std::uint8_t> content( 25, 0 );
	sxe::string_to_bytes( all_data, content.data(), 25 );
	const auto result = sxe::bytes_to_string( content.data(), 11 );
	EXPECT_EQ( result, "CJ_Recipe_B" );
}


TEST( byte_helpers_tests, float_to_bytes_3_1415 )
{
	std::vector<std::uint8_t> all_data( 4, 0 );
	sxe::float_to_bytes( 3.1415f, all_data.data() );

	EXPECT_EQ( all_data[ 3 ], 0x40 );
	EXPECT_EQ( all_data[ 2 ], 0x49 );
	EXPECT_EQ( all_data[ 1 ], 0x0E );
	EXPECT_EQ( all_data[ 0 ], 0x56 );
}


TEST( byte_helpers_tests, float_to_bytes_215_45698 )
{
	std::vector<std::uint8_t> all_data( 8, 0 );
	const float number = 215.45698f;
	sxe::float_to_bytes( number, all_data.data() );

	EXPECT_EQ( all_data[ 3 ], 0x43 );
	EXPECT_EQ( all_data[ 2 ], 0x57 );
	EXPECT_EQ( all_data[ 1 ], 0x74 );
	EXPECT_EQ( all_data[ 0 ], 0xFD );
}
