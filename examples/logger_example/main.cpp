// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/log/log.hpp"
#include "essentials/assert.hpp"
#include "std_logger.hpp"
#include "no_log_logger.hpp"


int main()
{
	auto& logger = sxe::logger::get_instance();
	sxe::logger_manager::get_instance().set_logger( logger );
	logger.set_log_level( LL_ERROR );
	logger.add_std_out_sink();
	logger.add_file_sink( "log.log", 1, 1 * 1024 * 1024 );

	SXE_LOG_LOCATED( LL_TRACE, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe");
	SXE_LOG_LOCATED( LL_DEBUG, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe");
	SXE_LOG_LOCATED( LL_INFO, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe");
	SXE_LOG_LOCATED( LL_WARN, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_ERROR, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_FATAL, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );

	SXE_LOG( LL_TRACE, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_DEBUG, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_INFO, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_WARN, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_ERROR, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_FATAL, "{}) Hello {}!", __LINE__, "John Doe" );

	logger.set_log_level( LL_TRACE );

	SXE_LOG_LOCATED( LL_TRACE, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_DEBUG, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_INFO, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_WARN, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_ERROR, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_FATAL, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );

	SXE_LOG( LL_TRACE, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_DEBUG, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_INFO, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_WARN, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_ERROR, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_FATAL, "{}) Hello {}!", __LINE__, "John Doe" );

	logger.remove_std_out_sink();

	std::cout << "removed std_out sink;\n";

	SXE_LOG_LOCATED( LL_TRACE, "main.cpp", __LINE__, "This shall apper only in the file sink." );
	SXE_LOG_LOCATED( LL_DEBUG, "main.cpp", __LINE__, "This shall apper only in the file sink." );
	SXE_LOG_LOCATED( LL_INFO, "main.cpp", __LINE__, "This shall apper only in the file sink." );
	SXE_LOG_LOCATED( LL_WARN, "main.cpp", __LINE__, "This shall apper only in the file sink." );
	SXE_LOG_LOCATED( LL_ERROR, "main.cpp", __LINE__, "This shall apper only in the file sink." );
	SXE_LOG_LOCATED( LL_FATAL, "main.cpp", __LINE__, "This shall apper only in the file sink." );

	SXE_LOG( LL_TRACE, "This shall apper only in the file sink." );
	SXE_LOG( LL_DEBUG, "This shall apper only in the file sink." );
	SXE_LOG( LL_INFO, "This shall apper only in the file sink." );
	SXE_LOG( LL_WARN, "This shall apper only in the file sink." );
	SXE_LOG( LL_ERROR, "This shall apper only in the file sink." );
	SXE_LOG( LL_FATAL, "This shall apper only in the file sink." );

	logger.remove_file_sink();

	std::cout << "removed file sink;\n";

	sxe::test::std_logger std_logger;
	sxe::logger_manager::get_instance().set_logger( std_logger );


	SXE_LOG_LOCATED( LL_TRACE, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_DEBUG, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_INFO, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_WARN, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_ERROR, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_FATAL, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );

	SXE_LOG( LL_TRACE, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_DEBUG, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_INFO, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_WARN, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_ERROR, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_FATAL, "{}) Hello {}!", __LINE__, "John Doe" );

	sxe::logger_manager::get_instance().set_logger( logger );
	logger.add_file_sink( "log2.log", 1, 1 * 1024 * 1024 );
	logger.set_log_level( LL_TRACE );

	SXE_LOG_LOCATED( LL_TRACE, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_DEBUG, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_INFO, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_WARN, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_ERROR, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG_LOCATED( LL_FATAL, "main.cpp", __LINE__, "{}) Hello {}!", __LINE__, "John Doe" );

	SXE_LOG( LL_TRACE, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_DEBUG, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_INFO, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_WARN, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_ERROR, "{}) Hello {}!", __LINE__, "John Doe" );
	SXE_LOG( LL_FATAL, "{}) Hello {}!", __LINE__, "John Doe" );

	logger.remove_file_sink();

	sxe::test::no_log_logger no_logging_logger;
	sxe::logger_manager::get_instance().set_logger( no_logging_logger );

	SXE_LOG( LL_TRACE, "This shall not apper");
	SXE_LOG( LL_DEBUG, "This shall not apper" );
	SXE_LOG( LL_INFO, "This shall not apper" );
	SXE_LOG( LL_WARN, "This shall not apper" );
	SXE_LOG( LL_ERROR, "This shall not apper" );
	SXE_LOG( LL_FATAL, "This shall not apper" );

	return 0;
}
