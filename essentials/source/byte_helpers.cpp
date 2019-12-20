// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/byte_helpers.hpp"

#include "essentials/assert.hpp"


namespace sxe
{


// cppcheck-suppress unusedFunction
bool extract_bool_from_byte( const std::size_t _bit, const std::uint8_t _byte )
{
	const auto is_bit = _bit < 8;
	SXE_ASSERT( is_bit, "{}", "Bit is out of bounds!" );
	auto mask = 1 << _bit;
	auto result = _byte & mask;
	return ( result != 0 );
}


// cppcheck-suppress unusedFunction
std::uint8_t inject_bool_into_byte( const std::size_t _bit, const bool _bool, const std::uint8_t _byte )
{
	const auto is_bit = _bit < 8;
	SXE_ASSERT( is_bit, "{}", "Bit is out of bounds!" );
	std::uint8_t result = _byte;
	if( _bool )
	{
		std::uint8_t mask = 1 << _bit;
		result = _byte | mask;
	}
	return ( result );
}


// cppcheck-suppress unusedFunction
std::string bytes_to_string( const std::uint8_t* _bytes, const std::size_t _max_length )
{
	std::size_t length = 0;
	while( length < _max_length && _bytes[ length ] != 0 )
	{
		++length;
	}
	return ( std::string( _bytes, _bytes + length ) );
}


// cppcheck-suppress unusedFunction
void string_to_bytes( const std::string& _value, std::uint8_t* _bytes, const std::size_t _max_length )
{
	std::size_t byte_idx = 0;
	for( std::string::size_type i = 0; i < _value.size(); ++i )
	{
		_bytes[ byte_idx++ ] = _value[ i ];
	}

	for( std::size_t i = 0; i < _max_length - _value.size(); ++i )
	{
		_bytes[ byte_idx++ ] = 0;
	}
}


// cppcheck-suppress unusedFunction
double bytes_to_double( const std::uint8_t* _bytes )
{
	const auto value = sxe::bytes_to_int< std::uint64_t >( _bytes );
	double final_value;
	std::memcpy( &final_value, &value, sizeof( final_value ) );
	return ( final_value );
}


// cppcheck-suppress unusedFunction
void double_to_bytes( const double _value, std::uint8_t* _bytes )
{
	// cppcheck-suppress invalidPointerCast
	const std::uint8_t* address_of_double = reinterpret_cast< const std::uint8_t* >( &_value );
	for( std::size_t i = 0; i < sizeof( double ); ++i )
	{
		_bytes[ i ] = address_of_double[ i ];
	}
}


// cppcheck-suppress unusedFunction
void float_to_bytes( const float _value, std::uint8_t* _bytes )
{
	// cppcheck-suppress invalidPointerCast
	const std::uint8_t* address_of_float = reinterpret_cast< const std::uint8_t* >( &_value );
	for( std::size_t i = 0; i < sizeof( float ); ++i)
	{
		_bytes[ i ] = address_of_float[ i ];
	}
}


}
