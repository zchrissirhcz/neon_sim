#include "test_util.hpp"

TEST(vuzp, u8)
{
    uint8x8x2_t src;
    src.val[0] = uint8x8_t{ 1, 2, 3, 4, 5, 6, 7, 8 };
    src.val[1] = uint8x8_t{ 9, 10, 11, 12, 13, 14, 15, 16 };
    uint8x8x2_t actual = vuzp_u8(src.val[0], src.val[1]);
    uint8x8x2_t expected;
    expected.val[0] = uint8x8_t{ 1, 3, 5, 7, 9, 11, 13, 15 };
    expected.val[1] = uint8x8_t{ 2, 4, 6, 8, 10, 12, 14, 16 };

    EXPECT_TRUE(almostEqual(expected, actual));
}