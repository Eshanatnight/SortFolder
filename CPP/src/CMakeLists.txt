CMAKE_MINIMUM_REQUIRED (VERSION 3.0)    # Set the minimum required version of CMake.
project(SortFolder)                     # Set the name of the project.

set(CMAKE_CXX_STANDARD 20)              # Set the C++ standard to use.


add_executable(${PROJECT_NAME}          # Add the main.cpp file to the project.
        main.cpp
        )
add_subdirectory(DirHandler)            # Add the subdirectory where the Library is

target_link_libraries(${PROJECT_NAME}   # Give the Current Project Name then The Project Name of The Library
        DirectoryHandler
)