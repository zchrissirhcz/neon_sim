#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

TEST(vget, low_s8)
{
    int8x16_t v1 = {
        1, 2, 3, 4, 5, 6, 7, 8,
        11, 12, 13, 14, 15, 16, 17, 18
    };
    int8x8_t v2 = vget_low_s8(v1);

    int8_t res[8];
    vst1_s8(res, v2);

    for (int i = 0; i < 8; i++)
    {
        printf("%d, ", res[i]);
    }
    printf("\n");
}