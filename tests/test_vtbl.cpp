#include "test_util.hpp"

TEST(vtbl1, u8)
{
    uint8x8_t src1 = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8x8_t src2 = {0, 0, 1, 1, 2, 2, 7, 8};
    uint8x8_t actual = vtbl1_u8(src1,src2);
    uint8x8_t expected = {1, 1, 2, 2, 3, 3, 8, 0};
    EXPECT_TRUE(almostEqual(expected, actual));
}