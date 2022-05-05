#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
//#include "arm_neon_sim.hpp"
#include "NEON_2_SSE.h"
#endif

#include "gtest/gtest.h"

// TEST(Save_D_Reg, int8x8)
// {
//     int8x8_t vd = {-128, -3, -5, 7, 2, 4, 6, 127};
//     int8_t ptr[8];
//     vst1_s8(ptr, vd);
//     printf("Done\n");
// }

// TEST(Save_D_Reg, uint8x8)
// {
//     uint8x8_t vd = {1, 0, 3, 5, 7, 2, 6, 255};
//     uint8_t ptr[8];
//     vst1_u8(ptr, vd);
//     printf("Done\n");
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

TEST(NEON2SSE, lldb_dump)
{
    //uint8x8_t vw8u = {64, 101, 11, 48, 86, 124, 33, 71};
    // uint8_t w8u[8] = {64, 101, 11, 48, 86, 124, 33, 71};
    // uint8x8_t vw8u = vld1_u8(w8u);

    // uint8_t temp[8];
    // vst1_u8(temp, vw8u);
    
    // uint8_t buf[8];
    // vst1_u8(buf, vw8u);
    // printf("Done\n");

    uint8_t w8u2[16] = {1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 13, 14, 15, 16, 17, 18};
    uint8x16_t vw8u2 = vld1q_u8(w8u2);
    uint8_t buf2[16];
    vst1q_u8(buf2, vw8u2);
    printf("Done2\n");

    float data[4] = { 1.1, 2.2, 3.3, 4.4 };
    float32x4_t vd = vld1q_f32(data);
    float buf3[4];
    vst1q_f32(buf3, vd);
    printf("Done\n");

    // double data4[2] = { 5.5, 7.7 };
    // float64x2_t vd4 = vld1q_f64(data4);
    // float buf4[4];
    // vst1q_f64(buf4, vd4); // NEON_2_SSE.h does not support this.
    // printf("Done\n");
}
// sse_type: one of ['m64_u64', 'm64_i64', 'm64_d64', 'm64_u32', 'm64_i32', 'm64_f32', 'm64_i16', 'm64_u16', 'm64_i8', 'm64_u8']