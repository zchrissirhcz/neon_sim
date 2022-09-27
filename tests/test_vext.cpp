#include "test_util.hpp"

TEST(vext, u8)
{
    {
        uint8x8_t src1 = {1, 2, 3, 4, 5, 6, 7, 8};
        uint8x8_t src2 = {9, 10, 11, 12, 13, 14, 15, 16};
        uint8x8_t expected = {4, 5, 6, 7, 8, 9, 10, 11};
        uint8x8_t actual = vext_u8(src1, src2, 3);
        EXPECT_TRUE(almostEqual(expected, actual));
    }

    {
        uint8_t s0_data[] = {71, 61, 51, 41, 31, 21, 11, 1};
        uint8x8_t s0 = vld1_u8(s0_data);

        uint8x8_t m = vdup_n_u8(0);
        uint8x8_t s1 = vext_u8(m, s0, 7); // 0, 71, 61, 51, 41, 31, 21, 11,
        uint8x8_t s2 = vext_u8(m, s0, 6); // 0, 0, 71, 61, 51, 41, 31, 21,
        uint8x8_t s3 = vext_u8(m, s0, 5);
        uint8x8_t s4 = vext_u8(m, s0, 4);
        uint8x8_t s5 = vext_u8(m, s0, 3);
        uint8x8_t s6 = vext_u8(m, s0, 2);
        uint8x8_t s7 = vext_u8(m, s0, 1);

        std::cout << "s1: " << s1 << std::endl;

        uint8_t s1_data[8];
        vst1_u8(s1_data, s1);

        // 0, 71, 61, 51, 41, 31, 21, 11,
        for (int i=0; i<8; i++)
        {
            printf("%d, ", s1_data[i]);
        }
        printf("\n");


        uint8_t s2_data[8];
        vst1_u8(s2_data, s2);

        uint8x8_t expected = { 0, 71, 61, 51, 41, 31, 21, 11 };
        for (int i=0; i<8; i++)
        {
            printf("%d, ", s2_data[i]);
        }
        printf("\n");
    }
}