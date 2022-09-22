#pragma once

#include <iostream>

// neon specific ones
#include <arm_neon.h>

// u8
static
std::ostream& operator <<(std::ostream& os, const uint8x8_t& v_data)
{
    for (int i = 0; i < 8; i++) {
        if (i > 0) os << ", ";
        os << (int)v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const uint8x16_t& v_data)
{
    for (int i = 0; i < 16; i++) {
        if (i > 0) os << ", ";
        os << (int)v_data[i];
    }
    return os;
}

// s8
static
std::ostream& operator <<(std::ostream& os, const int8x8_t& v_data)
{
    for (int i = 0; i < 8; i++) {
        if (i > 0) os << ", ";
        os << (int)v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const int8x16_t& v_data)
{
    for (int i = 0; i < 16; i++) {
        if (i > 0) os << ", ";
        os << (int)v_data[i];
    }
    return os;
}

//u16
static
std::ostream& operator <<(std::ostream& os, const uint16x4_t& v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) os << ", ";
        os << (int)v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const uint16x8_t& v_data)
{
    for (int i = 0; i < 8; i++) {
        if (i > 0) os << ", ";
        os << (int)v_data[i];
    }
    return os;
}

// s16
static
std::ostream& operator <<(std::ostream& os, const int16x4_t& v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const int16x8_t& v_data)
{
    for (int i = 0; i < 8; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

// u32
static
std::ostream& operator <<(std::ostream& os, const uint32x2_t& v_data)
{
    for (int i = 0; i < 2; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const uint32x4_t& v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

// s32
static
std::ostream& operator <<(std::ostream& os, const int32x2_t& v_data)
{
    for (int i = 0; i < 2; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const int32x4_t& v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

// float32
static
std::ostream& operator <<(std::ostream& os, const float32x2_t& v_data)
{
    for (int i = 0; i < 2; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const float32x4_t& v_data)
{
    for (int i = 0; i < 4; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

// uint64
static
std::ostream& operator <<(std::ostream& os, const uint64x1_t& v_data)
{
    for (int i = 0; i < 1; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const uint64x2_t& v_data)
{
    for (int i = 0; i < 2; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

// int64
static
std::ostream& operator <<(std::ostream& os, const int64x1_t& v_data)
{
    for (int i = 0; i < 1; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const int64x2_t& v_data)
{
    for (int i = 0; i < 2; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

// float64
static
std::ostream& operator <<(std::ostream& os, const float64x1_t& v_data)
{
    for (int i = 0; i < 1; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}

static
std::ostream& operator <<(std::ostream& os, const float64x2_t& v_data)
{
    for (int i = 0; i < 2; i++) {
        if (i > 0) os << ", ";
        os << v_data[i];
    }
    return os;
}


/////// print register arrays

// u8
static
std::ostream& operator <<(std::ostream& os, const uint8x8x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}
static
std::ostream& operator <<(std::ostream& os, const uint8x8x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}
static
std::ostream& operator <<(std::ostream& os, const uint8x8x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}
static
std::ostream& operator <<(std::ostream& os, const uint8x16x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}
static
std::ostream& operator <<(std::ostream& os, const uint8x16x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}
static
std::ostream& operator <<(std::ostream& os, const uint8x16x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}


// s8
static
std::ostream& operator <<(std::ostream& os, const int8x8x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const int8x8x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const int8x8x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const int8x16x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const int8x16x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const int8x16x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

// u16
static
std::ostream& operator <<(std::ostream& os, const uint16x4x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const uint16x4x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const uint16x4x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const uint16x8x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const uint16x8x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const uint16x8x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

// s16
static
std::ostream& operator <<(std::ostream& os, const int16x4x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const int16x4x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const int16x4x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const int16x8x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const int16x8x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const int16x8x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

// u32
static
std::ostream& operator <<(std::ostream& os, const uint32x2x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const uint32x2x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const uint32x2x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const uint32x4x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const uint32x4x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const uint32x4x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

// s32
static
std::ostream& operator <<(std::ostream& os, const int32x2x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const int32x2x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const int32x2x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const int32x4x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const int32x4x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const int32x4x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

// f32
static
std::ostream& operator <<(std::ostream& os, const float32x2x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const float32x2x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const float32x2x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const float32x4x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const float32x4x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const float32x4x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

// u64
static
std::ostream& operator <<(std::ostream& os, const uint64x1x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const uint64x1x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const uint64x1x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const uint64x2x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const uint64x2x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const uint64x2x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

// s64
static
std::ostream& operator <<(std::ostream& os, const int64x1x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const int64x1x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const int64x1x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const int64x2x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const int64x2x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const int64x2x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

// f64
#if __aarch64__
static
std::ostream& operator <<(std::ostream& os, const float64x1x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const float64x1x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const float64x1x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}

static
std::ostream& operator <<(std::ostream& os, const float64x2x2_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1];
}

static
std::ostream& operator <<(std::ostream& os, const float64x2x3_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2];
}

static
std::ostream& operator <<(std::ostream& os, const float64x2x4_t& v_data)
{
    return os << v_data.val[0] << std::endl << v_data.val[1] << std::endl << v_data.val[2] << std::endl << v_data.val[3];
}
#endif // __aarch64__
