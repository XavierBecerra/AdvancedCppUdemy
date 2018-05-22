
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.1)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId})
add_executable(${ProjectId} src/abstract.cpp)

file(GLOB project_sources src/race/*.cpp)
file(GLOB project_headers src/race/*.h src/race/*.hpp)

add_executable(race ${project_sources} ${project_headers})