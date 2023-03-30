cmake_minimum_required(VERSION 3.8)

project(essentials_all)

include(./CMakeHelpers/functions.cmake)
include(./CMakeHelpers/functionsAddCompilerFlags.cmake)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED CPP_VERSION AND "${CPP_VERSION}" STREQUAL "03")
	message(SEND_ERROR "Error: C++03 is no longer supported!")
endif()

set(CMAKE_CXX_FLAGS "${} -D \"FMT_HEADER_ONLY\"  -D \"SPDLOG_FMT_EXTERNAL\"")

if( (NOT "${FMT_LIB_INCLUDE}" STREQUAL "") AND (NOT "${FMT_LIB}" STREQUAL "") AND (NOT "${SPDLOG_LIB_INCLUDE}" STREQUAL "") AND (NOT "${SPDLOG_LIB}" STREQUAL ""))
	message(STATUS "libfmt or spdlog paths provided by user.")
else()
	if(EXISTS "${PROJECT_SOURCE_DIR}/conan_toolchain.cmake")
		message(STATUS "Using Conan.")
	else()
		message(STATUS "Conan CMake file not present. Conan is not used.")
	endif()
endif()

add_subdirectory(essentials)

if(ESS_BUILD_UNIT_TESTS AND EXISTS "${PROJECT_SOURCE_DIR}/essentials_unit_tests")
	message(STATUS "Build unit tests.")
	add_subdirectory(essentials_unit_tests)
endif()


if(ESS_BUILD_EXAMPLES AND EXISTS "${PROJECT_SOURCE_DIR}/examples")
	message(STATUS "Build examples.")
	add_subdirectory(examples)
endif()


if(ESS_BUILD_EXAMPLES AND EXISTS "${PROJECT_SOURCE_DIR}/bug_reproductions")
	message(STATUS "Build bug reproductions projects.")
	add_subdirectory(bug_reproductions)
endif()