#!/bin/bash

BUILD_DIR=android-arm64
DST_DIR=/data/local/tmp

testbed()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=testbed

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_ex1()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex1

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_ex2()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex2

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
    adb pull /data/local/tmp/out.png ./
}


#testbed
#test_ex1
test_ex2