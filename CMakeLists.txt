cmake_minimum_required(VERSION 3.20)

project(neon_sim)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include("cmake/output_dir.cmake")
include("cmake/deps.cmake")
include("cmake/asan.cmake")
include("cmake/debug_symbols.cmake")

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)