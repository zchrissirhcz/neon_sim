#include "test_util.hpp"

TEST(sub, vsubhn)
{
    // vsubhn_type: sub, half narrow
    // r = vsubhn_type(a, b), a和b是宽类型，r是(a-b)右移n/2位后的结果（高n/2位）
    int16x8_t v1 = { 100, 200, 300, 400, 500, 600, 700, 800 };
    int16x8_t v2 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int8x8_t actual = vsubhn_s16(v1, v2);
    int8x8_t expected = { 0, 0, 1, 1, 1, 2, 2, 3 };
    EXPECT_TRUE(almostEqual(expected, actual));
}