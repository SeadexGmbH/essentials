// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef MACRO_STRINGIFY_DA342339_7644_4448_B3ED_6C6FF7BA35CF
#define MACRO_STRINGIFY_DA342339_7644_4448_B3ED_6C6FF7BA35CF


#define SXE_STRINGIFY_STEP_2( ... ) #__VA_ARGS__
#define SXE_STRINGIFY_STEP_1( arg ) SXE_STRINGIFY_STEP_2 arg
#define SXE_STRINGIFY( text ) SXE_STRINGIFY_STEP_1( ( text ) )


#endif
