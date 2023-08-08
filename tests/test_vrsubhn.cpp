#include "test_util.hpp"

TEST(sub, vrsubhn)
{
    int16x8_t v1 = vdupq_n_s16(850);
    int16x8_t v2 = { 200, 400, 600, 800, 1000, 1200, 1400, 1600 };
    int8x8_t actual = vrsubhn_s16(v1, v2);
    int8x8_t expected = { 3, 2, 1, 0, -1, -1, -2, -3 };
    EXPECT_TRUE(almostEqual(expected, actual));
}
