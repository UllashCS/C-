cmake_minimum_required(VERSION 3.8)

project(GTestExample C CXX)

set ( CMAKE_C_STANDARD 99 )
set ( CMAKE_CXX_STANDARD 11 )
set ( CMAKE_POSITION_INDEPENDENT_CODE ON )
set ( gtest_force_shared_crt ON CACHE BOOL "" FORCE )

if ( NOT MSVC )
    add_compile_options("--coverage")
	add_link_options("--coverage")
endif()

add_subdirectory(googletest)

enable_testing()

#if(CMAKE_COMPILER_IS_GNUCXX)
#endif()

set(UnderTestHeaders
    ../src/MathOps.hpp
    ../src/Utils.hpp
)
set(UnderTestSources
    ../src/MathOps.cpp
    ../src/Utils.cpp
)

add_library(UnderTest STATIC  ${UnderTestSources} ${UnderTestHeaders})

add_executable(ExampleTests ExampleTests.cpp)
if ( MSVC )
	target_link_libraries(ExampleTests PUBLIC
		gtest_main
		UnderTest
	)
else()
	target_link_libraries(ExampleTests PUBLIC
		gtest_main
		UnderTest
		gcov
	)
endif()

add_test(
    NAME ExampleTests
    COMMAND ExampleTests
)

set(Headers
    Mock_Test.hpp
)

set(Sources
    DiffTests.cpp
    Mock_Test.cpp
)

add_executable(DiffTests ${Headers} ${Sources})
target_link_libraries(DiffTests PUBLIC
    gtest_main
    gmock_main
    UnderTest
)

add_test(
    NAME DiffTests
    COMMAND DiffTests
)

add_library(UnderTestC STATIC  ../src/MathOpsC.cpp ../src/MathOpsC.hpp)

set (TestMathOpsCHeaders
    MockMathOpsC.hpp
)

set (TestMathOpsCSouces
    TestMathOpsC.cpp
    MockMathOpsC.cpp
)

add_executable(TestMathOpsC ${TestMathOpsCSouces} ${TestMathOpsCHeaders})
target_link_libraries(TestMathOpsC PUBLIC
    gtest_main
    gmock_main
    UnderTestC
)

add_test(
    NAME TestMathOpsC
    COMMAND TestMathOpsC
)

add_library(LogicOps STATIC  ../src/LogicOps.cpp ../src/LogicOps.hpp)

set (TestLogicOpsHeaders
    MockLogicOps.hpp
)

set (TestLogicOpsSouces
    TestLogicOps.cpp
    MockLogicOps.cpp
)

add_executable(TestLogicOps ${TestLogicOpsSouces} ${TestLogicOpsHeaders})
target_link_libraries(TestLogicOps PUBLIC
    gtest_main
    gmock_main
    LogicOps
)

add_test(
    NAME TestLogicOps
    COMMAND TestLogicOps
)
