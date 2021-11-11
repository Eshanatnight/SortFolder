cmake_minimum_required(VERSION 3.0.0)
project("Folder_Sorter")

set( CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_subdirectory("src/CPP/include/Directory Handler")

add_executable( Folder_Sorter
    src/CPP/main.cpp
)

target_link_libraries( Folder_Sorter
    PRIVATE
    directory_handler
)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
