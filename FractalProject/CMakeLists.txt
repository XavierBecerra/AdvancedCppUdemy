set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 14)
cmake_minimum_required(VERSION 3.1)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})

project(${ProjectId})

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(Qt5Gui "/usr/lib/x86_64-linux-gnu/cmake/Qt5Gui")
set(Qt5Core "/usr/lib/x86_64-linux-gnu/cmake/Qt5Core")
set(Qt5Widgets_DIR "/usr/lib/x86_64-linux-gnu/cmake/Qt5Widgets")
#message(STATUS "Qt5Widgets_DIR : ${Qt5Widgets_DIR}")

# Find the QtWidgets library
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

#get_target_property(QtCore_location Qt5::Core LOCATION)

set(CMAKE_CXX_FLAGS "-Wall")

file(GLOB project_sources src/*.cpp)
file(GLOB project_headers src/*.h src/*.hpp)

add_executable(${ProjectId} ${project_sources} ${project_headers})

# Use the Widgets module from Qt 5.
target_link_libraries(${ProjectId} Qt5::Widgets)
target_link_libraries(${ProjectId} Qt5::Core)
target_link_libraries(${ProjectId} Qt5::Gui)