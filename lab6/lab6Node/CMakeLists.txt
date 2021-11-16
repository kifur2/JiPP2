cmake_minimum_required(VERSION 3.12)
project(lab6Node)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(lab6Node src/main.cpp src/Node.cpp)