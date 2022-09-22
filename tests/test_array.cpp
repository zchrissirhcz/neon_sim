#include "test_util.hpp"

TEST(array, lane)
{
    float32x4_t v0 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v1 = { 5.0, 6.0, 7.0, 8.0 };
    float32x4_t v2 = { 9.0, 10.0, 11.0, 12.0 };
    float32x4_t v3 = { 13.0, 14.0, 15.0, 16.0 };
    float32x4x4_t ary = { v0, v1, v2, v3 };
    float32x4_t actual = ary.val[2];
    float32x4_t expected = { 9.0, 10.0, 11.0, 12.0 };
    EXPECT_TRUE(almostEqual(expected, actual));
}