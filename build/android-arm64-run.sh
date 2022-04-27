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

test_ex6()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex6

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_ex7()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex7

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_ex8()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex8

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_ex9()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex9

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"

    adb pull /data/local/tmp/ex9_res1.png ./
    adb pull /data/local/tmp/ex9_res2.png ./
}

test_ex10()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex10

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_ex11()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_ex11

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_rgb2gray()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_rgb2gray

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
    
    adb pull /data/local/tmp/gray_cv.png ./
    adb pull /data/local/tmp/gray_my.png ./
}

test_rgb2bgr()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_rgb2bgr

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_threshold()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_threshold

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"

    adb pull /data/local/tmp/res_cv.png ./
    adb pull /data/local/tmp/res_my.png ./
}

test_transpose()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_transpose

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}

test_vld_lane()
{
    DST_DIR=/data/local/tmp
    EXE_FILE=test_vld_lane

    adb push $BUILD_DIR/$EXE_FILE $DST_DIR
    adb shell "cd $DST_DIR; chmod +x $DST_DIR/$EXE_FILE; ./$EXE_FILE"
}


#testbed
#test_ex1
#test_ex2
#test_ex3
#test_ex4
#test_ex5
#test_ex6
#test_ex7
#test_ex8
#test_ex9
#test_ex10
#test_ex11
#test_rgb2gray
#test_transpose
test_vld_lane
#test_rgb2bgr
#test_threshold