#include "test_util.hpp"

TEST(vaddhn_high_s16, normal)
{
    int8x8_t r = { 0, 1, 2, 3, 4, 5, 6, 7 };
    int16x8_t a = { 32000, 32001, 32002, 32003, 32004, 32005, 32006, 32007 };
    int16x8_t b = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int8x16_t expected = { 0, 1, 2, 3, 4, 5, 6, 7, 125, 125, 125, 125, 125, 125, 125, 125 };
    int8x16_t actual = vaddhn_high_s16(r, a, b);
    EXPECT_TRUE(almostEqual(expected, actual));
}