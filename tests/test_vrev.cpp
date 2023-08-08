#include "test_util.hpp"

TEST(vrev16, u8)
{
    uint8x8_t src1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    uint8x8_t actual = vrev16_u8(src1);
    uint8x8_t expected = { 2, 1, 4, 3, 6, 5, 8, 7 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vrev32, u8)
{
    uint8x8_t src1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    uint8x8_t actual = vrev32_u8(src1);
    uint8x8_t expected = { 4, 3, 2, 1, 8, 7, 6, 5 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vrev64, u8)
{
    uint8x8_t src1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    uint8x8_t actual = vrev64_u8(src1);
    uint8x8_t expected = { 8, 7, 6, 5, 4, 3, 2, 1 };
    EXPECT_TRUE(almostEqual(expected, actual));
}