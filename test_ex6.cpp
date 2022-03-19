#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

void transpose_trick()
{
    // dA = A0 A1 A2 A3 A4 A5 A6 A7
    // dB = B0 B1 B2 B3 B4 B5 B6 B7
    // dC = C0 C1 C2 C3 C4 C5 C6 C7
    // dD = D0 D1 D2 D3 D4 D5 D6 D7
    // dE = E0 E1 E2 E3 E4 E5 E6 E7
    // dF = F0 F1 F2 F3 F4 F5 F6 F7
    // dG = G0 G1 G2 G3 G4 G5 G6 G7
    // dH = H0 H1 H2 H3 H4 H5 H6 H7
    const uint8_t data[] = {
        10, 11, 12, 13, 14, 15, 16, 17,// 18,
        20, 21, 22, 23, 24, 25, 26, 27,// 28,
        30, 31, 32, 33, 34, 35, 36, 37,// 38,
        40, 41, 42, 43, 44, 45, 46, 47,// 48,
        50, 51, 52, 53, 54, 55, 56, 57,// 58,
        60, 61, 62, 63, 64, 65, 66, 67,// 68,
        70, 71, 72, 73, 74, 75, 76, 77,// 78,
        80, 81, 82, 83, 84, 85, 86, 87,// 88
    };

    uint8x8_t dA = vld1_u8(data + 0);
    uint8x8_t dB = vld1_u8(data + 8);
    uint8x8_t dC = vld1_u8(data + 16);
    uint8x8_t dD = vld1_u8(data + 24);
    uint8x8_t dE = vld1_u8(data + 32);
    uint8x8_t dF = vld1_u8(data + 40);
    uint8x8_t dG = vld1_u8(data + 48);
    uint8x8_t dH = vld1_u8(data + 56);

    //如何生成如下的内存布局
    // A0, B0, C0, D0, E0, F0, G0, H0, 
    // A1, B1, C1, D1, E1, F1, G1, H1,
    // A2, B2, C2, D2, E2, F2, G2, H2, 
    // A3, B3, C3, D3, E3, F3, G3, H3,
    // A4, B4, C4, D4, E4, F4, G4, H4, 
    // A5, B5, C5, D5, E5, F5, G5, H5,
    // A6, B6, C6, D6, E6, F6, G6, H6, 
    // A7, B7, C7, D7, E7, F7, G7, H7
    

    //首先vtrn_u8(dA, dB)，生成uint8x8x2_t
    uint8x8x2_t qAB = vtrn_u8(dA, dB);
    // std::cout << qAB.val[0] << std::endl;
    // std::cout << qAB.val[1] << std::endl;
    std::cout << "qAB:\n" << qAB << std::endl;
    // qAB = 
    // A0 B0 A2 B2 A4 B4 A6 B6
    // A1 B1 A3 B3 A5 B5 A7 B7

    //同理依次处理C, D, E, F, G, H, 如下
    uint8x8x2_t qCD = vtrn_u8(dC, dD);
    std::cout << "qCD:\n" << qCD << std::endl;
    // qCD = 
    // C0 D0 C2 D2 C4 D4 C6 D6
    // C1 D1 C3 D3 C5 D5 C7 D7

    uint8x8x2_t qEF = vtrn_u8(dE, dF);
    std::cout << "qEF:\n" << qEF << std::endl;
    // qEF = 
    // E0 F0 E2 F2 E4 F4 E6 F6
    // E1 F1 E3 F3 E5 F5 E7 F7

    uint8x8x2_t qGH = vtrn_u8(dG, dH);
    std::cout << "qGH:\n" << qGH << std::endl;
    // qGH = 
    // G0 H0 G2 H2 G4 H4 G6 H6
    // G1 H1 G3 H3 G5 H5 G7 H7

    std::cout << "   " << std::endl;

    //然后给uint8x8x2_t的向量combine，得到uint8x16_t，如下：
    uint8x16_t qcAB = vcombine_u8(qAB.val[0], qAB.val[1]);
    std::cout << "qcAB:\n" << qcAB << std::endl;
    // qcAB = 
    // A0 B0 A2 B2 A4 B4 A6 B6 A1 B1 A3 B3 A5 B5 A7 B7 

    //同理
    uint8x16_t qcCD = vcombine_u8(qCD.val[0], qCD.val[1]);
    std::cout << "qcCD:\n" << qcCD << std::endl;
    // qcCD = 
    // C0 D0 C2 D2 C4 D4 C6 D6 C1 D1 C3 D3 C5 D5 C7 D7

    uint8x16_t qcEF = vcombine_u8(qEF.val[0], qEF.val[1]);
    std::cout << "qcEF:\n" << qcEF << std::endl;
    // qcEF = 
    // E0 F0 E2 F2 E4 F4 E6 F6 E1 F1 E3 F3 E5 F5 E7 F7

    uint8x16_t qcGH = vcombine_u8(qGH.val[0], qGH.val[1]);
    std::cout << "qcGH:\n" << qcGH << std::endl;
    // qcGH = 
    // G0 H0 G2 H2 G4 H4 G6 H6 G1 H1 G3 H3 G5 H5 G7 H7

    std::cout << "   " << std::endl;

    //再vtrnq_u16(qcAB, qcCD)，得到uint16x8x2_t如下
    //uint16x8x2_t qABCD = vtrnq_u16((uint16x8_t)qcAB, (uint16x8_t)qcCD);
    uint16x8x2_t qABCD = vtrnq_u16(qcAB, qcCD);
    std::cout << "qABCD:\n" << (uint8x16_t)qABCD.val[0] << std::endl << (uint8x16_t)qABCD.val[1] << std::endl;
    // uint16x8x2_t qABCD = 
    // A0 B0 C0 D0 A4 B4 C4 D4 A1 B1 C1 D1 A5 B5 C5 D5 
    // A2 B2 C2 D2 A6 B6 C6 D6 A3 B3 C3 D3 A7 B7 C7 D7

    //同理
    uint16x8x2_t qEFGH = vtrnq_u16(qcEF, qcGH);
    std::cout << "qEFGH:\n" << (uint8x16_t)qEFGH.val[0] << std::endl << (uint8x16_t)qEFGH.val[1] << std::endl;
    // uint16x8x2_t qEFGH = 
    // E0 F0 G0 H0 E4 F4 G4 H4 E1 F1 G1 H1 E5 F5 G5 H5
    // E2 F2 G2 H2 E6 F6 G6 H6 E3 F3 G3 H3 E7 F7 G7 H7

    std::cout << "   " << std::endl;

    //再vtrn_u32(qABCD.val[0], qEFGH.val[0])得到uint32x4x2_t如下:
    uint32x4x2_t qq1 = vtrnq_u32(qABCD.val[0], qEFGH.val[0]);
    std::cout << "qq1:\n" << (uint8x16_t)qq1.val[0] << std::endl << (uint8x16_t)qq1.val[1] << std::endl;
    // uint32x4_t qq1 = 
    // A0 B0 C0 D0 E0 F0 G0 H0 A1 B1 C1 D1 E1 F1 G1 H1
    // A4 B4 C4 D4 E4 F4 G4 H4 A5 B5 C5 D5 E5 F5 G5 H5

    uint32x4x2_t qq2 = vtrnq_u32(qABCD.val[1], qEFGH.val[1]);
    std::cout << "qq2:\n" << (uint8x16_t)qq2.val[0] << std::endl << (uint8x16_t)qq2.val[1] << std::endl;
    // uint32x4_t qq2 = 
    // A2 B2 C2 D2 E2 F2 G2 H2 A3 B3 C3 D3 E3 F3 G3 H3
    // A6 B6 C6 D6 E6 F6 G6 H6 A7 B7 C7 D7 E7 F7 G7 H7

    // 再分别存储qq1.val[0]，qq2.val[0]，qq1.val[1]，qq2.val[1]，如下：
    uint8_t res[64];
    vst1q_u8(res + 0,  (uint8x16_t)qq1.val[0]);
    vst1q_u8(res + 16, (uint8x16_t)qq2.val[0]);
    vst1q_u8(res + 32, (uint8x16_t)qq1.val[1]);
    vst1q_u8(res + 48, (uint8x16_t)qq2.val[1]);
    // A0 B0 C0 D0 E0 F0 G0 H0 A1 B1 C1 D1 E1 F1 G1 H1
    // A2 B2 C2 D2 E2 F2 G2 H2 A3 B3 C3 D3 E3 F3 G3 H3
    // A4 B4 C4 D4 E4 F4 G4 H4 A5 B5 C5 D5 E5 F5 G5 H5
    // A6 B6 C6 D6 E6 F6 G6 H6 A7 B7 C7 D7 E7 F7 G7 H7

    std::cout << "\n" << "transposed result is:" << std::endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //std::cout << (int)res[i*8+j] << ", ";
            fprintf(stdout, "%8d, ", res[i*8+j]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void vmovn_example()
{
    // int16x8_t q = [K0 K0 K2 K2 K4 K4 K6 K6] 输出d = [K0 K2 K4 K6] vmovn_s32(q)即可
    int16x8_t q = {0, 0, 2, 2, 4, 4, 6, 6};
    int16x4_t d = vmovn_s32(q);
    std::cout << "q: " << q << std::endl;
    std::cout << "d: " << d << std::endl;
}

void alpha_example()
{
    //5, 对于3通道的alpha，如下K0K1 K0K1 K0K1 K2K3 K2K3 K2K3这样的，每个像素都对应两个short，一个通道3个像素，这3个像素的k都是一样的。 
    // 如果要取两个向量分别是{K0 K2 K0 K2}和{K1 K3 K1 K3}，只要加载alpha时往后偏一个像素，
    int16_t alpha[] = {0,1, 0,1, 0,1, 2,3, 2,3, 2,3};
    int dx = 0;
    int16x8_t dalpha = vld1q_s16(alpha + dx * 2 + 2);// K0 K1 K0 K1 K2 K3 K2 K3
    int16x4x2_t das = vtrn_s16(vget_low_s16(dalpha), vget_high_s16(dalpha));
    int16x4_t da0 = das.val[0];// K0 K2 K0 K2
    int16x4_t da1 = das.val[1];// K1 K3 K1 K3

    std::cout << "da0: " << da0 << std::endl;
    std::cout << "da1: " << da1 << std::endl;
}

// // TODO:
// void alpha_by_lut_example()
// {
//     int16_t alpha[] = {0,1, 0,1, 0,1, 2,3, 2,3, 2,3};
//     int dx = 0;
//     int16x8_t dalpha = vld1q_s16(alpha + dx * 2 + 2);// K0 K1 K0 K1 K2 K3 K2 K3

//     uint8_t offset2[] = {
//         0, 1, 4, 5, 2, 3, 6, 7
//     };
//     uint8x8_t doff2 = vld1_u8(offset2);

//     uint16x4_t dt0 = vtbl1_u8(dalpha, doff2);// K0 K2 K1 K3
//     uint16x4_t dt1 = vrev64_s32(dt0); // K1 K3 K0 K2
//     uint16x4_t da0 = vext_u16(dt1, dt0, 2);// K0 K2 K0 K2
//     uint16x4_t da1 = vext_u16(dt0, dt1, 2);// K1 K3 K1 K3
// }

int main()
{
    //transpose_trick();
    //vmovn_example();
    alpha_example();
    //alpha_by_lut_example();

    return 0;
}