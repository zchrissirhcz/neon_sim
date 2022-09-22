#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
//#include "NEON_2_SSE.h"
#endif

#include "gtest/gtest.h"
//
//TEST(LoadSave, vld1_s8)
//{
//    int8_t a[8] = { -128, 2, 3, 4, 5, 6, 7, 8 };
//    int8x8_t va = vld1_s8(a);
//    int8_t b[8];
//    vst1_s8(b, va);
//    for (int i = 0; i < 8; i++)
//    {
//        EXPECT_EQ(b[i], a[i]);
//    }
//}
//
//TEST(LoadSave, vld1_u8)
//{
//    uint8_t a[8] = { 1, 2, 3, 4, 255, 254, 253, 252 };
//    uint8x8_t va = vld1_u8(a);
//    uint8_t b[8];
//    vst1_u8(b, va);
//    for (int i = 0; i < 8; i++)
//    {
//        EXPECT_EQ(b[i], a[i]);
//    }
//}
//
//TEST(LoadSave, vld1_s16)
//{
//    int16_t a[4] = { -32768, 2, 3, 4};
//    int16x4_t va = vld1_s16(a);
//    int16_t b[4];
//    vst1_s16(b, va);
//    for (int i = 0; i < 4; i++)
//    {
//        EXPECT_EQ(b[i], a[i]);
//    }
//}
//
//TEST(LoadSave, vld1_u16)
//{
//    uint16_t a[4] = { 65535, 2, 3, 4 };
//    uint16x4_t va = vld1_u16(a);
//    uint16_t b[4];
//    vst1_u16(b, va);
//    for (int i = 0; i < 4; i++)
//    {
//        EXPECT_EQ(b[i], a[i]);
//    }
//}

template<typename T, typename VT, int n = 64 / sizeof(T)>
void test_vld1_type(std::function<VT(T*)> vld1_type, std::function<void(T*, VT)> vst1_type)
{
    T* a = new T[n];
    // TODO: fill in a with random numbers that of type T
    VT va = vld1_type(a);
    T* b = new T[n];
    vst1_type(b, va);
    for (int i = 0; i < n; i++)
    {
        EXPECT_EQ(b[i], a[i]);
    }
}

template<typename T, typename VT, int n = 128 / sizeof(T)>
void test_vld1q_type(std::function<VT(T*)> vld1_type, std::function<void(T*, VT)> vst1_type)
{
    T* a = new T[n];
    // TODO: fill in a with random numbers that of type T
    VT va = vld1_type(a);
    T* b = new T[n];
    vst1_type(b, va);
    for (int i = 0; i < n; i++)
    {
        EXPECT_EQ(b[i], a[i]);
    }
}

// TEST(LoadSave, vld1)
// {
//     test_vld1_type<int8_t, int8x8_t>(vld1_s8, vst1_s8);
//     test_vld1_type<uint8_t, uint8x8_t>(vld1_u8, vst1_u8);
//     test_vld1_type<int16_t, int16x4_t>(vld1_s16, vst1_s16);
//     test_vld1_type<uint16_t, uint16x4_t>(vld1_u16, vst1_u16);
//     test_vld1_type<int32_t, int32x2_t>(vld1_s32, vst1_s32);
//     test_vld1_type<uint32_t, uint32x2_t>(vld1_u32, vst1_u32);
//     test_vld1_type<int64_t, int64x1_t>(vld1_s64, vst1_s64);
//     test_vld1_type<uint64_t, uint64x1_t>(vld1_u64, vst1_u64);

//     test_vld1q_type<int8_t, int8x16_t>(vld1q_s8, vst1q_s8);
//     test_vld1q_type<uint8_t, uint8x16_t>(vld1q_u8, vst1q_u8);
//     test_vld1q_type<int16_t, int16x8_t>(vld1q_s16, vst1q_s16);
//     test_vld1q_type<uint16_t, uint16x8_t>(vld1q_u16, vst1q_u16);
//     test_vld1q_type<int32_t, int32x4_t>(vld1q_s32, vst1q_s32);
//     test_vld1q_type<uint32_t, uint32x4_t>(vld1q_u32, vst1q_u32);
//     test_vld1q_type<int64_t, int64x2_t>(vld1q_s64, vst1q_s64);
//     test_vld1q_type<uint64_t, uint64x2_t>(vld1q_u64, vst1q_u64);
// }

// TEST(Save_Q_Reg, int8x16)
// {
//     int8x16_t vd = {-128, -3, -5, 7, 2, 4, 6, 127, -128, -3, -5, 7, 2, 4, 6, 127};
//     int8_t ptr[16];
//     vst1q_s8(ptr, vd);
//     printf("Done\n");
// }

// TEST(Save_Q_Reg, uint8x16)
// {
//     uint8x16_t vd = {1, 0, 3, 5, 7, 2, 6, 255, 1, 0, 3, 5, 7, 2, 6, 255};
//     uint8_t ptr[16];
//     vst1q_u8(ptr, vd);
//     printf("Done\n");
// }
//
//TEST(NEON2SSE, lldb_dump)
//{
//    //uint8x8_t vw8u = {64, 101, 11, 48, 86, 124, 33, 71};
//    // uint8_t w8u[8] = {64, 101, 11, 48, 86, 124, 33, 71};
//    // uint8x8_t vw8u = vld1_u8(w8u);
//
//    // uint8_t temp[8];
//    // vst1_u8(temp, vw8u);
//    
//    // uint8_t buf[8];
//    // vst1_u8(buf, vw8u);
//    // printf("Done\n");
//
//    // uint8x16_t
//    //uint8_t vd1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18};
//    uint8_t d1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 251, 252, 253, 254, 255, 255, 255, 255};
//    uint8x16_t vd1 = vld1q_u8(d1);
//    uint8_t buf1[16];
//    vst1q_u8(buf1, vd1);
//    printf("Done1\n");
//
//    // int8x16_t
//    int8_t d2[16] = {-128, -127, 3, 4, 5, 6, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18};
//    int8x16_t vd2 = vld1q_s8(d2);
//    int8_t buf2[16];
//    vst1q_s8(buf2, vd2);
//    printf("Done2\n");
//
//    // uint16x8_t
//    uint16_t d3[8] = {0, 1, 2, 3, 65500, 65533, 65534, 65535};
//    uint16x8_t vd3 = vld1q_u16(d3);
//    uint16_t buf3[8];
//    vst1q_u16(buf3, vd3);
//    printf("Done3\n");
//
//    // int16x8_t
//    int16_t d4[8] = {-32768, -32767, -576, -35,  56, 169, 1444, 32767};
//    int16x8_t vd4 = vld1q_s16(d4);
//    int16_t buf4[8];
//    vst1q_s16(buf4, vd4);
//    printf("Done4\n");
//
//    // uint32x4_t
//    uint32_t d5[4] = {0, 1, 2147483647, 4294967295};
//    uint32x4_t vd5 = vld1q_u32(d5);
//    uint32_t buf5[4];
//    vst1q_u32(buf5, vd5);
//    printf("Done5\n");
//
//    // int32x4_t
//    int32_t d6[4] = {-2147483648, -34343, 4545454, 2147483647};
//    int32x4_t vd6 = vld1q_s32(d6);
//    int32_t buf6[4];
//    vst1q_s32(buf6, vd6);
//    printf("Done6\n");
//
//    // uint64x2_t
//    uint64_t d7[2] = {345, 6789};
//    uint64x2_t vd7 = vld1q_u64(d7);
//    uint64_t buf7[2];
//    vst1q_u64(buf7, vd7);
//    printf("Done7\n");
//
//    // int64x2_t
//    int64_t d8[2] = {-345, 6789};
//    int64x2_t vd8 = vld1q_s64(d8);
//    int64_t buf8[2];
//    vst1q_s64(buf8, vd8);
//    printf("Done8\n");
//
//    // float32x4_t
//    float32_t d9[4] = { 1.1, 2.2, 3.3, 4.4 };
//    float32x4_t vd9 = vld1q_f32(d9);
//    float buf9[4];
//    vst1q_f32(buf9, vd9);
//    printf("Done9\n");
//
//    // float64x2_t
//    // float64_t d10[2] = {-345.67, 89012.345};
//    // int64x2_t vd10 = vld1q_s64(d10);
//    // int64_t buf10[2];
//    // vst1q_f64(buf10, vd10);
//    // printf("Done10\n");
//
//    // double data4[2] = { 5.5, 7.7 };
//    // float64x2_t vd4 = vld1q_f64(data4);
//    // float buf4[4];
//    // vst1q_f64(buf4, vd4); // NEON_2_SSE.h does not support this.
//    // printf("Done\n");
//}
//// sse_type: one of ['m64_u64', 'm64_i64', 'm64_d64', 'm64_u32', 'm64_i32', 'm64_f32', 'm64_i16', 'm64_u16', 'm64_i8', 'm64_u8']
//
//
//TEST(LoadSave, vld_lane)
//{
//    uint8_t Sp[8] = { 10, 11, 12, 13, 41, 51, 61, 71 };
//
//    //int xofsp[8] = {21, 23, 25, 27, 22, 24, 26, 28};
//
//    // vld2_lane_u8	(uint8_t const * ptr, uint8x8x2_t src, const int lane)
//    // lane: [0, 7]
//
//
//    uint8x8_t v0 = { 2, 3, 4, 5, 6, 7, 8, 9 };
//    uint8x8_t v1 = { 11, 12, 13, 14, 15, 16, 17, 18 };
//    uint8x8x2_t _a0a1;
//    _a0a1.val[0] = v0;
//    _a0a1.val[1] = v1;
//
//    uint8x8x2_t _b0b1;
//
//    _b0b1 = vld2_lane_u8(Sp, _a0a1, 5);
//    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 1);
//    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 2);
//    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 3);
//    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 4);
//    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 5);
//    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 6);
//    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 7);
//
//    std::cout << "_a0a1:\n" << _a0a1 << std::endl;
//    std::cout << "_b0b1:\n" << _b0b1 << std::endl;
//
//
//    uint8x8_t src = { 7, 6, 5, 4, 1, 2, 3, 0 };
//    uint8x8_t w1 = vld1_lane_u8(Sp, src, 2);
//    std::cout << "w1:" << w1 << std::endl;
//}