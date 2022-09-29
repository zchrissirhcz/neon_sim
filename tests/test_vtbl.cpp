#include "test_util.hpp"

TEST(vtbl1, u8)
{
    uint8x8_t src1 = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8x8_t src2 = {0, 0, 1, 1, 2, 2, 7, 8};
    uint8x8_t actual = vtbl1_u8(src1,src2);
    uint8x8_t expected = {1, 1, 2, 2, 3, 3, 8, 0};
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vtbl2, u8)
{
    uint8x8_t v0 = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8x8_t v1 = {9, 10, 11, 12, 13, 14, 15, 16};
    uint8x8x2_t src;
    src.val[0] = v0;
    src.val[1] = v1;
    uint8x8_t src2 = {0, 0, 1, 1, 2, 2, 8, 10};
    uint8x8_t actual = vtbl2_u8(src, src2);
    uint8x8_t expected = {1, 1, 2, 2, 3, 3, 9, 11};
    EXPECT_TRUE(almostEqual(expected, actual));
}