// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef CONVERSION_99CAC61B_DD8A_43E2_8612_0F42873A5741
#define CONVERSION_99CAC61B_DD8A_43E2_8612_0F42873A5741


#include <string>
#include <sstream>
#include <limits>


namespace sxe
{


//!\brief Converts a string to uppercase.
//!\param _value String to be converted.
//!\return String in uppercase format.
//!\sa to_lower
std::string to_upper( const std::string& _value );

//!\brief Converts a string to lowercase.
//!\param _value String to be converted.
//!\return String in lowercase format.
//!\sa to_upper
std::string to_lower( const std::string& _value );

//!\brief Check if the remaining chunk of string is empty spaces.
//!\param _converter The stringstream to be checked.
//!\return True if the remaining string is empty (spaces), false otherwise.
bool contains_nothing_or_spaces( std::stringstream& converter );


//!\brief Template function to convert string to the given integer type.
//!\param _string String to be converted.
//!\param _int Integer where the converted value is placed.
//!\return True if conversion is successful, false otherwise.
template< typename _int_type >
bool string_to_integer( const std::string& _string, _int_type& _int )
{
	static_assert( std::is_integral< _int_type >::value, "_int_type is not a integer type!" );
	std::stringstream converter( _string );
	bool conversion_success = !( converter >> _int ).fail();
	if( conversion_success && ( converter.tellg() >= 0 ) )
	{
		conversion_success = contains_nothing_or_spaces( converter );
	}
	return( conversion_success );
}


//!\brief Template function to convert string to std::uint8_t integer type.
//!\param _string String to be converted.
//!\param _int Integer where the converted value is placed.
//!\return True if conversion is successful, false otherwise.
template<>
bool string_to_integer< std::uint8_t >( const std::string& _string, std::uint8_t& _int );


//!\brief Template function to convert string to std::int8_t integer type.
//!\param _string String to be converted.
//!\param _int Integer where the converted value is placed.
//!\return True if conversion is successful, false otherwise.
template<>
bool string_to_integer< std::int8_t >( const std::string& _string, std::int8_t& _int );


}


#endif
