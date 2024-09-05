cmake_minimum_required(VERSION 3.29)
project(clase)

set(CMAKE_CXX_STANDARD 20)

add_executable(clase main.cpp
        utils/pilas.cpp
        "utils/pilas .h")
