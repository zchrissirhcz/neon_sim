cmake_minimum_required(VERSION 3.20)

project(hello)

add_executable(testbed main.cpp)

if (ANDROID)
    target_link_libraries(testbed log)
endif()