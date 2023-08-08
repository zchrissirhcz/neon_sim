#include "test_util.hpp"

TEST(vaddq, f32)
{
    float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v2 = { 1.0, 1.0, 1.0, 1.0 };
    float32x4_t actual = vaddq_f32(v1, v2);
    float32x4_t expected = { 2.0, 3.0, 4.0, 5.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vadd, s8)
{
    {
        int8x8_t v1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
        int8x8_t v2 = { 1, 2, 3, 4, 5, 6, 7, 8 };
        int8x8_t expected = { 2, 4, 6, 8, 10, 12, 14, 16 };
        int8x8_t actual = vadd_s8(v1, v2);
        EXPECT_TRUE(almostEqual(expected, actual));
    }

    {
        // 对应位元素相加: ri = ai + bi
        // 对于 signed 类型， 例如s8, 超过127后， 要减去256 从而得到正确结果
        int8x8_t v1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
        int8x8_t v2 = { 10, 20, 30, 40, 50, 60, 70, 127 };
        int8x8_t actual = vadd_s8(v1, v2);
        int8x8_t expected = { 11, 22, 33, 44, 55, 66, 77, -121 };
        EXPECT_TRUE(almostEqual(expected, actual));
    }
}

TEST(vadd, s8_exceed)
{
    int8x8_t v1 = { 120, 121, 122, 123, 124, 125, 126, 127 };
    int8x8_t v2 = { 100, 100, 100, 100, 100, 100, 100, 100 };

    // 并不是 {220, 221, 222, 234, 224, 225, 226, 227}, 而是分别减去256
    int8x8_t expected = { -36, -35, -34, -33, -32, -31, -30, -29 };
    int8x8_t actual = vadd_s8(v1, v2);
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vadd, u8)
{
    uint8x8_t v1 = { 0, 1, 2, 3, 4, 5, 6, 7 };
    uint8x8_t v2 = { 8, 9, 10, 11, 12, 13, 14, 15 };
    uint8x8_t expected = { 8, 10, 12, 14, 16, 18, 20, 22 };
    uint8x8_t actual = vadd_u8(v1, v2);
    EXPECT_TRUE(almostEqual(expected, actual));
}