cmake_minimum_required( VERSION 3.0.0 )

add_library( Util
    utility.cpp
    utility.h
)
target_include_directories(DirectoryHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})