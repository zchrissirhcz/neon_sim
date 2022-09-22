add_library(neon_sim INTERFACE
  arm_neon_sim.hpp
)
target_compile_definitions(neon_sim INTERFACE -DNEON_SIM_IMPLEMENTATION)
target_include_directories(neon_sim INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})