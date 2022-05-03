#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

#include "gtest/gtest.h"

TEST(save, int8x8)
{
    int8x8_t vd = {1, 3, 5, 7, 2, 4, 6, 8};
    int8_t ptr[8];
    vst1_s8(ptr, vd);
    printf("Done\n");
}