cmake_minimum_required( VERSION 3.0.0 )

add_library(DirectoryHandler
	directory_handler.cpp
	directory_handler.h
)

target_include_directories(DirectoryHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})