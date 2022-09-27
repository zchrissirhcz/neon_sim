#include "test_util.hpp"

TEST(vget, low_s8)
{
    int8x16_t v1 = {
        1, 2, 3, 4, 5, 6, 7, 8,
        11, 12, 13, 14, 15, 16, 17, 18
    };
    int8x8_t actual = vget_low_s8(v1);
    int8x8_t expected = {1, 2, 3, 4, 5, 6, 7, 8};
    EXPECT_TRUE(almostEqual(expected, actual));
}