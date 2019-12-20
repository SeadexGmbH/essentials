// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef FILE_6B7D6D37_B879_4439_80E4_D333B62609C6
#define FILE_6B7D6D37_B879_4439_80E4_D333B62609C6


#if __cplusplus >= 201703L


#include <filesystem>
#include <string>
#include <vector>


namespace sxe
{


//!\brief Get the content of the given file as a string.
//!\param _file_path File path.
//!\return std::string File content as a string.
//!\sa file_to_bytes
std::string file_to_string( const std::filesystem::path& _file_path );

//!\brief Get the content of the given file as bytes (a vector of integers).
//!\param _file_path File path.
//!\return std::vector<std::uint8_t> File content as bytes.
//!\sa file_to_string, bytes_to_file
std::vector<std::uint8_t> file_to_bytes( const std::filesystem::path& _file_path );

//!\brief Get the content of the given file as bytes.
//!\param _file_path File path.
//!\param _bytes The memory position where the bytes starts.
//!\param _size Size of data to be writen in the file.
//!\sa file_to_bytes
void bytes_to_file( const std::filesystem::path& _file_path, const std::vector< std::uint8_t >& _bytes, 
	const std::size_t _size );

//!\brief Get the content of the given file as a string.
//!\param _file_path File path.
//!\return std::string File content as a string.
//!\sa file_to_bytes
void string_to_file( const std::filesystem::path& _file_name, const std::string& _output );


}


#endif


#endif
