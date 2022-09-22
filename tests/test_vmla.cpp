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