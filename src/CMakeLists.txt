cmake_minimum_required(VERSION 3.10)
project(doodlebugs)

set(CMAKE_CXX_STANDARD 14)

add_executable(doodlebugs game.cpp organism.cpp doodlebugs.cpp)