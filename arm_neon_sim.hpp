#pragma once

//----------------------------------------------------------------------
// 1. vector register type definition
//----------------------------------------------------------------------
#include <iostream>
#include <array>
#include <stdint.h>
#include <math.h> // fabs
#include <limits.h> // INT_MAX

typedef float float32_t;
typedef double float64_t;

template<class T, size_t N>
struct TxN;

template<class T, size_t N>
std::ostream& operator <<(std::ostream& os, TxN<T,N> const& t);

/// @brief Template class for VectorRegister
/// https://stackoverflow.com/questions/68427709/use-of-overloaded-operator-is-ambiguous
template<class T, size_t N>
struct TxN
{
    T val[N];

    TxN() = default;

    T& operator[](size_t i)
    {
        return val[i];
    }

    T const& operator[](size_t i) const
    {
        return val[i];
    }

    size_t size() const
    {
        return N;
    }

    // there are at least three different ways to do this operator, but
    //  this is the easiest, so I included below.
    friend std::ostream& operator <<(std::ostream& os, const TxN<T,N>& t)
    {
        if (typeid(t.val[0]) == typeid(int8_t))
        {
            os << static_cast<int>(t.val[0]);
        }
        else if (typeid(t.val[0]) == typeid(uint8_t))
        {
            os << static_cast<unsigned int>(t.val[0]);
        }
        else
        {
            os << t.val[0];
        }
        for (size_t i=1; i<N; ++i)
        {
            if (typeid(t.val[i]) == typeid(int8_t))
            {
                os << ',' << static_cast<int>(t.val[i]);
            }
            else if (typeid(t.val[i]) == typeid(uint8_t))
            {
                os << ',' << static_cast<unsigned int>(t.val[i]);
            }
            else
            {
                os << ',' << t.val[i];
            }
        }
        return os;
    }
};


//typedef unsigned short __fp16; // from ncnn.

/// @brief Vector Register DataTypes
// D Vector Registers. 64 bit long
using int8x8_t = TxN<int8_t, 8>;
using int16x4_t = TxN<int16_t, 4>;
using int32x2_t = TxN<int32_t, 2>;
using int64x1_t = TxN<int64_t, 1>;

using uint8x8_t = TxN<uint8_t, 8>;
using uint16x4_t = TxN<uint16_t, 4>;
using uint32x2_t = TxN<uint32_t, 2>;
using uint64x1_t = TxN<uint64_t, 1>;

using float16x4_t = TxN<__fp16, 4>;
using float32x2_t = TxN<float, 2>;
using float64x1_t = TxN<double, 1>;

// Q Vector Registers. 128 bit long
using int8x16_t = TxN<int8_t, 16>;
using int16x8_t = TxN<int16_t, 8>;
using int32x4_t = TxN<int32_t, 4>;
using int64x2_t = TxN<int64_t, 2>;

using uint8x16_t = TxN<uint8_t, 16>;
using uint16x8_t = TxN<uint16_t, 8>;
using uint32x4_t = TxN<uint32_t, 4>;
using uint64x2_t = TxN<uint64_t, 2>;

using float16x8_t = TxN<__fp16, 8>;
using float32x4_t = TxN<float, 4>;
using float64x2_t = TxN<double, 2>;


//----------------------------------------------------------------------
// 2. Intrinsics implementation
//----------------------------------------------------------------------

// Load
uint8x8_t vld1_u8(uint8_t const* ptr)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = ptr[i];
    }
    return r;
}

uint8x16_t vld1q_u8(uint8_t const* ptr)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++) {
        r[i] = ptr[i];
    }
    return r;
}

uint16x8_t vld1q_u16(uint16_t const* ptr)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = ptr[i];
    }
    return r;
}

uint32x4_t vld1q_u32(uint32_t const * ptr)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = ptr[i];
    }
    return r;
}


// Store
void vst1_u8(uint8_t* ptr, uint8x8_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[i] = val[i];
    }
}

void vst1q_u8(uint8_t* ptr, uint8x16_t val)
{
    for (int i = 0; i < 16; i++) {
        ptr[i] = val[i];
    }
}

void vst1q_u16(uint16_t* ptr, uint16x8_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[i] = val[i];
    }
}

void vst1q_u32(uint32_t* ptr, uint32x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[i] = val[i];
    }
}

// Vector Arithmetic
uint8x8_t vadd_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint16x8_t vaddl_u8(uint8x8_t a, uint8x8_t b)
{
    uint16x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = (uint16_t)(a[i]) + (uint16_t)(b[i]);
    }
    return D;
}

uint16x8_t vaddw_u8(uint16x8_t a, uint8x8_t b)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] + (uint16_t)(b[i]);
    }
    return r;
}

uint8x8_t vqadd_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8_t r;
    for (int i=0; i<8; i++)
    {
        uint16_t temp = (uint16_t)a[i] + (uint16_t)b[i];
        if (temp > UINT8_MAX) {
            r[i] = UINT8_MAX;
        }
        else {
            r[i] = temp;
        }
    }
    return r;
}

uint8x8_t vsub_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}


uint8x8_t vqsub_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (size_t i=0; i<8; i++)
    {
        int16_t temp = (int16_t)N[i] - (int16_t)M[i];
        if (temp > UINT8_MAX) {
            D[i] = UINT8_MAX;
        }
        else if (temp < 0) {
            D[i] = 0;
        }
        else {
            D[i] = temp;
        }
    }
    return D;
}

uint32x4_t vmulq_n_u32(uint32x4_t N, uint32_t M)
{
    uint32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

// Vector manipulation 
uint8x16_t vdupq_n_u8(uint8_t value)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++) {
        r[i] = value;
    }
    return r;
}

uint8x16_t vqsubq_u8(uint8x16_t a, uint8x16_t b)
{
    uint8x16_t D;
    for (size_t i=0; i<16; i++)
    {
        int16_t temp = (int16_t)a[i] - (int16_t)b[i];
        if (temp > UINT8_MAX) {
            D[i] = UINT8_MAX;
        }
        else if (temp < 0) {
            D[i] = 0;
        }
        else {
            D[i] = temp;
        }
    }
    return D;
}

//----------------------------------------------------------------------
// 3. Helper functions
//----------------------------------------------------------------------