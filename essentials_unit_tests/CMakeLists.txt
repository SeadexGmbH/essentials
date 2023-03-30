cmake_minimum_required(VERSION 3.8)

project(essentials_unit_tests)

set(HEADER_FILES "./../essentials/include/essentials/*.hpp" 
"./../essentials/include/essentials/compatibility/*.hpp"
"./../essentials/include/essentials/execution/*.hpp"
"./../essentials/include/essentials/log/*.hpp"
"./../essentials/include/essentials/preprocessor/*.hpp")
file(GLOB essentials_unit_tests_SRC "./*.cpp" ${HEADER_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addSeadexOptions.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

set(link_libraries_list "")

ADD_EXECUTABLE(essentials_unit_tests ${essentials_unit_tests_SRC})

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library_for_linking(link_libraries_list essentials)

	if( (NOT "${FMT_LIB_INCLUDE}" STREQUAL "") AND (NOT "${FMT_LIB}" STREQUAL "") 
	AND (NOT "${SPDLOG_LIB_INCLUDE}" STREQUAL "") AND (NOT "${SPDLOG_LIB}" STREQUAL "") 
	AND (NOT "${GTEST_LIB_INCLUDE}" STREQUAL "") AND (NOT "${GTEST_LIB}" STREQUAL ""))
		add_library_for_linking(link_libraries_list "${FMT_LIB}")
		add_library_for_linking(link_libraries_list "${SPDLOG_LIB}")
		add_library_for_linking(link_libraries_list "${GTEST_LIB}")
	else()
		target_link_directories(essentials_unit_tests PUBLIC ${CMAKE_LIBRARY_PATH})
		add_library_for_linking(link_libraries_list gtest)
	endif()
else()
	add_library_for_linking(link_libraries_list libessentials)

	if( (NOT "${FMT_LIB_INCLUDE}" STREQUAL "") AND (NOT "${FMT_LIB}" STREQUAL "") 
	AND (NOT "${SPDLOG_LIB_INCLUDE}" STREQUAL "") AND (NOT "${SPDLOG_LIB}" STREQUAL "") 
	AND (NOT "${GTEST_LIB_INCLUDE}" STREQUAL "") AND (NOT "${GTEST_LIB}" STREQUAL ""))
		add_library_for_linking(link_libraries_list "${FMT_LIB}")
		add_library_for_linking(link_libraries_list "${SPDLOG_LIB}")
		add_library_for_linking(link_libraries_list "${GTEST_LIB}")
	else()
		target_link_directories(essentials_unit_tests PUBLIC ${CMAKE_LIBRARY_PATH})
		add_library_for_linking(link_libraries_list gtest)
		find_package(Threads REQUIRED)
		add_library_for_linking(link_libraries_list Threads::Threads)
	endif()
endif()


include_directories("./../essentials/include")
if( (NOT "${FMT_LIB_INCLUDE}" STREQUAL "") AND (NOT "${FMT_LIB}" STREQUAL "")
AND (NOT "${SPDLOG_LIB_INCLUDE}" STREQUAL "") AND (NOT "${SPDLOG_LIB}" STREQUAL "")
AND (NOT "${GTEST_LIB_INCLUDE}" STREQUAL "") AND (NOT "${GTEST_LIB}" STREQUAL "") )
	include_directories("${FMT_LIB_INCLUDE}")
	include_directories("${SPDLOG_LIB_INCLUDE}")
	include_directories("${GTEST_LIB_INCLUDE}")
else()
	include_directories("${CMAKE_INCLUDE_PATH}")
	target_link_directories(essentials_unit_tests PUBLIC ${CMAKE_LIBRARY_PATH})
endif()


TARGET_LINK_LIBRARIES(essentials_unit_tests ${link_libraries_list})

ENABLE_TESTING()
ADD_TEST(essentials_unit_tests AUTO)

install(TARGETS essentials_unit_tests DESTINATION bin)