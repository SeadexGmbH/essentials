// Copyright (c) 2017-, Seadex GmbH
// The Seadex GmbH licenses this file to you under the MIT license.
// This file is part of the Seadex essentials library (http://essentials.seadex.de).


#ifndef VERSION_E55DC329_9A27_4598_928C_1CD8A4AA389E
#define VERSION_E55DC329_9A27_4598_928C_1CD8A4AA389E


#include <cstdint>


namespace sxe
{


namespace version
{


void log_version();


std::uint16_t get_major_version();
std::uint16_t get_minor_version();
std::uint16_t get_patch_version();


}


}


#endif
