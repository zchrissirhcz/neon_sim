

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
#find_package(ncnn REQUIRED)

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

#include("${libpng_install_dir}/lib/libpng/libpng16.cmake")
# set_target_properties(png
#   PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${libpng_install_dir}/include/libpng16
# )
# set_target_properties(png_static
#   PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${libpng_install_dir}/include/libpng16
# )

#find_package(libpng16 REQUIRED)


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
neon_sim_add_test(and)
neon_sim_add_test(vget)