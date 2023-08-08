#include "test_util.hpp"

TEST(vext, u8)
{
    {
        uint8x8_t src1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
        uint8x8_t src2 = { 9, 10, 11, 12, 13, 14, 15, 16 };
        uint8x8_t expected = { 4, 5, 6, 7, 8, 9, 10, 11 };
        uint8x8_t actual = vext_u8(src1, src2, 3);
        EXPECT_TRUE(almostEqual(expected, actual));
    }

    {
        uint8_t s0_data[] = { 71, 61, 51, 41, 31, 21, 11, 1 };
        uint8x8_t s0 = vld1_u8(s0_data);

        uint8x8_t m = vdup_n_u8(0);
        uint8x8_t s1 = vext_u8(m, s0, 7); // 0, 71, 61, 51, 41, 31, 21, 11,
        uint8x8_t s2 = vext_u8(m, s0, 6); // 0, 0, 71, 61, 51, 41, 31, 21,
        uint8x8_t s3 = vext_u8(m, s0, 5);
        uint8x8_t s4 = vext_u8(m, s0, 4);
        uint8x8_t s5 = vext_u8(m, s0, 3);
        uint8x8_t s6 = vext_u8(m, s0, 2);
        uint8x8_t s7 = vext_u8(m, s0, 1);

        uint8x8_t expected_s1 = { 0, 71, 61, 51, 41, 31, 21, 11 };
        uint8x8_t expected_s2 = { 0, 0, 71, 61, 51, 41, 31, 21 };
        uint8x8_t expected_s3 = { 0, 0, 0, 71, 61, 51, 41, 31 };
        uint8x8_t expected_s4 = { 0, 0, 0, 0, 71, 61, 51, 41 };
        uint8x8_t expected_s5 = { 0, 0, 0, 0, 0, 71, 61, 51 };
        uint8x8_t expected_s6 = { 0, 0, 0, 0, 0, 0, 71, 61 };
        uint8x8_t expected_s7 = { 0, 0, 0, 0, 0, 0, 0, 71 };

        EXPECT_TRUE(almostEqual(expected_s1, s1));
        EXPECT_TRUE(almostEqual(expected_s2, s2));
        EXPECT_TRUE(almostEqual(expected_s3, s3));
        EXPECT_TRUE(almostEqual(expected_s4, s4));
        EXPECT_TRUE(almostEqual(expected_s5, s5));
        EXPECT_TRUE(almostEqual(expected_s6, s6));
        EXPECT_TRUE(almostEqual(expected_s7, s7));
    }
}