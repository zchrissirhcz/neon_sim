#include "test_util.hpp"

TEST(sub, vsubl)
{
    // vsubl_type: Signed Subtract Long.
    int8x8_t v1 = vdup_n_s8(127);
    int8x8_t v2 = { 0, 1, 2, 3, -1, -2, -3, -4 };
    int16x8_t actual = vsubl_s8(v1, v2);
    int16x8_t expected = { 127, 126, 125, 124, 128, 129, 130, 131 };
    EXPECT_TRUE(almostEqual(expected, actual));
}