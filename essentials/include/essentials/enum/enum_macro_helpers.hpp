// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef ENUM_MACRO_HELPERS_E22B966A_6E0C_4C95_A920_388AB3FE457A
#define ENUM_MACRO_HELPERS_E22B966A_6E0C_4C95_A920_388AB3FE457A


#include "essentials/preprocessor/macro_helpers.hpp"
#include "essentials/enum/make_pair_idx_x.hpp"
#include "essentials/enum/enum_idx_x.hpp"


#define SXE_MAKE_PAIR_WITH_ENUM_STRING( a, b ) { a, SXE_STRINGIFY( b ) }

#define SXE_MAKE_PAIR_IDX( value, _idx, _values, _names ) \
SXE_MAKE_PAIR_WITH_ENUM_STRING( value( SXE_GET_ARGUMENT_NR( _idx, SXE_EXPAND( _values ) ) ), SXE_GET_ARGUMENT_NR( _idx, SXE_EXPAND( _names ) ) )

#define SXE_ENUM_CHAR_STEP_1(_a , _b) _b = _a

#define SXE_ENUM_CHAR( a, b ) SXE_ENUM_CHAR_STEP_1(a, b)

#if _MSC_VER
	#define SXE_ENUM_IDX( _idx, _values, _names ) \
	SXE_ENUM_CHAR( SXE_GET_ARGUMENT_NR( _idx, SXE_EXPAND( _values) ), SXE_GET_ARGUMENT_NR( _idx, SXE_EXPAND( _names ) ) )
#else
	#define SXE_ENUM_IDX( _idx, _values, _names ) \
	SXE_ENUM_CHAR( SXE_GET_ARGUMENT_NR( _idx, _values ), SXE_GET_ARGUMENT_NR( _idx, _names ) )
#endif


#define SXE_ENUM_PAIRS_IMPL( _txt, _values, _names ) \
SXE_EXPAND( SXE_SELECT( SXE_MAKE_PAIR_IDX, SXE_VA_SIZE_IDX( _values ) ) ) ( _txt, ( _values ), ( _names ) )


#if _MSC_VER 
	#define SXE_ENUM_PAIRS( _txt, _values, _names ) SXE_ENUM_PAIRS_IMPL( _txt, _values, _names )

	#define SXE_ENUM_PAIRS_WITH_EQUAL_IMPL( _values, _names ) \
	SXE_EXPAND( SXE_SELECT( SXE_ENUM_IDX, SXE_VA_SIZE_IDX( _values ) ) ) ( ( _values ), ( _names ) )
#else
	#define SXE_ENUM_PAIRS( _txt, _values, _names ) SXE_ENUM_PAIRS_IMPL( _txt, SXE_NO_SEQ_PARANTHESIS( _values ), SXE_NO_SEQ_PARANTHESIS( _names ) )

	#define SXE_ENUM_PAIRS_WITH_EQUAL_IMPL( _values, _names ) \
	SXE_EXPAND( SXE_SELECT( SXE_ENUM_IDX, SXE_VA_SIZE_IDX _values ) ) ( _values, _names )
#endif



#define SXE_ENUM_PAIRS_WITH_CHAR( _values, _names )\
SXE_ENUM_PAIRS_WITH_EQUAL_IMPL( _values, _names )


#if _MSC_VER

	#define SXE_ENUM_VALUES_IMPL( _enum_values, _enum_names) \
	SXE_ENUM_PAIRS_WITH_CHAR( _enum_values, _enum_names )

	#define SXE_ENUM_VALUES( _enum_values, _enum_value_names ) \
	SXE_ENUM_VALUES_IMPL( SXE_NO_SEQ_PARANTHESIS( _enum_values ), SXE_NO_SEQ_PARANTHESIS( _enum_value_names ) )

	#define SXE_ENUM_MAP( _txt, _enum_values, _enum_names) \
	{ SXE_ENUM_PAIRS( _txt, SXE_NO_SEQ_PARANTHESIS( _enum_values ), SXE_NO_SEQ_PARANTHESIS( _enum_names ) ) }
#else

	#define SXE_ENUM_VALUES( _enum_values, _enum_value_names ) \
	SXE_ENUM_PAIRS_WITH_CHAR( _enum_values, _enum_value_names )

	#define SXE_ENUM_MAP( _txt, _enum_values, _enum_names) \
	{ SXE_ENUM_PAIRS( _txt, _enum_values, _enum_names ) }
#endif


#endif
