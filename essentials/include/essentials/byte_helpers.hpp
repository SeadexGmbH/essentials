// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef BYTE_HELPERS_A9A61248_936B_478B_9209_56ADB95867A5
#define BYTE_HELPERS_A9A61248_936B_478B_9209_56ADB95867A5


#include <cstdint>
#include <string>


namespace sxe
{


//!\brief Extract a bool value from a given byte value.
//!\param _bit The bit where the desired bool value is located.
//!\param _byte The byte from which the bool is extracted.
//!\return bool The extracted bool value.
//!\sa inject_bool_into_byte
bool extract_bool_from_byte( const std::size_t _bit, const std::uint8_t _byte );

//!\brief Inject a bool value to a given bit position in a given byte.
//!\param _bit Position of the bool value in the byte.
//!\param _bool Bool value to be set.
//!\param _byte Byte into which the bool value is written.
//!\return std::uint8_t The new _byte value.
//!\sa extract_bool_from_byte
std::uint8_t inject_bool_into_byte( const std::size_t _bit, const bool _bool, const std::uint8_t _byte );

//!\brief Get string from the given bytes.
//!\param _bytes The memory position where the bytes start.
//!\param _length Length of the bytes.
//!\return std::string String value of the bytes.
//!\sa string_to_bytes
std::string bytes_to_string( const std::uint8_t* _bytes, const std::size_t _length );

//!\brief Put string into bytes.
//!\param _value String value.
//!\param _bytes The memory position where the bytes start.
//!\param _max_length Maximum length of bytes.
//!\sa bytes_to_string
void string_to_bytes( const std::string& _value, std::uint8_t* _bytes, const std::size_t _max_length );

//!\brief Get double value from bytes.
//!\param _bytes The memory position where the bytes start.
//!\return double Double value from bytes.
//!\sa double_to_bytes, float_to_bytes
double bytes_to_double( const std::uint8_t* _bytes );

//!\brief Set the given double value to bytes.
//!\param _value Double value to be set into bytes.
//!\param _bytes The memory position where the bytes start.
//!\sa bytes_to_double
void double_to_bytes( const double _value, std::uint8_t* _bytes );

//!\brief Set the given float value to bytes.
//!\param _value Float value to be set into bytes.
//!\param _bytes The memory position where the bytes start.
void float_to_bytes( const float _value, std::uint8_t* _bytes );

//!\brief Template function to get the integer type value from the given bytes.
//!\param _bytes The memory position where the bytes start.
//!\return _int_type Integer value from bytes.
//!\sa int_to_bytes
template<typename _int_type>
_int_type bytes_to_int( const std::uint8_t* _bytes )
{
	_int_type value = 0;
	for( std::size_t i = 0; i < sizeof( _int_type ); ++i)
	{
		value |= _int_type( _bytes[ i ] ) << ( 8 * i );
	}
	return ( value );
}

//!\brief Template function to set the integer type value to the given bytes.
//!\param _bytes The memory position where the bytes starts.
//!\param _value The integer value to be set.
//!\sa bytes_to_int
template< typename _int_type >
void int_to_bytes( std::uint8_t* _bytes, const _int_type _value )
{
	_int_type max = sizeof( _int_type ) - 1;
	for( _int_type i = 0; i <= max; ++i )
	{
		_bytes[ max - i ] = ( _value >> ( 8 * ( max - i ) ) ) & 0xFF;
	}
}


}


#endif
