// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef ENHANCED_ENUM_212A5BBE_0FA2_11EC_82A8_0242AC130003
#define ENHANCED_ENUM_212A5BBE_0FA2_11EC_82A8_0242AC130003


#include <map>
#include <stdexcept>
#include <cstdint>
#include <string>
#include <sstream>
#include <algorithm>

#include "essentials/assert_no_log.hpp"
#include "essentials/exception.hpp"
#include "essentials/preprocessor/macro_helpers.hpp"

#include "essentials/enum/enhanced_enum_select_x.hpp"
#include "essentials/enum/enhanced_enum_numeric_select_x.hpp"
#include "essentials/enum/enum_macro_helpers.hpp"


#define SXE_ENHANCED_ENUM_IMPL( _name, _enum_values, _enum_value_names )\
struct _name\
{\
	enum inner_value\
	{\
		SXE_ENUM_VALUES( _enum_values, _enum_value_names )\
	};\
\
\
	SXE_EXCEPTION( exception )\
\
\
	explicit _name() noexcept:\
		inner_value_( inner_value::SXE_GET_ARGUMENT_NR( 0, _enum_value_names ) )\
	{\
\
	}\
\
\
	_name( const inner_value& _value ) noexcept:\
		inner_value_( _value )\
	{\
\
	}\
\
\
	explicit _name( const std::string& _rhs ):\
		inner_value_( from_string( _rhs ) )\
	{\
\
	}\
\
\
	explicit _name( const std::intmax_t& _rhs ):\
		inner_value_( _name::from_int( _rhs ) )\
	{\
\
	}\
\
\
	_name( const _name& _rhs ) noexcept:\
		inner_value_( _rhs.inner_value_ )\
	{\
\
	}\
\
\
	_name& operator=( const _name& _rhs ) noexcept\
	{\
		if( this != &_rhs )\
		{\
			inner_value_ = _rhs.inner_value_;\
		}\
\
		return( *this );\
	}\
\
\
	friend bool operator==( const _name& _lhs, const _name& _rhs ) noexcept;\
	friend bool operator!=( const _name& _lhs, const _name& _rhs ) noexcept;\
	friend bool operator>( const _name& _lhs, const _name& _rhs ) noexcept;\
	friend bool operator<( const _name& _lhs, const _name& _rhs ) noexcept;\
	friend bool operator>=( const _name& _lhs, const _name& _rhs ) noexcept;\
	friend bool operator<=( const _name& _lhs, const _name& _rhs ) noexcept;\
	friend std::ostream& operator<<( std::ostream& _stream, const _name& _e ) noexcept;\
\
\
	operator inner_value() const noexcept\
	{\
		return( inner_value_ );\
	}\
\
\
	_name::inner_value from_string( const std::string& _rhs )\
	{\
		const auto found_value = find_by_value( _rhs );\
		SXE_ASSERT_NO_LOG( !enums_to_strings_.empty(), "Map cannot be empty!" );\
		_name::inner_value result = enums_to_strings_.begin()->first;\
		if( found_value != enums_to_strings_.end() )\
		{\
			result = found_value->first;\
		}\
		else\
		{\
			throw exception( get_invalid_representation_message( _rhs ) );\
		}\
\
		return( result );\
	}\
\
\
	_name::inner_value from_string_no_throw( const std::string& _rhs ) noexcept\
	{\
		SXE_ASSERT_NO_LOG( is_valid_representation( _rhs ), "Value is not a valid string representation!" );\
\
		const auto found_value = find_by_value( _rhs );\
		SXE_ASSERT_NO_LOG( !enums_to_strings_.empty(), "Map cannot be empty!" );\
		_name::inner_value result = enums_to_strings_.begin()->first;\
		if( found_value != enums_to_strings_.end() )\
		{\
			result = found_value->first;\
		}\
		else\
		{\
			SXE_ASSERT_NO_LOG( false, "Representation is valid. There has to be a match!" );\
		}\
\
		return( result );\
	}\
\
\
	_name::inner_value from_int( const std::intmax_t& _rhs )\
	{\
		const auto found_value = find_by_key( _rhs );\
		SXE_ASSERT_NO_LOG( !enums_to_strings_.empty(), "Map cannot be empty!" );\
		_name::inner_value result = enums_to_strings_.begin()->first;\
		if( found_value != enums_to_strings_.end() )\
		{\
			result = found_value->first;\
		}\
		else\
		{\
			throw exception( get_invalid_representation_message( _rhs ) );\
		}\
\
		return( result );\
	}\
\
\
	_name::inner_value from_int_no_throw( const std::intmax_t& _rhs ) noexcept\
	{\
		SXE_ASSERT_NO_LOG( is_valid_representation( _rhs ), "Value is not a valid int representation!" );\
\
		const auto found_value = find_by_key( _rhs );\
		SXE_ASSERT_NO_LOG( !enums_to_strings_.empty(), "Map cannot be empty!" );\
		_name::inner_value result = enums_to_strings_.begin()->first;\
		if( found_value != enums_to_strings_.end() )\
		{\
			result = found_value->first;\
		}\
		else\
		{\
			SXE_ASSERT_NO_LOG( false, "Representation is valid. There has to be a match!" );\
		}\
\
		return( result );\
	}\
\
\
	std::string to_string() const noexcept\
	{\
		const auto found_value = find_by_key( inner_value_ );\
		SXE_ASSERT_NO_LOG( found_value != enums_to_strings_.end(), "No match for own value is impossible!" );\
\
		return( found_value->second );\
	}\
\
\
	bool is_valid_representation( const std::string& _rhs ) const noexcept\
	{\
		return( find_by_value( _rhs ) != enums_to_strings_.end() );\
	}\
\
\
	bool is_valid_representation( const std::intmax_t& _rhs ) const noexcept\
	{\
		return( find_by_key( _rhs ) != enums_to_strings_.end() );\
	}\
\
\
private:\
	using enums_to_strings = std::map<inner_value, std::string>;\
\
\
	template< typename _value>\
	static std::string get_invalid_representation_message( const _value& _user_value) noexcept\
	{\
		return( fmt::format( "'{}' is not a valid representation for '{}'!", _user_value, SXE_STRINGIFY( _name ) ) );\
	}\
\
\
	static enums_to_strings::const_iterator find_by_key( const _name::inner_value& _rhs ) noexcept\
	{\
		return( enums_to_strings_.find( _rhs ) );\
	}\
\
\
	static enums_to_strings::const_iterator find_by_key( const std::intmax_t& _rhs ) noexcept\
	{\
		const auto found_value = std::find_if( enums_to_strings_.begin(), enums_to_strings_.end(),\
			[ _rhs ] ( const auto& _value )\
			{\
				return ( _value.first == _rhs );\
			}\
		);\
		return( found_value );\
	}\
\
\
	static enums_to_strings::const_iterator find_by_value( const std::string& _rhs ) noexcept\
	{\
		const auto found_value = std::find_if( enums_to_strings_.begin(), enums_to_strings_.end(),\
			[ _rhs ] ( const auto& _value )\
			{\
				return( _value.second == _rhs );\
			}\
		);\
		return( found_value );\
	}\
\
\
	inner_value inner_value_;\
	inline static enums_to_strings enums_to_strings_ = SXE_ENUM_MAP( _name::inner_value, _enum_values, _enum_value_names );\
};\
\
\
inline bool operator==( const _name& _lhs, const _name& _rhs ) noexcept\
{\
	return( _lhs.inner_value_ == _rhs.inner_value_ );\
}\
\
\
inline bool operator!=( const _name& _lhs, const _name& _rhs ) noexcept\
{\
	return( _lhs.inner_value_ != _rhs.inner_value_ );\
}\
\
\
inline bool operator>( const _name& _lhs, const _name& _rhs ) noexcept\
{\
	return( _lhs.inner_value_ > _rhs.inner_value_ );\
}\
\
\
inline bool operator<( const _name& _lhs, const _name& _rhs ) noexcept\
{\
	return( _lhs.inner_value_ < _rhs.inner_value_ );\
}\
\
\
inline bool operator>=( const _name& _lhs, const _name& _rhs ) noexcept\
{\
	return( _lhs.inner_value_ >= _rhs.inner_value_ );\
}\
\
\
inline bool operator<=( const _name& _lhs, const _name& _rhs ) noexcept\
{\
	return( _lhs.inner_value_ <= _rhs.inner_value_ );\
}\
\
\
inline std::ostream& operator<<( std::ostream& _stream, const _name& _e ) noexcept\
{\
	_stream << _e.to_string(); \
	return( _stream ); \
}\


//!\def SXE_ENHANCED_ENUM( ... )
//!\brief Create an enhanced enum.
#define SXE_ENHANCED_ENUM( ... ) SXE_EXPAND( SXE_VA_SELECT( SXE_ENHANCED_ENUM_SELECT, __VA_ARGS__ ) )

//!\def SXE_ENHANCED_ENUM_NUMERIC( ... )
//!\brief Create an enhanced enum with associated numeric values.
#define SXE_ENHANCED_ENUM_NUMERIC( ... ) SXE_EXPAND( SXE_VA_SELECT( SXE_ENHANCED_ENUM_NUMERIC_SELECT, __VA_ARGS__ ) )


#endif
