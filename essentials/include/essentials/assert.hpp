// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef BASE_0C97CC9D_8A5B_4696_9964_49819CD9233A
#define BASE_0C97CC9D_8A5B_4696_9964_49819CD9233A


#include "essentials/assert_no_log.hpp"
#include "essentials/log/log.hpp"
#include "essentials/log/log_level.hpp"


#ifndef NDEBUG


//!\def SXE_ASSERT( _condition, ... )
//!\brief Assert a given condition. Adds the message to the log for better diagnostics 
//! when the assert is triggered.
#define SXE_ASSERT( _condition, ... )                     \
 if( !( _condition ) )                                    \
 {                                                        \
   SXE_LOG( LL_FATAL, __VA_ARGS__ );                      \
 }                                                        \
 assert( ( _condition ) )                                 \

//!\def SXE_ASSERT_EXTENDED( _condition, _message, _formatted_message, ... )
//!\brief Assert a given condition. Adds the message to the assert and the formatted 
//! message to the log for better diagnostics when the assert is triggered.
#define SXE_ASSERT_EXTENDED( _condition, _message, ... )                     \
 if( !( _condition ) )                                                       \
 {                                                                           \
   SXE_LOG( LL_FATAL, __VA_ARGS__ );                                         \
 }                                                                           \
 assert( ( _condition ) && _message )                                        \


#else


#define SXE_ASSERT( _condition, ... ) static_cast<void>( _condition )

#define SXE_ASSERT_EXTENDED( _condition, ... ) static_cast<void>( _condition )


#endif


#endif
