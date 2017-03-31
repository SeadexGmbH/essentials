cmake_minimum_required(VERSION 3.5)

project(essentials_unit_tests)

set(CMAKE_VERBOSE_MAKEFILE, 1)

set(HEADER_FILES "./../essentials/include/*.hpp" "./../essentials/include/compatibility/*.hpp")
file(GLOB essentials_unit_tests_SRC "./*.cpp" ${HEADER_FILES})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	if( "${CMAKE_CXX_FLAGS}" STREQUAL "-m64" )
		set(extra_flags "${extra_flags} -m64")
		message(STATUS "setting platform x64")
	else()
		set(extra_flags "${extra_flags} -m32")
		message(STATUS "setting platform x86")
	endif()
		
	if("${CPP_VERSION}" STREQUAL "03")
		set(extra_flags "${extra_flags} -std=c++03 -Wall -Wpedantic -g -Wno-unknown-pragmas -D \"SX_CPP03_BOOST\" -D \"SX_NO_VARIADIC_MACRO\"")
	else()
		set(extra_flags "${extra_flags} -std=c++14 -Wall -Wpedantic -g")
	endif()
	
	# essentials's preprocessor definitions	
	
	option("SX_NO_STD_MAKE_UNIQUE" "When the standard make_unique is not available (e.g. no C++14 support), you have to define this preprocessor definition. An essentials drop-in replacement template will be used instead then.")		
	if( "${SX_NO_STD_MAKE_UNIQUE}" )
		set(extra_flags "${extra_flags} -D \"SX_NO_STD_MAKE_UNIQUE\"")	
	endif()
	
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# Checks buffer security.
	set(extra_flags "${extra_flags} /GS")
	
	#Sets output warning level.
	set(extra_flags "${extra_flags} /W4")
	
	#Disable specific Warnings.
	set(extra_flags "${extra_flags} /wd\"4127\" /wd\"4250\"")
	
	#Defines constants and macros.
	set(extra_flags "${extra_flags} /D \"_CRT_SECURE_NO_WARNINGS\"")
	
	#Enables function-level linking.
	set(extra_flags "${extra_flags} /Gy")
	
	#Specifies standard behavior under /Ze.
	set(extra_flags "${extra_flags} /Zc:wchar_t /Zc:inline")
	
	#Disable minimal rebuild.
	set(extra_flags "${extra_flags} /Gm-")
	
	#Enables additional security features and warnings.
	set(extra_flags "${extra_flags} /sdl")
			
	#Specifies floating-point behavior.
	set(extra_flags "${extra_flags} /fp:precise")
		
	#Multibyte character sets macro.
	set(extra_flags "${extra_flags} /D \"_MBCS\"")
		
	#Enables you to provide internal compiler error (ICE) information directly to the Visual C++ team.
	set(extra_flags "${extra_flags} /errorReport:prompt")
	
	#Treats warnings as errors.
	set(extra_flags "${extra_flags} /WX")
	
	#Generates intrinsic functions.
	set(extra_flags "${extra_flags} /Oi")
	
	#Specifies the model of exception handling.
	set(extra_flags "${extra_flags} /EHsc")
	
	#Creates an object file.
	set(extra_flags "${extra_flags} /Fo")
	
	#Marks an executable as verified to be compatible with the Windows Data Execution Prevention feature.
	#set(extra_flags "${extra_flags} /NXCOMPAT")
	
# essentials's preprocessor definitions	
	option("SX_NO_STD_MAKE_UNIQUE" "When the standard make_unique is not available (e.g. no C++14 support), you have to define this preprocessor definition. An essentials drop-in replacement template will be used instead then.")		
	if( "${SX_NO_STD_MAKE_UNIQUE}" )
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"SX_NO_STD_MAKE_UNIQUE\"")	
	endif()
endif()

# for release
if( "${CMAKE_BUILD_TYPE}" STREQUAL "Release" )
	#Creates fast code.
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
	
	#Controls LINK optimizations.
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /OPT:REF /OPT:ICF")
	
# for debug
elseif( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug" )
	#Creates a program database (PDB) file.
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /PDB")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${extra_flags}")

add_executable(essentials_unit_tests ${essentials_unit_tests_SRC})
include_directories("./../essentials/include/compatibility" "./../essentials/include")

#using boost
find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")		
	link_directories("${Y_BOOST_LIB_PATH}")
	link_directories(${Boost_LIBRARY_DIRS})
	ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK) 
endif()


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")	
	target_link_libraries (essentials_unit_tests LINK_PUBLIC essentials pthread boost_system boost_thread boost_chrono ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})	
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	target_link_libraries (essentials_unit_tests LINK_PUBLIC essentials)
endif()


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	SET(Boost_USE_STATIC_LIBS ON)		
	SET(BOOST_ROOT "${Y_BOOST_LIB_INCLUDE}")		
	SET(Boost_INCLUDE_DIRS "${Y_BOOST_LIB_INCLUDE}")
	include_directories(${Boost_INCLUDE_DIRS})		
	target_link_libraries(essentials_unit_tests LINK_PUBLIC ${Boost_LIBRARIES})
endif()

install(TARGETS essentials_unit_tests DESTINATION bin)
