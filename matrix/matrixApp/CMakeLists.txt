cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD  17)

include_directories(../matrixLib/include)

add_executable(matrixLibApp main.cpp)

target_link_libraries(matrixLibApp matrixLibLib)
