#include <stdio.h>
#if __ARM_NEON
#include <arm_neon.h>
#else
#include "NEON_2_SSE.h"
#endif

int main()
{
    uint16_t cols[8];
    //uint8x8_t vsrc0l1 = vld1_u8(cols);

    return 0;
}