// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef URI_72CBB6C3_57D9_443A_99F0_9EDE9A2BC07D
#define URI_72CBB6C3_57D9_443A_99F0_9EDE9A2BC07D


#include <deque>
#include <string>
#include <vector>
#include <sstream>


#include "essentials/assert.hpp"


namespace sxe
{


const char DEFAULT_URI_DELIMITER = '/';


//!\class basic_uri
//!\brief Class providing extended uri functionality.
template< const char _uri_delimiter >
class basic_uri final
{
public:

	//!\typedef uri_type
	//!\brief Alias for the basic_uri< _uri_delimiter >.
	using uri_type = basic_uri< _uri_delimiter >;


	//!\brief Constructor.
	//!\param _uri A possible first segment in the uri.
	basic_uri( const std::string& _uri = "" ) :
		uri_()
	{
		split_string_to_uri_segments( _uri );
	}


	~basic_uri() noexcept = default;

	//!\brief Check if the uri is empty.
	//!\return bool True if empty, false otherwise.
	//!\sa size
	bool is_empty() const
	{
		return( uri_.empty() );
	}

	//!\brief Get the uri as a string.
	//!\return std::string Uri as a string.
	const std::string to_string() const
	{
		return( build_uri() );
	}

	//!\brief Get the front segment as a string. Uri must not be empty!
	//!\return std::string Front segment.
	//!\sa pop_back, push_back, pop_front, push_front, get_back
	const std::string& get_front() const
	{
		SXE_ASSERT( !uri_.empty(), "Uri is empty!" );
		return( uri_.front() );
	}

	//!\brief Get the back segment as a string. Uri must not be empty!
	//!\return std::string Back segment.
	//!\sa pop_back, push_back, pop_front, push_front, get_front
	const std::string& get_back() const
	{
		SXE_ASSERT( !uri_.empty(), "Uri is empty!" );
		return( uri_.back() );
	}

	//!\brief Get a list of segments of the uri.
	//!\return const std::deque< std::string >& List of segments of the uri.
	const std::deque< std::string >& get_segments() const
	{
		return ( uri_ );
	}

	//!\brief Add a segment in the front of the uri.
	//!\param _segment String segment to be added.
	//!\return uri_type& Uri reference.
	//!\sa pop_back, push_back, pop_front, get_back, get_front
	uri_type& push_front( const std::string& _segment )
	{
		uri_.push_front( _segment );
		return ( *this );
	}

	//!\brief Add a segment in the back of the uri.
	//!\param _segment String segment to be added.
	//!\return uri_type& Uri reference.
	//!\sa pop_back, push_front, pop_front, get_back, get_front
	uri_type& push_back( const std::string& _segment )
	{
		uri_.push_back( _segment );
		return ( *this );
	}

	//!\brief Add a uri in the back of the uri.
	//!\param _uri Uri to be added.
	//!\return uri_type& Uri reference.
	//!\sa pop_back, push_front, pop_front, get_back, get_front
	uri_type& push_back( const uri_type& _uri )
	{
		for( const auto& segment : _uri.get_segments() )
		{
			push_back( segment );
		}
		return ( *this );
	}

	//!\brief Remove the segment in the front of the uri. Uri must not be empty!
	//!\return uri_type& Uri reference.
	//!\sa pop_back, push_front, push_back, get_back, get_front
	uri_type& pop_front()
	{
		SXE_ASSERT( !uri_.empty(), "Uri is empty!" );
		uri_.pop_front();
		return ( *this );
	}


	//!\brief Remove the segment in the back of the uri. Uri must not be empty!
	//!\return uri_type& Uri reference.
	//!\sa pop_front, push_front, push_back, get_back, get_front
	uri_type& pop_back()
	{
		SXE_ASSERT( !uri_.empty(), "Uri is empty!" );
		uri_.pop_back();
		return ( *this );
	}


	//!\brief Get the size of the uri.
	//!\return size_t Uri size.
	//!\sa is_empty
	size_t size() const
	{
		return( uri_.size() );
	}

	//!\brief Merge uri via operator/.
	//!\return uri_type& Uri reference.
	uri_type& operator/( const uri_type& _uri )
	{
		split_string_to_uri_segments( _uri.to_string() );
		return( *this );
	}


	//!\brief Merge uri via operator/.
	//!\return uri_type& Uri reference.
	uri_type& operator/( const std::string& _uri )
	{
		split_string_to_uri_segments( _uri );
		return( *this );
	}


private:
	const std::string build_uri() const
	{
		std::stringstream uri;

		for( const std::string& uri_element : uri_ )
		{
			uri << _uri_delimiter << uri_element;
		}

		return( uri.str() );
	}


	void split_string_to_uri_segments( const std::string& _uri )
	{
		std::string uri = _uri;
		if( !_uri.empty() )
		{
			if( _uri_delimiter == _uri[ 0 ] )
			{
				uri = _uri.substr( 1 );
			}

			std::string::size_type start = 0;
			std::string::size_type end = uri.find( _uri_delimiter );
			while( end != std::string::npos )
			{
				const std::string& segment = uri.substr( start, end - start );
				uri_.push_back( segment );
				start = ++end;
				end = uri.find( _uri_delimiter, end );
			}

			const std::string& last_segment = uri.substr( start );
			if( last_segment[ 0 ] != _uri_delimiter )
			{
				uri_.push_back( last_segment );
			}
		}
	}


	std::deque< std::string > uri_;
};


//!\typedef uri
//!\brief Alias for the uri having '/' as the delimiter.
using uri = basic_uri< DEFAULT_URI_DELIMITER >;


}


#endif
