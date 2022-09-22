macro(neon_sim_add_test name)
  add_executable(${name} ${CMAKE_CURRENT_SOURCE_DIR}/${name}.cpp)
  set(dep_libs ${ARGN} GTest::gtest GTest::gtest_main)
  if(NOT (CMAKE_SYSTEM_PROCESSOR MATCHES "^(arm|Arm|ARM|aarch64|AAarch64|AARCH64)"))
    list(APPEND dep_libs neon_sim)
  endif()
  if(ANDROID)
    list(APPEND dep_libs log)
  endif()

  target_link_libraries(${name} PRIVATE ${dep_libs})
  target_include_directories(${name} PUBLIC ${CMAKE_SOURCE_DIR}/src)
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
neon_sim_add_test(test_vtbl)
neon_sim_add_test(test_vrev)
neon_sim_add_test(test_vtrn)
neon_sim_add_test(test_vzip)