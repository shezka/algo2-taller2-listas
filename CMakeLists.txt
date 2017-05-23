cmake_minimum_required(VERSION 3.6)
project(Taller_iteradores)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Dicc.h
    lista.h
    test_dicc.cpp
    tests.cpp)


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Taller_iteradores ${SOURCE_FILES})
add_executable(runTests tests.cpp lista.h)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)