// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/string_utils.hpp"


namespace sxe
{


// cppcheck-suppress unusedFunction
std::string replace_all( const std::string& _data, const std::string& _replaced, const std::string& _replacer )
{
	auto data = _data;
	std::size_t pos = data.find( _replaced );

	while( pos != std::string::npos )
	{
		data.replace( pos, _replaced.size(), _replacer );
		pos = data.find( _replaced, pos + _replacer.size() );
	}

	return ( data );
}


// cppcheck-suppress unusedFunction
std::vector< std::string > split( const std::string& _source, const std::string& _delimiter )
{
	std::vector< std::string > result;
	auto source = _source;
	std::size_t pos = 0;
	std::string token;
	while( ( pos = source.find( _delimiter ) ) != std::string::npos )
	{
		token = source.substr( 0, pos );
		result.push_back( token );
		source.erase( 0, pos + _delimiter.length() );
	}
	result.push_back( source );

	return ( result );
}


}
