#include <stdio.h>
#include <stdlib.h>

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

#include <math.h>

//---------------------------------------------
//
//
// 使用NEON实现向量加法 a + b = c
//
//
//---------------------------------------------
int main()
{
    // 定义a, b, c
    unsigned char a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    unsigned char b[8] = {8, 9, 10, 11, 12, 13, 14, 15};
    unsigned char c[8];
    

    uint8x8_t rega, regb, regc; //定义3个8x8bit无符号整型的 NEON 寄存器

    // 加载 a, b 到寄存器
    rega = vld1_u8(&a[0]);
    regb = vld1_u8(&b[0]);

    std::cout << rega << std::endl;

    regc = vadd_u8(rega, regb); // 做加法

    std::cout << regc << std::endl;

    vst1_u8(&c[0], regc);  // 回写到c中

    // 测试
    for(int i = 0 ; i < 8 ; i++)
    {
        printf("%d 	",c[i] );
    }
    printf("\n");
}