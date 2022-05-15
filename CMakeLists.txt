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

add_library(neon_sim INTERFACE
  arm_neon_sim.hpp
)
target_compile_definitions(neon_sim INTERFACE -DNEON_SIM_IMPLEMENTATION)
target_include_directories(neon_sim INTERFACE ${CMAKE_SOURCE_DIR})

enable_testing()


macro(neon_sim_add_test name)
  add_executable(test_${name} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_${name}.cpp)
  set(dep_libs neon_sim ${ARGN} GTest::gtest GTest::gtest_main)
  if(ANDROID)
    list(APPEND dep_libs log)
  endif()
  target_link_libraries(test_${name} PRIVATE ${dep_libs})
  gtest_add_tests(TARGET test_${name})
endmacro()

neon_sim_add_test(add)
#neon_sim_add_test(ex2 png_static)
neon_sim_add_test(ex3)
neon_sim_add_test(ex4)
neon_sim_add_test(ex5)
neon_sim_add_test(ex6)
neon_sim_add_test(ex7)
neon_sim_add_test(ex8)
neon_sim_add_test(ex10 ${OpenCV_LIBS})
neon_sim_add_test(ex11)
neon_sim_add_test(rgb2gray ${OpenCV_LIBS})
neon_sim_add_test(rgb2bgr ${OpenCV_LIBS})
neon_sim_add_test(threshold ${OpenCV_LIBS})
#neon_sim_add_test(transpose ncnn)
neon_sim_add_test(NEON_2_SSE)
neon_sim_add_test(load_save)