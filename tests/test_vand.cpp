#include "test_util.hpp"

TEST(vand, u8)
{
    uint8x8_t v1 = {0, 9,  12, 11, 4, 13, 6, 17};
    uint8x8_t v2 = {8, 11, 10, 3, 12, 5, 14, 15};

    uint8x8_t expected = { 0, 9, 8, 3, 4, 5, 6, 1 };
    uint8x8_t actual = vand_u8(v1, v2);
    EXPECT_TRUE(almostEqual(expected, actual));
}