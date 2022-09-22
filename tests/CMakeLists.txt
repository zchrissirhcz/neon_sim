macro(neon_sim_add_test name)
  add_executable(${name} ${CMAKE_CURRENT_SOURCE_DIR}/${name}.cpp)
  set(dep_libs neon_sim ${ARGN} GTest::gtest GTest::gtest_main)
  if(ANDROID)
    list(APPEND dep_libs log)
  endif()
  target_link_libraries(${name} PRIVATE ${dep_libs})
  #gtest_add_tests(TARGET ${name})
  if((NOT ANDROID) AND CMAKE_SYSTEM_NAME MATCHES "Linux" AND CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64")
    gtest_add_tests(TARGET ${name}
      COMMAND ${CMAKE_COMMAND} -DTEST_EXECUTABLE=$<TARGET_FILE:${name}> -P ${CMAKE_SOURCE_DIR}/cmake/qemu_run_test.cmake
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
  else()
    gtest_add_tests(TARGET ${name}
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
  endif()
endmacro()

neon_sim_add_test(test_vext)