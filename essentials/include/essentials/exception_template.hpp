// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef EXCEPTION_TEMPLATE_6EFED438_B578_4EF6_B02A_53DC49B89A0D
#define EXCEPTION_TEMPLATE_6EFED438_B578_4EF6_B02A_53DC49B89A0D


#include <exception>

#include <fmt/format.h>

#include "essentials/preprocessor/macro_helpers.hpp"



//!\def SXE_EXCEPTION_WITH_BASE( _name, _base_class_name )
//!\brief Create an exception class inheriting the given base class with the given name. It also supports
//! creating messages with placeholders by calling fmt::format.
#define SXE_EXCEPTION_WITH_BASE( _name, _base_class_name )           \
class _name: public _base_class_name                                 \
{                                                                    \
public:                                                              \
  template< typename ... args >                                      \
  _name( const std::string & _what, args ... _args ):                \
    _base_class_name( _what, std::forward< args >( _args ) ... )     \
  {                                                                  \
  }                                                                  \
                                                                     \
                                                                     \
  virtual ~_name () noexcept override = default;                     \
};



//!\def SXE_EXCEPTION( _name )
//!\brief Create an exception class inheriting std::exception with the given name. It also supports
//! creating messages with placeholders by calling fmt::format.
#define SXE_EXCEPTION( _name )                             \
class _name: public std::exception                         \
{                                                          \
public:                                                    \
  template< typename ... args >                            \
  _name( const std::string & _what, args ... _args ):      \
    std::exception(),                                      \
    what_( fmt::format( _what.c_str(), _args ... ) )       \
  {                                                        \
  }                                                        \
                                                           \
                                                           \
	virtual ~_name () noexcept override = default;           \
                                                           \
                                                           \
  virtual const char* what() const throw () override       \
  {                                                        \
    return ( what_.c_str() );                              \
  }                                                        \
                                                           \
                                                           \
private:                                                   \
  std::string what_;                                       \
                                                           \
                                                           \
};


//!\def SXE_EXCEPTION_WITH_CODE_IN_NAMESPACE( _namespace, _name, _code )
//!\brief Create an exception class inheriting std::exception with the given name. 
//! It also supports creating messages with placeholders by calling fmt::format.
//! It provides an error code as well.
#define SXE_EXCEPTION_WITH_CODE_IN_NAMESPACE( _namespace, _name, _error_code_type )                                  \
namespace _namespace                                                                                                 \
{                                                                                                                    \
  using _name = exception_with_error_code< _error_code_type, class SXE_CAT( SXE_CAT( _namespace, _name ), _tag ) >;  \
}


//!\def SXE_EXCEPTION_WITH_CODE( _name, _code )
//!\brief Create an exception class inheriting std::exception with the given name. 
//! It also supports creating messages with placeholders by calling fmt::format.
//! It provides an error code as well.
#define SXE_EXCEPTION_WITH_CODE( _name, _error_code_type )                                          \
using _name = exception_with_error_code< _error_code_type, class _name##_tag >;


template< typename _error_code_type, typename _exception_tag_name >
class exception_with_error_code final: public std::exception
{
public:
  template< typename ... args >
  exception_with_error_code( const _error_code_type& _error_code, const std::string & _what, args ... _args ): 
    std::exception(),
    what_( fmt::format( _what.c_str(), _args ... ) ),
    error_code_( _error_code )
  {
    // Nothing to do...
  }


	virtual ~exception_with_error_code() noexcept override = default;


  virtual const char* what() const throw () override
  {
    return ( what_.c_str() );
  }


  _error_code_type error_code() const
  {
    return( error_code_ );
  }


private:
  std::string what_;
  _error_code_type error_code_;
};


#endif
