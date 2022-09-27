#include "test_util.hpp"

TEST(sub, vsubw)
{
    // vsubw_type: r = vsubw_type(a, b),  a和r是宽类型，b是窄类型
    int16x8_t v1 = {101, 102, 103, 104, 105, 106, 107, 108};
    int8x8_t v2 = {1, 2, 3, 4, 5, 6, 7, 8};
    int16x8_t actual = vsubw_s8(v1, v2);
    int16x8_t expected = {100, 100, 100, 100, 100, 100, 100, 100};
    EXPECT_TRUE(almostEqual(expected, actual));
}