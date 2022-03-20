cmake_minimum_required(VERSION 3.20)

project(hello)

set(CMAKE_CXX_STANDARD 11)

include("deps.cmake")

add_library(neon_sim INTERFACE
  arm_neon_sim.hpp
)

enable_testing()


macro(neon_sim_add_test name)
  add_executable(test_${name} ${CMAKE_CURRENT_SOURCE_DIR}/test_${name}.cpp)
  set(dep_libs neon_sim ${ARGN} GTest::gtest GTest::gtest_main)
  if(ANDROID)
    list(APPEND dep_libs log)
  endif()
  target_link_libraries(test_${name} PRIVATE ${dep_libs})
  gtest_add_tests(TARGET test_${name})
endmacro()

neon_sim_add_test(ex1)
neon_sim_add_test(ex2 png_static)
neon_sim_add_test(ex3)
neon_sim_add_test(ex4)
neon_sim_add_test(ex5)
neon_sim_add_test(ex6)
neon_sim_add_test(ex7)
neon_sim_add_test(ex8)
neon_sim_add_test(ex9 ${OpenCV_LIBS})
neon_sim_add_test(ex10 ${OpenCV_LIBS})
neon_sim_add_test(ex11)