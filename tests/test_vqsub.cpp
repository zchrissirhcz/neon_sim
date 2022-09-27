#include "test_util.hpp"

TEST(sub, vqsub)
{
    // vqsub_type: ri = sat(ai + bi) 饱和指令，相减结果超出元素的最大值时，元素就取最大值。
    // 相减结果如果小于当前类型最小值， 则元素就取类型最小值。
    {
        uint8x8_t v1 = vdup_n_u8(250);
        uint8x8_t v2 = {1, 2, 3, 4, 251, 252, 253, 254};
        uint8x8_t actual = vqsub_u8(v1, v2);
        uint8x8_t expected = {249, 248, 247, 246, 0, 0, 0, 0};
        EXPECT_TRUE(almostEqual(expected, actual));
    }

    {
        int8x8_t v1 = vdup_n_s8(120);
        int8x8_t v2 = {-11, 2, 3, 4, 121, 122, 123, 124};
        int8x8_t actual = vqsub_s8(v1, v2);
        int8x8_t expected = {127, 118, 117, 116, -1, -2, -3, -4};
        EXPECT_TRUE(almostEqual(expected, actual));
    }
}