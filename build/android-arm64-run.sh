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

test_ex3()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex3

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
    adb pull /data/local/tmp/out.png ./
}

test_ex4()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex4

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_ex5()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex5

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

#testbed
#test_ex1
#test_ex2
#test_ex3
#test_ex4
test_ex5