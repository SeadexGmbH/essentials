//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#define BOOST_TEST_MODULE essentials test

#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/unit_test.hpp>

#include "essentials/base.hpp"

#ifdef __linux__

#include <sys/resource.h>


void enable_core_dumps()
{
	struct rlimit core_limit;
	core_limit.rlim_cur = RLIM_INFINITY;
	core_limit.rlim_max = RLIM_INFINITY;

	const int setCoreSizeResult = setrlimit( RLIMIT_CORE, &core_limit );
	if( -1 == setCoreSizeResult ) {
		// error
	}
}

#endif


// cppcheck-suppress unusedFunction
boost::unit_test::test_suite* init_unit_test_suite( int argc, char* argv[] )
{
#ifdef __linux__
	enable_core_dumps();
#endif

	SX_UNUSED_PARAMETER( argc );
	SX_UNUSED_PARAMETER( argv );	
	boost::unit_test::test_suite* test_suite_unit_tests = BOOST_TEST_SUITE( "essentials unit tests" );

	return( test_suite_unit_tests );
}
