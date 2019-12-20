// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).

#ifndef MACRO_HELPERS_D52C3077_E0EF_4C4E_B451_1472DEE602E8
#define MACRO_HELPERS_D52C3077_E0EF_4C4E_B451_1472DEE602E8


#ifndef SX_NO_VARIADIC_MACRO


#include "essentials/preprocessor/macro_get_argument_x.hpp"
#include "essentials/preprocessor/macro_stringify.hpp"
#include "essentials/preprocessor/macro_count.hpp"


//!\def SXE_EXPAND( x )
//!\brief Helper to work around some Visual C++ compiler quirk dealing with variadic macros.
#define SXE_EXPAND( x ) x

//!\def SXE_SELECT( NAME, NUM )
//!\brief Creating a name from a base name and a number with an underscore between them.
#define SXE_SELECT( NAME, NUM ) SXE_CAT( NAME ## _, NUM )

//!\def SXE_VA_SELECT( NAME, ... )
//!\brief Selects the correct overloaded macro based on the number of parameters.
#define SXE_VA_SELECT( NAME, ... ) SXE_EXPAND( SXE_SELECT( NAME, SXE_VA_SIZE( __VA_ARGS__ ) )( __VA_ARGS__ ) )

#define SXE_CAT_II( p, res ) res
#define SXE_CAT_I( a, b ) SXE_CAT_II( ~, a ## b )

//!\def SXE_CAT( a, b )
//!\brief Concatenate two tokens.
#define SXE_CAT( a, b ) SXE_CAT_I( a, b )

//!\def SXE_GET_ARGUMENT_NR( x, ... )
//!\brief Gets the argument with index x from the given sequence. Starts with the index 0.
#define SXE_GET_ARGUMENT_NR( x, ...) SXE_EXPAND( SXE_SELECT( SXE_GET_ARGUMENT, x ) ) __VA_ARGS__

#define SXE_NO_SEQ_PARANTHESIS_IMPL( ... ) __VA_ARGS__

//!\def SXE_NO_SEQ_PARANTHESIS( seq )
//!\brief Removes the paranthesis of the given sequence.
#define SXE_NO_SEQ_PARANTHESIS( seq ) SXE_NO_SEQ_PARANTHESIS_IMPL seq


#endif


#endif
