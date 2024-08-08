cmake_minimum_required(VERSION 3.28)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test src/main.cpp
        src/algortim.cpp
        src/algortim.h
        src/soth.h
        src/libreriaAlgoritmos.h)
