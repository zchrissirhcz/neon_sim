#include "test_util.hpp"

TEST(vmovq_n, f32)
{
    float32x4_t actual = vmovq_n_f32(1.5);
    float32x4_t expected = { 1.5, 1.5, 1.5, 1.5 };
    EXPECT_TRUE(almostEqual(expected, actual));
}