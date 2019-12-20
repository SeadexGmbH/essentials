// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef TYPE_WRAPPER_212A5BBE_0FA2_11EC_82A8_0242AC130003
#define TYPE_WRAPPER_212A5BBE_0FA2_11EC_82A8_0242AC130003


#include <fmt/format.h>


namespace sxe
{


template< typename t_raw_type, typename t_wrapped_type_tag >
class type_wrapper final
{
public:
  using raw_type = t_raw_type;


  constexpr type_wrapper() :
    value_( t_raw_type() )
  {
    // nothing to do...
  }


  constexpr explicit type_wrapper( const raw_type& _value ) :
    value_( _value )
  {
    // nothing to do...
  }


  constexpr type_wrapper( const type_wrapper& _rhs ) :
    value_( _rhs.value_ )
  {
    // nothing to do...
  }


  constexpr type_wrapper( const type_wrapper&& _rhs ) :
    value_( std::move( _rhs.value_ ) )
  {
    // nothing to do...
  }


  explicit operator raw_type()
  {
    return( value_ );
  }


  raw_type& get_raw()
  {
    return( value_ );
  }


  const raw_type& get_raw() const
  {
    return( value_ );
  }


  void set_raw( const raw_type& _value )
  {
    value_ = _value;
  }


  type_wrapper& operator=( const type_wrapper& _rhs )
  {
    if( this != &_rhs )
    {
      value_ = _rhs.value_;
    }
    return( *this );
  }


  type_wrapper& operator=( const type_wrapper&& _rhs )
  {
    if( this != &_rhs )
    {
      value_ = std::move( _rhs.value_ );
    }
    return( *this );
  }


  bool operator==( const type_wrapper& _rhs ) const
  {
    return( value_ == _rhs.value_ );
  }


  bool operator!=( const type_wrapper& _rhs ) const
  {
    return( value_ != _rhs.value_ );
  }


  bool operator<( const type_wrapper& _rhs ) const
  {
    return( value_ < _rhs.value_ );
  }


  bool operator<=( const type_wrapper& _rhs ) const
  {
    return( value_ <= _rhs.value_ );
  }


  bool operator>( const type_wrapper& _rhs ) const
  {
    return( value_ > _rhs.value_ );
  }


  bool operator>=( const type_wrapper& _rhs ) const
  {
    return( value_ >= _rhs.value_ );
  }


  type_wrapper& operator+=( const type_wrapper& _rhs )
  {
    value_ += _rhs.value_;
    return( *this );
  }


  type_wrapper& operator-=( const type_wrapper& _rhs )
  {
    value_ -= _rhs.value_;
    return( *this );
  }


  type_wrapper& operator*=( const type_wrapper& _rhs )
  {
    value_ *= _rhs.value_;
    return( *this );
  }


  type_wrapper& operator/=( const type_wrapper& _rhs )
  {
    value_ /= _rhs.value_;
    return( *this );
  }


  type_wrapper& operator%=( const type_wrapper& _rhs )
  {
    value_ %= _rhs.value_;
    return( *this );
  }


  type_wrapper operator+() const
  {
    return( *this );
  }


  type_wrapper operator-() const
  {
    return( type_wrapper( -value_ ) );
  }


  type_wrapper operator+( const type_wrapper& _rhs ) const
  {
    return( type_wrapper( value_ + _rhs.value_ ) );
  }


  type_wrapper operator-( const type_wrapper& _rhs ) const
  {
    return( type_wrapper( value_ - _rhs.value_ ) );
  }


  type_wrapper operator*( const type_wrapper& _rhs ) const
  {
    return( type_wrapper( value_ * _rhs.value_ ) );
  }


  type_wrapper operator/( const type_wrapper& _rhs ) const
  {
    return( type_wrapper( value_ / _rhs.value_ ) );
  }


  type_wrapper operator%( const type_wrapper& _rhs ) const
  {
    return( type_wrapper( value_ % _rhs.value_ ) );
  }


  type_wrapper& operator++()
  {
    ++value_;
    return( *this );
  }


  type_wrapper operator++( const int )
  {
    type_wrapper result( *this );
    ++value_;
    return( result );
  }


  type_wrapper& operator--()
  {
    --value_;
    return( *this );
  }


  type_wrapper operator--( const int )
  {
    type_wrapper result( *this );
    --value_;
    return( result );
  }


  bool operator&&( const type_wrapper& _rhs )
  {
    return( value_ && _rhs.value_ );
  }


  bool operator||( const type_wrapper& _rhs )
  {
    return( value_ || _rhs.value_ );
  }


  type_wrapper operator!()
  {
    return( type_wrapper( !value_ ) );
  }


  friend std::ostream& operator<<( std::ostream& _stream, const type_wrapper& _type_wrapper )
  {
    _stream << _type_wrapper.value_;
    return( _stream );
  }


private:
  raw_type value_;
};


}


//!\def SXE_CREATE_TYPE_WITH_STR_FORMATTER_IN_NAMESPACE( _namespace, _name, _raw_type )
//!\brief Macro to wrap a type. The new type is created into the given namespace.
//! The _raw_type must be string convertable!
#define SXE_CREATE_TYPE_WITH_STR_FORMATTER_IN_NAMESPACE( _namespace, _name, _raw_type )            \
namespace _namespace                                                                               \
{                                                                                                  \
  using _name = sxe::type_wrapper< _raw_type, class _name##_tag >;                                 \
}                                                                                                  \
                                                                                                   \
template<>                                                                                         \
struct fmt::formatter<_namespace::_name>                                                           \
{                                                                                                  \
  constexpr auto parse( format_parse_context& _context ) -> decltype( _context.begin() )           \
  {                                                                                                \
    return( raw_type_formatter_.parse( _context ) );                                               \
}                                                                                                  \
                                                                                                   \
template <typename format_context>                                                                 \
auto format( const _namespace::_name& _wrapped_value, format_context& _context )                   \
  -> decltype( _context.out() )                                                                    \
{                                                                                                  \
  return( raw_type_formatter_.format( std::to_string( _wrapped_value ), _context ) );              \
}                                                                                                  \
                                                                                                   \
                                                                                                   \
fmt::formatter< std::string > raw_type_formatter_;                                                 \
}

//!\def SXE_CREATE_TYPE_IN_NAMESPACE( _namespace, _name, _raw_type )
//!\brief Macro to wrap a type. The new type is created into the given namespace.
#define SXE_CREATE_TYPE_IN_NAMESPACE( _namespace, _name, _raw_type )                               \
namespace _namespace                                                                               \
{                                                                                                  \
  using _name = sxe::type_wrapper< _raw_type, class _name##_tag >;                                 \
}                                                                                                  \
                                                                                                   \
template<>                                                                                         \
struct fmt::formatter<_namespace::_name>                                                           \
{                                                                                                  \
  constexpr auto parse( format_parse_context& _context ) -> decltype( _context.begin() )           \
  {                                                                                                \
    return( raw_type_formatter_.parse( _context ) );                                               \
}                                                                                                  \
                                                                                                   \
template <typename format_context>                                                                 \
auto format( const _namespace::_name& _wrapped_value, format_context& _context )                   \
  -> decltype( _context.out() )                                                                    \
{                                                                                                  \
  return( raw_type_formatter_.format( _wrapped_value.get_raw(), _context ) );                      \
}                                                                                                  \
                                                                                                   \
                                                                                                   \
fmt::formatter<_raw_type> raw_type_formatter_;                                                     \
}


#endif
