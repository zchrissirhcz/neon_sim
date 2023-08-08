#include "test_util.hpp"

TEST(sub, vhsub)
{
    int8x8_t v1 = vdup_n_s8(120);
    int8x8_t v2 = { 1, 2, 3, 4, 120, 121, 122, 123 };
    int8x8_t actual = vhsub_s8(v1, v2);
    int8x8_t expected = { 59, 59, 58, 58, 0, -1, -1, -2 };
    EXPECT_TRUE(almostEqual(expected, actual));
}