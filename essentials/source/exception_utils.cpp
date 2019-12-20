// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/exception_utils.hpp"


namespace sxe
{


std::string what( const std::exception_ptr& _exception_ptr )
{
  if( !_exception_ptr )
  {
    throw std::bad_exception();
  }

  try 
  {
    std::rethrow_exception( _exception_ptr );
  }
  catch( const std::exception& _exception ) 
  {
    return ( _exception.what() );
  }
  catch( ... )
  {
    return ( "Unknown exception!" );
  }
}


}
