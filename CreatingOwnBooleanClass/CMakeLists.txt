cmake_minimum_required(VERSION 3.8)
set(This booleanClass)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    boolean.hpp
)

set(Sources
    boolean.cpp
)

add_executable(${This} ${Sources} ${Headers})
