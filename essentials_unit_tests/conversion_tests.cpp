//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <boost/test/unit_test.hpp>

#include "essentials/conversion.hpp"

BOOST_AUTO_TEST_SUITE( conversion_tests )


BOOST_AUTO_TEST_CASE( convertion_test_string_to_int )
{
	int result = 0;
	const bool converted = sxe::string_to_int( "64", result );

	BOOST_CHECK_EQUAL( result, 64 );
	BOOST_CHECK_EQUAL( converted, true );
}


BOOST_AUTO_TEST_CASE( convertion_test_empty_string_to_int )
{
	int result = 0;
	const bool converted = sxe::string_to_int( "", result );

	BOOST_CHECK_EQUAL( result, 0 );
	BOOST_CHECK_EQUAL( converted, false );
}


BOOST_AUTO_TEST_CASE( convertion_test_float_string_to_int )
{
	int result = 0;
	const bool converted = sxe::string_to_int( "64,59", result );

	BOOST_CHECK_EQUAL( result, 64 );
	BOOST_CHECK_EQUAL( converted, true );
}


BOOST_AUTO_TEST_CASE( convertion_test_unsigned_int_to_string )
{
	const std::string converted = sxe::to_string( 65535 );
	BOOST_CHECK_EQUAL( converted, "65535" );	
}


BOOST_AUTO_TEST_CASE( convertion_test_int_to_string_max )
{
	const std::string converted = sxe::to_string( 2147483647 );
	BOOST_CHECK_EQUAL( converted, "2147483647" );
}


BOOST_AUTO_TEST_CASE( convertion_test_int_to_string_min )
{
	const std::string converted = sxe::to_string( -2147483647 );
	BOOST_CHECK_EQUAL( converted, "-2147483647" );
}


BOOST_AUTO_TEST_CASE( convertion_test_to_upper_1 )
{
	const std::string converted = sxe::to_upper( "hello yasmine Lib 1.2.0" );
	BOOST_CHECK_EQUAL( converted, "HELLO YASMINE LIB 1.2.0" );
}


BOOST_AUTO_TEST_CASE( convertion_test_to_upper_2 )
{
	const std::string converted = sxe::to_upper( "heLLo YaSmIne Lib 1.2.0" );
	BOOST_CHECK_EQUAL( converted, "HELLO YASMINE LIB 1.2.0" );
}


BOOST_AUTO_TEST_CASE( convertion_test_to_lower_1 )
{
	const std::string converted = sxe::to_lower( "HELLO YASMINE LIB 1.2.0" );
	BOOST_CHECK_EQUAL( converted, "hello yasmine lib 1.2.0" );
}


BOOST_AUTO_TEST_CASE( convertion_test_to_lower_2 )
{
	const std::string converted = sxe::to_lower( "HELLO YASMINE LIB 1.2.0 TesT_2" );
	BOOST_CHECK_EQUAL( converted, "hello yasmine lib 1.2.0 test_2" );
}

BOOST_AUTO_TEST_SUITE_END()
