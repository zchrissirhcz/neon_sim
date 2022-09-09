
#if __ARM_NEON
#include <arm_neon.h>
#elif defined(USE_NEON_PEDAL)
#include "neon_pedal.h"
#else
#include "NEON_2_SSE.h"
#endif

#include <stdio.h>
#include <iostream>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

template<typename Tp>
std::ostream& operator << (std::ostream& os, const std::vector<Tp>& v)
{
    for (int i=0; i<v.size(); i++)
    {
        if (i>0)
        {
            os << ", ";
        }
        os << v[i];
    }
    return os;
}


template<>
std::ostream& operator << (std::ostream& os, const std::vector<int8_t>& v)
{
    for (int i=0; i<v.size(); i++)
    {
        if (i>0)
        {
            os << ", ";
        }
        os << static_cast<int>(v[i]);
    }
    return os;
}

template<>
std::ostream& operator << (std::ostream& os, const std::vector<uint8_t>& v)
{
    for (int i=0; i<v.size(); i++)
    {
        if (i>0)
        {
            os << ", ";
        }
        os << static_cast<int>(v[i]);
    }
    return os;
}

TEST(vadd_s8, normal)
{
    int8x8_t v1 = {1, 2, 3, 4, 5, 6, 7, 8};
    int8x8_t v2 = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int8_t> gt = {2, 4, 6, 8, 10, 12, 14, 16};

    int8x8_t sum = vadd_s8(v1, v2);
    std::vector<int8_t> res(8);
    for (int i=0; i<8; i++)
    {
        res[i] = sum[i];
    }

    EXPECT_EQ(res, gt);
}

TEST(vadd_s8, exceed)
{
    int8x8_t v1 = {120, 121, 122, 123, 124, 125, 126, 127};
    int8x8_t v2 = {100, 100, 100, 100, 100, 100, 100, 100};

    // 并不是 {220, 221, 222, 234, 224, 225, 226, 227}, 而是分别减去256
    std::vector<int8_t> gt = {-36, -35, -34, -33, -32, -31, -30, -29};

    int8x8_t sum = vadd_s8(v1, v2);
    std::vector<int8_t> res(8);
    for (int i=0; i<8; i++)
    {
        res[i] = sum[i];
    }
    EXPECT_EQ(res, gt);
}

TEST(vaddq_f32, normal)
{
    float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v2 = { 1.0, 1.0, 1.0, 1.0 };
    std::vector<float> gt = {2, 3, 4, 5};

    float32x4_t sum = vaddq_f32(v1, v2);
    //std::cout << sum << std::endl;
    std::vector<float> res = {sum[0], sum[1], sum[2], sum[3]};
    EXPECT_EQ(res, gt);
}

TEST(vaddl_u8, normal)
{
    uint8x8_t v1 = { 240, 241, 242, 243, 244, 245, 246, 247};
    uint8x8_t v2 = { 100, 100, 100, 100, 100, 100, 100, 100};
    std::vector<uint16_t> gt = { 340, 341, 342, 343, 344, 345, 346, 347 };

    uint16x8_t sum = vaddl_u8(v1, v2);
    std::vector<uint16_t> res {sum[0], sum[1], sum[2], sum[3], sum[4], sum[5], sum[6], sum[7]};
    EXPECT_EQ(res, gt);
}

TEST(vaddl_high_s8, normal)
{
    int8x16_t v1 = { 0, 1, 2, 3, 4, 5, 6, 7, 100, 101, 102, 103, 104, 105, 106, 107};
    int8x16_t v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 100, 100, 100, 100, 100, 100, 100, 100};
    std::vector<int16_t> gt = {200, 201, 202, 203, 204, 205, 206, 207};

    int16x8_t sum = vaddl_high_s8(v1, v2);
    std::vector<int16_t> res {sum[0], sum[1], sum[2], sum[3], sum[4], sum[5], sum[6], sum[7]};
    EXPECT_EQ(res, gt);
}



TEST(vaddw_high_s8, normal)
{
    int16x8_t v1 = { 0, 1, 2, 3, 4, 5, 6, 7 };
    int8x16_t v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<int16_t> gt = {8, 10, 12, 14, 16, 18, 20, 22};

    int16x8_t sum = vaddw_high_s8(v1, v2);
    std::vector<int16_t> res {sum[0], sum[1], sum[2], sum[3], sum[4], sum[5], sum[6], sum[7]};
    EXPECT_EQ(res, gt);
}

TEST(vaddhn_high_s16, normal)
{
    int8x8_t r = {0, 1, 2, 3, 4, 5, 6, 7};
    int16x8_t a = {32000, 32001, 32002, 32003, 32004, 32005, 32006, 32007};
    int16x8_t b = {1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int8_t> gt = {0, 1, 2, 3, 4, 5, 6, 7, 125, 125, 125, 125, 125, 125, 125, 125};

    int8x16_t sum = vaddhn_high_s16(r, a, b);
    std::vector<int8_t> res(16);
    for (int i=0; i<16; i++) {
        res[i] = sum[i];
    };
    EXPECT_EQ(res, gt);
}

void test_vmulq()
{
    float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 };
    float32x4_t v2 = { 1.0, 1.0, 1.0, 1.0 };
    float32x4_t prod = vmulq_f32(v1, v2);
    //std::cout << prod << std::endl;
    std::vector<float> res {prod[0], prod[1], prod[2], prod[3]};
    std::cout << res << std::endl;
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}