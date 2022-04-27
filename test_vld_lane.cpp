#define NEON_SIM_IMPLEMENTATION

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

// static
// std::ostream& operator <<(std::ostream& os, const uint8x8_t& v_data)
// {
//     for (int i = 0; i < 8; i++) {
//         if (i > 0) os << ", ";
//         os << (int)v_data[i];
//     }
//     return os;
// }


// // u8
// static
// std::ostream& operator <<(std::ostream& os, const uint8x8x2_t& v_data)
// {
//     return os << v_data.val[0] << std::endl << v_data.val[1];
// }

int main()
{
    uint8_t Sp[8] = {10, 11, 12, 13, 41, 51, 61, 71};

    //int xofsp[8] = {21, 23, 25, 27, 22, 24, 26, 28};
 
    // vld2_lane_u8	(uint8_t const * ptr, uint8x8x2_t src, const int lane)
    // lane: [0, 7]

    
    uint8x8_t v0 = {2, 3, 4, 5, 6, 7, 8, 9};
    uint8x8_t v1 = {11, 12, 13, 14, 15, 16, 17, 18};
    uint8x8x2_t _a0a1;
    _a0a1.val[0] = v0;
    _a0a1.val[1] = v1;

    uint8x8x2_t _b0b1;

    _b0b1 = vld2_lane_u8(Sp, _a0a1, 5);
    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 1);
    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 2);
    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 3);
    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 4);
    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 5);
    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 6);
    // _a0a1 = vld2_lane_u8(Sp, _a0a1, 7);

    std::cout << "_a0a1:\n" << _a0a1 << std::endl;
    std::cout << "_b0b1:\n" << _b0b1 << std::endl;


    uint8x8_t src = {7, 6, 5, 4, 1, 2, 3, 0};
    uint8x8_t w1 = vld1_lane_u8(Sp, src, 2);
    std::cout << "w1:" << w1 << std::endl;
    
    return 0;
}