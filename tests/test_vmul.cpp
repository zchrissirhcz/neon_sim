#include "test_util.hpp"

TEST(vmulq, f32)
{
    float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v2 = { 1.0, 1.0, 1.0, 1.0 };
    float32x4_t actual = vmulq_f32(v1, v2);
    float32x4_t expected = { 1.0, 2.0, 3.0, 4.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vmulq_n, f32)
{
    float32x4_t v = { 1.0, 2.0, 3.0, 4.0 };
    float32_t s = 3.0;
    float32x4_t actual = vmulq_n_f32(v, s);
    float32x4_t expected = { 3.0, 6.0, 9.0, 12.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vmul, s8)
{
    int8x8_t v1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int8x8_t v2 = { 2, 100, -10, -100, 2, 3, 4, 5 };
    int8x8_t actual = vmul_s8(v1, v2);
    int8x8_t expected = { 2, -56, -30, 112, 10, 18, 28, 40 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(mul, vmul_n_s16)
{
    int16x4_t v1 = { 1, 2, 3, 4 };
    int16_t s = 2;
    int16x4_t actual = vmul_n_s16(v1, s);
    int16x4_t expected = { 2, 4, 6, 8 };
    EXPECT_TRUE(almostEqual(expected, actual));
}