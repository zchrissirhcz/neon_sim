#include "test_util.hpp"

TEST(vmlaq, f32)
{
    float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v2 = { 2.0, 2.0, 2.0, 2.0 };
    float32x4_t v3 = { 3.0, 3.0, 3.0, 3.0 };
    float32x4_t actual = vmlaq_f32(v3, v1, v2);  // acc = v3 + v1 * v2
    float32x4_t expected = { 5.0, 7.0, 9.0, 11.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}


TEST(vmlaq_n, f32)
{
    float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v2 = { 1.0, 1.0, 1.0, 1.0 };
    float32_t s = 3.0;
    float32x4_t actual = vmlaq_n_f32(v1, v2, s);
    float32x4_t expected = { 4.0, 5.0, 6.0, 7.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}