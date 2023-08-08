#include "test_util.hpp"

TEST(vaddl, u8)
{
    uint8x8_t v1 = { 240, 241, 242, 243, 244, 245, 246, 247 };
    uint8x8_t v2 = { 100, 100, 100, 100, 100, 100, 100, 100 };
    uint16x8_t expected = { 340, 341, 342, 343, 344, 345, 346, 347 };
    uint16x8_t actual = vaddl_u8(v1, v2);
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vaddl_high, s8)
{
    int8x16_t v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 100, 101, 102, 103, 104, 105, 106, 107 };
    int8x16_t v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 100, 100, 100, 100, 100, 100, 100, 100 };
    int16x8_t expected = { 200, 201, 202, 203, 204, 205, 206, 207 };
    int16x8_t actual = vaddl_high_s8(v1, v2);
    EXPECT_TRUE(almostEqual(expected, actual));
}