#include "test_util.hpp"

TEST(vtrn, u8)
{
    uint8x8x2_t src;
    src.val[0] = uint8x8_t{ 1, 2, 3, 4, 5, 6, 7, 8 };
    src.val[1] = uint8x8_t{ 9, 10, 11, 12, 13, 14, 15, 16 };
    uint8x8x2_t actual = vtrn_u8(src.val[0], src.val[1]);
    uint8x8x2_t expected;
    expected.val[0] = uint8x8_t{ 1, 9, 3, 11, 5, 13, 7, 15 };
    expected.val[1] = uint8x8_t{ 2, 10, 4, 12, 6, 14, 8, 16 };

    EXPECT_TRUE(almostEqual(expected, actual));
}