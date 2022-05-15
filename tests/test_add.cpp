#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

TEST(vadd, u8)
{
    uint8_t a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    uint8_t b[8] = {8, 9, 10, 11, 12, 13, 14, 15};
    uint8_t c[8];

    uint8_t expected_c[8];
    for (int i = 0; i < 8; i++)
    {
        expected_c[i] = a[i] + b[i];
    }
    
    uint8x8_t va, vb, vc;
    va = vld1_u8(a);
    vb = vld1_u8(b);
    vc = vadd_u8(va, vb);
    vst1_u8(c, vc);

    for(int i = 0 ; i < 8 ; i++)
    {
        EXPECT_EQ(expected_c[i], c[i]);
    }
}