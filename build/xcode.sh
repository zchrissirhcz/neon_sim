#!/bin/bash

BUILD_DIR=xcode
mkdir -p $BUILD_DIR
cd $BUILD_DIR

cmake ../.. -DCMAKE_BUILD_TYPE=Debug -G "Xcode"
cmake --build . -j
cd ..

