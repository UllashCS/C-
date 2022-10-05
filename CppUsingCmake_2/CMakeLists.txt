cmake_minimum_required(VERSION 3.8)
set(This SampleApplication)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    SampleApplication.hpp
)

set(Sources
    SampleApplication.cpp
)

add_executable(${This} ${Sources} ${Headers})
