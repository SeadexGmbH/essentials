// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef LOGGER_MANAGER_B5B37AF7_8035_4E06_830C_A525C8886692
#define LOGGER_MANAGER_B5B37AF7_8035_4E06_830C_A525C8886692


#include "essentials/log/i_logger.hpp"


namespace sxe
{


//!\class logger_manager
//!\brief Singleton class that manages the logger. The logger class is used as the default logger. If 
//! ESS_USE_NULL_LOGGER is defined, a null-functionality logger will be used instead.
class logger_manager final
{
public:

	//!\brief Get the instance of the singleton.
	static logger_manager& get_instance();

	//!\brief Set the logger to be used.
	void set_logger( i_logger& _logger );

	//!\brief Get the logger that is currently in use.
	i_logger& get_logger();


private:
	logger_manager();
	~logger_manager() noexcept = default;

	i_logger* logger_;

};


}


#endif
