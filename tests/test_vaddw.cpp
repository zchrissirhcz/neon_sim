#include "test_util.hpp"

TEST(vaddw_high, s8)
{
    int16x8_t v1 = { 0, 1, 2, 3, 4, 5, 6, 7 };
    int8x16_t v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int16x8_t expected = {8, 10, 12, 14, 16, 18, 20, 22};
    int16x8_t actual = vaddw_high_s8(v1, v2);
    EXPECT_TRUE(almostEqual(expected, actual));
}

TEST(vaddw, s8)
{
    //vaddw_type: 第一个vector元素宽度2倍于第二个vector元素；结果元素也是2倍宽度于第二个vector元素
    //WT v_out = vaddw_type(WT v1, T v2)
    int16x8_t v1 = vdupq_n_s16(300);
    int8x8_t v2 = {1, 2, 3, 4, 5, 6, 7, 8};
    int16x8_t actual = vaddw_s8(v1, v2);
    int16x8_t expected = {301, 302, 303, 304, 305, 306, 307, 308};
    EXPECT_TRUE(almostEqual(expected, actual));
}