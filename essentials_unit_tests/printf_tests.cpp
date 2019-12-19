//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <boost/test/unit_test.hpp>

#include "sxprintf.hpp"


BOOST_AUTO_TEST_SUITE( sxprintf_test )


BOOST_AUTO_TEST_CASE( sxprintf_test_string_only )
{
	const std::string printf_result = sxe::sxprintf( "hallo" );
	const std::string expected_printf_result = "hallo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_three_superfluous_parameters )
{
	const std::string printf_result = sxe::sxprintf( "hallo", 1, 2, 4 );
	const std::string expected_printf_result = "hallo[Superfluous parameter: 1][Superfluous parameter: 2][Superfluous parameter: 4]";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_superfluous_parameter )
{
	const std::string printf_result = sxe::sxprintf( "hallo % hallohallo %", 1, 2, 4 );
	const std::string expected_printf_result = "hallo 1 hallohallo 2[Superfluous parameter: 4]";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_one_superfluous_parameter )
{
	const std::string printf_result = sxe::sxprintf( "% hallo % hallohallo %", 1, 2, 4 );
	const std::string expected_printf_result = "1 hallo 2 hallohallo 4";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_05 )
{
	const std::string printf_result = sxe::sxprintf( "% hallo" );
	const std::string expected_printf_result = "[Missing parameter!]% hallo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_06 )
{
	const std::string printf_result = sxe::sxprintf( "%% hal%%l%o", 1 );
	const std::string expected_printf_result = "% hal%l1o";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_07 )
{
	const std::string printf_result = sxe::sxprintf( "%% hal%l%o", 1 );
	const std::string expected_printf_result = "% hal1l[Missing parameter!]%o";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_08 )
{
	const std::string printf_result = sxe::sxprintf( "%% hal%[x]lo", 55 );
	const std::string expected_printf_result = "% hal0x37lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_09 )
{
	const std::string printf_result = sxe::sxprintf( "hal%%%[X]lo", 255 );
	const std::string expected_printf_result = "hal%0xfflo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_10 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[]al%[X]lo", 47 );
	const std::string expected_printf_result = "h%47[Illegal output modifier!]al[Missing parameter!]%[X]lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_11 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[X]al%[3]lo", 25636347, 1 );
	const std::string expected_printf_result = "h%0x1872dfbal  1lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_12 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[03.1]al%[9.7]lo", 1.001, 123.001 );
	const std::string expected_printf_result = "h%001al  123.001lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_13 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[3.1]al%[09.7]lo", 1.001, 123.001 );
	const std::string expected_printf_result = "h%  1al00123.001lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_14 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[03.1]al%[09.7]lo", 1.001, 123.001 );
	const std::string expected_printf_result = "h%001al00123.001lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_15 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[.1]al%[.7]lo", 1.01, 1.00001 );
	const std::string expected_printf_result = "h%1al1.00001lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_16 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[0]al%[.7]lo", 1.01, 1.00001 );
	const std::string expected_printf_result = "h%1.01al1.00001lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_17 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[0a.1]al%[09.7]lo", 1.001, 123.001 );
	const std::string expected_printf_result = "h%1.001[Illegal output modifier!]al00123.001lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_18 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[03.a]al%[09.7]lo", 1.001, 123.001 );
	const std::string expected_printf_result = "h%1.001[Illegal output modifier!]al00123.001lo";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_19 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[03.1]al%[a9.7]lo", 1.001, 123.001 );
#ifndef SX_CPP03_BOOST
	const std::string expected_printf_result = "h%001al1e+02[Illegal output modifier!]lo";
#else
	const std::string expected_printf_result = "h%001al1e+002[Illegal output modifier!]lo";
#endif

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_20 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[03.1]al%[09.a]lo", 1.001, 123.001 );
#ifndef SX_CPP03_BOOST
	const std::string expected_printf_result = "h%001al1e+02[Illegal output modifier!]lo";
#else
	const std::string expected_printf_result = "h%001al1e+002[Illegal output modifier!]lo";
#endif

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}



BOOST_AUTO_TEST_CASE( sxprintf_test_21 )
{
	const std::string printf_result = sxe::sxprintf( "h%%%[03.1]al%[09a7]lo", 1.001, 123.001 );
#ifndef SX_CPP03_BOOST
	const std::string expected_printf_result = "h%001al1e+02[Illegal output modifier!]lo";
#else
	const std::string expected_printf_result = "h%001al1e+002[Illegal output modifier!]lo";
#endif

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_23 )
{
	const std::string printf_result = sxe::sxprintf( "Mein Name ist %. Ich bin % Jahre alt. Mwst.-Satz %\\%.", "Detlef" );
	const std::string expected_printf_result = "Mein Name ist Detlef. Ich bin [Missing parameter!]% Jahre alt. Mwst.-Satz [Missing parameter!]%\\[Missing parameter!]%.";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_24 )
{
	const std::string printf_result = sxe::sxprintf( "Formated output % foo %[10.5]!ab %!!!", 123.123456789, 123.123456789, 123.123456789 );
	const std::string expected_printf_result = "Formated output 123.123 foo     123.12!ab 123.12!!!";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_25 )
{
	const std::string printf_result = sxe::sxprintf( "Hex action: %[X] :)", 0xdeadbeef );
	const std::string expected_printf_result = "Hex action: 0xdeadbeef :)";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_26 )
{
	const std::string printf_result = sxe::sxprintf( "Formated output % foo %[11]!ab %!!!", 123.123456789, 123.123456789, 123.123456789 );
	const std::string expected_printf_result = "Formated output 123.123 foo     123.123!ab 123.123!!!";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_27 )
{
	const std::string printf_result = sxe::sxprintf( "Formated output % foo %[.5]!ab %!!!", 123.123456789, 123.123456789, 123.123456789 );
	const std::string expected_printf_result = "Formated output 123.123 foo 123.12!ab 123.12!!!";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_28 )
{
	const std::string printf_result = sxe::sxprintf( "Formated output % foo %[1234545678889568954674356345636363632623632626365743.5]!ab %!!!", 123.123456789, 123.123456789, 123.123456789 );
	const std::string expected_printf_result = "Formated output 123.123 foo 123.123[Illegal output modifier!]!ab 123.123!!!";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_29 )
{
	uint8_t number = 77;
	const std::string printf_result = sxe::sxprintf( "Formated output %", number );
	const std::string expected_printf_result = "Formated output 77";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_30 )
{
	uint8_t number = 77;
	const std::string printf_result = sxe::sxprintf( "Formated output %[8]", number );
	const std::string expected_printf_result = "Formated output       77";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_31 )
{
	uint8_t number = 77;
	const std::string printf_result = sxe::sxprintf( "Formated output %[08.3]", number );
	const std::string expected_printf_result = "Formated output 00000077";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_32 )
{
	uint8_t number = 77;
	const std::string printf_result = sxe::sxprintf( "Formated output %[08.3]", number, number, number );
	const std::string expected_printf_result = "Formated output 00000077[Superfluous parameter: 77][Superfluous parameter: 77]";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_CASE( sxprintf_test_33 )
{
	const std::string printf_result = sxe::sxprintf( "hallo%" );
	const std::string expected_printf_result = "hallo[Missing parameter!]%";

	BOOST_CHECK_EQUAL( printf_result, expected_printf_result );
}


BOOST_AUTO_TEST_SUITE_END()
