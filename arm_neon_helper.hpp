#pragma once

#include <iostream>
#include <arm_neon.h>

std::ostream& operator <<(std::ostream& os, uint8x8_t v_data)
{
    uint8_t data[8];
    vst1_u8(data, v_data);
    for (int i = 0; i < 8; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << (int)data[i];
    }
    os << std::endl;
    return os;
}

std::ostream& operator <<(std::ostream& os, float32x4_t v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << v_data[i];
    }
    return os;
}