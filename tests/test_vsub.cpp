#include "test_util.hpp"

TEST(sub, vsub)
{
    // vsub_type: ri = ai - bi
    uint8x8_t v1 = { 11, 12, 13, 14, 15, 16, 17, 18 };
    uint8x8_t v2 = vdup_n_u8(10);
    uint8x8_t actual = vsub_u8(v1, v2);
    uint8x8_t expected = { 1, 2, 3, 4, 5, 6, 7, 8 };
    EXPECT_TRUE(almostEqual(expected, actual));
}