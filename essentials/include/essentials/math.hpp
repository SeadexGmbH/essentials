// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef MATH_F3022496_A50C_4FD5_82F6_8F4A4D0FE3F9
#define MATH_F3022496_A50C_4FD5_82F6_8F4A4D0FE3F9


#include <cstdint>


namespace sxe
{


//!\brief Round a double value with the given precision.
//!\param _value Double value to round.
//!\param _precision Precision of round.
//!\return double Rounded double value.
//!\sa file_to_bytes
double round( const double _value, const std::uint16_t _precision );


}


#endif
