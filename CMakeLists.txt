cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

configure_file(
    ${CMAKE_SOURCE_DIR}/assets/arial.ttf
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets/arial.ttf
    COPYONLY
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_subdirectory(src)