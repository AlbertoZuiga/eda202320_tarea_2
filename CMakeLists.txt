cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set the project name

project(laberinto
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_subdirectory(src)
#add_subdirectory(tests)

add_executable(laberinto test/tarea_2.cpp src/maze.cpp src/pair.cpp src/node.cpp src/queue.cpp src/stack.cpp)
target_include_directories(laberinto PUBLIC ${PROJECT_SOURCE_DIR}/include)


# add the executable