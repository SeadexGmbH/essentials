// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef STRING_UTILS_AE49A607_6B6F_4CC0_BABF_940791514A49
#define STRING_UTILS_AE49A607_6B6F_4CC0_BABF_940791514A49


#include <string>
#include <vector>


namespace sxe
{

//!\brief Replace a string with another string in a string source.
//!\param _data Source string.
//!\param _replaced String to be replaced.
//!\param _replacer Replacer string.
//!\return std::string The result string after the replace.
std::string replace_all( const std::string& _data, const std::string& _replaced, const std::string& _replacer );

//!\brief Split string by the given delimiter.
//!\param _source Source string.
//!\param _delimiter Delimiter.
//!\return std::vector< std::string > List of segments resulted after the split.
std::vector< std::string > split( const std::string& _source, const std::string& _delimiter );


}


#endif
