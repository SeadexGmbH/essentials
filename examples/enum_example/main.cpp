// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include <string>

#include "essentials/enhanced_enum.hpp"
#include "essentials/log/log.hpp"


#define PRODUCTS YASMINE,PANDEMIC,ESSENTIALS,HERMES,GENESIS,YARCH

SXE_ENHANCED_ENUM( Software, PRODUCTS )


int main()
{
	auto& logger = sxe::logger::get_instance();
	logger.set_log_level( LL_TRACE );
	logger.add_std_out_sink();

	const auto software = Software( 3 );
	std::string result = "NO_RESULT";

	switch( software )
	{
	case Software::YASMINE:
		break;

	case Software::PANDEMIC:
		break;

	case Software::ESSENTIALS:
		break;

	case Software::HERMES:
		result = Software( Software::HERMES ).to_string();
		break;

	case Software::GENESIS:
		break;

	case Software::YARCH:
		break;

	default:
		break;
	}

	SXE_LOG( LL_DEBUG, "The result is {}.", result );

	return 0;
}