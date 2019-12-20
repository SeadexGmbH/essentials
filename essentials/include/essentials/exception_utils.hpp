// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef EXCEPTION_UTILS_EB733731_2E95_4DCA_8CFD_5438D0239973
#define EXCEPTION_UTILS_EB733731_2E95_4DCA_8CFD_5438D0239973


#include <exception>
#include <string>


namespace sxe
{


//!\brief Extracts the exception message.
//!\param _exception_ptr Exception pointer.
//!\return The message of the exception.
std::string what( const std::exception_ptr& _exception_ptr = std::current_exception() );


}


#endif
