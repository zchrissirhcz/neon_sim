if(DEFINED ENV{ARTIFACTS_DIR})
  set(ARTIFACTS_DIR "$ENV{ARTIFACTS_DIR}")
else()
  message(WARNING "ARTIFACTS_DIR env var not defined, abort")
endif()

#--- GoogleTest
if(ANDROID)
  set(GTest_DIR "${ARTIFACTS_DIR}/googletest/1.11.0/android-arm64/lib/cmake/GTest" CACHE PATH "Directory that contains GTestConfig.cmake")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(GTest_DIR "${ARTIFACTS_DIR}/googletest/1.11.0/linux-x64/lib/cmake/GTest" CACHE PATH "Directory that contains GTestConfig.cmake")
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
  set(GTest_DIR "${ARTIFACTS_DIR}/googletest/1.11.0/windows/vs2019-x64/lib/cmake/GTest" CACHE PATH "Directory that contains GTestConfig.cmake")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  set(GTest_DIR "${ARTIFACTS_DIR}/googletest/1.11.0/mac-x64/lib/cmake/GTest" CACHE PATH "Directory that contains GTestConfig.cmake")
else()
  message(WARNING "GTest_DIR not set yet")
endif()
message(STATUS ">>> GTest_DIR is: ${GTest_DIR}")
find_package(GTest REQUIRED)


#--- libpng
if(ANDROID)
  #set(png_DIR "${ARTIFACTS_DIR}/libpng/1.6.38-dev/linux-x64/lib/libpng")
  # set(png_lib "${ARTIFACTS_DIR}/libpng/1.6.38-dev/android-arm64/lib/libpng.a")
  # set(png_include_dir "${ARTIFACTS_DIR}/libpng/1.6.38-dev/android-arm64/include")
  set(libpng_install_dir "/home/zz/artifacts/libpng/1.6.38-dev/android-arm64")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
  # set(png_lib "${ARTIFACTS_DIR}/libpng/1.6.38-dev/linux-x64/lib/libpng16.a")
  # set(png_include_dir "${ARTIFACTS_DIR}/libpng/1.6.38-dev/linux-x64/include")
  set(libpng_install_dir "/home/zz/artifacts/libpng/1.6.38-dev/linux-x64")
endif()

include("${libpng_install_dir}/lib/libpng/libpng16.cmake")
set_target_properties(png
  PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${libpng_install_dir}/include/libpng16
)
set_target_properties(png_static
  PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${libpng_install_dir}/include/libpng16
)

#find_package(libpng16 REQUIRED)
