## 1. 打印 neon 向量的函数， 是否需要传引用？
```c++
#include <arm_neon.h>
#include <stdio.h>
#include <iostream>

#include "arm_neon_helper.hpp"
#include "autotimer.hpp"

const int g_loop_count = 1;//00000;

#define CONST const
//#define AND & // get correct print
#define AND // get wrong print

void dump(
    CONST uint8x8_t AND d0, CONST uint8x8_t AND d1, CONST uint8x8_t AND d2, CONST uint8x8_t AND d3,
    CONST uint8x8_t AND d4, CONST uint8x8_t AND d5, CONST uint8x8_t AND d6, CONST uint8x8_t AND d7,
    CONST std::string& msg)
{
    std::cout << "\n=== " << msg << " ===" << std::endl;
    std::cout << d0 << std::endl;
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    std::cout << d4 << std::endl;
    std::cout << d5 << std::endl;
    std::cout << d6 << std::endl;
    std::cout << d7 << std::endl;
}

void transpose_carotene()
{
    uint8_t buf[16]; // bug: should be 64

    uint8x8_t vdst0 = {11, 12, 13, 14, 15, 16, 17, 18};
    uint8x8_t vdst1 = {21, 22, 23, 24, 25, 26, 27, 28};
    uint8x8_t vdst2 = {31, 32, 33, 34, 35, 36, 37, 38};
    uint8x8_t vdst3 = {41, 42, 43, 44, 45, 46, 47, 48};
    uint8x8_t vdst4 = {51, 52, 53, 54, 55, 56, 57, 58};
    uint8x8_t vdst5 = {61, 62, 63, 64, 65, 66, 67, 68};
    uint8x8_t vdst6 = {71, 72, 73, 74, 75, 76, 77, 78};
    uint8x8_t vdst7 = {81, 82, 83, 84, 85, 86, 87, 88};

    dump(vdst0, vdst1, vdst2, vdst3, vdst4, vdst5, vdst6, vdst7, "carotene, int");
    
    // == 8x8 matrix transpose ==
    {
        AutoTimer timer("carotene");
        uint8x8x2_t vdst10t = vtrn_u8(vdst0, vdst1);
        uint8x8x2_t vdst32t = vtrn_u8(vdst2, vdst3);
        uint8x8x2_t vdst54t = vtrn_u8(vdst4, vdst5);
        uint8x8x2_t vdst76t = vtrn_u8(vdst6, vdst7);

        uint8x16_t vd1d0 = vcombine_u8(vdst10t.val[0], vdst10t.val[1]);
        uint8x16_t vd3d2 = vcombine_u8(vdst32t.val[0], vdst32t.val[1]);
        uint8x16_t vd5d4 = vcombine_u8(vdst54t.val[0], vdst54t.val[1]);
        uint8x16_t vd7d6 = vcombine_u8(vdst76t.val[0], vdst76t.val[1]);

        uint16x8x2_t vq1q0t = vtrnq_u16((uint16x8_t)vd1d0, (uint16x8_t)vd3d2);
        uint16x8x2_t vq3q2t = vtrnq_u16((uint16x8_t)vd5d4, (uint16x8_t)vd7d6);

        uint32x4x2_t vq2q0t = vtrnq_u32((uint32x4_t)vq1q0t.val[0], (uint32x4_t)vq3q2t.val[0]);
        uint32x4x2_t vq3q1t = vtrnq_u32((uint32x4_t)vq1q0t.val[1], (uint32x4_t)vq3q2t.val[1]);

        vst1q_u8(buf +  0, (uint8x16_t)vq2q0t.val[0]);
        vst1q_u8(buf + 16, (uint8x16_t)vq3q1t.val[0]);
        vst1q_u8(buf + 32, (uint8x16_t)vq2q0t.val[1]);
        vst1q_u8(buf + 48, (uint8x16_t)vq3q1t.val[1]);
    }

    vdst0 = vld1_u8(buf);
    vdst1 = vld1_u8(buf + 8);
    vdst2 = vld1_u8(buf + 16);
    vdst3 = vld1_u8(buf + 24);
    vdst4 = vld1_u8(buf + 32);
    vdst5 = vld1_u8(buf + 40);
    vdst6 = vld1_u8(buf + 48);
    vdst7 = vld1_u8(buf + 56);
    dump(vdst0, vdst1, vdst2, vdst3, vdst4, vdst5, vdst6, vdst7, "carotene, end");
}


int main()
{
    transpose_carotene();

    return 0;
}
```

上述代码本质 bug 在于 `buf[16]` 内存空间不足， 从而导致在传拷贝来实现打印时， 结果不对：
```
=== carotene, int ===
11, 12, 13, 14, 15, 16, 17, 18
21, 22, 23, 24, 25, 26, 27, 28
31, 32, 33, 34, 35, 36, 37, 38
41, 42, 43, 44, 45, 46, 47, 48
51, 52, 53, 54, 55, 56, 57, 58
61, 62, 63, 64, 65, 66, 67, 68
71, 72, 73, 74, 75, 76, 77, 78
81, 82, 83, 84, 85, 86, 87, 88
carotene: took   0.002 ms

=== carotene, end ===
11, 21, 31, 41, 51, 61, 71, 81
12, 22, 32, 42, 52, 62, 72, 82
98, 117, 103, 103, 97, 98, 108, 101
0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0
0, 0, 0, 0, 0, 0, 0, 0
2, 8, 32, 128, 2, 8, 32, 128
```

难免遇到 `buf[16]` 这样的bug， 因此比较好的方法是把所有的 `ostream& operator` 重载实现的 neon 向量打印，  都修改为传引用。
效果： 即使是 `buf[16]` 的内存不足问题存在， 仍然可以打印出正确结果。

## 2. 向量寄存器数组类型的元素赋值
如下写法，在有些编译器上会报错（例如 aarch64-linux-gnu-gcc 9.4.0)
```c++
    uint8x8x2_t src;
    src.val[0] = uint8x8_t{1, 2, 3, 4, 5, 6, 7, 8};
    src.val[1] = uint8x8_t{9, 10, 11, 12, 13, 14, 15, 16};
```

> error: cannot convert ‘<brace-enclosed initializer list>’ to ‘uint8x8_t’ {aka ‘__vector(8) unsigned char’} in assignment

解决方法是改为如下两种之一：
```c++
    uint8x8_t v0 = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8x8_t v1 = {9, 10, 11, 12, 13, 14, 15, 16};
    uint8x8x2_t src;
    src.val[0] = v0;
    src.val[1] = v1;
```

```c++
    uint8x8x2_t src;
    src.val[0] = uint8x8_t{1, 2, 3, 4, 5, 6, 7, 8};
    src.val[1] = uint8x8_t{9, 10, 11, 12, 13, 14, 15, 16};
```