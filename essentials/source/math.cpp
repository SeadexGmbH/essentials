// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/math.hpp"

#include <cmath>


namespace sxe
{


double round( const double _value, const std::uint16_t _precision )
{
	const auto precision = std::pow( 10, _precision );
	return ( std::round( _value * precision ) / precision );
}


}
