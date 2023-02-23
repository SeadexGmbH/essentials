cmake_minimum_required(VERSION 3.0)

project(essentials)

set(CMAKE_VERBOSE_MAKEFILE, 1)

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

file(GLOB essentials_SRC "include/essentials/*.hpp"
"include/essentials/compatibility/*.hpp"
"include/essentials/enum/*.hpp"
"include/essentials/execution/*.hpp"
"include/essentials/log/*.hpp"
"include/essentials/preprocessor/*.hpp"
"source/*.cpp")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(./../CMakeHelpers/addSpecificFlags.cmake)
include(./../CMakeHelpers/addSeadexOptions.cmake)

include_directories("./include")

option("ESS_USE_NULL_LOGGER" "If you don't want a log to be used, define this macro.")	
if( "${ESS_USE_NULL_LOGGER}" )
	set(extra_flags "${extra_flags} -D \"ESS_USE_NULL_LOGGER\"")
	message(STATUS "[lib essentials] ESS_USE_NULL_LOGGER is defined.")	
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	add_library(libessentials ${LINK_TYPE} ${essentials_SRC})
	if( NOT "${FMT_LIB_INCLUDE}" STREQUAL "" AND NOT "${FMT_LIB}" STREQUAL "" AND NOT "${SPDLOG_LIB_INCLUDE}" STREQUAL "" AND NOT "${SPDLOG_LIB}" STREQUAL "")
		include_directories("${FMT_LIB_INCLUDE}")
		include_directories("${SPDLOG_LIB_INCLUDE}")
		TARGET_LINK_LIBRARIES(libessentials ${FMT_LIB})
		TARGET_LINK_LIBRARIES(libessentials ${SPDLOG_LIB})
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D \"SPDLOG_FMT_EXTERNAL\"")
		message(STATUS "[lib essentials] libfmt or spdlog paths provided by user.")
	else()
		include_directories("${CMAKE_INCLUDE_PATH}")
		message(STATUS "[lib essentials] No libfmt or spdlog paths provided by user. Include Conan libraries headers.")
	endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	add_library(essentials STATIC ${essentials_SRC})
	if( NOT "${FMT_LIB_INCLUDE}" STREQUAL "" AND NOT "${FMT_LIB}" STREQUAL "" AND NOT "${SPDLOG_LIB_INCLUDE}" STREQUAL "" AND NOT "${SPDLOG_LIB}" STREQUAL "")
		include_directories("${FMT_LIB_INCLUDE}")
		include_directories("${SPDLOG_LIB_INCLUDE}")
		TARGET_LINK_LIBRARIES(essentials "${FMT_LIB}")
		TARGET_LINK_LIBRARIES(essentials "${SPDLOG_LIB}")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D \"SPDLOG_FMT_EXTERNAL\"")
		message(STATUS "[lib essentials] libfmt or spdlog paths provided by user.")
	else()
		include_directories("${CMAKE_INCLUDE_PATH}")
		message(STATUS "[lib essentials] No libfmt or spdlog paths provided by user. Include Conan libraries headers.")
	endif()
endif()

file(GLOB essentials_hpp "include/essentials/*.hpp")
file(GLOB essentials_compatibility_hpp "include/essentials/compatibility/*.hpp")
file(GLOB essentials_enum_hpp "include/essentials/enum/*.hpp")
file(GLOB essentials_execution_hpp "include/essentials/execution/*.hpp")
file(GLOB essentials_log_hpp "include/essentials/log/*.hpp")
file(GLOB essentials_preprocessor_hpp "include/essentials/preprocessor/*.hpp")

install(FILES ${essentials_hpp} DESTINATION include/essentials/)
install(FILES ${essentials_compatibility_hpp} DESTINATION include/essentials/compatibility/)
install(FILES ${essentials_enum_hpp} DESTINATION include/essentials/enum/)
install(FILES ${essentials_execution_hpp} DESTINATION include/essentials/execution/)
install(FILES ${essentials_log_hpp} DESTINATION include/essentials/log/)

install(FILES ${essentials_preprocessor_hpp} DESTINATION include/essentials/preprocessor/)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	install(TARGETS libessentials DESTINATION lib)
	set_target_properties(libessentials PROPERTIES PREFIX "")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	install(TARGETS essentials DESTINATION lib)
	set_target_properties(essentials PROPERTIES PREFIX "")
endif()
