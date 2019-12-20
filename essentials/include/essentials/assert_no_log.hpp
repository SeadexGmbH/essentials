// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef ASSERT_NO_LOG_C56D83C3_F136_4F3B_8E29_BD3B3FCFA54F
#define ASSERT_NO_LOG_C56D83C3_F136_4F3B_8E29_BD3B3FCFA54F


#include <cassert>


#ifndef NDEBUG


//!\def SXE_ASSERT_NO_LOG( _condition, ... )
//!\brief Assert a given condition.
#define SXE_ASSERT_NO_LOG( _condition, _message )                     \
 assert( ( _condition ) && _message )                                 \

#else


#define SXE_ASSERT_NO_LOG( _condition, ... ) static_cast<void>( _condition )


#endif


#endif
