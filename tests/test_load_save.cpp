#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

#include "gtest/gtest.h"

TEST(Save_D_Reg, int8x8)
{
    int8x8_t vd = {-128, -3, -5, 7, 2, 4, 6, 127};
    int8_t ptr[8];
    vst1_s8(ptr, vd);
    printf("Done\n");
}

TEST(Save_D_Reg, uint8x8)
{
    uint8x8_t vd = {1, 0, 3, 5, 7, 2, 6, 255};
    uint8_t ptr[8];
    vst1_u8(ptr, vd);
    printf("Done\n");
}

TEST(Save_Q_Reg, int8x16)
{
    int8x16_t vd = {-128, -3, -5, 7, 2, 4, 6, 127, -128, -3, -5, 7, 2, 4, 6, 127};
    int8_t ptr[16];
    vst1q_s8(ptr, vd);
    printf("Done\n");
}

TEST(Save_Q_Reg, uint8x16)
{
    uint8x16_t vd = {1, 0, 3, 5, 7, 2, 6, 255, 1, 0, 3, 5, 7, 2, 6, 255};
    uint8_t ptr[16];
    vst1q_u8(ptr, vd);
    printf("Done\n");
}
