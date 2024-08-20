cmake_minimum_required(VERSION 3.28)
project(dataDummy)

set(CMAKE_CXX_STANDARD 17)

add_executable(dataDummy
        file.h
        file.cpp
        test.cpp
        person.h
        person.cpp
)
