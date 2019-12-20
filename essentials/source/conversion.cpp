// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/conversion.hpp"

#include <stdexcept>
#include <algorithm>
#include <cctype>
#include <string>


namespace sxe
{


// cppcheck-suppress unusedFunction
std::string to_upper( const std::string& _value )
{
	std::string value_caps = _value;
	std::transform( value_caps.begin(), value_caps.end(), value_caps.begin(), []( char c ){return static_cast< char >( ::std::toupper( c ) ); } );
	return( value_caps );
}


// cppcheck-suppress unusedFunction
std::string to_lower( const std::string& _value )
{
	std::string value_to_lower = _value;
	std::transform( value_to_lower.begin(), value_to_lower.end(), value_to_lower.begin(), []( char c ){return static_cast< char >( ::std::tolower( c ) ); } );
	return( value_to_lower );
}


bool contains_nothing_or_spaces( std::stringstream& converter )
{
	std::string remaining( converter.str().substr( converter.tellg() ) );
	remaining.erase( 0, remaining.find_first_not_of( " " ) );
	remaining.erase( remaining.find_last_not_of( " " ) + 1 );
	return( remaining.empty() );
}


template<>
// cppcheck-suppress unusedFunction
bool string_to_integer< std::uint8_t >( const std::string& _string, std::uint8_t& _int )
{
	std::uint16_t value;
	std::stringstream converter( _string );
	bool conversion_success = !( converter >> value ).fail();
	if( conversion_success && ( converter.tellg() >= 0 ) )
	{
		conversion_success = contains_nothing_or_spaces( converter );
	}
	if( conversion_success )
	{
		conversion_success = ( value <= std::numeric_limits< std::uint8_t >::max() );
		if( conversion_success )
		{
			_int = static_cast< std::uint8_t >( value );
		}
	}
	return( conversion_success );
}


template<>
// cppcheck-suppress unusedFunction
bool string_to_integer< std::int8_t >( const std::string& _string, std::int8_t& _int )
{
	std::int16_t value;
	std::stringstream converter( _string );
	bool conversion_success = !( converter >> value ).fail();
	if( conversion_success && ( converter.tellg() >= 0 ) )
	{
		conversion_success = contains_nothing_or_spaces( converter );
	}
	if( conversion_success )
	{
		conversion_success = ( value <= std::numeric_limits< std::int8_t >::max() )
			&& ( value >= std::numeric_limits< std::int8_t >::min() );
		if( conversion_success )
		{
			_int = static_cast< std::int8_t >( value );
		}
	}
	return( conversion_success );
}


}
