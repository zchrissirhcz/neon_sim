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


#--- OpenCV
set(A_VERSION "4.5.5")
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
  set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/windows/${A_VERSION}")
elseif(ANDROID)
  set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/android-arm64/${A_VERSION}/sdk/native/jni")
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  message("not supported platform(${CVPKG_TARGET_PLATFORM}) for package OpenCV")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(OpenCV_DIR "${ARTIFACTS_DIR}/opencv/linux-x64/${A_VERSION}/lib/cmake/opencv4")
endif()

message(STATUS ">>> OpenCV_DIR: ${OpenCV_DIR}")
find_package(OpenCV REQUIRED)



#--- ncnn
if(CMAKE_SYSTEM_NAME MATCHES "Windows")
  set(ncnn_DIR "D:/dev/ncnn/build/vs2019-x64/install/lib/cmake/ncnn")
elseif(ANDROID)
  #set(ncnn_DIR "D:/dev/ncnn/build/android-arm64/install/lib/cmake/ncnn")
  #set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/20211208/android-armv8/lib/cmake/ncnn")
  set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/20220216/android-arm64/lib/cmake/ncnn")
elseif(CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(ncnn_DIR "${ARTIFACTS_DIR}/ncnn/20220216/linux-x64/lib/cmake/ncnn")
else()
  message(WARNING "ncnn_DIR not set yet")
endif()
message(STATUS ">>> ncnn_DIR: ${ncnn_DIR}")
find_package(ncnn REQUIRED)