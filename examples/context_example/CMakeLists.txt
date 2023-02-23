cmake_minimum_required(VERSION 3.0)

project(context_example)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

set(HEADER_FILES "./../../essentials/include/essentials/*.hpp"
"./../../essentials/include/essentials/compatibility/*.hpp"
"./../../essentials/include/essentials/execution/*.hpp"
"./../../essentials/include/essentials/log/*.hpp"
"./../../essentials/include/essentials/preprocessor/*.hpp")
file(GLOB context_example_SRC "./*.cpp" ${HEADER_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../../CMakeHelpers/addSpecificFlags.cmake)
include(./../../CMakeHelpers/addSeadexOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

set(link_libraries_list "")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library_for_linking(link_libraries_list essentials)
else()
	add_library_for_linking(link_libraries_list libessentials)
	find_package(Threads REQUIRED)
	add_library_for_linking(link_libraries_list Threads::Threads)
endif()

if( NOT "${FMT_LIB_INCLUDE}" STREQUAL "" AND NOT "${FMT_LIB}" STREQUAL "" AND NOT "${SPDLOG_LIB_INCLUDE}" STREQUAL "" AND NOT "${SPDLOG_LIB}" STREQUAL "")
	include_directories("${FMT_LIB_INCLUDE}")
	include_directories("${SPDLOG_LIB_INCLUDE}")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D \"SPDLOG_FMT_EXTERNAL\"")
	add_library_for_linking(link_libraries_list "${FMT_LIB}")
	add_library_for_linking(link_libraries_list "${SPDLOG_LIB}")
else()
	include_directories("${CMAKE_INCLUDE_PATH}")
endif()

message(STATUS "context_example linking to libraries: ${link_libraries_list}")

ADD_EXECUTABLE(context_example ${context_example_SRC})

include_directories("./../../essentials/include")

TARGET_LINK_LIBRARIES(context_example ${link_libraries_list})

ENABLE_TESTING()
ADD_TEST(context_example AUTO)

install(TARGETS context_example DESTINATION bin)
