#!/bin/bash

ANDROID_NDK=~/soft/android-ndk-r21e
TOOLCHAIN=$ANDROID_NDK/build/cmake/android.toolchain.cmake

BUILD_DIR=android-arm64
mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake -G Ninja \
    -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN \
    -DANDROID_ABI="arm64-v8a" \
    -DANDROID_PLATFORM=android-24 \
    -DCMAKE_BUILD_TYPE=Debug \
    ../..

#ninja
#cmake --build . --verbose
cmake --build .

cd ..
