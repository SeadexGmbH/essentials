// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef CONTEXT_MACROS_E8FFFB6E_1BAD_11EC_9621_0242AC130002
#define CONTEXT_MACROS_E8FFFB6E_1BAD_11EC_9621_0242AC130002


#include <functional>


//!\def SXE_CONTEXT_OPEN( ... )
//!\brief Macro to open a context function.
#define SXE_CONTEXT_OPEN( ... ) \
	std::function<void()> _func = [ __VA_ARGS__ ]() \
	{ \

//!\def SXE_CONTEXT_NAME_CLOSE_SYNC( _context )
//!\brief Macro to end a context function and execute it synchronously.
#define SXE_CONTEXT_NAME_CLOSE_SYNC( _context ) \
	}; \
	( _context ).execute_sync( std::move( _func ) );

//!\def SXE_CONTEXT_NAME_CLOSE_ASYNC( _context, _future )
//!\brief Macro to end a context function and execute it asynchronously.
#define SXE_CONTEXT_NAME_CLOSE_ASYNC( _context, _future ) \
	}; \
	_future = ( _context ).execute_async( std::move( _func ) );

//!\def SXE_CONTEXT_NAME_CLOSE_FIRE_AND_FORGET( _context )
//!\brief Macro to end a context function and execute it asynchronously.
#define SXE_CONTEXT_NAME_CLOSE_FIRE_AND_FORGET( _context ) \
	}; \
	( _context ).execute_async( std::move( _func ) );

//!\def SXE_CONTEXT_CLOSE_SYNC()
//!\brief Macro to end a context function and execute it synchronously. The context is a class member.
#define SXE_CONTEXT_CLOSE_SYNC() SXE_CONTEXT_NAME_CLOSE_SYNC( context_ )

//!\def SXE_CONTEXT_CLOSE_ASYNC( context_, _future )
//!\brief Macro to end a context function and execute it asynchronously. The context is a class member.
#define SXE_CONTEXT_CLOSE_ASYNC( _future ) SXE_CONTEXT_NAME_CLOSE_ASYNC( context_, _future )

//!\def SXE_CONTEXT_NAME_CLOSE_FIRE_AND_FORGET( _context )
//!\brief Macro to end a context function and execute it asynchronously. The context is a class member.
#define SXE_CONTEXT_CLOSE_FIRE_AND_FORGET() SXE_CONTEXT_NAME_CLOSE_FIRE_AND_FORGET( context_ )


#endif
