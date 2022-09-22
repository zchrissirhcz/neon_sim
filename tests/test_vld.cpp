#include "test_util.hpp"

TEST(vld1q, f32)
{
    float values[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    float32x4_t actual = vld1q_f32(values);
    float32x4_t expected = { 1.0, 2.0, 3.0, 4.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vld1q_dup, f32)
{
    float val = 3.0;
    float32x4_t expected = vld1q_dup_f32(&val);
    float32x4_t actual = { 3.0, 3.0, 3.0, 3.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}