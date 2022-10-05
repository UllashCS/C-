cmake_minimum_required(VERSION 3.8)
set(This Application)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    MathOps.hpp
    Utils.hpp
    MathOpsC.hpp
    UtilsC.hpp
    LogicOps.hpp
)
set(Sources
    Application.cpp
    MathOps.cpp
    Utils.cpp
    MathOpsC.cpp
    UtilsC.cpp
    LogicOps.cpp
)

add_executable(${This} ${Sources} ${Headers})
