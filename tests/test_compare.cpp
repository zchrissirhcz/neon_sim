#include "test_util.hpp"

TEST(vcltq, f32)
{
    float32x4_t v1 = { 1.0, 0.0, 1.0, 0.0 };
    float32x4_t v2 = { 0.0, 1.0, 1.0, 0.0 };
    uint32x4_t mask = vcltq_f32(v1, v2);  // v1 < v2
    float32x4_t ones = vmovq_n_f32(10.0);
    float32x4_t twos = vmovq_n_f32(20.0); // the conditional branches: if condition is true returns 10.0, else returns 20.0
    float32x4_t actual = vbslq_f32(mask, ones, twos);  // will select first if mask 0, second if mask 1
    float32x4_t expected = { 20.0, 10.0, 20.0, 20.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}