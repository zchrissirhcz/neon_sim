#include <iostream>
#include <stdio.h>

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

int test_vext()
{

#if __ARM_NEON
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

    // 0, 71, 61, 51, 41, 31, 21, 11,
    for (int i=0; i<8; i++)
    {
        printf("%d, ", s2_data[i]);
    }
    printf("\n");
#endif // __ARM_NEON

    return 0;
}

void test_vpaddl()
{
#if __ANDROID__
    uint8_t data[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    };
    uint8x8_t v_data = vld1_u8(data);
    uint16x4_t v_buf = vpaddl_u8(v_data);
    uint16_t buf[8];
    vst1_u16(buf, v_buf);

    for (int i = 0; i < 8; i++)
    {
        fprintf(stderr, "%d, ", buf[i]);
    }
    fprintf(stderr, "\n");
#endif // __ANDROID__
}

void dumpq_s16(int16_t data[8], const std::string& msg)
{
    fprintf(stderr, "%s: ", msg.c_str());
    for (int i = 0; i < 8; i++) {
        fprintf(stderr, "%d, ", data[i]);
    }
    fprintf(stderr, "\n");
}

void dump_u8(uint8_t data[8], const std::string& msg)
{
    fprintf(stderr, "%s: ", msg.c_str());
    for (int i = 0; i < 8; i++) {
        fprintf(stderr, "%d, ", data[i]);
    }
    fprintf(stderr, "\n");
}

void dump_s8(int8_t data[8], const std::string& msg)
{
    fprintf(stderr, "%s: ", msg.c_str());
    for (int i = 0; i < 8; i++) {
        fprintf(stderr, "%d, ", data[i]);
    }
    fprintf(stderr, "\n");
}

void dump_s32(int32_t data[4], const std::string& msg)
{
    fprintf(stderr, "%s: ", msg.c_str());
    for (int i = 0; i < 4; i++) {
        fprintf(stderr, "%d, ", data[i]);
    }
    fprintf(stderr, "\n");
}

void test_shift_right()
{
#if __ARM_NEON
    int16x8_t v_TWO = vdupq_n_s16(2);

    int16_t a[8] = {0, 1, 2, 3, 252, 253, 254, 255};
    int16x8_t v_a = vld1q_s16(a);
    
    uint8x8_t v_b = vqshrun_n_s16(v_a, 2);
    uint8_t b[8];
    vst1_u8(b, v_b);

    uint8x8_t v_c = vqrshrun_n_s16(v_a, 2);
    uint8_t c[8];
    vst1_u8(c, v_c);

    uint8x8_t v_d = vreinterpret_u8_s8(vshrn_n_s16(vaddq_s16(v_a, v_TWO), 2));
    uint8_t d[8];
    vst1_u8(d, v_d);

    dumpq_s16(a, "a");
    dump_u8(b, "b");
    dump_u8(c, "c");
    dump_u8(d, "d");

#endif // __ARM_NEON
}

void test_sub()
{
#if __ARM_NEON
    int16_t N[8] = {111, 222, 133, 444, 655, 766, 877, 988};
    int16_t M[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    int16x8_t v_N = vld1q_s16(N);
    int16x8_t v_M = vld1q_s16(M);
    int8x8_t v_res = vrsubhn_s16(v_N, v_M);
    int8_t res[8];
    vst1_s8(res, v_res);
    dump_s8(res, "res");
#endif // __ARM_NEON
}

void test_vrsubhn()
{
#if __ARM_NEON
    int16_t a[8] = {100, 101, 102, 103, 104, 105, 106, 107};
    int16_t b[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    int16x8_t v_a = vld1q_s16(a);
    int16x8_t v_b = vld1q_s16(b);
    int8x8_t v_c = vrsubhn_s16(v_a, v_b);

    int8_t c[8];
    vst1_s8(c, v_c);

    dumpq_s16(a, "a");
    dumpq_s16(b, "b");
    dump_s8(c, "c");
#endif // __ARM_NEON
}

void test_vqdmull()
{
#if __ARM_NEON
    int16x4_t v1 = {1, 2, 3, -(1<<15)};
    int16x4_t v2 = {2, 3, 4, -(1<<15)};
    int32x4_t v_out = vqdmull_s16(v1, v2);
    int32_t out[4];
    vst1q_s32(out, v_out);
    dump_s32(out, "out");
#endif // __ARM_NEON
}

void test_vld_lane()
{
#if __ARM_NEON
    int8_t data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int8x8_t v_src = {11, 12, 13, 14, 15, 16, 17, 18};
    const int lane = 1;
    int8x8_t v_res = vld1_lane_s8(data, v_src, lane);
    int8_t res[8];
    vst1_s8(res, v_res);
    dump_s8(res, "res");
#endif // __ARM_NEON
}

void test_transpose8x8()
{
#if __ARM_NEON
    uint8_t dst0[8] = {00, 01, 02, 03, 04, 05, 06, 07};
    uint8_t dst1[8] = {10, 11, 12, 13, 14, 15, 16, 17};
    uint8_t dst2[8] = {20, 21, 22, 23, 24, 25, 26, 27};
    uint8_t dst3[8] = {30, 31, 32, 33, 34, 35, 36, 37};
    uint8_t dst4[8] = {40, 41, 42, 43, 44, 45, 46, 47};
    uint8_t dst5[8] = {50, 51, 52, 53, 54, 55, 56, 57};
    uint8_t dst6[8] = {60, 61, 62, 63, 64, 65, 66, 67};
    uint8_t dst7[8] = {70, 71, 72, 73, 74, 75, 76, 77};

    fprintf(stderr, "before transpose:\n");
    uint8_t* ptrs[8] = {dst0, dst1, dst2, dst3, dst4, dst5, dst6, dst7};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fprintf(stderr, "%02d, ", ptrs[i][j]);
        }
        fprintf(stderr, "\n");
    }

    uint8x8_t vdst0 = vld1_u8(dst0);
    uint8x8_t vdst1 = vld1_u8(dst1);
    uint8x8_t vdst2 = vld1_u8(dst2);
    uint8x8_t vdst3 = vld1_u8(dst3);
    uint8x8_t vdst4 = vld1_u8(dst4);
    uint8x8_t vdst5 = vld1_u8(dst5);
    uint8x8_t vdst6 = vld1_u8(dst6);
    uint8x8_t vdst7 = vld1_u8(dst7);

    uint8_t temp[8][8];
    for (int i = 0; i < 8; i++) {
        temp[i][0] = vdst0[i];
        temp[i][1] = vdst1[i];
        temp[i][2] = vdst2[i];
        temp[i][3] = vdst3[i];
        temp[i][4] = vdst4[i];
        temp[i][5] = vdst5[i];
        temp[i][6] = vdst6[i];
        temp[i][7] = vdst7[i];
    }

    fprintf(stderr, "after transpose, temp is:\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            fprintf(stderr, "%02d, ", temp[i][j]);
        }
        fprintf(stderr, "\n");
    }


    // == 8x8 matrix transpose ==
    uint8x8x2_t vdst10t = vtrn_u8(vdst0, vdst1);
    uint8x8x2_t vdst32t = vtrn_u8(vdst2, vdst3);
    uint8x8x2_t vdst54t = vtrn_u8(vdst4, vdst5);
    uint8x8x2_t vdst76t = vtrn_u8(vdst6, vdst7);
    uint8x16_t vd1d0 = vcombine_u8(vdst10t.val[0], vdst10t.val[1]);
    uint8x16_t vd3d2 = vcombine_u8(vdst32t.val[0], vdst32t.val[1]);
    uint8x16_t vd5d4 = vcombine_u8(vdst54t.val[0], vdst54t.val[1]);
    uint8x16_t vd7d6 = vcombine_u8(vdst76t.val[0], vdst76t.val[1]);
    uint16x8x2_t vq1q0t = vtrnq_u16((uint16x8_t)vd1d0, (uint16x8_t)vd3d2);
    uint16x8x2_t vq3q2t = vtrnq_u16((uint16x8_t)vd5d4, (uint16x8_t)vd7d6);
    uint32x4x2_t vq2q0t = vtrnq_u32((uint32x4_t)vq1q0t.val[0], (uint32x4_t)vq3q2t.val[0]);
    uint32x4x2_t vq3q1t = vtrnq_u32((uint32x4_t)vq1q0t.val[1], (uint32x4_t)vq3q2t.val[1]);

    uint8_t buf[64];
    vst1q_u8(buf + 0 , (uint8x16_t)vq2q0t.val[0]);
    vst1q_u8(buf + 16, (uint8x16_t)vq3q1t.val[0]);
    vst1q_u8(buf + 32, (uint8x16_t)vq2q0t.val[1]);
    vst1q_u8(buf + 48, (uint8x16_t)vq3q1t.val[1]);
    fprintf(stderr, "the transpose result of neon is:\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int idx = i * 8 + j;
            fprintf(stderr, "%02d, ", buf[idx]);
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n");
#endif // __ARM_NEON
}

void test_vcltq()
{
#if __ARM_NEON
    float32x4_t v1 = { 1.0, 0.0, 1.0, 0.0 };
    float32x4_t v2 = { 0.0, 1.0, 1.0, 0.0 };

    {
        float32x4_t mask = vcltq_f32(v1, v2);  // v1 < v2
        float mask_data[4];
        vst1q_f32(mask_data, mask);
        fprintf(stderr, "with float32x4_t as return type, got:");
        for (int i = 0; i < 4; i++) {
            fprintf(stderr, "%f, ", mask_data[i]);
        }
        fprintf(stderr, "\n");
    }

    {
        uint32x4_t mask = vcltq_f32(v1, v2);  // v1 < v2
        uint32_t mask_data[4];
        vst1q_u32(mask_data, mask);
        fprintf(stderr, "with uint32x4_t as return type, got:");
        for (int i = 0; i < 4; i++) {
            fprintf(stderr, "%u, ", mask_data[i]);
        }
        fprintf(stderr, "\n");
    }

    fprintf(stderr, "%u", 0xffffffff);
#endif
}

int main()
{
    //test_vext();
    //test_vpaddl();
    //test_shift_right();
    //test_sub();
    //test_vrsubhn();
    //test_vqdmull();
    //test_vld_lane();
    //test_transpose8x8();
    test_vcltq();

    return 0;
}