cmake_minimum_required(VERSION 3.20)
project(projektKoncowy)
include_directories(includeKlasy)
set(CMAKE_CXX_STANDARD 14)

add_executable(projektKoncowy main.cpp includeKlasy/Pojazd.cpp includeKlasy/Stacja.cpp includeKlasy/Stacja.h includeKlasy/Czas.cpp includeKlasy/Czas.h)
