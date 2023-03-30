// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef LOGGER_3D4864A0_1603_11EC_9621_0242AC130002
#define LOGGER_3D4864A0_1603_11EC_9621_0242AC130002


#include <map>
#include <mutex>


#include "essentials/non_copyable.hpp"
#include "essentials/log/log_sink_type.hpp"
#include "essentials/log/log_level.hpp"

#include "essentials/log/i_logger.hpp"


namespace sxe
{


//!\class logger
//!\brief Essentials logger to be used in the logger manager to log into std out sink or file sinks.
class logger final
	: public virtual i_logger
{
public:
	//!\typedef sink
	//!\brief Alias for spdlog::sink_ptr.
	using sink = spdlog::sink_ptr;

	//!\brief Get the instance of the singleton.
	static logger& get_instance();

	//!\brief Add the std out sink to the logger.
	void add_std_out_sink();

	//!\brief Remove the std out sink from the logger.
	void remove_std_out_sink();

	// _log_file_path is not a std::filesystem::path because of C++11 not supporting std::filesystem
	//!\brief Add the file sink to the logger. Supports file rotation and file size limit.
	//!\param _log_file_path Path where log files are written.
	//!\param _max_log_file_count Maximum number of log files to rotate.
	//!\param _max_log_file_size Maximum size of a log file.
	void add_file_sink( const std::string& _log_file_path, const std::size_t _max_log_file_count,
		const std::size_t _max_log_file_size );

	//!\brief Remove the file sink from the logger.
	void remove_file_sink();


#if defined( __linux__ ) || defined( __ANDROID__ )


	void add_syslog_sink( const std::string& _name );
	void remove_syslog_sink();


#if defined( __ANDROID__ )


	void add_android_sink( const std::string& _name );
	void remove_android_sink();


#endif


#endif

	//!\brief Function to log a message.
	//!\param _file File to be logged.
	//!\param _line Line to be logged.
	//!\param _log_level Log level of the log.
	//!\param _message Message to be logged.
	virtual void log( const std::string& _file, const int _line, const log_level _log_level, 
		const std::string& _message ) override;

	//!\brief Function to get the log level.
	//!\return log_level Log level.
	log_level get_log_level() const;

	//!\brief Function to set the log level.
	//!\param _log_level Log level to be set.
	void set_log_level( const log_level _log_level );

	//!\brief Constructor.
	logger();
	virtual ~logger() noexcept override;


private:
	using logger_sptr = std::shared_ptr< spdlog::logger >;
	using sinks = std::map< log_sink_type, sink >;


	SXE_NO_COPY( logger )
	void configure_logger( const std::string& _name, const log_level _log_level );
	void remove_sink( const log_sink_type _sink );
	void check_existance( [[maybe_unused]] const log_sink_type _sink );
	void check_non_existance( [[maybe_unused]] const log_sink_type _sink );


	logger_sptr default_logger_;
	sinks created_sinks_;
	std::mutex logger_lock_;
};


}

#endif
