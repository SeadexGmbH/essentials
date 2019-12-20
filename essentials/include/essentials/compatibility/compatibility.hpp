// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef COMPATIBILITY_63A35CFD_26BC_42BE_9F09_D559349FFE63
#define COMPATIBILITY_63A35CFD_26BC_42BE_9F09_D559349FFE63


#include <memory>


namespace sxe
{


#if __cplusplus > 201402L


using std::make_unique;


#else


template< typename t, typename ... args >
std::unique_ptr< t > make_unique( args&& ... _args )
{
	return( std::unique_ptr< t >( new t( std::forward< args >( _args )... ) ) );
}


#endif


}


#endif
