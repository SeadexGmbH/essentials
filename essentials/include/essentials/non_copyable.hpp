// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef NON_COPYABLE_D2C5BF6C_4B43_42AF_9E42_1AAE2B5C49C8
#define NON_COPYABLE_D2C5BF6C_4B43_42AF_9E42_1AAE2B5C49C8


#include "essentials/compatibility/compatibility.hpp"


namespace sxe
{


//!\def SXE_NO_COPY( _class_name )
//!\brief Delete the copy constructor and assignment operator of the given class.
#define SXE_NO_COPY( _class_name )\
	_class_name( const _class_name& ) = delete;\
	_class_name& operator=( const _class_name& ) = delete;\
\


//!\def SXE_NO_ASSIGNMENT_OPERATOR( _class_name )
//!\brief Delete the assignment operator of the given class.
#define SXE_NO_ASSIGNMENT_OPERATOR( _class_name )\
	_class_name& operator=( const _class_name& ) = delete;\
\


}


#endif
