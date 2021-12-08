CMAKE_MINIMUM_REQUIRED (VERSION 3.0)    # Set the minimum required version of CMake.

project(DirectoryHandler)               # Set the name of the project.

set(CMAKE_CXX_STANDARD 20)				# Set the CMAKE CXX STANDARD

add_library( ${PROJECT_NAME}
	directory_handler.cpp
	directory_handler.h
	)