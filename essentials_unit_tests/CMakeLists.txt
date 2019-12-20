cmake_minimum_required(VERSION 3.0)

project(essentials_unit_tests)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

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

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library_for_linking(link_libraries_list essentials)
else()
	add_library_for_linking(link_libraries_list libessentials)
endif()

message(STATUS "essentials_unit_tests linking to libraries: ${link_libraries_list}")
message(STATUS "essentials_unit_tests linking to conanlibs: ${CONAN_LIBS}")

ADD_EXECUTABLE(essentials_unit_tests ${essentials_unit_tests_SRC})

include_directories("./../essentials/include")

TARGET_LINK_LIBRARIES(essentials_unit_tests ${link_libraries_list} ${CONAN_LIBS})

ENABLE_TESTING()
ADD_TEST(essentials_unit_tests AUTO)

install(TARGETS essentials_unit_tests DESTINATION bin)