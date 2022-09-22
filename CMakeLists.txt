cmake_minimum_required(VERSION 3.20)

project(neon_sim)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("cmake/deps.cmake")
include("cmake/sleek.cmake")

sleek_add_debug_symbol()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  sleek_add_flags("-fstandalone-debug")
endif()

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)