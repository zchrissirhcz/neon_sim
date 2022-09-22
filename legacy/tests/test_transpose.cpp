#include <stdio.h>
#include <iostream>

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

#include "autotimer.hpp"

#include "cpu.h"


const int g_loop_count = 1;//00000;

void dump(const uint8x8_t& d0, const uint8x8_t& d1, const uint8x8_t& d2, const uint8x8_t& d3, const uint8x8_t& d4, const uint8x8_t& d5, const uint8x8_t& d6, const uint8x8_t& d7, const std::string& msg)
{
    std::cout << "\n=== " << msg << " ===" << std::endl;
    std::cout << d0 << std::endl;
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    std::cout << d4 << std::endl;
    std::cout << d5 << std::endl;
    std::cout << d6 << std::endl;
    std::cout << d7 << std::endl;
}

void dump(const uint16x8_t& d0, const uint16x8_t& d1, const uint16x8_t& d2, const uint16x8_t& d3, const uint16x8_t& d4, const uint16x8_t& d5, const uint16x8_t& d6, const uint16x8_t& d7, const std::string& msg)
{
    std::cout << "\n=== " << msg << " ===" << std::endl;
    std::cout << d0 << std::endl;
    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << d3 << std::endl;
    std::cout << d4 << std::endl;
    std::cout << d5 << std::endl;
    std::cout << d6 << std::endl;
    std::cout << d7 << std::endl;
}

void init_input(uint8x8_t& d0, uint8x8_t& d1, uint8x8_t& d2, uint8x8_t& d3, uint8x8_t& d4, uint8x8_t& d5, uint8x8_t& d6, uint8x8_t& d7)
{
    d0 = {11, 12, 13, 14, 15, 16, 17, 18};
    d1 = {21, 22, 23, 24, 25, 26, 27, 28};
    d2 = {31, 32, 33, 34, 35, 36, 37, 38};
    d3 = {41, 42, 43, 44, 45, 46, 47, 48};
    d4 = {51, 52, 53, 54, 55, 56, 57, 58};
    d5 = {61, 62, 63, 64, 65, 66, 67, 68};
    d6 = {71, 72, 73, 74, 75, 76, 77, 78};
    d7 = {81, 82, 83, 84, 85, 86, 87, 88};
}

void transpose_carotene()
{
    uint8_t buf[64];

    uint8x8_t vdst0 = {11, 12, 13, 14, 15, 16, 17, 18};
    uint8x8_t vdst1 = {21, 22, 23, 24, 25, 26, 27, 28};
    uint8x8_t vdst2 = {31, 32, 33, 34, 35, 36, 37, 38};
    uint8x8_t vdst3 = {41, 42, 43, 44, 45, 46, 47, 48};
    uint8x8_t vdst4 = {51, 52, 53, 54, 55, 56, 57, 58};
    uint8x8_t vdst5 = {61, 62, 63, 64, 65, 66, 67, 68};
    uint8x8_t vdst6 = {71, 72, 73, 74, 75, 76, 77, 78};
    uint8x8_t vdst7 = {81, 82, 83, 84, 85, 86, 87, 88};
    //init_input(vdst0, vdst1, vdst2, vdst3, vdst4, vdst5, vdst6, vdst7);

    dump(vdst0, vdst1, vdst2, vdst3, vdst4, vdst5, vdst6, vdst7, "carotene, int");
    
    // == 8x8 matrix transpose ==
    {
        AutoTimer timer("carotene");//, g_loop_count);
        //for (int i = 0; i < g_loop_count; i++)
        //{
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

            vst1q_u8(buf +  0, (uint8x16_t)vq2q0t.val[0]);
            vst1q_u8(buf + 16, (uint8x16_t)vq3q1t.val[0]);
            vst1q_u8(buf + 32, (uint8x16_t)vq2q0t.val[1]);
            vst1q_u8(buf + 48, (uint8x16_t)vq3q1t.val[1]);
        //}
    }

    vdst0 = vld1_u8(buf);
    vdst1 = vld1_u8(buf + 8);
    vdst2 = vld1_u8(buf + 16);
    vdst3 = vld1_u8(buf + 24);
    vdst4 = vld1_u8(buf + 32);
    vdst5 = vld1_u8(buf + 40);
    vdst6 = vld1_u8(buf + 48);
    vdst7 = vld1_u8(buf + 56);
    dump(vdst0, vdst1, vdst2, vdst3, vdst4, vdst5, vdst6, vdst7, "carotene, end");
}

void transpose_plain()
{
    uint8_t buf[64];

    uint8x8_t d0; // = {11, 12, 13, 14, 15, 16, 17, 18};
    uint8x8_t d1; // = {21, 22, 23, 24, 25, 26, 27, 28};
    uint8x8_t d2; // = {31, 32, 33, 34, 35, 36, 37, 38};
    uint8x8_t d3; // = {41, 42, 43, 44, 45, 46, 47, 48};
    uint8x8_t d4; // = {51, 52, 53, 54, 55, 56, 57, 58};
    uint8x8_t d5; // = {61, 62, 63, 64, 65, 66, 67, 68};
    uint8x8_t d6; // = {71, 72, 73, 74, 75, 76, 77, 78};
    uint8x8_t d7; // = {81, 82, 83, 84, 85, 86, 87, 88};

    init_input(d0, d1, d2, d3, d4, d5, d6, d7);
    dump(d0, d1, d2, d3, d4, d5, d6, d7, "plain, int");

    {
        AutoTimer timer("plain", g_loop_count);
        for (int i = 0; i < g_loop_count; i++)
        {
            // phase1
            uint8x8x2_t d01 = vtrn_u8(d0, d1);
            uint8x8x2_t d23 = vtrn_u8(d2, d3);
            uint8x8x2_t d45 = vtrn_u8(d4, d5);
            uint8x8x2_t d67 = vtrn_u8(d6, d7);

            // phase2
            uint16x4_t v0 = vreinterpret_u16_u8(d01.val[0]);
            uint16x4_t v1 = vreinterpret_u16_u8(d01.val[1]);
            uint16x4_t v2 = vreinterpret_u16_u8(d23.val[0]);
            uint16x4_t v3 = vreinterpret_u16_u8(d23.val[1]);
            uint16x4_t v4 = vreinterpret_u16_u8(d45.val[0]);
            uint16x4_t v5 = vreinterpret_u16_u8(d45.val[1]);
            uint16x4_t v6 = vreinterpret_u16_u8(d67.val[0]);
            uint16x4_t v7 = vreinterpret_u16_u8(d67.val[1]);

            uint16x4x2_t v_tmp;
            v_tmp = vtrn_u16(v0, v2); v0 = v_tmp.val[0]; v2 = v_tmp.val[1];
            v_tmp = vtrn_u16(v1, v3); v1 = v_tmp.val[0]; v3 = v_tmp.val[1];
            v_tmp = vtrn_u16(v4, v6); v4 = v_tmp.val[0]; v6 = v_tmp.val[1];
            v_tmp = vtrn_u16(v5, v7); v5 = v_tmp.val[0]; v7 = v_tmp.val[1];

            // phase3
            uint32x2_t w0 = vreinterpret_u32_u16(v0);
            uint32x2_t w1 = vreinterpret_u32_u16(v1);
            uint32x2_t w2 = vreinterpret_u32_u16(v2);
            uint32x2_t w3 = vreinterpret_u32_u16(v3);
            uint32x2_t w4 = vreinterpret_u32_u16(v4);
            uint32x2_t w5 = vreinterpret_u32_u16(v5);
            uint32x2_t w6 = vreinterpret_u32_u16(v6);
            uint32x2_t w7 = vreinterpret_u32_u16(v7);

            uint32x2x2_t w_tmp;
            w_tmp = vtrn_u32(w0, w4); w0=w_tmp.val[0]; w4=w_tmp.val[1];
            w_tmp = vtrn_u32(w1, w5); w1=w_tmp.val[0]; w5=w_tmp.val[1];
            w_tmp = vtrn_u32(w2, w6); w2=w_tmp.val[0]; w6=w_tmp.val[1];
            w_tmp = vtrn_u32(w3, w7); w3=w_tmp.val[0]; w7=w_tmp.val[1];

            d0 = vreinterpret_u8_u32(w0);
            d1 = vreinterpret_u8_u32(w1);
            d2 = vreinterpret_u8_u32(w2);
            d3 = vreinterpret_u8_u32(w3);
            d4 = vreinterpret_u8_u32(w4);
            d5 = vreinterpret_u8_u32(w5);
            d6 = vreinterpret_u8_u32(w6);
            d7 = vreinterpret_u8_u32(w7);

            vst1_u8(buf +  0, d0);
            vst1_u8(buf +  8, d1);
            vst1_u8(buf + 16, d2);
            vst1_u8(buf + 24, d3);
            vst1_u8(buf + 32, d4);
            vst1_u8(buf + 40, d5);
            vst1_u8(buf + 48, d6);
            vst1_u8(buf + 56, d7);
        }
    }

    dump(d0, d1, d2, d3, d4, d5, d6, d7, "plain, end");
}

// u16 类型的 8x8 方阵 的转置。 用于 carotene 的 linear resize 的改写
void transpose_u16_8x8()
{
    uint16_t buf[64];

    uint16x8_t d0 = {11, 12, 13, 14, 15, 16, 17, 18};
    uint16x8_t d1 = {21, 22, 23, 24, 25, 26, 27, 28};
    uint16x8_t d2 = {31, 32, 33, 34, 35, 36, 37, 38};
    uint16x8_t d3 = {41, 42, 43, 44, 45, 46, 47, 48};
    uint16x8_t d4 = {51, 52, 53, 54, 55, 56, 57, 58};
    uint16x8_t d5 = {61, 62, 63, 64, 65, 66, 67, 68};
    uint16x8_t d6 = {71, 72, 73, 74, 75, 76, 77, 78};
    uint16x8_t d7 = {81, 82, 83, 84, 85, 86, 87, 88};

    dump(d0, d1, d2, d3, d4, d5, d6, d7, "transpose_u16_8x8, int");

    // phase1
    uint16x8x2_t d01 = vtrnq_u16(d0, d1);
    uint16x8x2_t d23 = vtrnq_u16(d2, d3);
    uint16x8x2_t d45 = vtrnq_u16(d4, d5);
    uint16x8x2_t d67 = vtrnq_u16(d6, d7);

    // phase2
    uint32x4_t v0 = vreinterpretq_u32_u16(d01.val[0]);
    uint32x4_t v1 = vreinterpretq_u32_u16(d01.val[1]);
    uint32x4_t v2 = vreinterpretq_u32_u16(d23.val[0]);
    uint32x4_t v3 = vreinterpretq_u32_u16(d23.val[1]);
    uint32x4_t v4 = vreinterpretq_u32_u16(d45.val[0]);
    uint32x4_t v5 = vreinterpretq_u32_u16(d45.val[1]);
    uint32x4_t v6 = vreinterpretq_u32_u16(d67.val[0]);
    uint32x4_t v7 = vreinterpretq_u32_u16(d67.val[1]);

    uint32x4x2_t v_tmp;
    v_tmp = vtrnq_u32(v0, v2); v0 = v_tmp.val[0]; v2 = v_tmp.val[1];
    v_tmp = vtrnq_u32(v1, v3); v1 = v_tmp.val[0]; v3 = v_tmp.val[1];
    v_tmp = vtrnq_u32(v4, v6); v4 = v_tmp.val[0]; v6 = v_tmp.val[1];
    v_tmp = vtrnq_u32(v5, v7); v5 = v_tmp.val[0]; v7 = v_tmp.val[1];

    // phase3
    uint64x2_t w0 = vreinterpretq_u64_u32(v0);
    uint64x2_t w1 = vreinterpretq_u64_u32(v1);
    uint64x2_t w2 = vreinterpretq_u64_u32(v2);
    uint64x2_t w3 = vreinterpretq_u64_u32(v3);
    uint64x2_t w4 = vreinterpretq_u64_u32(v4);
    uint64x2_t w5 = vreinterpretq_u64_u32(v5);
    uint64x2_t w6 = vreinterpretq_u64_u32(v6);
    uint64x2_t w7 = vreinterpretq_u64_u32(v7);

    d0 = vreinterpretq_u16_u64(vcombine_u64(vget_low_u64(w0), vget_low_u64(w4)));
    d1 = vreinterpretq_u16_u64(vcombine_u64(vget_low_u64(w1), vget_low_u64(w5)));
    d2 = vreinterpretq_u16_u64(vcombine_u64(vget_low_u64(w2), vget_low_u64(w6)));
    d3 = vreinterpretq_u16_u64(vcombine_u64(vget_low_u64(w3), vget_low_u64(w7)));
    d4 = vreinterpretq_u16_u64(vcombine_u64(vget_high_u64(w0), vget_high_u64(w4)));
    d5 = vreinterpretq_u16_u64(vcombine_u64(vget_high_u64(w1), vget_high_u64(w5)));
    d6 = vreinterpretq_u16_u64(vcombine_u64(vget_high_u64(w2), vget_high_u64(w6)));
    d7 = vreinterpretq_u16_u64(vcombine_u64(vget_high_u64(w3), vget_high_u64(w7)));

    vst1q_u16(buf +  0, d0);
    vst1q_u16(buf +  8, d1);
    vst1q_u16(buf + 16, d2);
    vst1q_u16(buf + 24, d3);
    vst1q_u16(buf + 32, d4);
    vst1q_u16(buf + 40, d5);
    vst1q_u16(buf + 48, d6);
    vst1q_u16(buf + 56, d7);

    dump(d0, d1, d2, d3, d4, d5, d6, d7, "transpose_u16_8x8, end");
}

int main()
{
    int powersave = 1; // small cores
    ncnn::set_cpu_powersave(powersave);
    // 测试表明， 两种方法的结果是一样的。
    // 新能测试结果不太稳定， 两者基本相当。
    //transpose_carotene();
    //transpose_plain();
    transpose_u16_8x8();

    return 0;
}