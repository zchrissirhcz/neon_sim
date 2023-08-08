#include "test_util.hpp"

TEST(vst1q, f32)
{
    float32x4_t v = { 1.0, 2.0, 3.0, 4.0 };
    std::vector<float> actual = { 0, 0, 0, 0, 0 };
    vst1q_f32(actual.data(), v);
    std::vector<float> expected = { 1.0, 2.0, 3.0, 4.0, 0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}

//- store lane of array of vectors: **vst4q_lane_f16** or **vst4q_lane_f32** or **vst4q_lane_f64** (change to **vst1...** / **vst2...** / **vst3...** for other array lengths);
TEST(vst4q_lane, f32)
{
    float32x4_t v0 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v1 = { 5.0, 6.0, 7.0, 8.0 };
    float32x4_t v2 = { 9.0, 10.0, 11.0, 12.0 };
    float32x4_t v3 = { 13.0, 14.0, 15.0, 16.0 };
    float32x4x4_t u = { v0, v1, v2, v3 };
    std::vector<float> actual(4);
    vst4q_lane_f32(actual.data(), u, 0);
    std::vector<float> expected = { 1.0, 5.0, 9.0, 13.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}