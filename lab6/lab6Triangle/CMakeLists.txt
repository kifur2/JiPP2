cmake_minimum_required(VERSION 3.20)
project(lab6Triangle)
include_directories(../lab6Node/include)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab6Triangle main.cpp Triangle.cpp ../lab6Node/src/Node.cpp)
