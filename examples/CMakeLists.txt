if(EXISTS "${PROJECT_SOURCE_DIR}/examples/context_example")
	message(STATUS "Build context example.")
	add_subdirectory(context_example)
endif()

if(EXISTS "${PROJECT_SOURCE_DIR}/examples/logger_example")
	message(STATUS "Build logger example.")
	add_subdirectory(logger_example)
endif()

if(EXISTS "${PROJECT_SOURCE_DIR}/examples/enum_example")
	message(STATUS "Build enum example.")
	add_subdirectory(enum_example)
endif()
