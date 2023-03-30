# essentials

## License

Copyright (c) 2017-, Seadex GmbH

Seadex GmbH licenses this project to you under the MIT license.

## Description

essentials is a small C++ library that offers very basic capabilities for applications and libraries:

* basic macros: improved assert, unused parameters, variables only used in asserts
* exception class macro: create own exception classes which can construct messages with placeholders
* macro for making a class non-copyable (C++11-style)
* macros for macro overloading
* macro for creating enhanced enums
* logging
* threading context
* bytes helper functions
* string conversion functions
* helper functions for file to string and file to bytes and vice versa
* datatype wrapper macro


## Dependencies

The essentials library uses the following libraries:

* fmt
* spdlog

For the unit tests project, the Google Test library is used.
