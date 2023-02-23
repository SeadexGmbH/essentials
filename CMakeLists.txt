cmake_minimum_required(VERSION 3.0)

project(essentials_all)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

include(./CMakeHelpers/setVariables.cmake)
include(./CMakeHelpers/functions.cmake)
include(./CMakeHelpers/functionsAddCompilerFlags.cmake)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED CPP_VERSION AND "${CPP_VERSION}" STREQUAL "03")
	message(SEND_ERROR "Error: C++03 is no longer supported!")
endif()

add_compile_options(-DFMT_HEADER_ONLY)

if( (NOT "${FMT_LIB_INCLUDE}" STREQUAL "") AND (NOT "${SPDLOG_LIB}" STREQUAL "") AND (NOT "${SPDLOG_LIB_INCLUDE}" STREQUAL "") AND (NOT "${SPDLOG_LIB}" STREQUAL ""))
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D \"SPDLOG_FMT_EXTERNAL\"")
	message(STATUS "libfmt or spdlog paths provided by user.")
else()
	if(EXISTS "${PROJECT_SOURCE_DIR}/conan_toolchain.cmake")
		message(STATUS "Using Conan.")		
		set(SPDLOG_FMT_EXTERNAL ON CACHE BOOL "")
	else()
		message(STATUS "Conan CMake file not present. Conan is not used.")
	endif()
endif()

add_subdirectory(essentials)

if(ESS_BUILD_UNIT_TESTS AND EXISTS "${PROJECT_SOURCE_DIR}/essentials_unit_tests")
	message(STATUS "Build unit tests.")
	add_subdirectory(essentials_unit_tests)
endif()


if(EXISTS "${PROJECT_SOURCE_DIR}/examples")
	message(STATUS "Build examples.")
	add_subdirectory(examples)
endif()


if(EXISTS "${PROJECT_SOURCE_DIR}/bug_reproductions")
	message(STATUS "Build bug reproductions projects.")
	add_subdirectory(bug_reproductions)
endif()