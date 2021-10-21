cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
project(firstLib)
# Dodajemy ścieżkę, w ktorej mają być wyszukiwane pliki nagłwkowe
include_directories(include)

# Dodajemy pliki, które mają byc kompilowane
# STATIC - biblioteka będzie statyczna
add_library(firstLibLib STATIC src/lib.cpp)