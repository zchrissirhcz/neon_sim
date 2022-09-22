#include "gtest/gtest.h"

#include <cmath>

#define NEON_SIM_IMPLEMENTATION

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif // __ARM_NEON


bool almostEqual(const uint8x8_t& expected, const uint8x8_t& actual, double eps=0)
{
    for (int i = 0; i < 8; i++)
    {
        const double diff = std::fabs((double)expected[i] - (double)actual[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual[i] << ") != expected[" << i << "] (" << (int)expected[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

TEST(vext, u8)
{
    printf("Hello\n");
    uint8x8_t src1 = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8x8_t src2 = {9, 10, 11, 12, 13, 14, 15, 16};
    uint8x8_t expected = {4, 5, 6, 7, 8, 9, 10, 11};
    uint8x8_t actual = vext_u8(src1, src2, 3);
    EXPECT_TRUE(almostEqual(expected, actual));
}