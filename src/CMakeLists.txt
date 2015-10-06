cmake_minimum_required(VERSION 2.8.11)
project(htn-decision)

set(CMAKE_CXX_FLAGS --std=c++11 ${CMAKE_CXX_FLAGS})

add_library(decision UtilitySystem.cpp
                     Options.cpp)

add_executable(decision-tester main.cpp)
target_link_libraries(decision-tester decision)
