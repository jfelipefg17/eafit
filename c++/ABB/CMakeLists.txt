cmake_minimum_required(VERSION 3.28)
project(ABB)

set(CMAKE_CXX_STANDARD 17)

add_executable(ABB main.cpp
        bst.cpp
        bst.h
        persona.h
        persona.cpp
        node.cpp
)
