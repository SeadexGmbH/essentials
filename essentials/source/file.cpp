// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#include "essentials/file.hpp"


#if __cplusplus >= 201703L


#include <sstream>
#include <fstream>

#include "essentials/exception.hpp"


namespace sxe
{


std::string file_to_string( const std::filesystem::path& _file_path )
{
	std::string content;
	std::ifstream inputFile( _file_path, std::ios::in | std::ios::binary );
	if( inputFile )
	{
		std::ostringstream outputString;
		outputString << inputFile.rdbuf();
		inputFile.close();
		auto file_size = std::filesystem::file_size( _file_path );

		if( !( outputString.rdstate() & std::ios::failbit ) )
		{
			content = outputString.str();
			if( content.size() != file_size )
			{
				throw exception( "Could not read file {} correctly!", _file_path.string() );
			}
		}
		else
		{
			throw exception( "Could not read file {} correctly!", _file_path.string() );
		}
	}
	else
	{
		throw exception( "Cannot read file {}!", _file_path.string() );
	}

	return ( content );
}


std::vector<std::uint8_t> file_to_bytes( const std::filesystem::path& _file_path )
{
	const auto content_as_string = file_to_string( _file_path );
	std::vector<std::uint8_t> content( content_as_string.begin(), content_as_string.end() );
	return ( content );
}


void bytes_to_file( const std::filesystem::path& _file_path, const std::vector< std::uint8_t >& _bytes, 
	const std::size_t _size )
{
	auto file = std::fstream( _file_path, std::ios::out | std::ios::binary );
	file.write( reinterpret_cast< const char* >( _bytes.data() ), _size );
	file.close();
}


void string_to_file( const std::filesystem::path& _file_name, const std::string& _output )
{
	std::ofstream file_stream( _file_name );
	file_stream.write( _output.c_str(), _output.size() );
	file_stream.close();

	if( file_stream.rdstate() & std::ios::failbit )
	{
		throw exception( "Could not write file {} correctly!", _file_name.string() );
	}
}


}


#endif
