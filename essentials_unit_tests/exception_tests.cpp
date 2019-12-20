// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <gtest/gtest.h>
#include <iostream>

#include "essentials/exception_template.hpp"
#include "essentials/type_wrapper.hpp"


SXE_EXCEPTION( test_exception )
SXE_EXCEPTION_WITH_BASE( test_exception_2, test_exception )

SXE_CREATE_TYPE_IN_NAMESPACE( test, status_code, int );
SXE_EXCEPTION_WITH_CODE( test_exception_code, test::status_code )
SXE_EXCEPTION_WITH_CODE_IN_NAMESPACE( test, test_exception_code_in_namespace, test::status_code )


TEST( sxe_exception_test, sxe_exception_test_param_int ) 
{
	EXPECT_THROW( { throw test_exception( "Seadex exception test {:d}/{:d}.", 9, 2021 ); }, test_exception );
}


TEST( sxe_exception_test, sxe_exception_test_param_string )
{
	EXPECT_THROW( { throw test_exception( "Seadex exception test {:s}/{:s}.", "09", "2021" ); }, test_exception );
}


TEST( sxe_exception_test, sxe_exception_test_param_boolean )
{
	EXPECT_THROW( { throw test_exception( "Seadex exception test works: {:d}/{:d}.", true, false ); }, test_exception );
}


TEST( sxe_exception_test, sxe_exception_test_param_different )
{
	EXPECT_THROW( { throw test_exception( "Seadex exception test works: {:d}/{:s}.", true, "false" ); }, test_exception );
}


TEST( sxe_exception_test, sxe_exception_test_param_different_2 )
{
	EXPECT_THROW( { throw test_exception( "Seadex exception test works: {:s}/{:d}.", "123", 2021 ); }, test_exception );
}


TEST( sxe_exception_test, sxe_exception_with_error_code )
{
	EXPECT_THROW(
		{ 
			try
			{
				throw test_exception_code( test::status_code( 1 ), "Seadex exception test works: {:s}/{:d}.", "123", 2021 );
			}
			catch( const test_exception_code& _exception )
			{
				EXPECT_STREQ( _exception.what(), "Seadex exception test works: 123/2021." );
				EXPECT_EQ( _exception.error_code(), test::status_code( 1 ) );
				throw;
			}
		}, test_exception_code );
}


TEST( sxe_exception_test, sxe_exception_with_error_code_in_namespace )
{
	EXPECT_THROW(
		{
			try
			{
				throw test::test_exception_code_in_namespace( test::status_code( 1 ), "Seadex exception test works: {:s}/{:d}.", "123", 2021 );
			}
			catch( const test::test_exception_code_in_namespace& _exception )
			{
				EXPECT_STREQ( _exception.what(), "Seadex exception test works: 123/2021." );
				EXPECT_EQ( _exception.error_code(), test::status_code( 1 ) );
				throw;
			}
		}, test::test_exception_code_in_namespace );
}


TEST( sxe_exception_test, sxe_exception_test_base )
{
	EXPECT_THROW( { throw test_exception_2( "Seadex exception test works: {:d}/{:d}.", true, false ); }, test_exception_2 );
}
