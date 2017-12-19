cmake_minimum_required(VERSION 2.8)

project(essentials_unit_tests)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

set(HEADER_FILES "./../essentials/include/essentials/*.hpp" "./../essentials/include/essentials/compatibility/*.hpp")
file(GLOB essentials_unit_tests_SRC "./*.cpp" ${HEADER_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addSeadexOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

add_executable(essentials_unit_tests ${essentials_unit_tests_SRC})
include_directories("./../essentials/include")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")		
	ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 
endif()

set(link_libraries_list "")
use_boost_libraries(link_libraries_list)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library_for_linking(link_libraries_list libessentials)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library_for_linking(link_libraries_list essentials)
endif()

message(STATUS "essentials_unit_tests linking to libraries: ${link_libraries_list}" )
target_link_libraries(essentials_unit_tests LINK_PUBLIC ${link_libraries_list})

install(TARGETS essentials_unit_tests DESTINATION bin)
