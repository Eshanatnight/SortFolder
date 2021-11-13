cmake_minimum_required(VERSION 3.0.0)

project("Folder_Sorter")

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

add_executable( Folder_Sorter
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/util)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/DirHandler)

add_subdirectory(src/DirHandler)
add_subdirectory(src/util)


target_link_libraries( ${PROJECT_NAME}
    DirHandler
    Util
)


set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
