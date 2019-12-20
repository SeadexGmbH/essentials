// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/log/logger.hpp"

#include <iostream>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/basic_file_sink.h>

#if defined( __linux__ ) || defined( __ANDROID__ )
#include <spdlog/sinks/syslog_sink.h>
#endif

#ifdef __ANDROID__
#include <spdlog/sinks/android_sink.h>
#endif


#include "essentials/assert_no_log.hpp"
#include "essentials/conversion.hpp"
#include "essentials/compatibility/compatibility.hpp"


namespace sxe
{


namespace
{


constexpr const char* const SXE_LOG_PATTERN = "%^%-8l%$ : %Y-%m-%dT%H:%M:%S.%f : [%g:%#] : %v";


}



logger& logger::get_instance()
{
	static logger instance;
	return( instance );
}


void logger::add_std_out_sink()
{
	check_non_existance( log_sink_type::STD_SINK );
	auto std_out_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	std_out_sink->set_color_mode( spdlog::color_mode::always );
	{
		std::lock_guard< std::mutex > lock( logger_lock_ );
		created_sinks_.insert( std::make_pair( log_sink_type::STD_SINK, std_out_sink ) );
		default_logger_->sinks().push_back( created_sinks_[ log_sink_type::STD_SINK ] );
		default_logger_->set_pattern( SXE_LOG_PATTERN );
	}
}


void logger::remove_std_out_sink()
{
	remove_sink( log_sink_type::STD_SINK );
}


void logger::add_file_sink( const std::string& _log_file_path, const std::size_t _max_log_file_count, 
	const std::size_t _max_log_file_size )
{
	check_non_existance( log_sink_type::FILE_SINK );
	auto file_sink = std::make_shared< spdlog::sinks::rotating_file_sink_mt >( _log_file_path, 
		_max_log_file_size, _max_log_file_count );
	{
		std::lock_guard< std::mutex > lock( logger_lock_ );
		created_sinks_.insert( std::make_pair<log_sink_type, sink>( log_sink_type::FILE_SINK, file_sink ) );
		default_logger_->sinks().push_back( created_sinks_[ log_sink_type::FILE_SINK ] );
		default_logger_->set_pattern( SXE_LOG_PATTERN );
	}
}


void logger::remove_file_sink()
{
	remove_sink( log_sink_type::FILE_SINK );
}


#if defined( __linux__ ) || defined( __ANDROID__ )


void logger::add_syslog_sink( const std::string& _name )
{
	check_non_existance( log_sink_type::SYSLOG_SINK );
	const int syslog_options = LOG_CONS | LOG_NDELAY;
	const int syslog_facility = LOG_USER;
	const bool enable_formatting = true;
	auto syslog_sink = std::make_shared< spdlog::sinks::syslog_sink_mt >( _name, syslog_options, syslog_facility, enable_formatting );
	{
		std::lock_guard< std::mutex > lock( logger_lock_ );
		created_sinks_.insert( std::make_pair<log_sink_type, sink >( log_sink_type::SYSLOG_SINK, syslog_sink ) );
		default_logger_->sinks().push_back( created_sinks_[ log_sink_type::SYSLOG_SINK ] );
	}
	default_logger_->set_pattern( SXE_LOG_PATTERN );
}


void logger::remove_syslog_sink()
{
	remove_sink( log_sink_type::SYSLOG_SINK );
}


#if defined( __ANDROID__ )


void logger::add_android_sink( const std::string& _name )
{
	check_non_existance( log_sink_type::ANDROID_SINK );
	const char* const ANDROID_TAG = "SXE_ANDROID";
	auto android_logger = std::make_shared < spdlog::sinks::android_sink_mt >( _name, ANDROID_TAG );
	{
		std::lock_guard< std::mutex > lock( logger_lock_ );
		created_sinks_.insert( std::make_pair<log_sink_type, sink >( log_sink_type::ANDROID_SINK, android_logger ) );
		default_logger_->sinks().push_back( created_sinks_[ log_sink_type::ANDROID_SINK ] );
	}
	default_logger_->set_pattern( SXE_LOG_PATTERN );
}


void logger::remove_android_sink()
{
	remove_sink( log_sink_type::ANDROID_SINK );
}


#endif


#endif


void logger::log( const std::string& _file, const int _line, const log_level _log_level, 
	const std::string& _message )
{
	std::lock_guard< std::mutex > lock( logger_lock_ );
	default_logger_->log( spdlog::source_loc { _file.c_str(), _line, SPDLOG_FUNCTION }, _log_level, _message );
}


log_level logger::get_log_level() const
{
	SXE_ASSERT_NO_LOG( default_logger_, "No default logger!" );
	return( default_logger_->level() );
}


void logger::set_log_level( const log_level _log_level )
{
	SXE_ASSERT_NO_LOG( default_logger_, "No default logger!" );
	default_logger_->set_level( _log_level );
}


logger::logger() :
	default_logger_()
{
	const char* const SXE_DEFAULT_NAME = "Seadex";
	configure_logger( SXE_DEFAULT_NAME, LL_DEBUG );
}


logger::~logger() noexcept
{
	// Nothing to do...
}


void logger::configure_logger( const std::string& _name, const log_level _log_level )
{
	default_logger_ = sxe::make_unique< spdlog::logger >( _name );
	default_logger_->set_pattern( SXE_LOG_PATTERN );
	default_logger_->set_level( _log_level );
	default_logger_->set_error_handler( [ this ] ( const std::string& _message )
		{
			default_logger_->error( "LOGGING NOT VALID: {}", _message );
		} );
	spdlog::set_default_logger( default_logger_ );
}


void logger::remove_sink( const log_sink_type _sink )
{
	SXE_ASSERT_NO_LOG( default_logger_, "No default logger!" );
	check_existance( _sink );

	{
		std::lock_guard< std::mutex > lock( logger_lock_ );
		const auto default_logger_it = std::find( default_logger_->sinks().begin(), default_logger_->sinks().end(), created_sinks_[ _sink ] );
		SXE_ASSERT_NO_LOG( default_logger_it != default_logger_->sinks().end(), "Sink was not created!");
		default_logger_->sinks().erase( default_logger_it );
		created_sinks_.erase( _sink );
	}
}


void logger::check_existance( [[maybe_unused]] const log_sink_type _sink )
{
	std::lock_guard< std::mutex > lock( logger_lock_ );
	SXE_ASSERT_NO_LOG( created_sinks_.find( _sink ) != created_sinks_.end(), "Sink does not exist!" );
}


void logger::check_non_existance( [[maybe_unused]] const log_sink_type _sink )
{
	std::lock_guard< std::mutex > lock( logger_lock_ );
	SXE_ASSERT_NO_LOG( created_sinks_.find( _sink ) == created_sinks_.end(), "Sink already exists!" );
}


}
