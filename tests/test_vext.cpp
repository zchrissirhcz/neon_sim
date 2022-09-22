#include "test_util.hpp"

TEST(vext, u8)
{
    printf("Hello\n");
    uint8x8_t src1 = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8x8_t src2 = {9, 10, 11, 12, 13, 14, 15, 16};
    uint8x8_t expected = {4, 5, 6, 7, 8, 9, 10, 11};
    uint8x8_t actual = vext_u8(src1, src2, 3);
    EXPECT_TRUE(almostEqual(expected, actual));
}