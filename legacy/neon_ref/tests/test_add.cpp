#include "gtest/gtest.h"

#include "pixel_neon.hpp"
#include <arm_neon.h>

// Reference implementation:
// int8x8_t vaddhn_u16(int16x8_t v1, int16x8_t v2)
// {
//     int8x8_t res;
//     for (int i=0; i<8; i++)
//     {
//         temp[i] = (v1[i] + v2[i])>>8;
//     }
//     return res;
// }

// vaddhn_s16
// vaddhn_s32
// vaddhn_s64
// vaddhn_u16
// vaddhn_u32
// vaddhn_u64
TEST(add, vaddhn_u16)
{
    //vaddhn_type: 结果vector元素的类型大小是输入vector元素的一半
    // 具体到 vaddhn_u16, 输入的两个参数v1, v2是u16类型的
    // 先算出u16类型的 v1+v2的结果 v_mid
    // 然后砍掉 v_mid 的低8位， 也就是高八位右移，得到最终结果
    uint16x8_t v1 = vdupq_n_u16(250);
    //uint16x8_t v2 = {1, 2, 3, 4, 5, 6, 7, 8};
    uint16x8_t v2 = {1, 2, 3, 4, 5, 6, 7, 264};
    //251:  0 ........
    //252:  0 ........
    //253:  0 ........
    //254:  0 ........
    //255:  0 11111111
    //256:  1 00000000
    //257:  1 00000001
    //258:  1 00000010
    //514: 10 00000010  514 = 250 + 264
    uint8x8_t v_out = vaddhn_u16(v1, v2);
    uint8_t expected_out[8] = {0, 0, 0, 0, 0, 1, 1, 2};

    pxl::uint16x8_t pv1 = pxl::vdupq_n_u16(250);
    pxl::uint16x8_t pv2 = {1, 2, 3, 4, 5, 6, 7, 264};
    pxl::uint8x8_t pv_out = pxl::vaddhn_u16(pv1, pv2);

    uint8_t out[8];
    vst1_u8(out, v_out);
    for (int i=0; i<8; i++)
    {
        ASSERT_EQ(expected_out[i], out[i]);
        //fprintf(stderr, "%d, ", out[i]);
        ASSERT_EQ(pv_out[i], out[i]);
    }
    //fprintf(stderr, "\n");
}

//saturating add
TEST(add, vqadd)
{
    // vqadd_type: ri = sat(ai + bi) 饱和指令，相加结果超出元素的最大值时，元素就取最大值。
    uint8x8_t v1 = vdup_n_u8(250);
    uint8x8_t v2 = {1, 2, 3, 4, 5, 6, 7, 8};
    uint8x8_t v_out = vqadd_u8(v1, v2);
    uint8_t expected_out[8] = {251, 252, 253, 254, 255, 255, 255, 255};

    pxl::uint8x8_t pv1 = pxl::vdup_n_u8(250);
    pxl::uint8x8_t pv2 = {1, 2, 3, 4, 5, 6, 7, 8};
    pxl::uint8x8_t pv_out = pxl::vqadd_u8(pv1, pv2);

    uint8_t out[8];
    vst1_u8(out, v_out);
    for (int i=0; i<8; i++)
    {
        ASSERT_EQ(expected_out[i], out[i]);
        ASSERT_EQ(pv_out[i], out[i]);
    }
}

TEST(add, vhadd)
{
    // 相加结果再除2。ri = (ai + bi) >> 1;
    // 不能整除2的话， 如果是正数结果， 则向下取整(3.5 => 3)
    //                 如果是负数结果， 则也是向下取整(-3.5 => -4)
    int8x8_t v1 = {1, 2, 3, 4, 5,  6,  7,   8};
    int8x8_t v2 = {1, 3, 5, 7, 9, 11, 13, -15};
    int8x8_t v_out = vhadd_s8(v1, v2);
    int8_t expected_out[8] = {1, 2, 4, 5, 7, 8, 10, -4};

    pxl::int8x8_t pv1 =  {1, 2, 3, 4, 5,  6,  7,   8};
    pxl::int8x8_t pv2 = {1, 3, 5, 7, 9, 11, 13, -15};
    pxl::int8x8_t pv_out = pxl::vhadd_s8(pv1, pv2);

    int8_t out[8];
    vst1_s8(out, v_out);
    for (int i=0; i<8; i++)
    {
        ASSERT_EQ(expected_out[i], out[i]);
        ASSERT_EQ(pv_out[i], out[i]);
        //fprintf(stderr, ">>> %d, ", pv_out[i]);
    }
    //fprintf(stderr, "\n");
    int a = -7;
    // fprintf(stderr, "-7/2=%d\n", -7/2); // -3
    // fprintf(stderr, "-7>>1=%d\n", (-7>>1)); // -3
    // fprintf(stderr, "(8-15)>>1=%d\n", ( (-7)>>1)); // -4
}

TEST(add, vrhadd)
{
    // vrhadd_type: 相加结果再除2(四舍五入)。ri = (ai + bi + 1) >> 1
    // 结果也是向下取整。
    int8x8_t v1 = {120, 2, 3, 4, 5,  6,  7,   1};
    int8x8_t v2 = {121, 3, 5, 7, 9, 11, 13, -15};
    int8x8_t v_out = vrhadd_s8(v1, v2);
    int8_t expected_out[8] = {121, 3, 4, 6, 7, 9, 10, -7};

    pxl::int8x8_t pv1 =  {120, 2, 3, 4, 5,  6,  7,   1};
    pxl::int8x8_t pv2 = {121, 3, 5, 7, 9, 11, 13, -15};
    pxl::int8x8_t pv_out = pxl::vrhadd_s8(pv1, pv2);

    int8_t out[8];
    vst1_s8(out, v_out);
    for (int i=0; i<8; i++)
    {
        ASSERT_EQ(expected_out[i], out[i]);
        ASSERT_EQ(pv_out[i], out[i]);
    }
}
