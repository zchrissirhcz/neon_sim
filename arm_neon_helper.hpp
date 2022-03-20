#pragma once

#include <iostream>

// neon specific ones
#include <arm_neon.h>
std::ostream& operator <<(std::ostream& os, uint8x8_t v_data)
{
    for (int i = 0; i < 8; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << (int)v_data[i];
    }
    return os;
}

std::ostream& operator <<(std::ostream& os, uint8x16_t v_data)
{
    for (int i = 0; i < 16; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << (int)v_data[i];
    }
    return os;
}

std::ostream& operator <<(std::ostream& os, uint16x8_t v_data)
{
    for (int i = 0; i < 8; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << (int)v_data[i];
    }
    return os;
}

std::ostream& operator <<(std::ostream& os, int16x8_t v_data)
{
    for (int i = 0; i < 8; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << v_data[i];
    }
    return os;
}

std::ostream& operator <<(std::ostream& os, int16x4_t v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << v_data[i];
    }
    return os;
}

std::ostream& operator <<(std::ostream& os, uint16x4_t v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << v_data[i];
    }
    return os;
}

std::ostream& operator <<(std::ostream& os, uint32x4_t v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << v_data[i];
    }
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


// general ones
std::ostream& operator <<(std::ostream& os, uint8x8x2_t v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

std::ostream& operator <<(std::ostream& os, uint16x8x2_t v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

std::ostream& operator <<(std::ostream& os, uint32x4x2_t v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}