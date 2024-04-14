cmake_minimum_required(VERSION 3.20)
project(neon_sim)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_library(neon_sim STATIC
  neon_sim.hpp
  neon_sim.cpp
)
target_include_directories(neon_sim PUBLIC .)

file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
add_executable(test_neon_sim ${TEST_SOURCES})
target_link_libraries(test_neon_sim PRIVATE neon_sim)