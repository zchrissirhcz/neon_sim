#include "test_util.hpp"

TEST(vmaxq, f32)
{
    float32x4_t v0 = { 5.0, 2.0, 3.0, 4.0 };
    float32x4_t v1 = { 1.0, 6.0, 7.0, 8.0 };
    float32x4_t actual = vmaxq_f32(v0, v1);
    float32x4_t expected = { 5.0, 6.0, 7.0, 8.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vpmax, f32)
{
    float32x4_t v0 = { 1.0, 2.0, 3.0, 4.0 };
    float32x2_t maxOfHalfs = vpmax_f32(vget_low_f32(v0), vget_high_f32(v0));
    float32x2_t maxOfMaxOfHalfs = vpmax_f32(maxOfHalfs, maxOfHalfs);
    float actual = vget_lane_f32(maxOfMaxOfHalfs, 0);
    float expected = 4.0;
    EXPECT_EQ(expected, actual);
}

TEST(vminq, f32)
{
    float32x4_t v0 = { 5.0, 2.0, 3.0, 4.0 };
    float32x4_t v1 = { 1.0, 6.0, 7.0, 8.0 };
    float32x4_t actual = vminq_f32(v0, v1);
    float32x4_t expected = { 1.0, 2.0, 3.0, 4.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vpmin, f32)
{
    float32x4_t v0 = { 1.0, 2.0, 3.0, 4.0 };
    float32x2_t minOfHalfs = vpmin_f32(vget_low_f32(v0), vget_high_f32(v0));
    float32x2_t minOfMinOfHalfs = vpmin_f32(minOfHalfs, minOfHalfs);
    float expected = vget_lane_f32(minOfMinOfHalfs, 0);
    float actual = 1.0;
    EXPECT_EQ(expected, actual);
}