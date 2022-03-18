#pragma once

#include <iostream>
#include <arm_neon.h>

std::ostream& operator <<(std::ostream& os, uint8x8_t v_data)
{
    uint8_t data[8];
    vst1_u8(data, v_data);
    for (int i = 0; i < 8; i++) {
        os << (int)data[i] << ", ";
    }
    os << std::endl;
    return os;
}