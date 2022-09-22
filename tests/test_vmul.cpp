#include "test_util.hpp"

TEST(vmulq, f32)
{
    float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v2 = { 1.0, 1.0, 1.0, 1.0 };
    float32x4_t actual = vmulq_f32(v1, v2);
    float32x4_t expected = { 1.0, 2.0, 3.0, 4.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}