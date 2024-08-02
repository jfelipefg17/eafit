cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        pointers.cpp
        pointers.h
        insercion.cpp
        insercion.h
        seleccion.cpp
        seleccion.h
        burbuja.cpp
        burbuja.h
        evenodd.cpp
        evenodd.h
        mergeSort.cpp
        mergeSort.h
        quickSort.cpp
        quickSort.h)
