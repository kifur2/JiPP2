cmake_minimum_required(VERSION 3.20)
project(notesy)

set(CMAKE_CXX_STANDARD 14)

add_executable(notesy main.cpp Notes.cpp Notes.h)
