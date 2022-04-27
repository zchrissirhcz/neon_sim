#pragma once

//
// usage:
// #define NEON_SIM_IMPLEMENTATION
//
// #if __ARM_NEON
// #include <arm_neon.h>
// #include "arm_neon_helper.hpp"
// #else
// #include "arm_neon_sim.hpp"
// #endif

//----------------------------------------------------------------------
// 1. vector register type definition
//----------------------------------------------------------------------
#include <iostream>
#include <array>
#include <stdint.h>
#include <string.h>
#include <math.h> // fabs
#include <limits.h> // INT_MAX

#define __ARM_NEON 1
#define __aarch64__ 1

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

    TxN() {
        for (int i = 0; i < N; i++) {
            val[i] = 0;
        }
    }

    //! braced-init-list
    TxN(std::initializer_list<T> init)//: size_(init.size()), capacity_(init.size())
    {
        if (init.size() != N) {
            abort();
        }
        typename std::initializer_list<T>::iterator it = init.begin();
        for (int i = 0; i < init.size(); i++) {
            val[i] = *it;
            it ++;
        }
    }


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

    // type operator
    template<typename T2, size_t N2>
    operator TxN<T2, N2>()
    {
        if (sizeof(T)*N == sizeof(T2)*N2) {
            TxN<T2, N2> obj;
            memcpy(obj.val, val, sizeof(T)*N);
            return obj;
        }
        abort();
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
                os << ", " << static_cast<int>(t.val[i]);
            }
            else if (typeid(t.val[i]) == typeid(uint8_t))
            {
                os << ", " << static_cast<unsigned int>(t.val[i]);
            }
            else
            {
                os << ", " << t.val[i];
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


//-------
//vector register arary types
//-------
typedef struct int8x8x2_t {
  int8x8_t val[2];
} int8x8x2_t;

typedef struct int8x16x2_t {
  int8x16_t val[2];
} int8x16x2_t;

typedef struct int16x4x2_t {
  int16x4_t val[2];
} int16x4x2_t;

typedef struct int16x8x2_t {
  int16x8_t val[2];
} int16x8x2_t;

typedef struct int32x2x2_t {
  int32x2_t val[2];
} int32x2x2_t;

typedef struct int32x4x2_t {
  int32x4_t val[2];
} int32x4x2_t;

typedef struct int64x1x2_t {
  int64x1_t val[2];
} int64x1x2_t;

typedef struct int64x2x2_t {
  int64x2_t val[2];
} int64x2x2_t;

typedef struct uint8x8x2_t {
  uint8x8_t val[2];
} uint8x8x2_t;

typedef struct uint8x16x2_t {
  uint8x16_t val[2];
} uint8x16x2_t;

typedef struct uint16x4x2_t {
  uint16x4_t val[2];
} uint16x4x2_t;

typedef struct uint16x8x2_t {
  uint16x8_t val[2];
} uint16x8x2_t;

typedef struct uint32x2x2_t {
  uint32x2_t val[2];
} uint32x2x2_t;

typedef struct uint32x4x2_t {
  uint32x4_t val[2];
} uint32x4x2_t;

typedef struct uint64x1x2_t {
  uint64x1_t val[2];
} uint64x1x2_t;

typedef struct uint64x2x2_t {
  uint64x2_t val[2];
} uint64x2x2_t;

typedef struct float16x4x2_t {
  float16x4_t val[2];
} float16x4x2_t;

typedef struct float16x8x2_t {
  float16x8_t val[2];
} float16x8x2_t;

typedef struct float32x2x2_t {
  float32x2_t val[2];
} float32x2x2_t;

typedef struct float32x4x2_t {
  float32x4_t val[2];
} float32x4x2_t;

#ifdef __aarch64__
typedef struct float64x1x2_t {
  float64x1_t val[2];
} float64x1x2_t;

typedef struct float64x2x2_t {
  float64x2_t val[2];
} float64x2x2_t;

#endif

typedef struct int8x8x3_t {
  int8x8_t val[3];
} int8x8x3_t;

typedef struct int8x16x3_t {
  int8x16_t val[3];
} int8x16x3_t;

typedef struct int16x4x3_t {
  int16x4_t val[3];
} int16x4x3_t;

typedef struct int16x8x3_t {
  int16x8_t val[3];
} int16x8x3_t;

typedef struct int32x2x3_t {
  int32x2_t val[3];
} int32x2x3_t;

typedef struct int32x4x3_t {
  int32x4_t val[3];
} int32x4x3_t;

typedef struct int64x1x3_t {
  int64x1_t val[3];
} int64x1x3_t;

typedef struct int64x2x3_t {
  int64x2_t val[3];
} int64x2x3_t;

typedef struct uint8x8x3_t {
  uint8x8_t val[3];
} uint8x8x3_t;

typedef struct uint8x16x3_t {
  uint8x16_t val[3];
} uint8x16x3_t;

typedef struct uint16x4x3_t {
  uint16x4_t val[3];
} uint16x4x3_t;

typedef struct uint16x8x3_t {
  uint16x8_t val[3];
} uint16x8x3_t;

typedef struct uint32x2x3_t {
  uint32x2_t val[3];
} uint32x2x3_t;

typedef struct uint32x4x3_t {
  uint32x4_t val[3];
} uint32x4x3_t;

typedef struct uint64x1x3_t {
  uint64x1_t val[3];
} uint64x1x3_t;

typedef struct uint64x2x3_t {
  uint64x2_t val[3];
} uint64x2x3_t;

typedef struct float16x4x3_t {
  float16x4_t val[3];
} float16x4x3_t;

typedef struct float16x8x3_t {
  float16x8_t val[3];
} float16x8x3_t;

typedef struct float32x2x3_t {
  float32x2_t val[3];
} float32x2x3_t;

typedef struct float32x4x3_t {
  float32x4_t val[3];
} float32x4x3_t;

#ifdef __aarch64__
typedef struct float64x1x3_t {
  float64x1_t val[3];
} float64x1x3_t;

typedef struct float64x2x3_t {
  float64x2_t val[3];
} float64x2x3_t;

#endif

typedef struct int8x8x4_t {
  int8x8_t val[4];
} int8x8x4_t;

typedef struct int8x16x4_t {
  int8x16_t val[4];
} int8x16x4_t;

typedef struct int16x4x4_t {
  int16x4_t val[4];
} int16x4x4_t;

typedef struct int16x8x4_t {
  int16x8_t val[4];
} int16x8x4_t;

typedef struct int32x2x4_t {
  int32x2_t val[4];
} int32x2x4_t;

typedef struct int32x4x4_t {
  int32x4_t val[4];
} int32x4x4_t;

typedef struct int64x1x4_t {
  int64x1_t val[4];
} int64x1x4_t;

typedef struct int64x2x4_t {
  int64x2_t val[4];
} int64x2x4_t;

typedef struct uint8x8x4_t {
  uint8x8_t val[4];
} uint8x8x4_t;

typedef struct uint8x16x4_t {
  uint8x16_t val[4];
} uint8x16x4_t;

typedef struct uint16x4x4_t {
  uint16x4_t val[4];
} uint16x4x4_t;

typedef struct uint16x8x4_t {
  uint16x8_t val[4];
} uint16x8x4_t;

typedef struct uint32x2x4_t {
  uint32x2_t val[4];
} uint32x2x4_t;

typedef struct uint32x4x4_t {
  uint32x4_t val[4];
} uint32x4x4_t;

typedef struct uint64x1x4_t {
  uint64x1_t val[4];
} uint64x1x4_t;

typedef struct uint64x2x4_t {
  uint64x2_t val[4];
} uint64x2x4_t;

typedef struct float16x4x4_t {
  float16x4_t val[4];
} float16x4x4_t;

typedef struct float16x8x4_t {
  float16x8_t val[4];
} float16x8x4_t;

typedef struct float32x2x4_t {
  float32x2_t val[4];
} float32x2x4_t;

typedef struct float32x4x4_t {
  float32x4_t val[4];
} float32x4x4_t;

#ifdef __aarch64__
typedef struct float64x1x4_t {
  float64x1_t val[4];
} float64x1x4_t;

typedef struct float64x2x4_t {
  float64x2_t val[4];
} float64x2x4_t;

#endif

//----------------------------------------------------------------------
// 2. Load & Store
//----------------------------------------------------------------------

// vld1_type
int8x8_t	vld1_s8	(int8_t const * ptr);
int16x4_t	vld1_s16	(int16_t const * ptr);
int32x2_t	vld1_s32	(int32_t const * ptr);
int64x1_t	vld1_s64	(int64_t const * ptr);
uint8x8_t	vld1_u8	(uint8_t const * ptr);
uint16x4_t	vld1_u16	(uint16_t const * ptr);
uint32x2_t	vld1_u32	(uint32_t const * ptr);
uint64x1_t	vld1_u64	(uint64_t const * ptr);
float32x2_t	vld1_f32	(float32_t const * ptr);
float64x1_t	vld1_f64	(float64_t const * ptr);

// vld1q_type
int8x16_t	vld1q_s8	(int8_t const * ptr);
int16x8_t	vld1q_s16	(int16_t const * ptr);
int32x4_t	vld1q_s32	(int32_t const * ptr);
int64x2_t	vld1q_s64	(int64_t const * ptr);
uint8x16_t	vld1q_u8	(uint8_t const * ptr);
uint16x8_t	vld1q_u16	(uint16_t const * ptr);
uint32x4_t	vld1q_u32	(uint32_t const * ptr);
uint64x2_t	vld1q_u64	(uint64_t const * ptr);
float32x4_t	vld1q_f32	(float32_t const * ptr);
float64x2_t	vld1q_f64	(float64_t const * ptr);

// vld1_lane_type
int8x8_t	vld1_lane_s8	(int8_t const * ptr, int8x8_t src, const int lane);
int16x4_t	vld1_lane_s16	(int16_t const * ptr, int16x4_t src, const int lane);
int32x2_t	vld1_lane_s32	(int32_t const * ptr, int32x2_t src, const int lane);
int64x1_t	vld1_lane_s64	(int64_t const * ptr, int64x1_t src, const int lane);
uint8x8_t	vld1_lane_u8	(uint8_t const * ptr, uint8x8_t src, const int lane);
uint16x4_t	vld1_lane_u16	(uint16_t const * ptr, uint16x4_t src, const int lane);
uint32x2_t	vld1_lane_u32	(uint32_t const * ptr, uint32x2_t src, const int lane);
uint64x1_t	vld1_lane_u64	(uint64_t const * ptr, uint64x1_t src, const int lane);
float32x2_t	vld1_lane_f32	(float32_t const * ptr, float32x2_t src, const int lane);
float64x1_t	vld1_lane_f64	(float64_t const * ptr, float64x1_t src, const int lane);

// vld1q_lane_type:
int8x16_t	vld1q_lane_s8	(int8_t const * ptr, int8x16_t src, const int lane);
int16x8_t	vld1q_lane_s16	(int16_t const * ptr, int16x8_t src, const int lane);
int32x4_t	vld1q_lane_s32	(int32_t const * ptr, int32x4_t src, const int lane);
int64x2_t	vld1q_lane_s64	(int64_t const * ptr, int64x2_t src, const int lane);
uint8x16_t	vld1q_lane_u8	(uint8_t const * ptr, uint8x16_t src, const int lane);
uint16x8_t	vld1q_lane_u16	(uint16_t const * ptr, uint16x8_t src, const int lane);
uint32x4_t	vld1q_lane_u32	(uint32_t const * ptr, uint32x4_t src, const int lane);
uint64x2_t	vld1q_lane_u64	(uint64_t const * ptr, uint64x2_t src, const int lane);
float32x4_t	vld1q_lane_f32	(float32_t const * ptr, float32x4_t src, const int lane);
float64x2_t	vld1q_lane_f64	(float64_t const * ptr, float64x2_t src, const int lane);

// vld1_dup_type:
int8x8_t	vld1_dup_s8	(int8_t const * ptr);
int16x4_t	vld1_dup_s16	(int16_t const * ptr);
int32x2_t	vld1_dup_s32	(int32_t const * ptr);
int64x1_t	vld1_dup_s64	(int64_t const * ptr);
uint8x8_t	vld1_dup_u8	(uint8_t const * ptr);
uint16x4_t	vld1_dup_u16	(uint16_t const * ptr);
uint32x2_t	vld1_dup_u32	(uint32_t const * ptr);
uint64x1_t	vld1_dup_u64	(uint64_t const * ptr);
float32x2_t	vld1_dup_f32	(float32_t const * ptr);
float64x1_t	vld1_dup_f64	(float64_t const * ptr);

// vld1q_dup_type:
int8x16_t	vld1q_dup_s8	(int8_t const * ptr);
int16x8_t	vld1q_dup_s16	(int16_t const * ptr);
int32x4_t	vld1q_dup_s32	(int32_t const * ptr);
int64x2_t	vld1q_dup_s64	(int64_t const * ptr);
uint8x16_t	vld1q_dup_u8	(uint8_t const * ptr);
uint16x8_t	vld1q_dup_u16	(uint16_t const * ptr);
uint32x4_t	vld1q_dup_u32	(uint32_t const * ptr);
uint64x2_t	vld1q_dup_u64	(uint64_t const * ptr);
float32x4_t	vld1q_dup_f32	(float32_t const * ptr);
float64x2_t	vld1q_dup_f64	(float64_t const * ptr);

// vld2_type
int8x8x2_t	vld2_s8	(int8_t const * ptr);
int16x4x2_t	vld2_s16	(int16_t const * ptr);
int32x2x2_t	vld2_s32	(int32_t const * ptr);
uint8x8x2_t	vld2_u8	(uint8_t const * ptr);
uint16x4x2_t	vld2_u16	(uint16_t const * ptr);
uint32x2x2_t	vld2_u32	(uint32_t const * ptr);
float32x2x2_t	vld2_f32	(float32_t const * ptr);
int64x1x2_t	vld2_s64	(int64_t const * ptr);
uint64x1x2_t	vld2_u64	(uint64_t const * ptr);
float64x1x2_t	vld2_f64	(float64_t const * ptr);

// vld2q_type
int8x16x2_t	vld2q_s8	(int8_t const * ptr);
int16x8x2_t	vld2q_s16	(int16_t const * ptr);
int32x4x2_t	vld2q_s32	(int32_t const * ptr);
uint8x16x2_t	vld2q_u8	(uint8_t const * ptr);
uint16x8x2_t	vld2q_u16	(uint16_t const * ptr);
uint32x4x2_t	vld2q_u32	(uint32_t const * ptr);
float32x4x2_t	vld2q_f32	(float32_t const * ptr);
int64x2x2_t	vld2q_s64	(int64_t const * ptr);
uint64x2x2_t	vld2q_u64	(uint64_t const * ptr);
float64x2x2_t	vld2q_f64	(float64_t const * ptr);

// vld2_lane_type:
int16x4x2_t	vld2_lane_s16	(int16_t const * ptr, int16x4x2_t src, const int lane);
int32x2x2_t	vld2_lane_s32	(int32_t const * ptr, int32x2x2_t src, const int lane);
uint16x4x2_t	vld2_lane_u16	(uint16_t const * ptr, uint16x4x2_t src, const int lane);
uint32x2x2_t	vld2_lane_u32	(uint32_t const * ptr, uint32x2x2_t src, const int lane);
float32x2x2_t	vld2_lane_f32	(float32_t const * ptr, float32x2x2_t src, const int lane);
int8x8x2_t	vld2_lane_s8	(int8_t const * ptr, int8x8x2_t src, const int lane);
uint8x8x2_t	vld2_lane_u8	(uint8_t const * ptr, uint8x8x2_t src, const int lane);
int64x1x2_t	vld2_lane_s64	(int64_t const * ptr, int64x1x2_t src, const int lane);
uint64x1x2_t	vld2_lane_u64	(uint64_t const * ptr, uint64x1x2_t src, const int lane);
float64x1x2_t	vld2_lane_f64	(float64_t const * ptr, float64x1x2_t src, const int lane);

// vld2q_lane_type:
int16x8x2_t	vld2q_lane_s16	(int16_t const * ptr, int16x8x2_t src, const int lane);
int32x4x2_t	vld2q_lane_s32	(int32_t const * ptr, int32x4x2_t src, const int lane);
uint16x8x2_t	vld2q_lane_u16	(uint16_t const * ptr, uint16x8x2_t src, const int lane);
uint32x4x2_t	vld2q_lane_u32	(uint32_t const * ptr, uint32x4x2_t src, const int lane);
float32x4x2_t	vld2q_lane_f32	(float32_t const * ptr, float32x4x2_t src, const int lane);
int8x16x2_t	vld2q_lane_s8	(int8_t const * ptr, int8x16x2_t src, const int lane);
uint8x16x2_t	vld2q_lane_u8	(uint8_t const * ptr, uint8x16x2_t src, const int lane);
int64x2x2_t	vld2q_lane_s64	(int64_t const * ptr, int64x2x2_t src, const int lane);
uint64x2x2_t	vld2q_lane_u64	(uint64_t const * ptr, uint64x2x2_t src, const int lane);
float64x2x2_t	vld2q_lane_f64	(float64_t const * ptr, float64x2x2_t src, const int lane);

// vld2_dup_type:
int8x8x2_t	vld2_dup_s8	(int8_t const * ptr);
int16x4x2_t	vld2_dup_s16	(int16_t const * ptr);
int32x2x2_t	vld2_dup_s32	(int32_t const * ptr);
uint8x8x2_t	vld2_dup_u8	(uint8_t const * ptr);
uint16x4x2_t	vld2_dup_u16	(uint16_t const * ptr);
uint32x2x2_t	vld2_dup_u32	(uint32_t const * ptr);
float32x2x2_t	vld2_dup_f32	(float32_t const * ptr);
int64x1x2_t	vld2_dup_s64	(int64_t const * ptr);
uint64x1x2_t	vld2_dup_u64	(uint64_t const * ptr);
float64x1x2_t	vld2_dup_f64	(float64_t const * ptr);

// vld3_type
int8x8x3_t	vld3_s8	(int8_t const * ptr);
int16x4x3_t	vld3_s16	(int16_t const * ptr);
int32x2x3_t	vld3_s32	(int32_t const * ptr);
uint8x8x3_t	vld3_u8	(uint8_t const * ptr);
uint16x4x3_t	vld3_u16	(uint16_t const * ptr);
uint32x2x3_t	vld3_u32	(uint32_t const * ptr);
float32x2x3_t	vld3_f32	(float32_t const * ptr);
int64x1x3_t	vld3_s64	(int64_t const * ptr);
uint64x1x3_t	vld3_u64	(uint64_t const * ptr);
float64x1x3_t	vld3_f64	(float64_t const * ptr);

// vld3q_type
int8x16x3_t	vld3q_s8	(int8_t const * ptr);
int16x8x3_t	vld3q_s16	(int16_t const * ptr);
int32x4x3_t	vld3q_s32	(int32_t const * ptr);
uint8x16x3_t	vld3q_u8	(uint8_t const * ptr);
uint16x8x3_t	vld3q_u16	(uint16_t const * ptr);
uint32x4x3_t	vld3q_u32	(uint32_t const * ptr);
float32x4x3_t	vld3q_f32	(float32_t const * ptr);
int64x2x3_t	vld3q_s64	(int64_t const * ptr);
uint64x2x3_t	vld3q_u64	(uint64_t const * ptr);
float64x2x3_t	vld3q_f64	(float64_t const * ptr);

// vld3_lane_type:
int16x4x3_t	vld3_lane_s16	(int16_t const * ptr, int16x4x3_t src, const int lane);
int32x2x3_t	vld3_lane_s32	(int32_t const * ptr, int32x2x3_t src, const int lane);
uint16x4x3_t	vld3_lane_u16	(uint16_t const * ptr, uint16x4x3_t src, const int lane);
uint32x2x3_t	vld3_lane_u32	(uint32_t const * ptr, uint32x2x3_t src, const int lane);
float32x2x3_t	vld3_lane_f32	(float32_t const * ptr, float32x2x3_t src, const int lane);
int8x8x3_t	vld3_lane_s8	(int8_t const * ptr, int8x8x3_t src, const int lane);
uint8x8x3_t	vld3_lane_u8	(uint8_t const * ptr, uint8x8x3_t src, const int lane);
int64x1x3_t	vld3_lane_s64	(int64_t const * ptr, int64x1x3_t src, const int lane);
uint64x1x3_t	vld3_lane_u64	(uint64_t const * ptr, uint64x1x3_t src, const int lane);
float64x1x3_t	vld3_lane_f64	(float64_t const * ptr, float64x1x3_t src, const int lane);

// vld3q_lane_type:
int16x8x3_t	vld3q_lane_s16	(int16_t const * ptr, int16x8x3_t src, const int lane);
int32x4x3_t	vld3q_lane_s32	(int32_t const * ptr, int32x4x3_t src, const int lane);
uint16x8x3_t	vld3q_lane_u16	(uint16_t const * ptr, uint16x8x3_t src, const int lane);
uint32x4x3_t	vld3q_lane_u32	(uint32_t const * ptr, uint32x4x3_t src, const int lane);
float32x4x3_t	vld3q_lane_f32	(float32_t const * ptr, float32x4x3_t src, const int lane);
int8x16x3_t	vld3q_lane_s8	(int8_t const * ptr, int8x16x3_t src, const int lane);
uint8x16x3_t	vld3q_lane_u8	(uint8_t const * ptr, uint8x16x3_t src, const int lane);
int64x2x3_t	vld3q_lane_s64	(int64_t const * ptr, int64x2x3_t src, const int lane);
uint64x2x3_t	vld3q_lane_u64	(uint64_t const * ptr, uint64x2x3_t src, const int lane);
float64x2x3_t	vld3q_lane_f64	(float64_t const * ptr, float64x2x3_t src, const int lane);

// vld3_dup_type:
int8x8x3_t	vld3_dup_s8	(int8_t const * ptr);
int16x4x3_t	vld3_dup_s16	(int16_t const * ptr);
int32x2x3_t	vld3_dup_s32	(int32_t const * ptr);
uint8x8x3_t	vld3_dup_u8	(uint8_t const * ptr);
uint16x4x3_t	vld3_dup_u16	(uint16_t const * ptr);
uint32x2x3_t	vld3_dup_u32	(uint32_t const * ptr);
float32x2x3_t	vld3_dup_f32	(float32_t const * ptr);
int64x1x3_t	vld3_dup_s64	(int64_t const * ptr);
uint64x1x3_t	vld3_dup_u64	(uint64_t const * ptr);
float64x1x3_t	vld3_dup_f64	(float64_t const * ptr);

// vld4_type
int8x8x4_t	vld4_s8	(int8_t const * ptr);
int16x4x4_t	vld4_s16	(int16_t const * ptr);
int32x2x4_t	vld4_s32	(int32_t const * ptr);
uint8x8x4_t	vld4_u8	(uint8_t const * ptr);
uint16x4x4_t	vld4_u16	(uint16_t const * ptr);
uint32x2x4_t	vld4_u32	(uint32_t const * ptr);
float32x2x4_t	vld4_f32	(float32_t const * ptr);
int64x1x4_t	vld4_s64	(int64_t const * ptr);
uint64x1x4_t	vld4_u64	(uint64_t const * ptr);
float64x1x4_t	vld4_f64	(float64_t const * ptr);

// vld4q_type
int8x16x4_t	vld4q_s8	(int8_t const * ptr);
int16x8x4_t	vld4q_s16	(int16_t const * ptr);
int32x4x4_t	vld4q_s32	(int32_t const * ptr);
uint8x16x4_t	vld4q_u8	(uint8_t const * ptr);
uint16x8x4_t	vld4q_u16	(uint16_t const * ptr);
uint32x4x4_t	vld4q_u32	(uint32_t const * ptr);
float32x4x4_t	vld4q_f32	(float32_t const * ptr);
int64x2x4_t	vld4q_s64	(int64_t const * ptr);
uint64x2x4_t	vld4q_u64	(uint64_t const * ptr);
float64x2x4_t	vld4q_f64	(float64_t const * ptr);

// vld4_lane_type:
int16x4x4_t	vld4_lane_s16	(int16_t const * ptr, int16x4x4_t src, const int lane);
int32x2x4_t	vld4_lane_s32	(int32_t const * ptr, int32x2x4_t src, const int lane);
uint16x4x4_t	vld4_lane_u16	(uint16_t const * ptr, uint16x4x4_t src, const int lane);
uint32x2x4_t	vld4_lane_u32	(uint32_t const * ptr, uint32x2x4_t src, const int lane);
float32x2x4_t	vld4_lane_f32	(float32_t const * ptr, float32x2x4_t src, const int lane);
int8x8x4_t	vld4_lane_s8	(int8_t const * ptr, int8x8x4_t src, const int lane);
uint8x8x4_t	vld4_lane_u8	(uint8_t const * ptr, uint8x8x4_t src, const int lane);
int64x1x4_t	vld4_lane_s64	(int64_t const * ptr, int64x1x4_t src, const int lane);
uint64x1x4_t	vld4_lane_u64	(uint64_t const * ptr, uint64x1x4_t src, const int lane);
float64x1x4_t	vld4_lane_f64	(float64_t const * ptr, float64x1x4_t src, const int lane);

// vld4q_lane_type:
int16x8x4_t	vld4q_lane_s16	(int16_t const * ptr, int16x8x4_t src, const int lane);
int32x4x4_t	vld4q_lane_s32	(int32_t const * ptr, int32x4x4_t src, const int lane);
uint16x8x4_t	vld4q_lane_u16	(uint16_t const * ptr, uint16x8x4_t src, const int lane);
uint32x4x4_t	vld4q_lane_u32	(uint32_t const * ptr, uint32x4x4_t src, const int lane);
float32x4x4_t	vld4q_lane_f32	(float32_t const * ptr, float32x4x4_t src, const int lane);
int8x16x4_t	vld4q_lane_s8	(int8_t const * ptr, int8x16x4_t src, const int lane);
uint8x16x4_t	vld4q_lane_u8	(uint8_t const * ptr, uint8x16x4_t src, const int lane);
int64x2x4_t	vld4q_lane_s64	(int64_t const * ptr, int64x2x4_t src, const int lane);
uint64x2x4_t	vld4q_lane_u64	(uint64_t const * ptr, uint64x2x4_t src, const int lane);
float64x2x4_t	vld4q_lane_f64	(float64_t const * ptr, float64x2x4_t src, const int lane);

// vld4q_dup_type: 
int8x16x4_t	vld4q_dup_s8	(int8_t const * ptr);
int16x8x4_t	vld4q_dup_s16	(int16_t const * ptr);
int32x4x4_t	vld4q_dup_s32	(int32_t const * ptr);
uint8x16x4_t	vld4q_dup_u8	(uint8_t const * ptr);
uint16x8x4_t	vld4q_dup_u16	(uint16_t const * ptr);
uint32x4x4_t	vld4q_dup_u32	(uint32_t const * ptr);
float32x4x4_t	vld4q_dup_f32	(float32_t const * ptr);
int64x2x4_t	vld4q_dup_s64	(int64_t const * ptr);
uint64x2x4_t	vld4q_dup_u64	(uint64_t const * ptr);
float64x2x4_t	vld4q_dup_f64	(float64_t const * ptr);

// vst1_type
void	vst1_s8	(int8_t * ptr, int8x8_t val);
void	vst1_s16	(int16_t * ptr, int16x4_t val);
void	vst1_s32	(int32_t * ptr, int32x2_t val);
void	vst1_s64	(int64_t * ptr, int64x1_t val);
void	vst1_u8	(uint8_t * ptr, uint8x8_t val);
void	vst1_u16	(uint16_t * ptr, uint16x4_t val);
void	vst1_u32	(uint32_t * ptr, uint32x2_t val);
void	vst1_u64	(uint64_t * ptr, uint64x1_t val);
void	vst1_f32	(float32_t * ptr, float32x2_t val);
void	vst1_f64	(float64_t * ptr, float64x1_t val);

// vst1q_type
void	vst1q_s8	(int8_t * ptr, int8x16_t val);
void	vst1q_s16	(int16_t * ptr, int16x8_t val);
void	vst1q_s32	(int32_t * ptr, int32x4_t val);
void	vst1q_s64	(int64_t * ptr, int64x2_t val);
void	vst1q_u8	(uint8_t * ptr, uint8x16_t val);
void	vst1q_u16	(uint16_t * ptr, uint16x8_t val);
void	vst1q_u32	(uint32_t * ptr, uint32x4_t val);
void	vst1q_u64	(uint64_t * ptr, uint64x2_t val);
void	vst1q_f32	(float32_t * ptr, float32x4_t val);
void	vst1q_f64	(float64_t * ptr, float64x2_t val);

// vst1_lane_type
void	vst1_lane_s8	(int8_t * ptr, int8x8_t val, const int lane);
void	vst1_lane_s16	(int16_t * ptr, int16x4_t val, const int lane);
void	vst1_lane_s32	(int32_t * ptr, int32x2_t val, const int lane);
void	vst1_lane_s64	(int64_t * ptr, int64x1_t val, const int lane);
void	vst1_lane_u8	(uint8_t * ptr, uint8x8_t val, const int lane);
void	vst1_lane_u16	(uint16_t * ptr, uint16x4_t val, const int lane);
void	vst1_lane_u32	(uint32_t * ptr, uint32x2_t val, const int lane);
void	vst1_lane_u64	(uint64_t * ptr, uint64x1_t val, const int lane);
void	vst1_lane_f32	(float32_t * ptr, float32x2_t val, const int lane);
void	vst1_lane_f64	(float64_t * ptr, float64x1_t val, const int lane);

// vst1q_lane_type
void	vst1q_lane_s8	(int8_t * ptr, int8x16_t val, const int lane);
void	vst1q_lane_s16	(int16_t * ptr, int16x8_t val, const int lane);
void	vst1q_lane_s32	(int32_t * ptr, int32x4_t val, const int lane);
void	vst1q_lane_s64	(int64_t * ptr, int64x2_t val, const int lane);
void	vst1q_lane_u8	(uint8_t * ptr, uint8x16_t val, const int lane);
void	vst1q_lane_u16	(uint16_t * ptr, uint16x8_t val, const int lane);
void	vst1q_lane_u32	(uint32_t * ptr, uint32x4_t val, const int lane);
void	vst1q_lane_u64	(uint64_t * ptr, uint64x2_t val, const int lane);
void	vst1q_lane_f32	(float32_t * ptr, float32x4_t val, const int lane);
void	vst1q_lane_f64	(float64_t * ptr, float64x2_t val, const int lane);

// vst2_type:
void	vst2_s8	(int8_t * ptr, int8x8x2_t val);
void	vst2_s16	(int16_t * ptr, int16x4x2_t val);
void	vst2_s32	(int32_t * ptr, int32x2x2_t val);
void	vst2_u8	(uint8_t * ptr, uint8x8x2_t val);
void	vst2_u16	(uint16_t * ptr, uint16x4x2_t val);
void	vst2_u32	(uint32_t * ptr, uint32x2x2_t val);
void	vst2_f32	(float32_t * ptr, float32x2x2_t val);
void	vst2_s64	(int64_t * ptr, int64x1x2_t val);
void	vst2_u64	(uint64_t * ptr, uint64x1x2_t val);
void	vst2_f64	(float64_t * ptr, float64x1x2_t val);

// vst2q_type:
void	vst2q_s8	(int8_t * ptr, int8x16x2_t val);
void	vst2q_s16	(int16_t * ptr, int16x8x2_t val);
void	vst2q_s32	(int32_t * ptr, int32x4x2_t val);
void	vst2q_u8	(uint8_t * ptr, uint8x16x2_t val);
void	vst2q_u16	(uint16_t * ptr, uint16x8x2_t val);
void	vst2q_u32	(uint32_t * ptr, uint32x4x2_t val);
void	vst2q_f32	(float32_t * ptr, float32x4x2_t val);
void	vst2q_s64	(int64_t * ptr, int64x2x2_t val);
void	vst2q_u64	(uint64_t * ptr, uint64x2x2_t val);
void	vst2q_f64	(float64_t * ptr, float64x2x2_t val);


// vst2_lane_type:
void	vst2_lane_s8	(int8_t * ptr, int8x8x2_t val, const int lane);
void	vst2_lane_u8	(uint8_t * ptr, uint8x8x2_t val, const int lane);
void	vst2_lane_s16	(int16_t * ptr, int16x4x2_t val, const int lane);
void	vst2_lane_s32	(int32_t * ptr, int32x2x2_t val, const int lane);
void	vst2_lane_u16	(uint16_t * ptr, uint16x4x2_t val, const int lane);
void	vst2_lane_u32	(uint32_t * ptr, uint32x2x2_t val, const int lane);
void	vst2_lane_f32	(float32_t * ptr, float32x2x2_t val, const int lane);
void	vst2_lane_s64	(int64_t * ptr, int64x1x2_t val, const int lane);
void	vst2_lane_u64	(uint64_t * ptr, uint64x1x2_t val, const int lane);
void	vst2_lane_f64	(float64_t * ptr, float64x1x2_t val, const int lane);

// vst2q_lane_type:
void	vst2q_lane_s16	(int16_t * ptr, int16x8x2_t val, const int lane);
void	vst2q_lane_s32	(int32_t * ptr, int32x4x2_t val, const int lane);
void	vst2q_lane_u16	(uint16_t * ptr, uint16x8x2_t val, const int lane);
void	vst2q_lane_u32	(uint32_t * ptr, uint32x4x2_t val, const int lane);
void	vst2q_lane_f32	(float32_t * ptr, float32x4x2_t val, const int lane);
void	vst2q_lane_s8	(int8_t * ptr, int8x16x2_t val, const int lane);
void	vst2q_lane_u8	(uint8_t * ptr, uint8x16x2_t val, const int lane);
void	vst2q_lane_s64	(int64_t * ptr, int64x2x2_t val, const int lane);
void	vst2q_lane_u64	(uint64_t * ptr, uint64x2x2_t val, const int lane);
void	vst2q_lane_f64	(float64_t * ptr, float64x2x2_t val, const int lane);

// vst3_type:
void	vst3_s8	(int8_t * ptr, int8x8x3_t val);
void	vst3_s16	(int16_t * ptr, int16x4x3_t val);
void	vst3_s32	(int32_t * ptr, int32x2x3_t val);
void	vst3_u8	(uint8_t * ptr, uint8x8x3_t val);
void	vst3_u16	(uint16_t * ptr, uint16x4x3_t val);
void	vst3_u32	(uint32_t * ptr, uint32x2x3_t val);
void	vst3_f32	(float32_t * ptr, float32x2x3_t val);
void	vst3_s64	(int64_t * ptr, int64x1x3_t val);
void	vst3_u64	(uint64_t * ptr, uint64x1x3_t val);
void	vst3_f64	(float64_t * ptr, float64x1x3_t val);

// vst3q_type
void	vst3q_s8	(int8_t * ptr, int8x16x3_t val);
void	vst3q_s16	(int16_t * ptr, int16x8x3_t val);
void	vst3q_s32	(int32_t * ptr, int32x4x3_t val);
void	vst3q_u8	(uint8_t * ptr, uint8x16x3_t val);
void	vst3q_u16	(uint16_t * ptr, uint16x8x3_t val);
void	vst3q_u32	(uint32_t * ptr, uint32x4x3_t val);
void	vst3q_f32	(float32_t * ptr, float32x4x3_t val);
void	vst3q_s64	(int64_t * ptr, int64x2x3_t val);
void	vst3q_u64	(uint64_t * ptr, uint64x2x3_t val);
void	vst3q_f64	(float64_t * ptr, float64x2x3_t val);

// vst3_lane_type:
void	vst3_lane_s8	(int8_t * ptr, int8x8x3_t val, const int lane);
void	vst3_lane_u8	(uint8_t * ptr, uint8x8x3_t val, const int lane);
void	vst3_lane_s16	(int16_t * ptr, int16x4x3_t val, const int lane);
void	vst3_lane_s32	(int32_t * ptr, int32x2x3_t val, const int lane);
void	vst3_lane_u16	(uint16_t * ptr, uint16x4x3_t val, const int lane);
void	vst3_lane_u32	(uint32_t * ptr, uint32x2x3_t val, const int lane);
void	vst3_lane_f32	(float32_t * ptr, float32x2x3_t val, const int lane);
void	vst3_lane_s64	(int64_t * ptr, int64x1x3_t val, const int lane);
void	vst3_lane_u64	(uint64_t * ptr, uint64x1x3_t val, const int lane);
void	vst3_lane_f64	(float64_t * ptr, float64x1x3_t val, const int lane);

// vst3q_lane_type:
void	vst3q_lane_s16	(int16_t * ptr, int16x8x3_t val, const int lane);
void	vst3q_lane_s32	(int32_t * ptr, int32x4x3_t val, const int lane);
void	vst3q_lane_u16	(uint16_t * ptr, uint16x8x3_t val, const int lane);
void	vst3q_lane_u32	(uint32_t * ptr, uint32x4x3_t val, const int lane);
void	vst3q_lane_f32	(float32_t * ptr, float32x4x3_t val, const int lane);
void	vst3q_lane_s8	(int8_t * ptr, int8x16x3_t val, const int lane);
void	vst3q_lane_u8	(uint8_t * ptr, uint8x16x3_t val, const int lane);
void	vst3q_lane_s64	(int64_t * ptr, int64x2x3_t val, const int lane);
void	vst3q_lane_u64	(uint64_t * ptr, uint64x2x3_t val, const int lane);
void	vst3q_lane_f64	(float64_t * ptr, float64x2x3_t val, const int lane);

// vst4_type
void	vst4_s8	(int8_t * ptr, int8x8x4_t val);
void	vst4_s16	(int16_t * ptr, int16x4x4_t val);
void	vst4_s32	(int32_t * ptr, int32x2x4_t val);
void	vst4_u8	(uint8_t * ptr, uint8x8x4_t val);
void	vst4_u16	(uint16_t * ptr, uint16x4x4_t val);
void	vst4_u32	(uint32_t * ptr, uint32x2x4_t val);
void	vst4_f32	(float32_t * ptr, float32x2x4_t val);
void	vst4_s64	(int64_t * ptr, int64x1x4_t val);
void	vst4_u64	(uint64_t * ptr, uint64x1x4_t val);
void	vst4_f64	(float64_t * ptr, float64x1x4_t val);

// vst4q_type
void	vst4q_s8	(int8_t * ptr, int8x16x4_t val);
void	vst4q_s16	(int16_t * ptr, int16x8x4_t val);
void	vst4q_s32	(int32_t * ptr, int32x4x4_t val);
void	vst4q_u8	(uint8_t * ptr, uint8x16x4_t val);
void	vst4q_u16	(uint16_t * ptr, uint16x8x4_t val);
void	vst4q_u32	(uint32_t * ptr, uint32x4x4_t val);
void	vst4q_f32	(float32_t * ptr, float32x4x4_t val);
void	vst4q_s64	(int64_t * ptr, int64x2x4_t val);
void	vst4q_u64	(uint64_t * ptr, uint64x2x4_t val);
void	vst4q_f64	(float64_t * ptr, float64x2x4_t val);

// vst4_lane_type:
void	vst4_lane_s8	(int8_t * ptr, int8x8x4_t val, const int lane);
void	vst4_lane_u8	(uint8_t * ptr, uint8x8x4_t val, const int lane);
void	vst4_lane_s16	(int16_t * ptr, int16x4x4_t val, const int lane);
void	vst4_lane_s32	(int32_t * ptr, int32x2x4_t val, const int lane);
void	vst4_lane_u16	(uint16_t * ptr, uint16x4x4_t val, const int lane);
void	vst4_lane_u32	(uint32_t * ptr, uint32x2x4_t val, const int lane);
void	vst4_lane_f32	(float32_t * ptr, float32x2x4_t val, const int lane);
void	vst4_lane_s64	(int64_t * ptr, int64x1x4_t val, const int lane);
void	vst4_lane_u64	(uint64_t * ptr, uint64x1x4_t val, const int lane);
void	vst4_lane_f64	(float64_t * ptr, float64x1x4_t val, const int lane);

// vst4q_lane_type:
void	vst4q_lane_s16	(int16_t * ptr, int16x8x4_t val, const int lane);
void	vst4q_lane_s32	(int32_t * ptr, int32x4x4_t val, const int lane);
void	vst4q_lane_u16	(uint16_t * ptr, uint16x8x4_t val, const int lane);
void	vst4q_lane_u32	(uint32_t * ptr, uint32x4x4_t val, const int lane);
void	vst4q_lane_f32	(float32_t * ptr, float32x4x4_t val, const int lane);
void	vst4q_lane_s8	(int8_t * ptr, int8x16x4_t val, const int lane);
void	vst4q_lane_u8	(uint8_t * ptr, uint8x16x4_t val, const int lane);
void	vst4q_lane_s64	(int64_t * ptr, int64x2x4_t val, const int lane);
void	vst4q_lane_u64	(uint64_t * ptr, uint64x2x4_t val, const int lane);
void	vst4q_lane_f64	(float64_t * ptr, float64x2x4_t val, const int lane);

//----------------------------------------------------------------------
// 3. Add & Sub
//----------------------------------------------------------------------

// vadd_type
int8x8_t	vadd_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vadd_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vadd_s32	(int32x2_t a, int32x2_t b);
int64x1_t	vadd_s64	(int64x1_t a, int64x1_t b);
uint8x8_t	vadd_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vadd_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vadd_u32	(uint32x2_t a, uint32x2_t b);
uint64x1_t	vadd_u64	(uint64x1_t a, uint64x1_t b);
float32x2_t	vadd_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vadd_f64	(float64x1_t a, float64x1_t b);

// vaddq_type
int8x16_t	vaddq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vaddq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vaddq_s32	(int32x4_t a, int32x4_t b);
int64x2_t	vaddq_s64	(int64x2_t a, int64x2_t b);
uint8x16_t	vaddq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vaddq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vaddq_u32	(uint32x4_t a, uint32x4_t b);
uint64x2_t	vaddq_u64	(uint64x2_t a, uint64x2_t b);
float32x4_t	vaddq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vaddq_f64	(float64x2_t a, float64x2_t b);

// vaddl_type
int16x8_t	vaddl_s8	(int8x8_t a, int8x8_t b);
int32x4_t	vaddl_s16	(int16x4_t a, int16x4_t b);
int64x2_t	vaddl_s32	(int32x2_t a, int32x2_t b);
uint16x8_t	vaddl_u8	(uint8x8_t a, uint8x8_t b);
uint32x4_t	vaddl_u16	(uint16x4_t a, uint16x4_t b);
uint64x2_t	vaddl_u32	(uint32x2_t a, uint32x2_t b);
int16x8_t	vaddl_high_s8	(int8x16_t a, int8x16_t b);
int32x4_t	vaddl_high_s16	(int16x8_t a, int16x8_t b);
int64x2_t	vaddl_high_s32	(int32x4_t a, int32x4_t b);
uint16x8_t	vaddl_high_u8	(uint8x16_t a, uint8x16_t b);
uint32x4_t	vaddl_high_u16	(uint16x8_t a, uint16x8_t b);
uint64x2_t	vaddl_high_u32	(uint32x4_t a, uint32x4_t b);

// vaddw_type
int16x8_t	vaddw_s8	(int16x8_t a, int8x8_t b);
int32x4_t	vaddw_s16	(int32x4_t a, int16x4_t b);
int64x2_t	vaddw_s32	(int64x2_t a, int32x2_t b);
uint16x8_t	vaddw_u8	(uint16x8_t a, uint8x8_t b);
uint32x4_t	vaddw_u16	(uint32x4_t a, uint16x4_t b);
uint64x2_t	vaddw_u32	(uint64x2_t a, uint32x2_t b);
int16x8_t	vaddw_high_s8	(int16x8_t a, int8x16_t b);
int32x4_t	vaddw_high_s16	(int32x4_t a, int16x8_t b);
int64x2_t	vaddw_high_s32	(int64x2_t a, int32x4_t b);
uint16x8_t	vaddw_high_u8	(uint16x8_t a, uint8x16_t b);
uint32x4_t	vaddw_high_u16	(uint32x4_t a, uint16x8_t b);
uint64x2_t	vaddw_high_u32	(uint64x2_t a, uint32x4_t b);

// vaddhn_type
int8x8_t	vaddhn_s16	(int16x8_t a, int16x8_t b);
int16x4_t	vaddhn_s32	(int32x4_t a, int32x4_t b);
int32x2_t	vaddhn_s64	(int64x2_t a, int64x2_t b);
uint8x8_t	vaddhn_u16	(uint16x8_t a, uint16x8_t b);
uint16x4_t	vaddhn_u32	(uint32x4_t a, uint32x4_t b);
uint32x2_t	vaddhn_u64	(uint64x2_t a, uint64x2_t b);
int8x16_t	vaddhn_high_s16	(int8x8_t r, int16x8_t a, int16x8_t b);
int16x8_t	vaddhn_high_s32	(int16x4_t r, int32x4_t a, int32x4_t b);
int32x4_t	vaddhn_high_s64	(int32x2_t r, int64x2_t a, int64x2_t b);
uint8x16_t	vaddhn_high_u16	(uint8x8_t r, uint16x8_t a, uint16x8_t b);
uint16x8_t	vaddhn_high_u32	(uint16x4_t r, uint32x4_t a, uint32x4_t b);
uint32x4_t	vaddhn_high_u64	(uint32x2_t r, uint64x2_t a, uint64x2_t b);

// vqadd_type
int8x8_t	vqadd_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vqadd_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vqadd_s32	(int32x2_t a, int32x2_t b);
int64x1_t	vqadd_s64	(int64x1_t a, int64x1_t b);
uint8x8_t	vqadd_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vqadd_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vqadd_u32	(uint32x2_t a, uint32x2_t b);
uint64x1_t	vqadd_u64	(uint64x1_t a, uint64x1_t b);

// vqaddq_type
int8x16_t	vqaddq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vqaddq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vqaddq_s32	(int32x4_t a, int32x4_t b);
int64x2_t	vqaddq_s64	(int64x2_t a, int64x2_t b);
uint8x16_t	vqaddq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vqaddq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vqaddq_u32	(uint32x4_t a, uint32x4_t b);
uint64x2_t	vqaddq_u64	(uint64x2_t a, uint64x2_t b);

// vhadd_type
int8x8_t	vhadd_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vhadd_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vhadd_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vhadd_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vhadd_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vhadd_u32	(uint32x2_t a, uint32x2_t b);

// vhaddq_type
int8x16_t	vhaddq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vhaddq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vhaddq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vhaddq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vhaddq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vhaddq_u32	(uint32x4_t a, uint32x4_t b);

// vrhadd_type
int8x8_t	vrhadd_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vrhadd_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vrhadd_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vrhadd_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vrhadd_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vrhadd_u32	(uint32x2_t a, uint32x2_t b);

// vrhaddq_type
int8x16_t	vrhaddq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vrhaddq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vrhaddq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vrhaddq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vrhaddq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vrhaddq_u32	(uint32x4_t a, uint32x4_t b);

// vpadd_type
int8x8_t	vpadd_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vpadd_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vpadd_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vpadd_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vpadd_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vpadd_u32	(uint32x2_t a, uint32x2_t b);
float32x2_t	vpadd_f32	(float32x2_t a, float32x2_t b);
float16x4_t	vpadd_f16	(float16x4_t a, float16x4_t b);

// vpaddl_type
int16x4_t	vpaddl_s8	(int8x8_t a);
int32x2_t	vpaddl_s16	(int16x4_t a);
int64x1_t	vpaddl_s32	(int32x2_t a);
uint16x4_t	vpaddl_u8	(uint8x8_t a);
uint32x2_t	vpaddl_u16	(uint16x4_t a);
uint64x1_t	vpaddl_u32	(uint32x2_t a);

// vpaddlq_type:
int16x8_t	vpaddlq_s8	(int8x16_t a);
int32x4_t	vpaddlq_s16	(int16x8_t a);
int64x2_t	vpaddlq_s32	(int32x4_t a);
uint16x8_t	vpaddlq_u8	(uint8x16_t a);
uint32x4_t	vpaddlq_u16	(uint16x8_t a);
uint64x2_t	vpaddlq_u32	(uint32x4_t a);

// vpadal_type:
int16x4_t	vpadal_s8	(int16x4_t a, int8x8_t b);
int32x2_t	vpadal_s16	(int32x2_t a, int16x4_t b);
int64x1_t	vpadal_s32	(int64x1_t a, int32x2_t b);
uint16x4_t	vpadal_u8	(uint16x4_t a, uint8x8_t b);
uint32x2_t	vpadal_u16	(uint32x2_t a, uint16x4_t b);
uint64x1_t	vpadal_u32	(uint64x1_t a, uint32x2_t b);

// vsub_type:
int8x8_t	vsub_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vsub_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vsub_s32	(int32x2_t a, int32x2_t b);
int64x1_t	vsub_s64	(int64x1_t a, int64x1_t b);
uint8x8_t	vsub_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vsub_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vsub_u32	(uint32x2_t a, uint32x2_t b);
uint64x1_t	vsub_u64	(uint64x1_t a, uint64x1_t b);
float32x2_t	vsub_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vsub_f64	(float64x1_t a, float64x1_t b);
float16x4_t	vsub_f16	(float16x4_t a, float16x4_t b);

// vsubq_type:
int8x16_t	vsubq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vsubq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vsubq_s32	(int32x4_t a, int32x4_t b);
int64x2_t	vsubq_s64	(int64x2_t a, int64x2_t b);
uint8x16_t	vsubq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vsubq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vsubq_u32	(uint32x4_t a, uint32x4_t b);
uint64x2_t	vsubq_u64	(uint64x2_t a, uint64x2_t b);
float32x4_t	vsubq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vsubq_f64	(float64x2_t a, float64x2_t b);
float16x8_t	vsubq_f16	(float16x8_t a, float16x8_t b);

// vsubl_type:
int16x8_t	vsubl_s8	(int8x8_t a, int8x8_t b);
int32x4_t	vsubl_s16	(int16x4_t a, int16x4_t b);
int64x2_t	vsubl_s32	(int32x2_t a, int32x2_t b);
uint16x8_t	vsubl_u8	(uint8x8_t a, uint8x8_t b);
uint32x4_t	vsubl_u16	(uint16x4_t a, uint16x4_t b);
uint64x2_t	vsubl_u32	(uint32x2_t a, uint32x2_t b);
int16x8_t	vsubl_high_s8	(int8x16_t a, int8x16_t b);
int32x4_t	vsubl_high_s16	(int16x8_t a, int16x8_t b);
int64x2_t	vsubl_high_s32	(int32x4_t a, int32x4_t b);
uint16x8_t	vsubl_high_u8	(uint8x16_t a, uint8x16_t b);
uint32x4_t	vsubl_high_u16	(uint16x8_t a, uint16x8_t b);
uint64x2_t	vsubl_high_u32	(uint32x4_t a, uint32x4_t b);

// vsubw_type:
int16x8_t	vsubw_s8	(int16x8_t a, int8x8_t b);
int32x4_t	vsubw_s16	(int32x4_t a, int16x4_t b);
int64x2_t	vsubw_s32	(int64x2_t a, int32x2_t b);
uint16x8_t	vsubw_u8	(uint16x8_t a, uint8x8_t b);
uint32x4_t	vsubw_u16	(uint32x4_t a, uint16x4_t b);
uint64x2_t	vsubw_u32	(uint64x2_t a, uint32x2_t b);
int16x8_t	vsubw_high_s8	(int16x8_t a, int8x16_t b);
int32x4_t	vsubw_high_s16	(int32x4_t a, int16x8_t b);
int64x2_t	vsubw_high_s32	(int64x2_t a, int32x4_t b);
uint16x8_t	vsubw_high_u8	(uint16x8_t a, uint8x16_t b);
uint32x4_t	vsubw_high_u16	(uint32x4_t a, uint16x8_t b);
uint64x2_t	vsubw_high_u32	(uint64x2_t a, uint32x4_t b);

// vsubhn_type:
int8x8_t	vsubhn_s16	(int16x8_t a, int16x8_t b);
int16x4_t	vsubhn_s32	(int32x4_t a, int32x4_t b);
int32x2_t	vsubhn_s64	(int64x2_t a, int64x2_t b);
uint8x8_t	vsubhn_u16	(uint16x8_t a, uint16x8_t b);
uint16x4_t	vsubhn_u32	(uint32x4_t a, uint32x4_t b);
uint32x2_t	vsubhn_u64	(uint64x2_t a, uint64x2_t b);
int8x16_t	vsubhn_high_s16	(int8x8_t r, int16x8_t a, int16x8_t b);
int16x8_t	vsubhn_high_s32	(int16x4_t r, int32x4_t a, int32x4_t b);
int32x4_t	vsubhn_high_s64	(int32x2_t r, int64x2_t a, int64x2_t b);
uint8x16_t	vsubhn_high_u16	(uint8x8_t r, uint16x8_t a, uint16x8_t b);
uint16x8_t	vsubhn_high_u32	(uint16x4_t r, uint32x4_t a, uint32x4_t b);
uint32x4_t	vsubhn_high_u64	(uint32x2_t r, uint64x2_t a, uint64x2_t b);

// vqsub_type:
int8x8_t	vqsub_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vqsub_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vqsub_s32	(int32x2_t a, int32x2_t b);
int64x1_t	vqsub_s64	(int64x1_t a, int64x1_t b);
uint8x8_t	vqsub_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vqsub_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vqsub_u32	(uint32x2_t a, uint32x2_t b);
uint64x1_t	vqsub_u64	(uint64x1_t a, uint64x1_t b);

// vqsubq_type:
int8x16_t	vqsubq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vqsubq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vqsubq_s32	(int32x4_t a, int32x4_t b);
int64x2_t	vqsubq_s64	(int64x2_t a, int64x2_t b);
uint8x16_t	vqsubq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vqsubq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vqsubq_u32	(uint32x4_t a, uint32x4_t b);
uint64x2_t	vqsubq_u64	(uint64x2_t a, uint64x2_t b);

// vhsub_type:
int8x8_t	vhsub_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vhsub_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vhsub_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vhsub_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vhsub_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vhsub_u32	(uint32x2_t a, uint32x2_t b);

// vhsubq_type:
int8x16_t	vhsubq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vhsubq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vhsubq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vhsubq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vhsubq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vhsubq_u32	(uint32x4_t a, uint32x4_t b);

// vrsubhn_type:
int8x8_t	vrsubhn_s16	(int16x8_t a, int16x8_t b);
int16x4_t	vrsubhn_s32	(int32x4_t a, int32x4_t b);
int32x2_t	vrsubhn_s64	(int64x2_t a, int64x2_t b);
uint8x8_t	vrsubhn_u16	(uint16x8_t a, uint16x8_t b);
uint16x4_t	vrsubhn_u32	(uint32x4_t a, uint32x4_t b);
uint32x2_t	vrsubhn_u64	(uint64x2_t a, uint64x2_t b);
int8x16_t	vrsubhn_high_s16	(int8x8_t r, int16x8_t a, int16x8_t b);
int16x8_t	vrsubhn_high_s32	(int16x4_t r, int32x4_t a, int32x4_t b);
int32x4_t	vrsubhn_high_s64	(int32x2_t r, int64x2_t a, int64x2_t b);
uint8x16_t	vrsubhn_high_u16	(uint8x8_t r, uint16x8_t a, uint16x8_t b);
uint16x8_t	vrsubhn_high_u32	(uint16x4_t r, uint32x4_t a, uint32x4_t b);
uint32x4_t	vrsubhn_high_u64	(uint32x2_t r, uint64x2_t a, uint64x2_t b);

//----------------------------------------------------------------------
// 4. Initialize Vector Registers
//----------------------------------------------------------------------

// vcreate_type: 
int8x8_t	vcreate_s8	(uint64_t a);
int16x4_t	vcreate_s16	(uint64_t a);
int32x2_t	vcreate_s32	(uint64_t a);
int64x1_t	vcreate_s64	(uint64_t a);
uint8x8_t	vcreate_u8	(uint64_t a);
uint16x4_t	vcreate_u16	(uint64_t a);
uint32x2_t	vcreate_u32	(uint64_t a);
uint64x1_t	vcreate_u64	(uint64_t a);
float32x2_t	vcreate_f32	(uint64_t a);
float64x1_t	vcreate_f64	(uint64_t a);

// vdup_n_type:
int8x8_t	vdup_n_s8	(int8_t value);
int16x4_t	vdup_n_s16	(int16_t value);
int32x2_t	vdup_n_s32	(int32_t value);
int64x1_t	vdup_n_s64	(int64_t value);
uint8x8_t	vdup_n_u8	(uint8_t value);
uint16x4_t	vdup_n_u16	(uint16_t value);
uint32x2_t	vdup_n_u32	(uint32_t value);
uint64x1_t	vdup_n_u64	(uint64_t value);
float32x2_t	vdup_n_f32	(float32_t value);
float64x1_t	vdup_n_f64	(float64_t value);

// vmov_n_type:
int8x8_t	vmov_n_s8	(int8_t value);
int16x4_t	vmov_n_s16	(int16_t value);
int32x2_t	vmov_n_s32	(int32_t value);
int64x1_t	vmov_n_s64	(int64_t value);
uint8x8_t	vmov_n_u8	(uint8_t value);
uint32x2_t	vmov_n_u32	(uint32_t value);
uint64x1_t	vmov_n_u64	(uint64_t value);
float32x2_t	vmov_n_f32	(float32_t value);
float64x1_t	vmov_n_f64	(float64_t value);

// vdupq_n_type:
int8x16_t	vdupq_n_s8	(int8_t value);
int16x8_t	vdupq_n_s16	(int16_t value);
int32x4_t	vdupq_n_s32	(int32_t value);
int64x2_t	vdupq_n_s64	(int64_t value);
uint8x16_t	vdupq_n_u8	(uint8_t value);
uint16x8_t	vdupq_n_u16	(uint16_t value);
uint32x4_t	vdupq_n_u32	(uint32_t value);
uint64x2_t	vdupq_n_u64	(uint64_t value);
float32x4_t	vdupq_n_f32	(float32_t value);
float64x2_t	vdupq_n_f64	(float64_t value);

// vmovq_n_type:
int8x16_t	vmovq_n_s8	(int8_t value);
int16x8_t	vmovq_n_s16	(int16_t value);
int32x4_t	vmovq_n_s32	(int32_t value);
int64x2_t	vmovq_n_s64	(int64_t value);
uint8x16_t	vmovq_n_u8	(uint8_t value);
uint16x8_t	vmovq_n_u16	(uint16_t value);
uint32x4_t	vmovq_n_u32	(uint32_t value);
uint64x2_t	vmovq_n_u64	(uint64_t value);
float32x4_t	vmovq_n_f32	(float32_t value);
float64x2_t	vmovq_n_f64	(float64_t value);

// vdup_lane_type:
int8x8_t	vdup_lane_s8	(int8x8_t vec, const int lane);
int16x4_t	vdup_lane_s16	(int16x4_t vec, const int lane);
int32x2_t	vdup_lane_s32	(int32x2_t vec, const int lane);
int64x1_t	vdup_lane_s64	(int64x1_t vec, const int lane);
uint8x8_t	vdup_lane_u8	(uint8x8_t vec, const int lane);
uint16x4_t	vdup_lane_u16	(uint16x4_t vec, const int lane);
uint32x2_t	vdup_lane_u32	(uint32x2_t vec, const int lane);
uint64x1_t	vdup_lane_u64	(uint64x1_t vec, const int lane);
float32x2_t	vdup_lane_f32	(float32x2_t vec, const int lane);
float64x1_t	vdup_lane_f64	(float64x1_t vec, const int lane);
float16x4_t	vdup_lane_f16	(float16x4_t vec, const int lane);

// vdupq_lane_type:
int8x16_t	vdupq_lane_s8	(int8x8_t vec, const int lane);
int16x8_t	vdupq_lane_s16	(int16x4_t vec, const int lane);
int32x4_t	vdupq_lane_s32	(int32x2_t vec, const int lane);
int64x2_t	vdupq_lane_s64	(int64x1_t vec, const int lane);
uint8x16_t	vdupq_lane_u8	(uint8x8_t vec, const int lane);
uint16x8_t	vdupq_lane_u16	(uint16x4_t vec, const int lane);
uint32x4_t	vdupq_lane_u32	(uint32x2_t vec, const int lane);
uint64x2_t	vdupq_lane_u64	(uint64x1_t vec, const int lane);
float32x4_t	vdupq_lane_f32	(float32x2_t vec, const int lane);
float64x2_t	vdupq_lane_f64	(float64x1_t vec, const int lane);
float16x8_t	vdupq_lane_f16	(float16x4_t vec, const int lane);

// vmovl_type:
int16x8_t	vmovl_s8	(int8x8_t a);
int32x4_t	vmovl_s16	(int16x4_t a);
int64x2_t	vmovl_s32	(int32x2_t a);
uint16x8_t	vmovl_u8	(uint8x8_t a);
uint32x4_t	vmovl_u16	(uint16x4_t a);
uint64x2_t	vmovl_u32	(uint32x2_t a);
int16x8_t	vmovl_high_s8	(int8x16_t a);
int32x4_t	vmovl_high_s16	(int16x8_t a);
int64x2_t	vmovl_high_s32	(int32x4_t a);
uint16x8_t	vmovl_high_u8	(uint8x16_t a);
uint32x4_t	vmovl_high_u16	(uint16x8_t a);
uint64x2_t	vmovl_high_u32	(uint32x4_t a);

// vmovn_type:
int8x8_t	vmovn_s16	(int16x8_t a);
int16x4_t	vmovn_s32	(int32x4_t a);
int32x2_t	vmovn_s64	(int64x2_t a);
uint8x8_t	vmovn_u16	(uint16x8_t a);
uint16x4_t	vmovn_u32	(uint32x4_t a);
uint32x2_t	vmovn_u64	(uint64x2_t a);
int8x16_t	vmovn_high_s16	(int8x8_t r, int16x8_t a);
int16x8_t	vmovn_high_s32	(int16x4_t r, int32x4_t a);
int32x4_t	vmovn_high_s64	(int32x2_t r, int64x2_t a);
uint8x16_t	vmovn_high_u16	(uint8x8_t r, uint16x8_t a);
uint16x8_t	vmovn_high_u32	(uint16x4_t r, uint32x4_t a);
uint32x4_t	vmovn_high_u64	(uint32x2_t r, uint64x2_t a);

// vqmovn_type:
int8x8_t	vqmovn_s16	(int16x8_t a);
int16x4_t	vqmovn_s32	(int32x4_t a);
int32x2_t	vqmovn_s64	(int64x2_t a);
uint8x8_t	vqmovn_u16	(uint16x8_t a);
uint16x4_t	vqmovn_u32	(uint32x4_t a);
uint32x2_t	vqmovn_u64	(uint64x2_t a);
int8x16_t	vqmovn_high_s16	(int8x8_t r, int16x8_t a);
int16x8_t	vqmovn_high_s32	(int16x4_t r, int32x4_t a);
int32x4_t	vqmovn_high_s64	(int32x2_t r, int64x2_t a);
uint8x16_t	vqmovn_high_u16	(uint8x8_t r, uint16x8_t a);
uint16x8_t	vqmovn_high_u32	(uint16x4_t r, uint32x4_t a);
uint32x4_t	vqmovn_high_u64	(uint32x2_t r, uint64x2_t a);

// vqmovun_type:
uint8x8_t	vqmovun_s16	(int16x8_t a);
uint16x4_t	vqmovun_s32	(int32x4_t a);
uint32x2_t	vqmovun_s64	(int64x2_t a);
uint8x16_t	vqmovun_high_s16	(uint8x8_t r, int16x8_t a);
uint16x8_t	vqmovun_high_s32	(uint16x4_t r, int32x4_t a);
uint32x4_t	vqmovun_high_s64	(uint32x2_t r, int64x2_t a);

//----------------------------------------------------------------------
// 5. Shift Left & Right
//----------------------------------------------------------------------

// vshl_type:
int8x8_t	vshl_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vshl_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vshl_s32	(int32x2_t a, int32x2_t b);
int64x1_t	vshl_s64	(int64x1_t a, int64x1_t b);
uint8x8_t	vshl_u8	(uint8x8_t a, int8x8_t b);
uint16x4_t	vshl_u16	(uint16x4_t a, int16x4_t b);
uint32x2_t	vshl_u32	(uint32x2_t a, int32x2_t b);
uint64x1_t	vshl_u64	(uint64x1_t a, int64x1_t b);
int8x8_t	vshl_n_s8	(int8x8_t a, const int n);
int16x4_t	vshl_n_s16	(int16x4_t a, const int n);
int32x2_t	vshl_n_s32	(int32x2_t a, const int n);
int64x1_t	vshl_n_s64	(int64x1_t a, const int n);
uint8x8_t	vshl_n_u8	(uint8x8_t a, const int n);
uint16x4_t	vshl_n_u16	(uint16x4_t a, const int n);
uint32x2_t	vshl_n_u32	(uint32x2_t a, const int n);
uint64x1_t	vshl_n_u64	(uint64x1_t a, const int n);

// vshlq_type:
int8x16_t	vshlq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vshlq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vshlq_s32	(int32x4_t a, int32x4_t b);
int64x2_t	vshlq_s64	(int64x2_t a, int64x2_t b);
uint8x16_t	vshlq_u8	(uint8x16_t a, int8x16_t b);
uint16x8_t	vshlq_u16	(uint16x8_t a, int16x8_t b);
uint32x4_t	vshlq_u32	(uint32x4_t a, int32x4_t b);
uint64x2_t	vshlq_u64	(uint64x2_t a, int64x2_t b);
int8x16_t	vshlq_n_s8	(int8x16_t a, const int n);
int16x8_t	vshlq_n_s16	(int16x8_t a, const int n);
int32x4_t	vshlq_n_s32	(int32x4_t a, const int n);
int64x2_t	vshlq_n_s64	(int64x2_t a, const int n);
uint8x16_t	vshlq_n_u8	(uint8x16_t a, const int n);
uint16x8_t	vshlq_n_u16	(uint16x8_t a, const int n);
uint32x4_t	vshlq_n_u32	(uint32x4_t a, const int n);
uint64x2_t	vshlq_n_u64	(uint64x2_t a, const int n);

// vshl_n_type:
int8x8_t	vshl_n_s8	(int8x8_t a, const int n);
int16x4_t	vshl_n_s16	(int16x4_t a, const int n);
int32x2_t	vshl_n_s32	(int32x2_t a, const int n);
int64x1_t	vshl_n_s64	(int64x1_t a, const int n);
uint8x8_t	vshl_n_u8	(uint8x8_t a, const int n);
uint16x4_t	vshl_n_u16	(uint16x4_t a, const int n);
uint32x2_t	vshl_n_u32	(uint32x2_t a, const int n);
uint64x1_t	vshl_n_u64	(uint64x1_t a, const int n);

// vshlq_n_type:
int8x16_t	vshlq_n_s8	(int8x16_t a, const int n);
int16x8_t	vshlq_n_s16	(int16x8_t a, const int n);
int32x4_t	vshlq_n_s32	(int32x4_t a, const int n);
int64x2_t	vshlq_n_s64	(int64x2_t a, const int n);
uint8x16_t	vshlq_n_u8	(uint8x16_t a, const int n);
uint16x8_t	vshlq_n_u16	(uint16x8_t a, const int n);
uint32x4_t	vshlq_n_u32	(uint32x4_t a, const int n);
uint64x2_t	vshlq_n_u64	(uint64x2_t a, const int n);

// vqshl_type:
int8x8_t	vqshl_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vqshl_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vqshl_s32	(int32x2_t a, int32x2_t b);
int64x1_t	vqshl_s64	(int64x1_t a, int64x1_t b);
uint8x8_t	vqshl_u8	(uint8x8_t a, int8x8_t b);
uint16x4_t	vqshl_u16	(uint16x4_t a, int16x4_t b);
uint32x2_t	vqshl_u32	(uint32x2_t a, int32x2_t b);
uint64x1_t	vqshl_u64	(uint64x1_t a, int64x1_t b);
int8x8_t	vqshl_n_s8	(int8x8_t a, const int n);
int16x4_t	vqshl_n_s16	(int16x4_t a, const int n);
int32x2_t	vqshl_n_s32	(int32x2_t a, const int n);
int64x1_t	vqshl_n_s64	(int64x1_t a, const int n);
uint8x8_t	vqshl_n_u8	(uint8x8_t a, const int n);
uint16x4_t	vqshl_n_u16	(uint16x4_t a, const int n);
uint32x2_t	vqshl_n_u32	(uint32x2_t a, const int n);
uint64x1_t	vqshl_n_u64	(uint64x1_t a, const int n);

// vqshlq_type:
int8x16_t	vqshlq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vqshlq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vqshlq_s32	(int32x4_t a, int32x4_t b);
int64x2_t	vqshlq_s64	(int64x2_t a, int64x2_t b);
uint8x16_t	vqshlq_u8	(uint8x16_t a, int8x16_t b);
uint16x8_t	vqshlq_u16	(uint16x8_t a, int16x8_t b);
uint32x4_t	vqshlq_u32	(uint32x4_t a, int32x4_t b);
uint64x2_t	vqshlq_u64	(uint64x2_t a, int64x2_t b);
int8x16_t	vqshlq_n_s8	(int8x16_t a, const int n);
int16x8_t	vqshlq_n_s16	(int16x8_t a, const int n);
int32x4_t	vqshlq_n_s32	(int32x4_t a, const int n);
int64x2_t	vqshlq_n_s64	(int64x2_t a, const int n);
uint8x16_t	vqshlq_n_u8	(uint8x16_t a, const int n);
uint16x8_t	vqshlq_n_u16	(uint16x8_t a, const int n);
uint32x4_t	vqshlq_n_u32	(uint32x4_t a, const int n);
uint64x2_t	vqshlq_n_u64	(uint64x2_t a, const int n);

// vrshl_type:
int8x8_t	vrshl_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vrshl_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vrshl_s32	(int32x2_t a, int32x2_t b);
int64x1_t	vrshl_s64	(int64x1_t a, int64x1_t b);
uint8x8_t	vrshl_u8	(uint8x8_t a, int8x8_t b);
uint16x4_t	vrshl_u16	(uint16x4_t a, int16x4_t b);
uint32x2_t	vrshl_u32	(uint32x2_t a, int32x2_t b);
uint64x1_t	vrshl_u64	(uint64x1_t a, int64x1_t b);

// vrshlq_type:
int8x16_t	vrshlq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vrshlq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vrshlq_s32	(int32x4_t a, int32x4_t b);
int64x2_t	vrshlq_s64	(int64x2_t a, int64x2_t b);
uint8x16_t	vrshlq_u8	(uint8x16_t a, int8x16_t b);
uint16x8_t	vrshlq_u16	(uint16x8_t a, int16x8_t b);
uint32x4_t	vrshlq_u32	(uint32x4_t a, int32x4_t b);
uint64x2_t	vrshlq_u64	(uint64x2_t a, int64x2_t b);

// vqrshl_type:
int8x8_t	vqrshl_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vqrshl_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vqrshl_s32	(int32x2_t a, int32x2_t b);
int64x1_t	vqrshl_s64	(int64x1_t a, int64x1_t b);
uint8x8_t	vqrshl_u8	(uint8x8_t a, int8x8_t b);
uint16x4_t	vqrshl_u16	(uint16x4_t a, int16x4_t b);
uint32x2_t	vqrshl_u32	(uint32x2_t a, int32x2_t b);
uint64x1_t	vqrshl_u64	(uint64x1_t a, int64x1_t b);

// vqrshlq_type:
int8x16_t	vqrshlq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vqrshlq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vqrshlq_s32	(int32x4_t a, int32x4_t b);
int64x2_t	vqrshlq_s64	(int64x2_t a, int64x2_t b);
uint8x16_t	vqrshlq_u8	(uint8x16_t a, int8x16_t b);
uint16x8_t	vqrshlq_u16	(uint16x8_t a, int16x8_t b);
uint32x4_t	vqrshlq_u32	(uint32x4_t a, int32x4_t b);
uint64x2_t	vqrshlq_u64	(uint64x2_t a, int64x2_t b);

// vqshl_n_type:
int8x8_t	vqshl_n_s8	(int8x8_t a, const int n);
int16x4_t	vqshl_n_s16	(int16x4_t a, const int n);
int32x2_t	vqshl_n_s32	(int32x2_t a, const int n);
int64x1_t	vqshl_n_s64	(int64x1_t a, const int n);
uint8x8_t	vqshl_n_u8	(uint8x8_t a, const int n);
uint16x4_t	vqshl_n_u16	(uint16x4_t a, const int n);
uint32x2_t	vqshl_n_u32	(uint32x2_t a, const int n);
uint64x1_t	vqshl_n_u64	(uint64x1_t a, const int n);

// vqshlq_n_type:
int8x16_t	vqshlq_n_s8	(int8x16_t a, const int n);
int16x8_t	vqshlq_n_s16	(int16x8_t a, const int n);
int32x4_t	vqshlq_n_s32	(int32x4_t a, const int n);
int64x2_t	vqshlq_n_s64	(int64x2_t a, const int n);
uint8x16_t	vqshlq_n_u8	(uint8x16_t a, const int n);
uint16x8_t	vqshlq_n_u16	(uint16x8_t a, const int n);
uint32x4_t	vqshlq_n_u32	(uint32x4_t a, const int n);
uint64x2_t	vqshlq_n_u64	(uint64x2_t a, const int n);

// vqshlu_n_type:
uint8x8_t	vqshlu_n_s8	(int8x8_t a, const int n);
uint16x4_t	vqshlu_n_s16	(int16x4_t a, const int n);
uint32x2_t	vqshlu_n_s32	(int32x2_t a, const int n);
uint64x1_t	vqshlu_n_s64	(int64x1_t a, const int n);

// vqshluq_n_type:
uint8x16_t	vqshluq_n_s8	(int8x16_t a, const int n);
uint16x8_t	vqshluq_n_s16	(int16x8_t a, const int n);
uint32x4_t	vqshluq_n_s32	(int32x4_t a, const int n);
uint64x2_t	vqshluq_n_s64	(int64x2_t a, const int n);

// vshll_n_type:
int16x8_t	vshll_n_s8	(int8x8_t a, const int n);
int32x4_t	vshll_n_s16	(int16x4_t a, const int n);
int64x2_t	vshll_n_s32	(int32x2_t a, const int n);
uint16x8_t	vshll_n_u8	(uint8x8_t a, const int n);
uint32x4_t	vshll_n_u16	(uint16x4_t a, const int n);
uint64x2_t	vshll_n_u32	(uint32x2_t a, const int n);

// vshr_n_type: ri = ai >> b
int8x8_t	vshr_n_s8	(int8x8_t a, const int n);
int16x4_t	vshr_n_s16	(int16x4_t a, const int n);
int32x2_t	vshr_n_s32	(int32x2_t a, const int n);
int64x1_t	vshr_n_s64	(int64x1_t a, const int n);
uint8x8_t	vshr_n_u8	(uint8x8_t a, const int n);
uint16x4_t	vshr_n_u16	(uint16x4_t a, const int n);
uint32x2_t	vshr_n_u32	(uint32x2_t a, const int n);
uint64x1_t	vshr_n_u64	(uint64x1_t a, const int n);

// vshrq_n_type:
int8x16_t	vshrq_n_s8	(int8x16_t a, const int n);
int16x8_t	vshrq_n_s16	(int16x8_t a, const int n);
int32x4_t	vshrq_n_s32	(int32x4_t a, const int n);
int64x2_t	vshrq_n_s64	(int64x2_t a, const int n);
uint8x16_t	vshrq_n_u8	(uint8x16_t a, const int n);
uint16x8_t	vshrq_n_u16	(uint16x8_t a, const int n);
uint32x4_t	vshrq_n_u32	(uint32x4_t a, const int n);
uint64x2_t	vshrq_n_u64	(uint64x2_t a, const int n);

// vrshr_n_type: ri = round(ai >> b)
int8x8_t	vrshr_n_s8	(int8x8_t a, const int n);
int16x4_t	vrshr_n_s16	(int16x4_t a, const int n);
int32x2_t	vrshr_n_s32	(int32x2_t a, const int n);
int64x1_t	vrshr_n_s64	(int64x1_t a, const int n);
uint8x8_t	vrshr_n_u8	(uint8x8_t a, const int n);
uint16x4_t	vrshr_n_u16	(uint16x4_t a, const int n);
uint32x2_t	vrshr_n_u32	(uint32x2_t a, const int n);
uint64x1_t	vrshr_n_u64	(uint64x1_t a, const int n);

// vrshrq_n_type:
int8x16_t	vrshrq_n_s8	(int8x16_t a, const int n);
int16x8_t	vrshrq_n_s16	(int16x8_t a, const int n);
int32x4_t	vrshrq_n_s32	(int32x4_t a, const int n);
int64x2_t	vrshrq_n_s64	(int64x2_t a, const int n);
uint8x16_t	vrshrq_n_u8	(uint8x16_t a, const int n);
uint16x8_t	vrshrq_n_u16	(uint16x8_t a, const int n);
uint32x4_t	vrshrq_n_u32	(uint32x4_t a, const int n);
uint64x2_t	vrshrq_n_u64	(uint64x2_t a, const int n);

// vsra_n_type: ri = (ai >> c) + (bi >> c)
int8x8_t	vsra_n_s8	(int8x8_t a, int8x8_t b, const int n);
int16x4_t	vsra_n_s16	(int16x4_t a, int16x4_t b, const int n);
int32x2_t	vsra_n_s32	(int32x2_t a, int32x2_t b, const int n);
int64x1_t	vsra_n_s64	(int64x1_t a, int64x1_t b, const int n);
uint8x8_t	vsra_n_u8	(uint8x8_t a, uint8x8_t b, const int n);
uint16x4_t	vsra_n_u16	(uint16x4_t a, uint16x4_t b, const int n);
uint32x2_t	vsra_n_u32	(uint32x2_t a, uint32x2_t b, const int n);
uint64x1_t	vsra_n_u64	(uint64x1_t a, uint64x1_t b, const int n);

// vsraq_n_type:
int8x16_t	vsraq_n_s8	(int8x16_t a, int8x16_t b, const int n);
int16x8_t	vsraq_n_s16	(int16x8_t a, int16x8_t b, const int n);
int32x4_t	vsraq_n_s32	(int32x4_t a, int32x4_t b, const int n);
int64x2_t	vsraq_n_s64	(int64x2_t a, int64x2_t b, const int n);
uint8x16_t	vsraq_n_u8	(uint8x16_t a, uint8x16_t b, const int n);
uint16x8_t	vsraq_n_u16	(uint16x8_t a, uint16x8_t b, const int n);
uint32x4_t	vsraq_n_u32	(uint32x4_t a, uint32x4_t b, const int n);
uint64x2_t	vsraq_n_u64	(uint64x2_t a, uint64x2_t b, const int n);

// vrsra_n_type: ri = round((ai >> c) + (bi >> c))
int8x8_t	vrsra_n_s8	(int8x8_t a, int8x8_t b, const int n);
int16x4_t	vrsra_n_s16	(int16x4_t a, int16x4_t b, const int n);
int32x2_t	vrsra_n_s32	(int32x2_t a, int32x2_t b, const int n);
int64x1_t	vrsra_n_s64	(int64x1_t a, int64x1_t b, const int n);
uint8x8_t	vrsra_n_u8	(uint8x8_t a, uint8x8_t b, const int n);
uint16x4_t	vrsra_n_u16	(uint16x4_t a, uint16x4_t b, const int n);
uint32x2_t	vrsra_n_u32	(uint32x2_t a, uint32x2_t b, const int n);
uint64x1_t	vrsra_n_u64	(uint64x1_t a, uint64x1_t b, const int n);

// vrsraq_n_type:
int8x16_t	vrsraq_n_s8	(int8x16_t a, int8x16_t b, const int n);
int16x8_t	vrsraq_n_s16	(int16x8_t a, int16x8_t b, const int n);
int32x4_t	vrsraq_n_s32	(int32x4_t a, int32x4_t b, const int n);
int64x2_t	vrsraq_n_s64	(int64x2_t a, int64x2_t b, const int n);
uint8x16_t	vrsraq_n_u8	(uint8x16_t a, uint8x16_t b, const int n);
uint16x8_t	vrsraq_n_u16	(uint16x8_t a, uint16x8_t b, const int n);
uint32x4_t	vrsraq_n_u32	(uint32x4_t a, uint32x4_t b, const int n);
uint64x2_t	vrsraq_n_u64	(uint64x2_t a, uint64x2_t b, const int n);

// vshrn_n_type: 窄指令 ri = ai >> b
int8x8_t	vshrn_n_s16	(int16x8_t a, const int n);
int16x4_t	vshrn_n_s32	(int32x4_t a, const int n);
int32x2_t	vshrn_n_s64	(int64x2_t a, const int n);
uint8x8_t	vshrn_n_u16	(uint16x8_t a, const int n);
uint16x4_t	vshrn_n_u32	(uint32x4_t a, const int n);
uint32x2_t	vshrn_n_u64	(uint64x2_t a, const int n);

// vqshrun_n_type:
uint8x8_t	vqshrun_n_s16	(int16x8_t a, const int n);
uint16x4_t	vqshrun_n_s32	(int32x4_t a, const int n);
uint32x2_t	vqshrun_n_s64	(int64x2_t a, const int n);

// vqrshrun_n_type:
uint8x8_t	vqrshrun_n_s16	(int16x8_t a, const int n);
uint16x4_t	vqrshrun_n_s32	(int32x4_t a, const int n);
uint32x2_t	vqrshrun_n_s64	(int64x2_t a, const int n);

// vqshrn_n_type:
int8x8_t	vqshrn_n_s16	(int16x8_t a, const int n);
int16x4_t	vqshrn_n_s32	(int32x4_t a, const int n);
int32x2_t	vqshrn_n_s64	(int64x2_t a, const int n);
uint8x8_t	vqshrn_n_u16	(uint16x8_t a, const int n);
uint16x4_t	vqshrn_n_u32	(uint32x4_t a, const int n);
uint32x2_t	vqshrn_n_u64	(uint64x2_t a, const int n);

// vrshrn_n_type:
int8x8_t	vrshrn_n_s16	(int16x8_t a, const int n);
int16x4_t	vrshrn_n_s32	(int32x4_t a, const int n);
int32x2_t	vrshrn_n_s64	(int64x2_t a, const int n);
uint8x8_t	vrshrn_n_u16	(uint16x8_t a, const int n);
uint16x4_t	vrshrn_n_u32	(uint32x4_t a, const int n);
uint32x2_t	vrshrn_n_u64	(uint64x2_t a, const int n);

// vqrshrn_n_type:
int8x8_t	vqrshrn_n_s16	(int16x8_t a, const int n);
int16x4_t	vqrshrn_n_s32	(int32x4_t a, const int n);
int32x2_t	vqrshrn_n_s64	(int64x2_t a, const int n);
uint8x8_t	vqrshrn_n_u16	(uint16x8_t a, const int n);
uint16x4_t	vqrshrn_n_u32	(uint32x4_t a, const int n);
uint32x2_t	vqrshrn_n_u64	(uint64x2_t a, const int n);

// vsri_n_type:
int8x8_t	vsri_n_s8	(int8x8_t a, int8x8_t b, const int n);
int16x4_t	vsri_n_s16	(int16x4_t a, int16x4_t b, const int n);
int32x2_t	vsri_n_s32	(int32x2_t a, int32x2_t b, const int n);
int64x1_t	vsri_n_s64	(int64x1_t a, int64x1_t b, const int n);
uint8x8_t	vsri_n_u8	(uint8x8_t a, uint8x8_t b, const int n);
uint16x4_t	vsri_n_u16	(uint16x4_t a, uint16x4_t b, const int n);
uint32x2_t	vsri_n_u32	(uint32x2_t a, uint32x2_t b, const int n);
uint64x1_t	vsri_n_u64	(uint64x1_t a, uint64x1_t b, const int n);

// vsriq_n_type:
int8x16_t	vsriq_n_s8	(int8x16_t a, int8x16_t b, const int n);
int16x8_t	vsriq_n_s16	(int16x8_t a, int16x8_t b, const int n);
int32x4_t	vsriq_n_s32	(int32x4_t a, int32x4_t b, const int n);
int64x2_t	vsriq_n_s64	(int64x2_t a, int64x2_t b, const int n);
uint8x16_t	vsriq_n_u8	(uint8x16_t a, uint8x16_t b, const int n);
uint16x8_t	vsriq_n_u16	(uint16x8_t a, uint16x8_t b, const int n);
uint32x4_t	vsriq_n_u32	(uint32x4_t a, uint32x4_t b, const int n);
uint64x2_t	vsriq_n_u64	(uint64x2_t a, uint64x2_t b, const int n);

// vsli_n_type:
int8x8_t	vsli_n_s8	(int8x8_t a, int8x8_t b, const int n);
int16x4_t	vsli_n_s16	(int16x4_t a, int16x4_t b, const int n);
int32x2_t	vsli_n_s32	(int32x2_t a, int32x2_t b, const int n);
int64x1_t	vsli_n_s64	(int64x1_t a, int64x1_t b, const int n);
uint8x8_t	vsli_n_u8	(uint8x8_t a, uint8x8_t b, const int n);
uint16x4_t	vsli_n_u16	(uint16x4_t a, uint16x4_t b, const int n);
uint32x2_t	vsli_n_u32	(uint32x2_t a, uint32x2_t b, const int n);
uint64x1_t	vsli_n_u64	(uint64x1_t a, uint64x1_t b, const int n);

// vsliq_n_type:
int8x16_t	vsliq_n_s8	(int8x16_t a, int8x16_t b, const int n);
int16x8_t	vsliq_n_s16	(int16x8_t a, int16x8_t b, const int n);
int32x4_t	vsliq_n_s32	(int32x4_t a, int32x4_t b, const int n);
int64x2_t	vsliq_n_s64	(int64x2_t a, int64x2_t b, const int n);
uint8x16_t	vsliq_n_u8	(uint8x16_t a, uint8x16_t b, const int n);
uint16x8_t	vsliq_n_u16	(uint16x8_t a, uint16x8_t b, const int n);
uint32x4_t	vsliq_n_u32	(uint32x4_t a, uint32x4_t b, const int n);
uint64x2_t	vsliq_n_u64	(uint64x2_t a, uint64x2_t b, const int n);

//----------------------------------------------------------------------
// 6. Get vector register lane value
//----------------------------------------------------------------------

// vget_low_type: 获取 128bit vector 的低半部分元素,输出的是元素类型相同的 64bit vector。
int8x8_t	vget_low_s8	(int8x16_t a);
int16x4_t	vget_low_s16	(int16x8_t a);
int32x2_t	vget_low_s32	(int32x4_t a);
int64x1_t	vget_low_s64	(int64x2_t a);
uint8x8_t	vget_low_u8	(uint8x16_t a);
uint16x4_t	vget_low_u16	(uint16x8_t a);
uint32x2_t	vget_low_u32	(uint32x4_t a);
uint64x1_t	vget_low_u64	(uint64x2_t a);
float16x4_t	vget_low_f16	(float16x8_t a);
float32x2_t	vget_low_f32	(float32x4_t a);
float64x1_t	vget_low_f64	(float64x2_t a);

// vget_high_type: 获取 128bit vector 的高半部分元素,输出的是元素类型相同的 64bitvector。
int8x8_t	vget_high_s8	(int8x16_t a);
int16x4_t	vget_high_s16	(int16x8_t a);
int32x2_t	vget_high_s32	(int32x4_t a);
int64x1_t	vget_high_s64	(int64x2_t a);
uint8x8_t	vget_high_u8	(uint8x16_t a);
uint16x4_t	vget_high_u16	(uint16x8_t a);
uint32x2_t	vget_high_u32	(uint32x4_t a);
uint64x1_t	vget_high_u64	(uint64x2_t a);
float16x4_t	vget_high_f16	(float16x8_t a);
float32x2_t	vget_high_f32	(float32x4_t a);
float64x1_t	vget_high_f64	(float64x2_t a);

// vget_lane_type: 获取元素类型为 type 的 vector 中指定的某个元素值。
uint8_t	vget_lane_u8	(uint8x8_t v, const int lane);
uint16_t	vget_lane_u16	(uint16x4_t v, const int lane);
uint32_t	vget_lane_u32	(uint32x2_t v, const int lane);
uint64_t	vget_lane_u64	(uint64x1_t v, const int lane);
int8_t	vget_lane_s8	(int8x8_t v, const int lane);
int16_t	vget_lane_s16	(int16x4_t v, const int lane);
int32_t	vget_lane_s32	(int32x2_t v, const int lane);
int64_t	vget_lane_s64	(int64x1_t v, const int lane);
float32_t	vget_lane_f32	(float32x2_t v, const int lane);
float64_t	vget_lane_f64	(float64x1_t v, const int lane);

// vgetq_lane_type:
uint8_t	vgetq_lane_u8	(uint8x16_t v, const int lane);
uint16_t	vgetq_lane_u16	(uint16x8_t v, const int lane);
uint32_t	vgetq_lane_u32	(uint32x4_t v, const int lane);
uint64_t	vgetq_lane_u64	(uint64x2_t v, const int lane);
int8_t	vgetq_lane_s8	(int8x16_t v, const int lane);
int16_t	vgetq_lane_s16	(int16x8_t v, const int lane);
int32_t	vgetq_lane_s32	(int32x4_t v, const int lane);
int64_t	vgetq_lane_s64	(int64x2_t v, const int lane);
float32_t	vgetq_lane_f32	(float32x4_t v, const int lane);
float64_t	vgetq_lane_f64	(float64x2_t v, const int lane);

// vset_lane_type:
uint8x8_t	vset_lane_u8	(uint8_t a, uint8x8_t v, const int lane);
uint16x4_t	vset_lane_u16	(uint16_t a, uint16x4_t v, const int lane);
uint32x2_t	vset_lane_u32	(uint32_t a, uint32x2_t v, const int lane);
uint64x1_t	vset_lane_u64	(uint64_t a, uint64x1_t v, const int lane);
int8x8_t	vset_lane_s8	(int8_t a, int8x8_t v, const int lane);
int16x4_t	vset_lane_s16	(int16_t a, int16x4_t v, const int lane);
int32x2_t	vset_lane_s32	(int32_t a, int32x2_t v, const int lane);
int64x1_t	vset_lane_s64	(int64_t a, int64x1_t v, const int lane);
float32x2_t	vset_lane_f32	(float32_t a, float32x2_t v, const int lane);
float64x1_t	vset_lane_f64	(float64_t a, float64x1_t v, const int lane);

// vsetq_lane_type:
uint8x16_t	vsetq_lane_u8	(uint8_t a, uint8x16_t v, const int lane);
uint16x8_t	vsetq_lane_u16	(uint16_t a, uint16x8_t v, const int lane);
uint32x4_t	vsetq_lane_u32	(uint32_t a, uint32x4_t v, const int lane);
uint64x2_t	vsetq_lane_u64	(uint64_t a, uint64x2_t v, const int lane);
int8x16_t	vsetq_lane_s8	(int8_t a, int8x16_t v, const int lane);
int16x8_t	vsetq_lane_s16	(int16_t a, int16x8_t v, const int lane);
int32x4_t	vsetq_lane_s32	(int32_t a, int32x4_t v, const int lane);
int64x2_t	vsetq_lane_s64	(int64_t a, int64x2_t v, const int lane);
float32x4_t	vsetq_lane_f32	(float32_t a, float32x4_t v, const int lane);
float64x2_t	vsetq_lane_f64	(float64_t a, float64x2_t v, const int lane);

//----------------------------------------------------------------------
// 7. Vector Registers Manipulation
//----------------------------------------------------------------------

// vext_type:
int8x8_t	vext_s8	(int8x8_t a, int8x8_t b, const int n);
int16x4_t	vext_s16	(int16x4_t a, int16x4_t b, const int n);
int32x2_t	vext_s32	(int32x2_t a, int32x2_t b, const int n);
int64x1_t	vext_s64	(int64x1_t a, int64x1_t b, const int n);
uint8x8_t	vext_u8	(uint8x8_t a, uint8x8_t b, const int n);
uint16x4_t	vext_u16	(uint16x4_t a, uint16x4_t b, const int n);
uint32x2_t	vext_u32	(uint32x2_t a, uint32x2_t b, const int n);
uint64x1_t	vext_u64	(uint64x1_t a, uint64x1_t b, const int n);
float32x2_t	vext_f32	(float32x2_t a, float32x2_t b, const int n);
float64x1_t	vext_f64	(float64x1_t a, float64x1_t b, const int n);
float16x4_t	vext_f16	(float16x4_t a, float16x4_t b, const int n);

// vextq_type:
int8x16_t	vextq_s8	(int8x16_t a, int8x16_t b, const int n);
int16x8_t	vextq_s16	(int16x8_t a, int16x8_t b, const int n);
int32x4_t	vextq_s32	(int32x4_t a, int32x4_t b, const int n);
int64x2_t	vextq_s64	(int64x2_t a, int64x2_t b, const int n);
uint8x16_t	vextq_u8	(uint8x16_t a, uint8x16_t b, const int n);
uint16x8_t	vextq_u16	(uint16x8_t a, uint16x8_t b, const int n);
uint32x4_t	vextq_u32	(uint32x4_t a, uint32x4_t b, const int n);
uint64x2_t	vextq_u64	(uint64x2_t a, uint64x2_t b, const int n);
float32x4_t	vextq_f32	(float32x4_t a, float32x4_t b, const int n);
float64x2_t	vextq_f64	(float64x2_t a, float64x2_t b, const int n);
float16x8_t	vextq_f16	(float16x8_t a, float16x8_t b, const int n);

// vtbl1_type:
int8x8_t	vtbl1_s8	(int8x8_t a, int8x8_t idx);
uint8x8_t	vtbl1_u8	(uint8x8_t a, uint8x8_t idx);

// vtbl2_type:
int8x8_t	vtbl2_s8	(int8x8x2_t a, int8x8_t idx);
uint8x8_t	vtbl2_u8	(uint8x8x2_t a, uint8x8_t idx);

// vtbl3_type:
int8x8_t	vtbl3_s8	(int8x8x3_t a, int8x8_t idx);
uint8x8_t	vtbl3_u8	(uint8x8x3_t a, uint8x8_t idx);

// vtbl4_type:
int8x8_t	vtbl4_s8	(int8x8x4_t a, int8x8_t idx);
uint8x8_t	vtbl4_u8	(uint8x8x4_t a, uint8x8_t idx);

// vtbx1_type:
int8x8_t	vtbx1_s8	(int8x8_t a, int8x8_t b, int8x8_t idx);
uint8x8_t	vtbx1_u8	(uint8x8_t a, uint8x8_t b, uint8x8_t idx);

// vtbx2_type:
int8x8_t	vtbx2_s8	(int8x8_t a, int8x8x2_t b, int8x8_t idx);
uint8x8_t	vtbx2_u8	(uint8x8_t a, uint8x8x2_t b, uint8x8_t idx);

// vtbx3_type:
int8x8_t	vtbx3_s8	(int8x8_t a, int8x8x3_t b, int8x8_t idx);
uint8x8_t	vtbx3_u8	(uint8x8_t a, uint8x8x3_t b, uint8x8_t idx);

// vtbx4_type:
int8x8_t	vtbx4_s8	(int8x8_t a, int8x8x4_t b, int8x8_t idx);
uint8x8_t	vtbx4_u8	(uint8x8_t a, uint8x8x4_t b, uint8x8_t idx);

// vqtbl1_type:
int8x8_t	vqtbl1_s8	(int8x16_t t, uint8x8_t idx);
uint8x8_t	vqtbl1_u8	(uint8x16_t t, uint8x8_t idx);

// vqtbl2_type:
int8x8_t	vqtbl2_s8	(int8x16x2_t t, uint8x8_t idx);
uint8x8_t	vqtbl2_u8	(uint8x16x2_t t, uint8x8_t idx);

// vqtbl3_type:
int8x8_t	vqtbl3_s8	(int8x16x3_t t, uint8x8_t idx);
uint8x8_t	vqtbl3_u8	(uint8x16x3_t t, uint8x8_t idx);

// vqtbl4_type:
int8x8_t	vqtbl4_s8	(int8x16x4_t t, uint8x8_t idx);
uint8x8_t	vqtbl4_u8	(uint8x16x4_t t, uint8x8_t idx);

// vrev16_type:
int8x8_t	vrev16_s8	(int8x8_t vec);
uint8x8_t	vrev16_u8	(uint8x8_t vec);

// vrev16q_type:
int8x16_t	vrev16q_s8	(int8x16_t vec);
uint8x16_t	vrev16q_u8	(uint8x16_t vec);

// vrev32_type:
int8x8_t	vrev32_s8	(int8x8_t vec);
int16x4_t	vrev32_s16	(int16x4_t vec);
uint8x8_t	vrev32_u8	(uint8x8_t vec);
uint16x4_t	vrev32_u16	(uint16x4_t vec);

// vrev32q_type:
int8x16_t	vrev32q_s8	(int8x16_t vec);
int16x8_t	vrev32q_s16	(int16x8_t vec);
uint8x16_t	vrev32q_u8	(uint8x16_t vec);
uint16x8_t	vrev32q_u16	(uint16x8_t vec);

// vrev64_type:
int8x8_t	vrev64_s8	(int8x8_t vec);
int16x4_t	vrev64_s16	(int16x4_t vec);
int32x2_t	vrev64_s32	(int32x2_t vec);
uint8x8_t	vrev64_u8	(uint8x8_t vec);
uint16x4_t	vrev64_u16	(uint16x4_t vec);
uint32x2_t	vrev64_u32	(uint32x2_t vec);
float32x2_t	vrev64_f32	(float32x2_t vec);

// vrev64q_type:
int8x16_t	vrev64q_s8	(int8x16_t vec);
int16x8_t	vrev64q_s16	(int16x8_t vec);
int32x4_t	vrev64q_s32	(int32x4_t vec);
uint8x16_t	vrev64q_u8	(uint8x16_t vec);
uint16x8_t	vrev64q_u16	(uint16x8_t vec);
uint32x4_t	vrev64q_u32	(uint32x4_t vec);
float32x4_t	vrev64q_f32	(float32x4_t vec);

// vtrn_type:
int8x8x2_t	vtrn_s8	(int8x8_t a, int8x8_t b);
int16x4x2_t	vtrn_s16	(int16x4_t a, int16x4_t b);
uint8x8x2_t	vtrn_u8	(uint8x8_t a, uint8x8_t b);
uint16x4x2_t	vtrn_u16	(uint16x4_t a, uint16x4_t b);
int32x2x2_t	vtrn_s32	(int32x2_t a, int32x2_t b);
float32x2x2_t	vtrn_f32	(float32x2_t a, float32x2_t b);
uint32x2x2_t	vtrn_u32	(uint32x2_t a, uint32x2_t b);
float16x4x2_t	vtrn_f16	(float16x4_t a, float16x4_t b);

// vtrnq_type:
int8x16x2_t	vtrnq_s8	(int8x16_t a, int8x16_t b);
int16x8x2_t	vtrnq_s16	(int16x8_t a, int16x8_t b);
int32x4x2_t	vtrnq_s32	(int32x4_t a, int32x4_t b);
float32x4x2_t	vtrnq_f32	(float32x4_t a, float32x4_t b);
uint8x16x2_t	vtrnq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8x2_t	vtrnq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4x2_t	vtrnq_u32	(uint32x4_t a, uint32x4_t b);
float16x8x2_t	vtrnq_f16	(float16x8_t a, float16x8_t b);

// vzip_type:
int8x8x2_t	vzip_s8	(int8x8_t a, int8x8_t b);
int16x4x2_t	vzip_s16	(int16x4_t a, int16x4_t b);
uint8x8x2_t	vzip_u8	(uint8x8_t a, uint8x8_t b);
uint16x4x2_t	vzip_u16	(uint16x4_t a, uint16x4_t b);
int32x2x2_t	vzip_s32	(int32x2_t a, int32x2_t b);
float32x2x2_t	vzip_f32	(float32x2_t a, float32x2_t b);
uint32x2x2_t	vzip_u32	(uint32x2_t a, uint32x2_t b);

// vzipq_type:
int8x16x2_t	vzipq_s8	(int8x16_t a, int8x16_t b);
int16x8x2_t	vzipq_s16	(int16x8_t a, int16x8_t b);
int32x4x2_t	vzipq_s32	(int32x4_t a, int32x4_t b);
float32x4x2_t	vzipq_f32	(float32x4_t a, float32x4_t b);
uint8x16x2_t	vzipq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8x2_t	vzipq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4x2_t	vzipq_u32	(uint32x4_t a, uint32x4_t b);
float16x8x2_t	vzipq_f16	(float16x8_t a, float16x8_t b);

// vuzp_type:
int8x8x2_t	vuzp_s8	(int8x8_t a, int8x8_t b);
int16x4x2_t	vuzp_s16	(int16x4_t a, int16x4_t b);
int32x2x2_t	vuzp_s32	(int32x2_t a, int32x2_t b);
float32x2x2_t	vuzp_f32	(float32x2_t a, float32x2_t b);
uint8x8x2_t	vuzp_u8	(uint8x8_t a, uint8x8_t b);
uint16x4x2_t	vuzp_u16	(uint16x4_t a, uint16x4_t b);
uint32x2x2_t	vuzp_u32	(uint32x2_t a, uint32x2_t b);

// vuzpq_type:
int8x16x2_t	vuzpq_s8	(int8x16_t a, int8x16_t b);
int16x8x2_t	vuzpq_s16	(int16x8_t a, int16x8_t b);
int32x4x2_t	vuzpq_s32	(int32x4_t a, int32x4_t b);
float32x4x2_t	vuzpq_f32	(float32x4_t a, float32x4_t b);
uint8x16x2_t	vuzpq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8x2_t	vuzpq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4x2_t	vuzpq_u32	(uint32x4_t a, uint32x4_t b);
float16x8x2_t	vuzpq_f16	(float16x8_t a, float16x8_t b);

// vcombine_type:
int8x16_t	vcombine_s8	(int8x8_t low, int8x8_t high);
int16x8_t	vcombine_s16	(int16x4_t low, int16x4_t high);
int32x4_t	vcombine_s32	(int32x2_t low, int32x2_t high);
int64x2_t	vcombine_s64	(int64x1_t low, int64x1_t high);
uint8x16_t	vcombine_u8	(uint8x8_t low, uint8x8_t high);
uint16x8_t	vcombine_u16	(uint16x4_t low, uint16x4_t high);
uint32x4_t	vcombine_u32	(uint32x2_t low, uint32x2_t high);
uint64x2_t	vcombine_u64	(uint64x1_t low, uint64x1_t high);
float32x4_t	vcombine_f32	(float32x2_t low, float32x2_t high);
float64x2_t	vcombine_f64	(float64x1_t low, float64x1_t high);

// vbsl_type:
int8x8_t	vbsl_s8	(uint8x8_t a, int8x8_t b, int8x8_t c);
int16x4_t	vbsl_s16	(uint16x4_t a, int16x4_t b, int16x4_t c);
int32x2_t	vbsl_s32	(uint32x2_t a, int32x2_t b, int32x2_t c);
int64x1_t	vbsl_s64	(uint64x1_t a, int64x1_t b, int64x1_t c);
uint8x8_t	vbsl_u8	(uint8x8_t a, uint8x8_t b, uint8x8_t c);
uint16x4_t	vbsl_u16	(uint16x4_t a, uint16x4_t b, uint16x4_t c);
uint32x2_t	vbsl_u32	(uint32x2_t a, uint32x2_t b, uint32x2_t c);
uint64x1_t	vbsl_u64	(uint64x1_t a, uint64x1_t b, uint64x1_t c);
float32x2_t	vbsl_f32	(uint32x2_t a, float32x2_t b, float32x2_t c);
float64x1_t	vbsl_f64	(uint64x1_t a, float64x1_t b, float64x1_t c);
float16x4_t	vbsl_f16	(uint16x4_t a, float16x4_t b, float16x4_t c);

// vbslq_type:
int8x16_t	vbslq_s8	(uint8x16_t a, int8x16_t b, int8x16_t c);
int16x8_t	vbslq_s16	(uint16x8_t a, int16x8_t b, int16x8_t c);
int32x4_t	vbslq_s32	(uint32x4_t a, int32x4_t b, int32x4_t c);
int64x2_t	vbslq_s64	(uint64x2_t a, int64x2_t b, int64x2_t c);
uint8x16_t	vbslq_u8	(uint8x16_t a, uint8x16_t b, uint8x16_t c);
uint16x8_t	vbslq_u16	(uint16x8_t a, uint16x8_t b, uint16x8_t c);
uint32x4_t	vbslq_u32	(uint32x4_t a, uint32x4_t b, uint32x4_t c);
uint64x2_t	vbslq_u64	(uint64x2_t a, uint64x2_t b, uint64x2_t c);
float32x4_t	vbslq_f32	(uint32x4_t a, float32x4_t b, float32x4_t c);
float64x2_t	vbslq_f64	(uint64x2_t a, float64x2_t b, float64x2_t c);
float16x8_t	vbslq_f16	(uint16x8_t a, float16x8_t b, float16x8_t c);

//----------------------------------------------------------------------
// 8. Type conversion
//----------------------------------------------------------------------
// vcvt_type1_type2:
int32x2_t	vcvt_s32_f32	(float32x2_t a);
uint32x2_t	vcvt_u32_f32	(float32x2_t a);
int64x1_t	vcvt_s64_f64	(float64x1_t a);
uint64x1_t	vcvt_u64_f64	(float64x1_t a);
int32x2_t	vcvt_n_s32_f32	(float32x2_t a, const int n);
uint32x2_t	vcvt_n_u32_f32	(float32x2_t a, const int n);
int64x1_t	vcvt_n_s64_f64	(float64x1_t a, const int n);
uint64x1_t	vcvt_n_u64_f64	(float64x1_t a, const int n);
float32x2_t	vcvt_f32_s32	(int32x2_t a);
float32x2_t	vcvt_f32_u32	(uint32x2_t a);
float64x1_t	vcvt_f64_s64	(int64x1_t a);
float64x1_t	vcvt_f64_u64	(uint64x1_t a);
float32x2_t	vcvt_n_f32_s32	(int32x2_t a, const int n);
float32x2_t	vcvt_n_f32_u32	(uint32x2_t a, const int n);
float64x1_t	vcvt_n_f64_s64	(int64x1_t a, const int n);
float64x1_t	vcvt_n_f64_u64	(uint64x1_t a, const int n);
float16x4_t	vcvt_f16_f32	(float32x4_t a);
float16x8_t	vcvt_high_f16_f32	(float16x4_t r, float32x4_t a);
float32x2_t	vcvt_f32_f64	(float64x2_t a);
float32x4_t	vcvt_high_f32_f64	(float32x2_t r, float64x2_t a);
float32x4_t	vcvt_f32_f16	(float16x4_t a);
float32x4_t	vcvt_high_f32_f16	(float16x8_t a);
float64x2_t	vcvt_f64_f32	(float32x2_t a);
float64x2_t	vcvt_high_f64_f32	(float32x4_t a);
float16x4_t	vcvt_f16_s16	(int16x4_t a);
float16x4_t	vcvt_f16_u16	(uint16x4_t a);
int16x4_t	vcvt_s16_f16	(float16x4_t a);
uint16x4_t	vcvt_u16_f16	(float16x4_t a);
float16x4_t	vcvt_n_f16_s16	(int16x4_t a, const int n);
float16x4_t	vcvt_n_f16_u16	(uint16x4_t a, const int n);
int16x4_t	vcvt_n_s16_f16	(float16x4_t a, const int n);
uint16x4_t	vcvt_n_u16_f16	(float16x4_t a, const int n);

// vcvtq_type1_type2:
int32x4_t	vcvtq_s32_f32	(float32x4_t a);
uint32x4_t	vcvtq_u32_f32	(float32x4_t a);
int64x2_t	vcvtq_s64_f64	(float64x2_t a);
uint64x2_t	vcvtq_u64_f64	(float64x2_t a);
int32x4_t	vcvtq_n_s32_f32	(float32x4_t a, const int n);
uint32x4_t	vcvtq_n_u32_f32	(float32x4_t a, const int n);
int64x2_t	vcvtq_n_s64_f64	(float64x2_t a, const int n);
uint64x2_t	vcvtq_n_u64_f64	(float64x2_t a, const int n);
float32x4_t	vcvtq_f32_s32	(int32x4_t a);
float32x4_t	vcvtq_f32_u32	(uint32x4_t a);
float64x2_t	vcvtq_f64_s64	(int64x2_t a);
float64x2_t	vcvtq_f64_u64	(uint64x2_t a);
float32x4_t	vcvtq_n_f32_s32	(int32x4_t a, const int n);
float32x4_t	vcvtq_n_f32_u32	(uint32x4_t a, const int n);
float64x2_t	vcvtq_n_f64_s64	(int64x2_t a, const int n);
float64x2_t	vcvtq_n_f64_u64	(uint64x2_t a, const int n);
float16x8_t	vcvtq_f16_s16	(int16x8_t a);
float16x8_t	vcvtq_f16_u16	(uint16x8_t a);
int16x8_t	vcvtq_s16_f16	(float16x8_t a);
uint16x8_t	vcvtq_u16_f16	(float16x8_t a);
float16x8_t	vcvtq_n_f16_s16	(int16x8_t a, const int n);
float16x8_t	vcvtq_n_f16_u16	(uint16x8_t a, const int n);
int16x8_t	vcvtq_n_s16_f16	(float16x8_t a, const int n);
uint16x8_t	vcvtq_n_u16_f16	(float16x8_t a, const int n);

// vcvt_n_type1_type2:
int32x2_t	vcvt_n_s32_f32	(float32x2_t a, const int n);
uint32x2_t	vcvt_n_u32_f32	(float32x2_t a, const int n);
int64x1_t	vcvt_n_s64_f64	(float64x1_t a, const int n);
uint64x1_t	vcvt_n_u64_f64	(float64x1_t a, const int n);
float32x2_t	vcvt_n_f32_s32	(int32x2_t a, const int n);
float32x2_t	vcvt_n_f32_u32	(uint32x2_t a, const int n);
float64x1_t	vcvt_n_f64_s64	(int64x1_t a, const int n);
float64x1_t	vcvt_n_f64_u64	(uint64x1_t a, const int n);
float16x4_t	vcvt_n_f16_s16	(int16x4_t a, const int n);
float16x4_t	vcvt_n_f16_u16	(uint16x4_t a, const int n);
int16x4_t	vcvt_n_s16_f16	(float16x4_t a, const int n);
uint16x4_t	vcvt_n_u16_f16	(float16x4_t a, const int n);

// vcvtq_n_type1_type2:
int32x4_t	vcvtq_n_s32_f32	(float32x4_t a, const int n);
uint32x4_t	vcvtq_n_u32_f32	(float32x4_t a, const int n);
int64x2_t	vcvtq_n_s64_f64	(float64x2_t a, const int n);
uint64x2_t	vcvtq_n_u64_f64	(float64x2_t a, const int n);
float32x4_t	vcvtq_n_f32_s32	(int32x4_t a, const int n);
float32x4_t	vcvtq_n_f32_u32	(uint32x4_t a, const int n);
float64x2_t	vcvtq_n_f64_s64	(int64x2_t a, const int n);
float64x2_t	vcvtq_n_f64_u64	(uint64x2_t a, const int n);
float16x8_t	vcvtq_n_f16_s16	(int16x8_t a, const int n);
float16x8_t	vcvtq_n_f16_u16	(uint16x8_t a, const int n);
int16x8_t	vcvtq_n_s16_f16	(float16x8_t a, const int n);
uint16x8_t	vcvtq_n_u16_f16	(float16x8_t a, const int n);

// vreinterpret_type1_type2: 太多了，有11页。按常用类型做二次拆分

// vreinterpret_u8_type
uint8x8_t	vreinterpret_u8_s8	(int8x8_t a);
uint8x8_t	vreinterpret_u8_s16	(int16x4_t a);
uint8x8_t	vreinterpret_u8_s32	(int32x2_t a);
uint8x8_t	vreinterpret_u8_f32	(float32x2_t a);
uint8x8_t	vreinterpret_u8_u16	(uint16x4_t a);
uint8x8_t	vreinterpret_u8_u32	(uint32x2_t a);
uint8x8_t	vreinterpret_u8_u64	(uint64x1_t a);
uint8x8_t	vreinterpret_u8_s64	(int64x1_t a);
uint8x8_t	vreinterpret_u8_f16	(float16x4_t a);
uint8x8_t	vreinterpret_u8_f64	(float64x1_t a);

// vreinterpret_u16_type
uint16x4_t	vreinterpret_u16_s8	(int8x8_t a);
uint16x4_t	vreinterpret_u16_s16	(int16x4_t a);
uint16x4_t	vreinterpret_u16_s32	(int32x2_t a);
uint16x4_t	vreinterpret_u16_f32	(float32x2_t a);
uint16x4_t	vreinterpret_u16_u8	(uint8x8_t a);
uint16x4_t	vreinterpret_u16_u32	(uint32x2_t a);
uint16x4_t	vreinterpret_u16_u64	(uint64x1_t a);
uint16x4_t	vreinterpret_u16_s64	(int64x1_t a);
uint16x4_t	vreinterpret_u16_f16	(float16x4_t a);
uint16x4_t	vreinterpret_u16_f64	(float64x1_t a);

// vreinterpret_u32_type
uint32x2_t	vreinterpret_u32_s8	(int8x8_t a);
uint32x2_t	vreinterpret_u32_s16	(int16x4_t a);
uint32x2_t	vreinterpret_u32_s32	(int32x2_t a);
uint32x2_t	vreinterpret_u32_f32	(float32x2_t a);
uint32x2_t	vreinterpret_u32_u8	(uint8x8_t a);
uint32x2_t	vreinterpret_u32_u16	(uint16x4_t a);
uint32x2_t	vreinterpret_u32_u64	(uint64x1_t a);
uint32x2_t	vreinterpret_u32_s64	(int64x1_t a);
uint32x2_t	vreinterpret_u32_f16	(float16x4_t a);
uint32x2_t	vreinterpret_u32_f64	(float64x1_t a);

// vreinterpret_u64_type
uint64x1_t	vreinterpret_u64_s8	(int8x8_t a);
uint64x1_t	vreinterpret_u64_s16	(int16x4_t a);
uint64x1_t	vreinterpret_u64_s32	(int32x2_t a);
uint64x1_t	vreinterpret_u64_f32	(float32x2_t a);
uint64x1_t	vreinterpret_u64_u8	(uint8x8_t a);
uint64x1_t	vreinterpret_u64_u16	(uint16x4_t a);
uint64x1_t	vreinterpret_u64_u32	(uint32x2_t a);
uint64x1_t	vreinterpret_u64_s64	(int64x1_t a);
uint64x1_t	vreinterpret_u64_f16	(float16x4_t a);
uint64x1_t	vreinterpret_u64_f64	(float64x1_t a);

// vreinterpret_s8_type
int8x8_t	vreinterpret_s8_s16	(int16x4_t a);
int8x8_t	vreinterpret_s8_s32	(int32x2_t a);
int8x8_t	vreinterpret_s8_f32	(float32x2_t a);
int8x8_t	vreinterpret_s8_u8	(uint8x8_t a);
int8x8_t	vreinterpret_s8_u16	(uint16x4_t a);
int8x8_t	vreinterpret_s8_u32	(uint32x2_t a);
int8x8_t	vreinterpret_s8_u64	(uint64x1_t a);
int8x8_t	vreinterpret_s8_s64	(int64x1_t a);
int8x8_t	vreinterpret_s8_f16	(float16x4_t a);
int8x8_t	vreinterpret_s8_f64	(float64x1_t a);

// vreinterpret_s16_type
int16x4_t	vreinterpret_s16_s8	(int8x8_t a);
int16x4_t	vreinterpret_s16_s32	(int32x2_t a);
int16x4_t	vreinterpret_s16_f32	(float32x2_t a);
int16x4_t	vreinterpret_s16_u8	(uint8x8_t a);
int16x4_t	vreinterpret_s16_u16	(uint16x4_t a);
int16x4_t	vreinterpret_s16_u32	(uint32x2_t a);
int16x4_t	vreinterpret_s16_u64	(uint64x1_t a);
int16x4_t	vreinterpret_s16_s64	(int64x1_t a);
int16x4_t	vreinterpret_s16_f16	(float16x4_t a);
int16x4_t	vreinterpret_s16_f64	(float64x1_t a);

// vreinterpret_s32_type
int32x2_t	vreinterpret_s32_s8	(int8x8_t a);
int32x2_t	vreinterpret_s32_s16	(int16x4_t a);
int32x2_t	vreinterpret_s32_f32	(float32x2_t a);
int32x2_t	vreinterpret_s32_u8	(uint8x8_t a);
int32x2_t	vreinterpret_s32_u16	(uint16x4_t a);
int32x2_t	vreinterpret_s32_u32	(uint32x2_t a);
int32x2_t	vreinterpret_s32_u64	(uint64x1_t a);
int32x2_t	vreinterpret_s32_s64	(int64x1_t a);
int32x2_t	vreinterpret_s32_f16	(float16x4_t a);
int32x2_t	vreinterpret_s32_f64	(float64x1_t a);

// vreinterpret_s64_type
int64x1_t	vreinterpret_s64_s8	(int8x8_t a);
int64x1_t	vreinterpret_s64_s16	(int16x4_t a);
int64x1_t	vreinterpret_s64_s32	(int32x2_t a);
int64x1_t	vreinterpret_s64_f32	(float32x2_t a);
int64x1_t	vreinterpret_s64_u8	(uint8x8_t a);
int64x1_t	vreinterpret_s64_u16	(uint16x4_t a);
int64x1_t	vreinterpret_s64_u32	(uint32x2_t a);
int64x1_t	vreinterpret_s64_u64	(uint64x1_t a);
int64x1_t	vreinterpret_s64_f16	(float16x4_t a);
int64x1_t	vreinterpret_s64_f64	(float64x1_t a);

// vreinterpret_f32_type
float32x2_t	vreinterpret_f32_s8	(int8x8_t a);
float32x2_t	vreinterpret_f32_s16	(int16x4_t a);
float32x2_t	vreinterpret_f32_s32	(int32x2_t a);
float32x2_t	vreinterpret_f32_u8	(uint8x8_t a);
float32x2_t	vreinterpret_f32_u16	(uint16x4_t a);
float32x2_t	vreinterpret_f32_u32	(uint32x2_t a);
float32x2_t	vreinterpret_f32_u64	(uint64x1_t a);
float32x2_t	vreinterpret_f32_s64	(int64x1_t a);
float32x2_t	vreinterpret_f32_f16	(float16x4_t a);
float32x2_t	vreinterpret_f32_f64	(float64x1_t a);

// vreinterpret_f64_type
float64x1_t	vreinterpret_f64_s8	(int8x8_t a);
float64x1_t	vreinterpret_f64_s16	(int16x4_t a);
float64x1_t	vreinterpret_f64_s32	(int32x2_t a);
float64x1_t	vreinterpret_f64_f32	(float32x2_t a);
float64x1_t	vreinterpret_f64_u8	(uint8x8_t a);
float64x1_t	vreinterpret_f64_u16	(uint16x4_t a);
float64x1_t	vreinterpret_f64_u32	(uint32x2_t a);
float64x1_t	vreinterpret_f64_u64	(uint64x1_t a);
float64x1_t	vreinterpret_f64_s64	(int64x1_t a);
float64x1_t	vreinterpret_f64_f16	(float16x4_t a);

// vreinterpretq_type1_type2: 结果也特别多，也做二次拆分

// vreinterpretq_u8_type
uint8x16_t	vreinterpretq_u8_s8	(int8x16_t a);
uint8x16_t	vreinterpretq_u8_s16	(int16x8_t a);
uint8x16_t	vreinterpretq_u8_s32	(int32x4_t a);
uint8x16_t	vreinterpretq_u8_f32	(float32x4_t a);
uint8x16_t	vreinterpretq_u8_u16	(uint16x8_t a);
uint8x16_t	vreinterpretq_u8_u32	(uint32x4_t a);
uint8x16_t	vreinterpretq_u8_u64	(uint64x2_t a);
uint8x16_t	vreinterpretq_u8_s64	(int64x2_t a);
uint8x16_t	vreinterpretq_u8_f16	(float16x8_t a);
uint8x16_t	vreinterpretq_u8_f64	(float64x2_t a);

// vreinterpretq_u16_type
uint16x8_t	vreinterpretq_u16_s8	(int8x16_t a);
uint16x8_t	vreinterpretq_u16_s16	(int16x8_t a);
uint16x8_t	vreinterpretq_u16_s32	(int32x4_t a);
uint16x8_t	vreinterpretq_u16_f32	(float32x4_t a);
uint16x8_t	vreinterpretq_u16_u8	(uint8x16_t a);
uint16x8_t	vreinterpretq_u16_u32	(uint32x4_t a);
uint16x8_t	vreinterpretq_u16_u64	(uint64x2_t a);
uint16x8_t	vreinterpretq_u16_s64	(int64x2_t a);
uint16x8_t	vreinterpretq_u16_f16	(float16x8_t a);
uint16x8_t	vreinterpretq_u16_f64	(float64x2_t a);

// vreinterpretq_u32_type
uint32x4_t	vreinterpretq_u32_s8	(int8x16_t a);
uint32x4_t	vreinterpretq_u32_s16	(int16x8_t a);
uint32x4_t	vreinterpretq_u32_s32	(int32x4_t a);
uint32x4_t	vreinterpretq_u32_f32	(float32x4_t a);
uint32x4_t	vreinterpretq_u32_u8	(uint8x16_t a);
uint32x4_t	vreinterpretq_u32_u16	(uint16x8_t a);
uint32x4_t	vreinterpretq_u32_u64	(uint64x2_t a);
uint32x4_t	vreinterpretq_u32_s64	(int64x2_t a);
uint32x4_t	vreinterpretq_u32_f16	(float16x8_t a);
uint32x4_t	vreinterpretq_u32_f64	(float64x2_t a);

// vreinterpretq_u64_type
uint64x2_t	vreinterpretq_u64_s8	(int8x16_t a);
uint64x2_t	vreinterpretq_u64_s16	(int16x8_t a);
uint64x2_t	vreinterpretq_u64_s32	(int32x4_t a);
uint64x2_t	vreinterpretq_u64_f32	(float32x4_t a);
uint64x2_t	vreinterpretq_u64_u8	(uint8x16_t a);
uint64x2_t	vreinterpretq_u64_u16	(uint16x8_t a);
uint64x2_t	vreinterpretq_u64_u32	(uint32x4_t a);
uint64x2_t	vreinterpretq_u64_s64	(int64x2_t a);
uint64x2_t	vreinterpretq_u64_f16	(float16x8_t a);
uint64x2_t	vreinterpretq_u64_f64	(float64x2_t a);

// vreinterpretq_s8_type
int8x16_t	vreinterpretq_s8_s16	(int16x8_t a);
int8x16_t	vreinterpretq_s8_s32	(int32x4_t a);
int8x16_t	vreinterpretq_s8_f32	(float32x4_t a);
int8x16_t	vreinterpretq_s8_u8	(uint8x16_t a);
int8x16_t	vreinterpretq_s8_u16	(uint16x8_t a);
int8x16_t	vreinterpretq_s8_u32	(uint32x4_t a);
int8x16_t	vreinterpretq_s8_u64	(uint64x2_t a);
int8x16_t	vreinterpretq_s8_s64	(int64x2_t a);
int8x16_t	vreinterpretq_s8_f16	(float16x8_t a);
int8x16_t	vreinterpretq_s8_f64	(float64x2_t a);

// vreinterpretq_s16_type
int16x8_t	vreinterpretq_s16_s8	(int8x16_t a);
int16x8_t	vreinterpretq_s16_s32	(int32x4_t a);
int16x8_t	vreinterpretq_s16_f32	(float32x4_t a);
int16x8_t	vreinterpretq_s16_u8	(uint8x16_t a);
int16x8_t	vreinterpretq_s16_u16	(uint16x8_t a);
int16x8_t	vreinterpretq_s16_u32	(uint32x4_t a);
int16x8_t	vreinterpretq_s16_u64	(uint64x2_t a);
int16x8_t	vreinterpretq_s16_s64	(int64x2_t a);
int16x8_t	vreinterpretq_s16_f16	(float16x8_t a);
int16x8_t	vreinterpretq_s16_f64	(float64x2_t a);

// vreinterpretq_s32_type
int32x4_t	vreinterpretq_s32_s8	(int8x16_t a);
int32x4_t	vreinterpretq_s32_s16	(int16x8_t a);
int32x4_t	vreinterpretq_s32_f32	(float32x4_t a);
int32x4_t	vreinterpretq_s32_u8	(uint8x16_t a);
int32x4_t	vreinterpretq_s32_u16	(uint16x8_t a);
int32x4_t	vreinterpretq_s32_u32	(uint32x4_t a);
int32x4_t	vreinterpretq_s32_u64	(uint64x2_t a);
int32x4_t	vreinterpretq_s32_s64	(int64x2_t a);
int32x4_t	vreinterpretq_s32_f16	(float16x8_t a);
int32x4_t	vreinterpretq_s32_f64	(float64x2_t a);

// vreinterpretq_s64_type
int64x2_t	vreinterpretq_s64_s8	(int8x16_t a);
int64x2_t	vreinterpretq_s64_s16	(int16x8_t a);
int64x2_t	vreinterpretq_s64_s32	(int32x4_t a);
int64x2_t	vreinterpretq_s64_f32	(float32x4_t a);
int64x2_t	vreinterpretq_s64_u8	(uint8x16_t a);
int64x2_t	vreinterpretq_s64_u16	(uint16x8_t a);
int64x2_t	vreinterpretq_s64_u32	(uint32x4_t a);
int64x2_t	vreinterpretq_s64_u64	(uint64x2_t a);
int64x2_t	vreinterpretq_s64_f16	(float16x8_t a);
int64x2_t	vreinterpretq_s64_f64	(float64x2_t a);

// vreinterpretq_f32_type
float32x4_t	vreinterpretq_f32_s8	(int8x16_t a);
float32x4_t	vreinterpretq_f32_s16	(int16x8_t a);
float32x4_t	vreinterpretq_f32_s32	(int32x4_t a);
float32x4_t	vreinterpretq_f32_u8	(uint8x16_t a);
float32x4_t	vreinterpretq_f32_u16	(uint16x8_t a);
float32x4_t	vreinterpretq_f32_u32	(uint32x4_t a);
float32x4_t	vreinterpretq_f32_u64	(uint64x2_t a);
float32x4_t	vreinterpretq_f32_s64	(int64x2_t a);
float32x4_t	vreinterpretq_f32_f16	(float16x8_t a);
float32x4_t	vreinterpretq_f32_f64	(float64x2_t a);

// vreinterpretq_f64_type
float64x2_t	vreinterpretq_f64_s8	(int8x16_t a);
float64x2_t	vreinterpretq_f64_s16	(int16x8_t a);
float64x2_t	vreinterpretq_f64_s32	(int32x4_t a);
float64x2_t	vreinterpretq_f64_f32	(float32x4_t a);
float64x2_t	vreinterpretq_f64_u8	(uint8x16_t a);
float64x2_t	vreinterpretq_f64_u16	(uint16x8_t a);
float64x2_t	vreinterpretq_f64_u32	(uint32x4_t a);
float64x2_t	vreinterpretq_f64_u64	(uint64x2_t a);
float64x2_t	vreinterpretq_f64_s64	(int64x2_t a);
float64x2_t	vreinterpretq_f64_f16	(float16x8_t a);

//----------------------------------------------------------------------
// 9. Multiply
//----------------------------------------------------------------------

// vmul_type: ri = ai * bi
int8x8_t	vmul_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vmul_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vmul_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vmul_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vmul_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vmul_u32	(uint32x2_t a, uint32x2_t b);
float32x2_t	vmul_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vmul_f64	(float64x1_t a, float64x1_t b);

// vmulq_type:
int8x16_t	vmulq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vmulq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vmulq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vmulq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vmulq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vmulq_u32	(uint32x4_t a, uint32x4_t b);
float32x4_t	vmulq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vmulq_f64	(float64x2_t a, float64x2_t b);

// vmul_n_type: ri = ai * b
int16x4_t	vmul_n_s16	(int16x4_t a, int16_t b);
int32x2_t	vmul_n_s32	(int32x2_t a, int32_t b);
uint16x4_t	vmul_n_u16	(uint16x4_t a, uint16_t b);
uint32x2_t	vmul_n_u32	(uint32x2_t a, uint32_t b);
float32x2_t	vmul_n_f32	(float32x2_t a, float32_t b);
float64x1_t	vmul_n_f64	(float64x1_t a, float64_t b);

// vmulq_n_type:
int16x8_t	vmulq_n_s16	(int16x8_t a, int16_t b);
int32x4_t	vmulq_n_s32	(int32x4_t a, int32_t b);
uint16x8_t	vmulq_n_u16	(uint16x8_t a, uint16_t b);
uint32x4_t	vmulq_n_u32	(uint32x4_t a, uint32_t b);
float32x4_t	vmulq_n_f32	(float32x4_t a, float32_t b);
float64x2_t	vmulq_n_f64	(float64x2_t a, float64_t b);

// vmul_lane_type: ri = ai * b[c]
int16x4_t	vmul_lane_s16	(int16x4_t a, int16x4_t v, const int lane);
int32x2_t	vmul_lane_s32	(int32x2_t a, int32x2_t v, const int lane);
uint16x4_t	vmul_lane_u16	(uint16x4_t a, uint16x4_t v, const int lane);
uint32x2_t	vmul_lane_u32	(uint32x2_t a, uint32x2_t v, const int lane);
float32x2_t	vmul_lane_f32	(float32x2_t a, float32x2_t v, const int lane);
float64x1_t	vmul_lane_f64	(float64x1_t a, float64x1_t v, const int lane);

// vmulq_lane_type:
int16x8_t	vmulq_lane_s16	(int16x8_t a, int16x4_t v, const int lane);
int32x4_t	vmulq_lane_s32	(int32x4_t a, int32x2_t v, const int lane);
uint16x8_t	vmulq_lane_u16	(uint16x8_t a, uint16x4_t v, const int lane);
uint32x4_t	vmulq_lane_u32	(uint32x4_t a, uint32x2_t v, const int lane);
float32x4_t	vmulq_lane_f32	(float32x4_t a, float32x2_t v, const int lane);
float64x2_t	vmulq_lane_f64	(float64x2_t a, float64x1_t v, const int lane);

// vmull_type: 变长乘法运算,为了防止溢出
int16x8_t	vmull_s8	(int8x8_t a, int8x8_t b);
int32x4_t	vmull_s16	(int16x4_t a, int16x4_t b);
int64x2_t	vmull_s32	(int32x2_t a, int32x2_t b);
uint16x8_t	vmull_u8	(uint8x8_t a, uint8x8_t b);
uint32x4_t	vmull_u16	(uint16x4_t a, uint16x4_t b);
uint64x2_t	vmull_u32	(uint32x2_t a, uint32x2_t b);

// vmull_n_type:
int32x4_t	vmull_n_s16	(int16x4_t a, int16_t b);
int64x2_t	vmull_n_s32	(int32x2_t a, int32_t b);
uint32x4_t	vmull_n_u16	(uint16x4_t a, uint16_t b);
uint64x2_t	vmull_n_u32	(uint32x2_t a, uint32_t b);

// vmull_lane_type:
int32x4_t	vmull_lane_s16	(int16x4_t a, int16x4_t v, const int lane);
int64x2_t	vmull_lane_s32	(int32x2_t a, int32x2_t v, const int lane);
uint32x4_t	vmull_lane_u16	(uint16x4_t a, uint16x4_t v, const int lane);
uint64x2_t	vmull_lane_u32	(uint32x2_t a, uint32x2_t v, const int lane);

// vqdmull_type: l 变长两倍乘法运算,运算值是有符号数(两个 type_MIN 相乘会溢出,取饱和值)
int32x4_t	vqdmull_s16	(int16x4_t a, int16x4_t b);
int64x2_t	vqdmull_s32	(int32x2_t a, int32x2_t b);

// vqdmull_n_type:
int32x4_t	vqdmull_n_s16	(int16x4_t a, int16_t b);
int64x2_t	vqdmull_n_s32	(int32x2_t a, int32_t b);

// vqdmull_lane_type:
int32x4_t	vqdmull_lane_s16	(int16x4_t a, int16x4_t v, const int lane);
int64x2_t	vqdmull_lane_s32	(int32x2_t a, int32x2_t v, const int lane);

// vqdmulh_type:
int16x4_t	vqdmulh_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vqdmulh_s32	(int32x2_t a, int32x2_t b);

// vqdmulhq_type:
int16x8_t	vqdmulhq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vqdmulhq_s32	(int32x4_t a, int32x4_t b);

// vqdmulh_n_type:
int16x4_t	vqdmulh_n_s16	(int16x4_t a, int16_t b);
int32x2_t	vqdmulh_n_s32	(int32x2_t a, int32_t b);

// vqdmulhq_n_type:
int16x8_t	vqdmulhq_n_s16	(int16x8_t a, int16_t b);
int32x4_t	vqdmulhq_n_s32	(int32x4_t a, int32_t b);

// vqdmulh_lane_type:
int16x4_t	vqdmulh_lane_s16	(int16x4_t a, int16x4_t v, const int lane);
int32x2_t	vqdmulh_lane_s32	(int32x2_t a, int32x2_t v, const int lane);

// vqdmulhq_lane_type:
int16x8_t	vqdmulhq_lane_s16	(int16x8_t a, int16x4_t v, const int lane);
int32x4_t	vqdmulhq_lane_s32	(int32x4_t a, int32x2_t v, const int lane);

// vqrdmulh_type:
int16x4_t	vqrdmulh_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vqrdmulh_s32	(int32x2_t a, int32x2_t b);

// vqrdmulhq_type:
int16x8_t	vqrdmulhq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vqrdmulhq_s32	(int32x4_t a, int32x4_t b);

// vqrdmulh_n_type:
int16x4_t	vqrdmulh_n_s16	(int16x4_t a, int16_t b);
int32x2_t	vqrdmulh_n_s32	(int32x2_t a, int32_t b);

// vqrdmulhq_n_type:
int16x8_t	vqrdmulhq_n_s16	(int16x8_t a, int16_t b);
int32x4_t	vqrdmulhq_n_s32	(int32x4_t a, int32_t b);

// vqrdmulh_lane_type:
int16x4_t	vqrdmulh_lane_s16	(int16x4_t a, int16x4_t v, const int lane);
int32x2_t	vqrdmulh_lane_s32	(int32x2_t a, int32x2_t v, const int lane);

// vqrdmulhq_lane_type:
int16x8_t	vqrdmulhq_lane_s16	(int16x8_t a, int16x4_t v, const int lane);
int32x4_t	vqrdmulhq_lane_s32	(int32x4_t a, int32x2_t v, const int lane);

// vcvtn_type1_type2:
int32x2_t	vcvtn_s32_f32	(float32x2_t a);
uint32x2_t	vcvtn_u32_f32	(float32x2_t a);
int64x1_t	vcvtn_s64_f64	(float64x1_t a);
uint64x1_t	vcvtn_u64_f64	(float64x1_t a);
int16x4_t	vcvtn_s16_f16	(float16x4_t a);
uint16x4_t	vcvtn_u16_f16	(float16x4_t a);

// vcvtnq_type1_type2:
int32x4_t	vcvtnq_s32_f32	(float32x4_t a);
uint32x4_t	vcvtnq_u32_f32	(float32x4_t a);
int64x2_t	vcvtnq_s64_f64	(float64x2_t a);
uint64x2_t	vcvtnq_u64_f64	(float64x2_t a);
int16x8_t	vcvtnq_s16_f16	(float16x8_t a);
uint16x8_t	vcvtnq_u16_f16	(float16x8_t a);

//----------------------------------------------------------------------
// 10. Multiply-accumulate
//----------------------------------------------------------------------

// vmla_type: ri = ai + bi * ci
int8x8_t	vmla_s8	(int8x8_t a, int8x8_t b, int8x8_t c);
int16x4_t	vmla_s16	(int16x4_t a, int16x4_t b, int16x4_t c);
int32x2_t	vmla_s32	(int32x2_t a, int32x2_t b, int32x2_t c);
uint8x8_t	vmla_u8	(uint8x8_t a, uint8x8_t b, uint8x8_t c);
uint16x4_t	vmla_u16	(uint16x4_t a, uint16x4_t b, uint16x4_t c);
uint32x2_t	vmla_u32	(uint32x2_t a, uint32x2_t b, uint32x2_t c);
float32x2_t	vmla_f32	(float32x2_t a, float32x2_t b, float32x2_t c);
float64x1_t	vmla_f64	(float64x1_t a, float64x1_t b, float64x1_t c);

// vmlaq_type:
int8x16_t	vmlaq_s8	(int8x16_t a, int8x16_t b, int8x16_t c);
int16x8_t	vmlaq_s16	(int16x8_t a, int16x8_t b, int16x8_t c);
int32x4_t	vmlaq_s32	(int32x4_t a, int32x4_t b, int32x4_t c);
uint8x16_t	vmlaq_u8	(uint8x16_t a, uint8x16_t b, uint8x16_t c);
uint16x8_t	vmlaq_u16	(uint16x8_t a, uint16x8_t b, uint16x8_t c);
uint32x4_t	vmlaq_u32	(uint32x4_t a, uint32x4_t b, uint32x4_t c);
float32x4_t	vmlaq_f32	(float32x4_t a, float32x4_t b, float32x4_t c);
float64x2_t	vmlaq_f64	(float64x2_t a, float64x2_t b, float64x2_t c);

// vmla_n_type: ri = ai + bi * c
int16x4_t	vmla_n_s16	(int16x4_t a, int16x4_t b, int16_t c);
int32x2_t	vmla_n_s32	(int32x2_t a, int32x2_t b, int32_t c);
uint16x4_t	vmla_n_u16	(uint16x4_t a, uint16x4_t b, uint16_t c);
uint32x2_t	vmla_n_u32	(uint32x2_t a, uint32x2_t b, uint32_t c);
float32x2_t	vmla_n_f32	(float32x2_t a, float32x2_t b, float32_t c);

// vmlaq_n_type:
int16x8_t	vmlaq_n_s16	(int16x8_t a, int16x8_t b, int16_t c);
int32x4_t	vmlaq_n_s32	(int32x4_t a, int32x4_t b, int32_t c);
uint16x8_t	vmlaq_n_u16	(uint16x8_t a, uint16x8_t b, uint16_t c);
uint32x4_t	vmlaq_n_u32	(uint32x4_t a, uint32x4_t b, uint32_t c);
float32x4_t	vmlaq_n_f32	(float32x4_t a, float32x4_t b, float32_t c);

// vmla_lane_type: ri = ai + bi * c[d]
int16x4_t	vmla_lane_s16	(int16x4_t a, int16x4_t b, int16x4_t v, const int lane);
int32x2_t	vmla_lane_s32	(int32x2_t a, int32x2_t b, int32x2_t v, const int lane);
uint16x4_t	vmla_lane_u16	(uint16x4_t a, uint16x4_t b, uint16x4_t v, const int lane);
uint32x2_t	vmla_lane_u32	(uint32x2_t a, uint32x2_t b, uint32x2_t v, const int lane);
float32x2_t	vmla_lane_f32	(float32x2_t a, float32x2_t b, float32x2_t v, const int lane);

// vmlaq_lane_type:
int16x8_t	vmlaq_lane_s16	(int16x8_t a, int16x8_t b, int16x4_t v, const int lane);
int32x4_t	vmlaq_lane_s32	(int32x4_t a, int32x4_t b, int32x2_t v, const int lane);
uint16x8_t	vmlaq_lane_u16	(uint16x8_t a, uint16x8_t b, uint16x4_t v, const int lane);
uint32x4_t	vmlaq_lane_u32	(uint32x4_t a, uint32x4_t b, uint32x2_t v, const int lane);
float32x4_t	vmlaq_lane_f32	(float32x4_t a, float32x4_t b, float32x2_t v, const int lane);

// vmlal_type: 长指令 ri = ai + bi * ci
int16x8_t	vmlal_s8	(int16x8_t a, int8x8_t b, int8x8_t c);
int32x4_t	vmlal_s16	(int32x4_t a, int16x4_t b, int16x4_t c);
int64x2_t	vmlal_s32	(int64x2_t a, int32x2_t b, int32x2_t c);
uint16x8_t	vmlal_u8	(uint16x8_t a, uint8x8_t b, uint8x8_t c);
uint32x4_t	vmlal_u16	(uint32x4_t a, uint16x4_t b, uint16x4_t c);
uint64x2_t	vmlal_u32	(uint64x2_t a, uint32x2_t b, uint32x2_t c);

// vmlal_n_type:
int32x4_t	vmlal_n_s16	(int32x4_t a, int16x4_t b, int16_t c);
int64x2_t	vmlal_n_s32	(int64x2_t a, int32x2_t b, int32_t c);
uint32x4_t	vmlal_n_u16	(uint32x4_t a, uint16x4_t b, uint16_t c);
uint64x2_t	vmlal_n_u32	(uint64x2_t a, uint32x2_t b, uint32_t c);

// vmlal_lane_type:
int32x4_t	vmlal_lane_s16	(int32x4_t a, int16x4_t b, int16x4_t v, const int lane);
int64x2_t	vmlal_lane_s32	(int64x2_t a, int32x2_t b, int32x2_t v, const int lane);
uint32x4_t	vmlal_lane_u16	(uint32x4_t a, uint16x4_t b, uint16x4_t v, const int lane);
uint64x2_t	vmlal_lane_u32	(uint64x2_t a, uint32x2_t b, uint32x2_t v, const int lane);

// vfma_f32:ri = ai + bi * ci 在加法之前,bi、ci 相乘的结果不会被四舍五入
float32x2_t	vfma_f32	(float32x2_t a, float32x2_t b, float32x2_t c);

// vqdmlal_type: ri = sat(ai + 2 * bi * ci) bi/ci 的元素大小是 ai 的一半
int32x4_t	vqdmlal_s16	(int32x4_t a, int16x4_t b, int16x4_t c);
int64x2_t	vqdmlal_s32	(int64x2_t a, int32x2_t b, int32x2_t c);

// vqdmlal_n_type: ri = sat(ai + 2 * bi * c)
int32x4_t	vqdmlal_n_s16	(int32x4_t a, int16x4_t b, int16_t c);
int64x2_t	vqdmlal_n_s32	(int64x2_t a, int32x2_t b, int32_t c);

// vqdmlal_lane_type: ri = sat(ai + 2 * bi * c[d])
int32x4_t	vqdmlal_lane_s16	(int32x4_t a, int16x4_t b, int16x4_t v, const int lane);
int64x2_t	vqdmlal_lane_s32	(int64x2_t a, int32x2_t b, int32x2_t v, const int lane);

//----------------------------------------------------------------------
// 11. Multiply-Subtract
//----------------------------------------------------------------------

// vmls_type: ri = ai - bi * ci
int8x8_t	vmls_s8	(int8x8_t a, int8x8_t b, int8x8_t c);
int16x4_t	vmls_s16	(int16x4_t a, int16x4_t b, int16x4_t c);
int32x2_t	vmls_s32	(int32x2_t a, int32x2_t b, int32x2_t c);
uint8x8_t	vmls_u8	(uint8x8_t a, uint8x8_t b, uint8x8_t c);
uint16x4_t	vmls_u16	(uint16x4_t a, uint16x4_t b, uint16x4_t c);
uint32x2_t	vmls_u32	(uint32x2_t a, uint32x2_t b, uint32x2_t c);
float32x2_t	vmls_f32	(float32x2_t a, float32x2_t b, float32x2_t c);
float64x1_t	vmls_f64	(float64x1_t a, float64x1_t b, float64x1_t c);

// vmlsq_type:
int8x16_t	vmlsq_s8	(int8x16_t a, int8x16_t b, int8x16_t c);
int16x8_t	vmlsq_s16	(int16x8_t a, int16x8_t b, int16x8_t c);
int32x4_t	vmlsq_s32	(int32x4_t a, int32x4_t b, int32x4_t c);
uint8x16_t	vmlsq_u8	(uint8x16_t a, uint8x16_t b, uint8x16_t c);
uint16x8_t	vmlsq_u16	(uint16x8_t a, uint16x8_t b, uint16x8_t c);
uint32x4_t	vmlsq_u32	(uint32x4_t a, uint32x4_t b, uint32x4_t c);
float32x4_t	vmlsq_f32	(float32x4_t a, float32x4_t b, float32x4_t c);
float64x2_t	vmlsq_f64	(float64x2_t a, float64x2_t b, float64x2_t c);

// vmls_n_type: ri = ai - bi * c
int16x4_t	vmls_n_s16	(int16x4_t a, int16x4_t b, int16_t c);
int32x2_t	vmls_n_s32	(int32x2_t a, int32x2_t b, int32_t c);
uint16x4_t	vmls_n_u16	(uint16x4_t a, uint16x4_t b, uint16_t c);
uint32x2_t	vmls_n_u32	(uint32x2_t a, uint32x2_t b, uint32_t c);
float32x2_t	vmls_n_f32	(float32x2_t a, float32x2_t b, float32_t c);

// vmlsq_n_type:
int16x8_t	vmlsq_n_s16	(int16x8_t a, int16x8_t b, int16_t c);
int32x4_t	vmlsq_n_s32	(int32x4_t a, int32x4_t b, int32_t c);
uint16x8_t	vmlsq_n_u16	(uint16x8_t a, uint16x8_t b, uint16_t c);
uint32x4_t	vmlsq_n_u32	(uint32x4_t a, uint32x4_t b, uint32_t c);
float32x4_t	vmlsq_n_f32	(float32x4_t a, float32x4_t b, float32_t c);

// vmls_lane_type: ri = ai - bi * c[d]
int16x4_t	vmls_lane_s16	(int16x4_t a, int16x4_t b, int16x4_t v, const int lane);
int32x2_t	vmls_lane_s32	(int32x2_t a, int32x2_t b, int32x2_t v, const int lane);
uint16x4_t	vmls_lane_u16	(uint16x4_t a, uint16x4_t b, uint16x4_t v, const int lane);
uint32x2_t	vmls_lane_u32	(uint32x2_t a, uint32x2_t b, uint32x2_t v, const int lane);
float32x2_t	vmls_lane_f32	(float32x2_t a, float32x2_t b, float32x2_t v, const int lane);

// vmlsq_lane_type:
int16x8_t	vmlsq_lane_s16	(int16x8_t a, int16x8_t b, int16x4_t v, const int lane);
int32x4_t	vmlsq_lane_s32	(int32x4_t a, int32x4_t b, int32x2_t v, const int lane);
uint16x8_t	vmlsq_lane_u16	(uint16x8_t a, uint16x8_t b, uint16x4_t v, const int lane);
uint32x4_t	vmlsq_lane_u32	(uint32x4_t a, uint32x4_t b, uint32x2_t v, const int lane);
float32x4_t	vmlsq_lane_f32	(float32x4_t a, float32x4_t b, float32x2_t v, const int lane);

// vmlsl_type: 长指令 ri = ai - bi * ci
int16x8_t	vmlsl_s8	(int16x8_t a, int8x8_t b, int8x8_t c);
int32x4_t	vmlsl_s16	(int32x4_t a, int16x4_t b, int16x4_t c);
int64x2_t	vmlsl_s32	(int64x2_t a, int32x2_t b, int32x2_t c);
uint16x8_t	vmlsl_u8	(uint16x8_t a, uint8x8_t b, uint8x8_t c);
uint32x4_t	vmlsl_u16	(uint32x4_t a, uint16x4_t b, uint16x4_t c);
uint64x2_t	vmlsl_u32	(uint64x2_t a, uint32x2_t b, uint32x2_t c);

// vmlsl_n_type:
int32x4_t	vmlsl_n_s16	(int32x4_t a, int16x4_t b, int16_t c);
int64x2_t	vmlsl_n_s32	(int64x2_t a, int32x2_t b, int32_t c);
uint32x4_t	vmlsl_n_u16	(uint32x4_t a, uint16x4_t b, uint16_t c);
uint64x2_t	vmlsl_n_u32	(uint64x2_t a, uint32x2_t b, uint32_t c);

// vmlsl_lane_type:
int32x4_t	vmlsl_lane_s16	(int32x4_t a, int16x4_t b, int16x4_t v, const int lane);
int64x2_t	vmlsl_lane_s32	(int64x2_t a, int32x2_t b, int32x2_t v, const int lane);
uint32x4_t	vmlsl_lane_u16	(uint32x4_t a, uint16x4_t b, uint16x4_t v, const int lane);
uint64x2_t	vmlsl_lane_u32	(uint64x2_t a, uint32x2_t b, uint32x2_t v, const int lane);

// vfms_f32:ri = ai - bi * ci 在减法之前,bi、ci 相乘的结果不会被四舍五入
float32x2_t	vfms_f32	(float32x2_t a, float32x2_t b, float32x2_t c);

// vqdmlsl_type: ri = sat(ai – 2 * bi * ci) bi/ci 的元素大小是 ai 的一半
int32x4_t	vqdmlsl_s16	(int32x4_t a, int16x4_t b, int16x4_t c);
int64x2_t	vqdmlsl_s32	(int64x2_t a, int32x2_t b, int32x2_t c);

// vqdmlsl_n_type: ri = sat(ai – 2 * bi * c)
int32x4_t	vqdmlsl_n_s16	(int32x4_t a, int16x4_t b, int16_t c);
int64x2_t	vqdmlsl_n_s32	(int64x2_t a, int32x2_t b, int32_t c);

// vqdmlsl_lane_type: ri = sat(ai – 2 * bi * c[d])
int32x4_t	vqdmlsl_lane_s16	(int32x4_t a, int16x4_t b, int16x4_t v, const int lane);
int64x2_t	vqdmlsl_lane_s32	(int64x2_t a, int32x2_t b, int32x2_t v, const int lane);

//----------------------------------------------------------------------
// 12. Max-Min
//----------------------------------------------------------------------

// vmax_type: ri = ai >= bi ? ai : bi
int8x8_t	vmax_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vmax_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vmax_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vmax_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vmax_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vmax_u32	(uint32x2_t a, uint32x2_t b);
float32x2_t	vmax_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vmax_f64	(float64x1_t a, float64x1_t b);
float16x4_t	vmax_f16	(float16x4_t a, float16x4_t b);

// vmaxq_type:
int8x16_t	vmaxq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vmaxq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vmaxq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vmaxq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vmaxq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vmaxq_u32	(uint32x4_t a, uint32x4_t b);
float32x4_t	vmaxq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vmaxq_f64	(float64x2_t a, float64x2_t b);
float16x8_t	vmaxq_f16	(float16x8_t a, float16x8_t b);

// vpmax_type: r0 = a0 >= a1 ? a0 : a1, ..., r4 = b0 >= b1 ? b0 : b1, ...
int8x8_t	vpmax_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vpmax_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vpmax_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vpmax_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vpmax_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vpmax_u32	(uint32x2_t a, uint32x2_t b);
float32x2_t	vpmax_f32	(float32x2_t a, float32x2_t b);
float16x4_t	vpmax_f16	(float16x4_t a, float16x4_t b);

// vmin_type: ri = ai <= bi ? ai : bi
int8x8_t	vmin_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vmin_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vmin_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vmin_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vmin_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vmin_u32	(uint32x2_t a, uint32x2_t b);
float32x2_t	vmin_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vmin_f64	(float64x1_t a, float64x1_t b);
float16x4_t	vmin_f16	(float16x4_t a, float16x4_t b);

// vminq_type:
int8x16_t	vminq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vminq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vminq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vminq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vminq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vminq_u32	(uint32x4_t a, uint32x4_t b);
float32x4_t	vminq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vminq_f64	(float64x2_t a, float64x2_t b);

// vpmin_type: r0 = a0 <= a1 ? a0 : a1, ..., r4 = b0 <= b1 ? b0 : b1, ...
int8x8_t	vpmin_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vpmin_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vpmin_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vpmin_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vpmin_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vpmin_u32	(uint32x2_t a, uint32x2_t b);
float32x2_t	vpmin_f32	(float32x2_t a, float32x2_t b);

// vmaxv_type:
int8_t	vmaxv_s8	(int8x8_t a);
int16_t	vmaxv_s16	(int16x4_t a);
int32_t	vmaxv_s32	(int32x2_t a);
uint8_t	vmaxv_u8	(uint8x8_t a);
uint16_t	vmaxv_u16	(uint16x4_t a);
uint32_t	vmaxv_u32	(uint32x2_t a);
float32_t	vmaxv_f32	(float32x2_t a);

// vmaxvq_type:
int8_t	vmaxvq_s8	(int8x16_t a);
int16_t	vmaxvq_s16	(int16x8_t a);
int32_t	vmaxvq_s32	(int32x4_t a);
uint8_t	vmaxvq_u8	(uint8x16_t a);
uint16_t	vmaxvq_u16	(uint16x8_t a);
uint32_t	vmaxvq_u32	(uint32x4_t a);
float32_t	vmaxvq_f32	(float32x4_t a);
float64_t	vmaxvq_f64	(float64x2_t a);

// vmaxnm_type:
float32x2_t	vmaxnm_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vmaxnm_f64	(float64x1_t a, float64x1_t b);

// vmaxnmq_type:
float32x4_t	vmaxnmq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vmaxnmq_f64	(float64x2_t a, float64x2_t b);

// vmaxnmv_type:
float32_t	vmaxnmv_f32	(float32x2_t a);

// vmaxnmq_type:
float32x4_t	vmaxnmq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vmaxnmq_f64	(float64x2_t a, float64x2_t b);
float16x8_t	vmaxnmq_f16	(float16x8_t a, float16x8_t b);

// vmaxnmh_type:
//float16_t	vmaxnmh_f16	(float16_t a, float16_t b);

// vminv_type:
int8_t	vminv_s8	(int8x8_t a);
int16_t	vminv_s16	(int16x4_t a);
int32_t	vminv_s32	(int32x2_t a);
uint8_t	vminv_u8	(uint8x8_t a);
uint16_t	vminv_u16	(uint16x4_t a);
uint32_t	vminv_u32	(uint32x2_t a);
float32_t	vminv_f32	(float32x2_t a);

// vminvq_type:
int8_t	vminvq_s8	(int8x16_t a);
int16_t	vminvq_s16	(int16x8_t a);
int32_t	vminvq_s32	(int32x4_t a);
uint8_t	vminvq_u8	(uint8x16_t a);
uint16_t	vminvq_u16	(uint16x8_t a);
uint32_t	vminvq_u32	(uint32x4_t a);
float32_t	vminvq_f32	(float32x4_t a);
float64_t	vminvq_f64	(float64x2_t a);

// vminnm_type:
float32x2_t	vminnm_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vminnm_f64	(float64x1_t a, float64x1_t b);
float16x4_t	vminnm_f16	(float16x4_t a, float16x4_t b);

// vminnmq_type:
float32x4_t	vminnmq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vminnmq_f64	(float64x2_t a, float64x2_t b);
float16x8_t	vminnmq_f16	(float16x8_t a, float16x8_t b);

// vminnmv_type:
float32_t	vminnmv_f32	(float32x2_t a);

// vminnmq_type:
float32x4_t	vminnmq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vminnmq_f64	(float64x2_t a, float64x2_t b);
float16x8_t	vminnmq_f16	(float16x8_t a, float16x8_t b);

// vminnmh_type:
//float16_t	vminnmh_f16	(float16_t a, float16_t b);

//----------------------------------------------------------------------
// 13. Comparison and Test
//----------------------------------------------------------------------

// vceq_type: ri = ai == bi ? 1...1 : 0...0
uint8x8_t	vceq_s8	(int8x8_t a, int8x8_t b);
uint16x4_t	vceq_s16	(int16x4_t a, int16x4_t b);
uint32x2_t	vceq_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vceq_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vceq_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vceq_u32	(uint32x2_t a, uint32x2_t b);
uint32x2_t	vceq_f32	(float32x2_t a, float32x2_t b);
uint64x1_t	vceq_s64	(int64x1_t a, int64x1_t b);
uint64x1_t	vceq_u64	(uint64x1_t a, uint64x1_t b);
uint64x1_t	vceq_f64	(float64x1_t a, float64x1_t b);

// vceqq_type:
uint8x16_t	vceqq_s8	(int8x16_t a, int8x16_t b);
uint16x8_t	vceqq_s16	(int16x8_t a, int16x8_t b);
uint32x4_t	vceqq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vceqq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vceqq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vceqq_u32	(uint32x4_t a, uint32x4_t b);
uint32x4_t	vceqq_f32	(float32x4_t a, float32x4_t b);
uint64x2_t	vceqq_s64	(int64x2_t a, int64x2_t b);
uint64x2_t	vceqq_u64	(uint64x2_t a, uint64x2_t b);
uint64x2_t	vceqq_f64	(float64x2_t a, float64x2_t b);

// vcge_type: ri = ai >= bi ? 1...1:0...0
uint8x8_t	vcge_s8	(int8x8_t a, int8x8_t b);
uint16x4_t	vcge_s16	(int16x4_t a, int16x4_t b);
uint32x2_t	vcge_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vcge_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vcge_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vcge_u32	(uint32x2_t a, uint32x2_t b);
uint32x2_t	vcge_f32	(float32x2_t a, float32x2_t b);
uint64x1_t	vcge_s64	(int64x1_t a, int64x1_t b);
uint64x1_t	vcge_u64	(uint64x1_t a, uint64x1_t b);
uint64x1_t	vcge_f64	(float64x1_t a, float64x1_t b);
uint16x4_t	vcge_f16	(float16x4_t a, float16x4_t b);

// vcgeq_type:
uint8x16_t	vcgeq_s8	(int8x16_t a, int8x16_t b);
uint16x8_t	vcgeq_s16	(int16x8_t a, int16x8_t b);
uint32x4_t	vcgeq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vcgeq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vcgeq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vcgeq_u32	(uint32x4_t a, uint32x4_t b);
uint32x4_t	vcgeq_f32	(float32x4_t a, float32x4_t b);
uint64x2_t	vcgeq_s64	(int64x2_t a, int64x2_t b);
uint64x2_t	vcgeq_u64	(uint64x2_t a, uint64x2_t b);
uint64x2_t	vcgeq_f64	(float64x2_t a, float64x2_t b);
uint16x8_t	vcgeq_f16	(float16x8_t a, float16x8_t b);

// vcle_type: ri = ai <= bi ? 1...1:0...0
uint8x8_t	vcle_s8	(int8x8_t a, int8x8_t b);
uint16x4_t	vcle_s16	(int16x4_t a, int16x4_t b);
uint32x2_t	vcle_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vcle_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vcle_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vcle_u32	(uint32x2_t a, uint32x2_t b);
uint32x2_t	vcle_f32	(float32x2_t a, float32x2_t b);
uint64x1_t	vcle_s64	(int64x1_t a, int64x1_t b);
uint64x1_t	vcle_u64	(uint64x1_t a, uint64x1_t b);
uint64x1_t	vcle_f64	(float64x1_t a, float64x1_t b);
uint16x4_t	vcle_f16	(float16x4_t a, float16x4_t b);

// vcleq_type:
uint8x16_t	vcleq_s8	(int8x16_t a, int8x16_t b);
uint16x8_t	vcleq_s16	(int16x8_t a, int16x8_t b);
uint32x4_t	vcleq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vcleq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vcleq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vcleq_u32	(uint32x4_t a, uint32x4_t b);
uint32x4_t	vcleq_f32	(float32x4_t a, float32x4_t b);
uint64x2_t	vcleq_s64	(int64x2_t a, int64x2_t b);
uint64x2_t	vcleq_u64	(uint64x2_t a, uint64x2_t b);
uint64x2_t	vcleq_f64	(float64x2_t a, float64x2_t b);
uint16x8_t	vcleq_f16	(float16x8_t a, float16x8_t b);

// vcgt_type: ri = ai > bi ? 1...1:0...0
uint8x8_t	vcgt_s8	(int8x8_t a, int8x8_t b);
uint16x4_t	vcgt_s16	(int16x4_t a, int16x4_t b);
uint32x2_t	vcgt_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vcgt_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vcgt_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vcgt_u32	(uint32x2_t a, uint32x2_t b);
uint32x2_t	vcgt_f32	(float32x2_t a, float32x2_t b);
uint64x1_t	vcgt_s64	(int64x1_t a, int64x1_t b);
uint64x1_t	vcgt_u64	(uint64x1_t a, uint64x1_t b);
uint64x1_t	vcgt_f64	(float64x1_t a, float64x1_t b);
uint16x4_t	vcgt_f16	(float16x4_t a, float16x4_t b);

// vcgtq_type:
uint8x16_t	vcgtq_s8	(int8x16_t a, int8x16_t b);
uint16x8_t	vcgtq_s16	(int16x8_t a, int16x8_t b);
uint32x4_t	vcgtq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vcgtq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vcgtq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vcgtq_u32	(uint32x4_t a, uint32x4_t b);
uint32x4_t	vcgtq_f32	(float32x4_t a, float32x4_t b);
uint64x2_t	vcgtq_s64	(int64x2_t a, int64x2_t b);
uint64x2_t	vcgtq_u64	(uint64x2_t a, uint64x2_t b);
uint64x2_t	vcgtq_f64	(float64x2_t a, float64x2_t b);
uint16x8_t	vcgtq_f16	(float16x8_t a, float16x8_t b);

// vclt_type: ri = ai < bi ? 1...1:0...0
uint8x8_t	vclt_s8	(int8x8_t a, int8x8_t b);
uint16x4_t	vclt_s16	(int16x4_t a, int16x4_t b);
uint32x2_t	vclt_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vclt_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vclt_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vclt_u32	(uint32x2_t a, uint32x2_t b);
uint32x2_t	vclt_f32	(float32x2_t a, float32x2_t b);
uint64x1_t	vclt_s64	(int64x1_t a, int64x1_t b);
uint64x1_t	vclt_u64	(uint64x1_t a, uint64x1_t b);
uint64x1_t	vclt_f64	(float64x1_t a, float64x1_t b);
uint16x4_t	vclt_f16	(float16x4_t a, float16x4_t b);

// vcltq_type:
uint8x16_t	vcltq_s8	(int8x16_t a, int8x16_t b);
uint16x8_t	vcltq_s16	(int16x8_t a, int16x8_t b);
uint32x4_t	vcltq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vcltq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vcltq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vcltq_u32	(uint32x4_t a, uint32x4_t b);
uint32x4_t	vcltq_f32	(float32x4_t a, float32x4_t b);
uint64x2_t	vcltq_s64	(int64x2_t a, int64x2_t b);
uint64x2_t	vcltq_u64	(uint64x2_t a, uint64x2_t b);
uint64x2_t	vcltq_f64	(float64x2_t a, float64x2_t b);
uint16x8_t	vcltq_f16	(float16x8_t a, float16x8_t b);

// vcage_f32: ri = |ai| >= |bi| ? 1...1:0...0
uint32x2_t	vcage_f32	(float32x2_t a, float32x2_t b);

// vcageq_f32:
uint32x4_t	vcageq_f32	(float32x4_t a, float32x4_t b);

// vcale_f32: ri = |ai| <= |bi| ? 1...1:0...0
uint32x2_t	vcale_f32	(float32x2_t a, float32x2_t b);

// vcaleq_f32:
uint32x4_t	vcaleq_f32	(float32x4_t a, float32x4_t b);

// vcagt_f32: ri = |ai| > |bi| ? 1...1:0...0
uint32x2_t	vcagt_f32	(float32x2_t a, float32x2_t b);

// vcagtq_f32:
uint32x4_t	vcagtq_f32	(float32x4_t a, float32x4_t b);

// vcalt_f32: ri = |ai| < |bi| ? 1...1:0...0
uint32x2_t	vcalt_f32	(float32x2_t a, float32x2_t b);

// vcaltq_f32:
uint32x4_t	vcaltq_f32	(float32x4_t a, float32x4_t b);

// vtst_type: ri = (ai & bi != 0) ? 1...1:0...0
uint8x8_t	vtst_s8	(int8x8_t a, int8x8_t b);
uint16x4_t	vtst_s16	(int16x4_t a, int16x4_t b);
uint32x2_t	vtst_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vtst_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vtst_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vtst_u32	(uint32x2_t a, uint32x2_t b);
uint64x1_t	vtst_s64	(int64x1_t a, int64x1_t b);
uint64x1_t	vtst_u64	(uint64x1_t a, uint64x1_t b);

// vtstq_type:
uint8x16_t	vtstq_s8	(int8x16_t a, int8x16_t b);
uint16x8_t	vtstq_s16	(int16x8_t a, int16x8_t b);
uint32x4_t	vtstq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vtstq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vtstq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vtstq_u32	(uint32x4_t a, uint32x4_t b);
uint64x2_t	vtstq_s64	(int64x2_t a, int64x2_t b);
uint64x2_t	vtstq_u64	(uint64x2_t a, uint64x2_t b);

//----------------------------------------------------------------------
// 14. Rounding
//----------------------------------------------------------------------

// vrndn_type:
float32x2_t	vrndn_f32	(float32x2_t a);
float64x1_t	vrndn_f64	(float64x1_t a);
float16x4_t	vrndn_f16	(float16x4_t a);

// vrndnq_type:
float32x4_t	vrndnq_f32	(float32x4_t a);
float64x2_t	vrndnq_f64	(float64x2_t a);
float16x8_t	vrndnq_f16	(float16x8_t a);

// vrnda_type:
float32x2_t	vrnda_f32	(float32x2_t a);
float64x1_t	vrnda_f64	(float64x1_t a);
float16x4_t	vrnda_f16	(float16x4_t a);

// vrndaq_type:
float32x4_t	vrndaq_f32	(float32x4_t a);
float64x2_t	vrndaq_f64	(float64x2_t a);
float16x8_t	vrndaq_f16	(float16x8_t a);

// vrndp_type:
float32x2_t	vrndp_f32	(float32x2_t a);
float64x1_t	vrndp_f64	(float64x1_t a);
float16x4_t	vrndp_f16	(float16x4_t a);

// vrndpq_type:
float32x4_t	vrndpq_f32	(float32x4_t a);
float64x2_t	vrndpq_f64	(float64x2_t a);
float16x8_t	vrndpq_f16	(float16x8_t a);

// vrndm_type:
float32x2_t	vrndm_f32	(float32x2_t a);
float64x1_t	vrndm_f64	(float64x1_t a);
float16x4_t	vrndm_f16	(float16x4_t a);

// vrndmq_type:
float32x4_t	vrndmq_f32	(float32x4_t a);
float64x2_t	vrndmq_f64	(float64x2_t a);
float16x8_t	vrndmq_f16	(float16x8_t a);

// vrnd_type:
float32x2_t	vrnd_f32	(float32x2_t a);
float64x1_t	vrnd_f64	(float64x1_t a);
float16x4_t	vrnd_f16	(float16x4_t a);

// vrndq_type:
float32x4_t	vrndq_f32	(float32x4_t a);
float64x2_t	vrndq_f64	(float64x2_t a);
float16x8_t	vrndq_f16	(float16x8_t a);

//----------------------------------------------------------------------
// 15. Absolute Values
//----------------------------------------------------------------------

// vabs_type: ri = |ai|
int8x8_t	vabs_s8	(int8x8_t a);
int16x4_t	vabs_s16	(int16x4_t a);
int32x2_t	vabs_s32	(int32x2_t a);
float32x2_t	vabs_f32	(float32x2_t a);
int64x1_t	vabs_s64	(int64x1_t a);
float64x1_t	vabs_f64	(float64x1_t a);
float16x4_t	vabs_f16	(float16x4_t a);

// vabsq_type:
int8x16_t	vabsq_s8	(int8x16_t a);
int16x8_t	vabsq_s16	(int16x8_t a);
int32x4_t	vabsq_s32	(int32x4_t a);
float32x4_t	vabsq_f32	(float32x4_t a);
int64x2_t	vabsq_s64	(int64x2_t a);
float64x2_t	vabsq_f64	(float64x2_t a);
float16x8_t	vabsq_f16	(float16x8_t a);

// vqabs_type: ri = sat(|ai|)
int8x8_t	vqabs_s8	(int8x8_t a);
int16x4_t	vqabs_s16	(int16x4_t a);
int32x2_t	vqabs_s32	(int32x2_t a);
int64x1_t	vqabs_s64	(int64x1_t a);

// vqabsq_type:
int8x16_t	vqabsq_s8	(int8x16_t a);
int16x8_t	vqabsq_s16	(int16x8_t a);
int32x4_t	vqabsq_s32	(int32x4_t a);
int64x2_t	vqabsq_s64	(int64x2_t a);

// vabd_type: ri = |ai - bi|
int8x8_t	vabd_s8	(int8x8_t a, int8x8_t b);
int16x4_t	vabd_s16	(int16x4_t a, int16x4_t b);
int32x2_t	vabd_s32	(int32x2_t a, int32x2_t b);
uint8x8_t	vabd_u8	(uint8x8_t a, uint8x8_t b);
uint16x4_t	vabd_u16	(uint16x4_t a, uint16x4_t b);
uint32x2_t	vabd_u32	(uint32x2_t a, uint32x2_t b);
float32x2_t	vabd_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vabd_f64	(float64x1_t a, float64x1_t b);
float16x4_t	vabd_f16	(float16x4_t a, float16x4_t b);

// vabdq_type:
int8x16_t	vabdq_s8	(int8x16_t a, int8x16_t b);
int16x8_t	vabdq_s16	(int16x8_t a, int16x8_t b);
int32x4_t	vabdq_s32	(int32x4_t a, int32x4_t b);
uint8x16_t	vabdq_u8	(uint8x16_t a, uint8x16_t b);
uint16x8_t	vabdq_u16	(uint16x8_t a, uint16x8_t b);
uint32x4_t	vabdq_u32	(uint32x4_t a, uint32x4_t b);
float32x4_t	vabdq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vabdq_f64	(float64x2_t a, float64x2_t b);
float16x8_t	vabdq_f16	(float16x8_t a, float16x8_t b);

// vabdl_type: 长指令
int16x8_t	vabdl_s8	(int8x8_t a, int8x8_t b);
int32x4_t	vabdl_s16	(int16x4_t a, int16x4_t b);
int64x2_t	vabdl_s32	(int32x2_t a, int32x2_t b);
uint16x8_t	vabdl_u8	(uint8x8_t a, uint8x8_t b);
uint32x4_t	vabdl_u16	(uint16x4_t a, uint16x4_t b);
uint64x2_t	vabdl_u32	(uint32x2_t a, uint32x2_t b);

// vabdl_high_type:
int16x8_t	vabdl_high_s8	(int8x16_t a, int8x16_t b);
int32x4_t	vabdl_high_s16	(int16x8_t a, int16x8_t b);
int64x2_t	vabdl_high_s32	(int32x4_t a, int32x4_t b);
uint16x8_t	vabdl_high_u8	(uint8x16_t a, uint8x16_t b);
uint32x4_t	vabdl_high_u16	(uint16x8_t a, uint16x8_t b);
uint64x2_t	vabdl_high_u32	(uint32x4_t a, uint32x4_t b);

// vaba_type: ri = ai + |bi - ci|
int8x8_t	vaba_s8	(int8x8_t a, int8x8_t b, int8x8_t c);
int16x4_t	vaba_s16	(int16x4_t a, int16x4_t b, int16x4_t c);
int32x2_t	vaba_s32	(int32x2_t a, int32x2_t b, int32x2_t c);
uint8x8_t	vaba_u8	(uint8x8_t a, uint8x8_t b, uint8x8_t c);
uint16x4_t	vaba_u16	(uint16x4_t a, uint16x4_t b, uint16x4_t c);
uint32x2_t	vaba_u32	(uint32x2_t a, uint32x2_t b, uint32x2_t c);

// vabaq_type:
int8x16_t	vabaq_s8	(int8x16_t a, int8x16_t b, int8x16_t c);
int16x8_t	vabaq_s16	(int16x8_t a, int16x8_t b, int16x8_t c);
int32x4_t	vabaq_s32	(int32x4_t a, int32x4_t b, int32x4_t c);
uint8x16_t	vabaq_u8	(uint8x16_t a, uint8x16_t b, uint8x16_t c);
uint16x8_t	vabaq_u16	(uint16x8_t a, uint16x8_t b, uint16x8_t c);
uint32x4_t	vabaq_u32	(uint32x4_t a, uint32x4_t b, uint32x4_t c);

// vabal_type: 长指令
int16x8_t	vabal_s8	(int16x8_t a, int8x8_t b, int8x8_t c);
int32x4_t	vabal_s16	(int32x4_t a, int16x4_t b, int16x4_t c);
int64x2_t	vabal_s32	(int64x2_t a, int32x2_t b, int32x2_t c);
uint16x8_t	vabal_u8	(uint16x8_t a, uint8x8_t b, uint8x8_t c);
uint32x4_t	vabal_u16	(uint32x4_t a, uint16x4_t b, uint16x4_t c);
uint64x2_t	vabal_u32	(uint64x2_t a, uint32x2_t b, uint32x2_t c);

// vabal_high_type:
int16x8_t	vabal_high_s8	(int16x8_t a, int8x16_t b, int8x16_t c);
int32x4_t	vabal_high_s16	(int32x4_t a, int16x8_t b, int16x8_t c);
int64x2_t	vabal_high_s32	(int64x2_t a, int32x4_t b, int32x4_t c);
uint16x8_t	vabal_high_u8	(uint16x8_t a, uint8x16_t b, uint8x16_t c);
uint32x4_t	vabal_high_u16	(uint32x4_t a, uint16x8_t b, uint16x8_t c);
uint64x2_t	vabal_high_u32	(uint64x2_t a, uint32x4_t b, uint32x4_t c);

//----------------------------------------------------------------------
// 16. Reciprocal Estimation
//----------------------------------------------------------------------

// vrecpe_type:
uint32x2_t	vrecpe_u32	(uint32x2_t a);
float32x2_t	vrecpe_f32	(float32x2_t a);
float64x1_t	vrecpe_f64	(float64x1_t a);
float16x4_t	vrecpe_f16	(float16x4_t a);

// vrecpeq_type:
uint32x4_t	vrecpeq_u32	(uint32x4_t a);
float32x4_t	vrecpeq_f32	(float32x4_t a);
float64x2_t	vrecpeq_f64	(float64x2_t a);
float16x8_t	vrecpeq_f16	(float16x8_t a);

// vrecps_type:
float32x2_t	vrecps_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vrecps_f64	(float64x1_t a, float64x1_t b);
float16x4_t	vrecps_f16	(float16x4_t a, float16x4_t b);

// vrecpsq_type:
float32x4_t	vrecpsq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vrecpsq_f64	(float64x2_t a, float64x2_t b);
float16x8_t	vrecpsq_f16	(float16x8_t a, float16x8_t b);

//----------------------------------------------------------------------
// 17. Reciprocal Square Root Estimation
//----------------------------------------------------------------------

// vrsqrte_type:
uint32x2_t	vrsqrte_u32	(uint32x2_t a);
float32x2_t	vrsqrte_f32	(float32x2_t a);
float64x1_t	vrsqrte_f64	(float64x1_t a);
float16x4_t	vrsqrte_f16	(float16x4_t a);

// vrsqrteq_type:
uint32x4_t	vrsqrteq_u32	(uint32x4_t a);
float32x4_t	vrsqrteq_f32	(float32x4_t a);
float64x2_t	vrsqrteq_f64	(float64x2_t a);
float16x8_t	vrsqrteq_f16	(float16x8_t a);

// vrsqrts_type:
float32x2_t	vrsqrts_f32	(float32x2_t a, float32x2_t b);
float64x1_t	vrsqrts_f64	(float64x1_t a, float64x1_t b);
float16x4_t	vrsqrts_f16	(float16x4_t a, float16x4_t b);

// vrsqrtsq_type:
float32x4_t	vrsqrtsq_f32	(float32x4_t a, float32x4_t b);
float64x2_t	vrsqrtsq_f64	(float64x2_t a, float64x2_t b);
float16x8_t	vrsqrtsq_f16	(float16x8_t a, float16x8_t b);

#if defined(NEON_SIM_IMPLEMENTATION)

//----------------------------------------------------------------------
// 2. Intrinsics implementation
//----------------------------------------------------------------------

////// Load
// vld1
uint8x8_t vld1_u8(uint8_t const* ptr)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = ptr[i];
    }
    return r;
}
int8x8_t vld1_s8(int8_t const* ptr)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = ptr[i];
    }
    return r;
}
uint16x4_t vld1_u16(uint16_t const * ptr)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = ptr[i];
    }
    return r;
}
int16x4_t vld1_s16(int16_t const * ptr)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = ptr[i];
    }
    return r;
}
uint32x2_t vld1_u32(uint32_t const * ptr)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = ptr[i];
    }
    return r;
}
int32x2_t vld1_s32(int32_t const * ptr)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = ptr[i];
    }
    return r;
}
float32x2_t vld1_f32(float32_t const * ptr)
{
    float32x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = ptr[i];
    }
    return r;
}
float64x1_t vld1_f64(float64_t const * ptr)
{
    float64x1_t r;
    r[0] = ptr[0];
    return r;
}

// vld1q
uint8x16_t vld1q_u8(uint8_t const* ptr)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++) {
        r[i] = ptr[i];
    }
    return r;
}
int8x16_t vld1q_s8(int8_t const* ptr)
{
    int8x16_t r;
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
int16x8_t vld1q_s16(int16_t const* ptr)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = ptr[i];
    }
    return r;
}
uint32x4_t vld1q_u32(uint32_t const* ptr)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = ptr[i];
    }
    return r;
}
int32x4_t vld1q_s32(int32_t const* ptr)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = ptr[i];
    }
    return r;
}
float32x4_t vld1q_f32(float32_t const* ptr)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}


// vld2
uint8x8x2_t vld2_u8(uint8_t const * ptr)
{
    uint8x8x2_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
int8x8x2_t vld2_s8(int8_t const * ptr)
{
    int8x8x2_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
uint16x4x2_t vld2_u16(uint16_t const * ptr)
{
    uint16x4x2_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
int16x4x2_t vld2_s16(int16_t const * ptr)
{
    int16x4x2_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
uint32x2x2_t vld2_u32(uint32_t const * ptr)
{
    uint32x2x2_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
int32x2x2_t vld_s32(int32_t const * ptr)
{
    int32x2x2_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
float32x2x2_t vld2_f32(float const * ptr)
{
    float32x2x2_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}

// vld2q
uint8x16x2_t vld2q_u8(uint8_t const * ptr)
{
    uint8x16x2_t r;
    for (int i = 0; i < 16; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
int8x16x2_t vld2q_s8(int8_t const * ptr)
{
    int8x16x2_t r;
    for (int i = 0; i < 16; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
uint16x8x2_t vld2q_u16(uint16_t const * ptr)
{
    uint16x8x2_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
int16x8x2_t vld2q_s16(int16_t const * ptr)
{
    int16x8x2_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
uint32x4x2_t vld2q_u32(uint32_t const * ptr)
{
    uint32x4x2_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}
int32x4x2_t vld2q_s32(int32_t const * ptr)
{
    int32x4x2_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[2*i + 0];
        r.val[1][i] = ptr[2*i + 1];
    }
    return r;
}

// vld3
uint8x8x3_t vld3_u8(uint8_t const * ptr)
{
    uint8x8x3_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
int8x8x3_t vld3_s8(int8_t const * ptr)
{
    int8x8x3_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
uint16x4x3_t vld3_u16(uint16_t const * ptr)
{
    uint16x4x3_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
int16x4x3_t vld3_s16(int16_t const * ptr)
{
    int16x4x3_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
uint32x2x3_t vld3_u32(uint32_t const * ptr)
{
    uint32x2x3_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
int32x2x3_t vld3_s32(int32_t const * ptr)
{
    int32x2x3_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
float32x2x3_t vld3_f32(float const * ptr)
{
    float32x2x3_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}

// vld3q
uint8x16x3_t vld3q_u8(uint8_t const * ptr)
{
    uint8x16x3_t r;
    for (int i = 0; i < 16; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
int8x16x3_t vld3q_s8(int8_t const * ptr)
{
    int8x16x3_t r;
    for (int i = 0; i < 16; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
uint16x8x3_t vld3q_u16(uint16_t const * ptr)
{
    uint16x8x3_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
int16x8x3_t vld3q_s16(int16_t const * ptr)
{
    int16x8x3_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
uint32x4x3_t vld3q_u32(uint32_t const * ptr)
{
    uint32x4x3_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}
int32x4x3_t vld3q_s32(int32_t const * ptr)
{
    int32x4x3_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
    }
    return r;
}

//////////
// vld4
uint8x8x4_t vld4_u8(uint8_t const * ptr)
{
    uint8x8x4_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
int8x8x4_t vld4_s8(int8_t const * ptr)
{
    int8x8x4_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
uint16x4x4_t vld4_u16(uint16_t const * ptr)
{
    uint16x4x4_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
int16x4x4_t vld4_s16(int16_t const * ptr)
{
    int16x4x4_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
uint32x2x4_t vld4_u32(uint32_t const * ptr)
{
    uint32x2x4_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
int32x2x4_t vld4_s32(int32_t const * ptr)
{
    int32x2x4_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
float32x2x4_t vld4_f32(float const * ptr)
{
    float32x2x4_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}

// vld4q
uint8x16x4_t vld4q_u8(uint8_t const * ptr)
{
    uint8x16x4_t r;
    for (int i = 0; i < 16; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
int8x16x4_t vld4q_s8(int8_t const * ptr)
{
    int8x16x4_t r;
    for (int i = 0; i < 16; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
uint16x8x4_t vld4q_u16(uint16_t const * ptr)
{
    uint16x8x4_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
int16x8x4_t vld4q_s16(int16_t const * ptr)
{
    int16x8x4_t r;
    for (int i = 0; i < 8; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
uint32x4x4_t vld4q_u32(uint32_t const * ptr)
{
    uint32x4x4_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}
int32x4x4_t vld4q_s32(int32_t const * ptr)
{
    int32x4x4_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][i] = ptr[4*i + 0];
        r.val[1][i] = ptr[4*i + 1];
        r.val[2][i] = ptr[4*i + 2];
        r.val[3][i] = ptr[4*i + 3];
    }
    return r;
}

// vld1q_dup
float32x4_t vld1q_dup_f32(float32_t const* ptr)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = ptr[0];
    }
    return r;
}

int8x8_t vld1_lane_s8(int8_t const * ptr, int8x8_t src, const int lane)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = src[i];
    }
    r[lane] = ptr[0];
    return r;
}

uint8x8_t vld1_lane_u8(uint8_t const * ptr, uint8x8_t src, const int lane)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = src[i];
    }
    r[lane] = ptr[0];
    return r;
}

/// vldX_lane_type, X > 1
uint8x8x2_t vld2_lane_u8(uint8_t const* ptr, uint8x8x2_t src, const int lane)
{
    uint8x8x2_t res;
    if ( ! (lane >= 0 && lane <=7) )
    {
        fprintf(stderr, "only support [0, 7] for param lane\n");
        abort();
    }
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == lane)
            {
                res.val[j][i] = ptr[j];
            }
            else
            {
                res.val[j][i] = src.val[j][i];
            }
        }
    }
    return res;
}

uint8x8x3_t vld3_lane_u8(uint8_t const* ptr, uint8x8x3_t src, const int lane)
{
    if ( ! (lane >= 0 && lane <=7) )
    {
        fprintf(stderr, "only support [0, 7] for param lane\n");
        abort();
    }
    uint8x8x3_t res;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == lane)
            {
                res.val[j][i] = ptr[j];
            }
            else
            {
                res.val[j][i] = src.val[j][i];
            }
        }
    }
    return res;
}

uint8x8x4_t vld4_lane_u8(uint8_t const* ptr, uint8x8x4_t src, const int lane)
{
    if ( ! (lane >= 0 && lane <=7) )
    {
        fprintf(stderr, "only support [0, 7] for param lane\n");
        abort();
    }
    uint8x8x4_t res;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == lane)
            {
                res.val[j][i] = ptr[j];
            }
            else
            {
                res.val[j][i] = src.val[j][i];
            }
        }
    }
    return res;
}



////// Store

// vst1
void vst1_u8(uint8_t* ptr, uint8x8_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[i] = val[i];
    }
}
void vst1_s8(int8_t* ptr, int8x8_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[i] = val[i];
    }
}
void vst1_u16(uint16_t * ptr, uint16x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[i] = val[i];
    }
}
void vst1_s16(int16_t * ptr, int16x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[i] = val[i];
    }
}
void vst1_u32(uint32_t * ptr, uint32x2_t val)
{
    for (int i = 0; i < 2; i++) {
        ptr[i] = val[i];
    }
}
void vst1_s32(int32_t * ptr, int32x2_t val)
{
    for (int i = 0; i < 2; i++) {
        ptr[i] = val[i];
    }
}

// vst1q
void vst1q_u8(uint8_t* ptr, uint8x16_t val)
{
    for (int i = 0; i < 16; i++) {
        ptr[i] = val[i];
    }
}
void vst1q_s8(int8_t* ptr, int8x16_t val)
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
void vst1q_s16(int16_t* ptr, int16x8_t val)
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
void vst1q_s32(int32_t* ptr, int32x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[i] = val[i];
    }
}
void vst1q_f32(float32_t* ptr, float32x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[i] = val[i];
    }
}

// vst2
void vst2_s8(int8_t * ptr, int8x8x2_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2_s16(int16_t * ptr, int16x4x2_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2_s32(int32_t * ptr, int32x2x2_t val)
{
    for (int i = 0; i < 2; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}

void vst2_u8(uint8_t * ptr, uint8x8x2_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2_u16(uint16_t * ptr, uint16x4x2_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2_u32(uint32_t * ptr, uint32x2x2_t val)
{
    for (int i = 0; i < 2; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}

// vst2q
void vst2q_s8(int8_t * ptr, int8x16x2_t val)
{
    for (int i = 0; i < 16; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2q_s16(int16_t * ptr, int16x8x2_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2q_s32(int32_t * ptr, int32x4x2_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2q_u8(uint8_t * ptr, uint8x16x2_t val)
{
    for (int i = 0; i < 16; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2q_u16(uint16_t * ptr, uint16x8x2_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}
void vst2q_u32(uint32_t * ptr, uint32x4x2_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[2*i+0] = val.val[0][i];
        ptr[2*i+1] = val.val[1][i];
    }
}

// vst3
void vst3_s8(int8_t * ptr, int8x8x3_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3_s16(int16_t * ptr, int16x4x3_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3_s32(int32_t * ptr, int32x2x3_t val)
{
    for (int i = 0; i < 2; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}

void vst3_u8(uint8_t * ptr, uint8x8x3_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3_u16(uint16_t * ptr, uint16x4x3_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3_u32(uint32_t * ptr, uint32x2x3_t val)
{
    for (int i = 0; i < 2; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}

// vst3q
void vst3q_s8(int8_t * ptr, int8x16x3_t val)
{
    for (int i = 0; i < 16; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3q_s16(int16_t * ptr, int16x8x3_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3q_s32(int32_t * ptr, int32x4x3_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3q_u8(uint8_t * ptr, uint8x16x3_t val)
{
    for (int i = 0; i < 16; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3q_u16(uint16_t * ptr, uint16x8x3_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}
void vst3q_u32(uint32_t * ptr, uint32x4x3_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[3*i+0] = val.val[0][i];
        ptr[3*i+1] = val.val[1][i];
        ptr[3*i+2] = val.val[2][i];
    }
}

////////////////////////
// vst4
void vst4_s8(int8_t * ptr, int8x8x4_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
void vst4_s16(int16_t * ptr, int16x4x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
void vst4_s32(int32_t * ptr, int32x2x4_t val)
{
    for (int i = 0; i < 2; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}

void vst4_u8(uint8_t * ptr, uint8x8x4_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+4] = val.val[3][i];
    }
}
void vst4_u16(uint16_t * ptr, uint16x4x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
void vst4_u32(uint32_t * ptr, uint32x2x4_t val)
{
    for (int i = 0; i < 2; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+2] = val.val[3][i];
    }
}

// vst4q
void vst4q_s8(int8_t * ptr, int8x16x4_t val)
{
    for (int i = 0; i < 16; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
void vst4q_s16(int16_t * ptr, int16x8x4_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
void vst4q_s32(int32_t * ptr, int32x4x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
void vst4q_u8(uint8_t * ptr, uint8x16x4_t val)
{
    for (int i = 0; i < 16; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
void vst4q_u16(uint16_t * ptr, uint16x8x4_t val)
{
    for (int i = 0; i < 8; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
void vst4q_u32(uint32_t * ptr, uint32x4x4_t val)
{
    for (int i = 0; i < 4; i++) {
        ptr[4*i+0] = val.val[0][i];
        ptr[4*i+1] = val.val[1][i];
        ptr[4*i+2] = val.val[2][i];
        ptr[4*i+3] = val.val[3][i];
    }
}
///////////////////////

// vst4q_lane
void vst4q_lane_f32(float32_t* ptr, float32x4x4_t val, const int lane)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val.val[i][lane];
    }
}

// vmaxq_type
int8x16_t vmaxq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i=0; i<16; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int16x8_t vmaxq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int32x4_t vmaxq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int8x16_t vmaxq_u8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i=0; i<16; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int16x8_t vmaxq_u16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int32x4_t vmaxq_u32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

float32x4_t vmaxq_f32(float32x4_t N, float32x4_t M)
{
    float32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}


// Vector Arithmetic

// vadd
int8x8_t vadd_s8(int8x8_t N, int8x8_t M)
{
    int8x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int16x4_t vadd_s16(int16x4_t N, int16x4_t M)
{
    int16x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}


int32x2_t vadd_s32(int32x2_t N, int32x2_t M)
{
    int32x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int64x1_t vadd_s64(int64x1_t N, int64x1_t M)
{
    int64x1_t D;
    D[0] = N[0] + M[0];
    return D;
}


uint8x8_t vadd_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint16x4_t vadd_u16(uint16x4_t N, uint16x4_t M)
{
    uint16x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint32x2_t vadd_u32(uint32x2_t N, uint32x2_t M)
{
    uint32x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint64x1_t vadd_u64(uint64x1_t N, uint64x1_t M)
{
    uint64x1_t D;
    D[0] = N[0] + M[0];
    return D;
}

// vaddl
uint16x8_t vaddl_u8(uint8x8_t a, uint8x8_t b)
{
    uint16x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = (uint16_t)(a[i]) + (uint16_t)(b[i]);
    }
    return D;
}

int16x8_t vaddw_s8(int16x8_t a, int8x8_t b)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

int32x4_t	vaddw_s16	(int32x4_t a, int16x4_t b)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

int64x2_t	vaddw_s32	(int64x2_t a, int32x2_t b)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint16x8_t vaddw_u8(uint16x8_t a, uint8x8_t b)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint32x4_t	vaddw_u16	(uint32x4_t a, uint16x4_t b)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint64x2_t	vaddw_u32	(uint64x2_t a, uint32x2_t b)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

// vaddq

int8x16_t vaddq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (size_t i=0; i<16; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int16x8_t vaddq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int32x4_t vaddq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int64x2_t vaddq_s64(int64x2_t N, int64x2_t M)
{
    int64x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint8x16_t vaddq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (size_t i=0; i<16; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint16x8_t vaddq_u16(uint16x8_t N, uint16x8_t M)
{
    uint16x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint32x4_t vaddq_u32(uint32x4_t N, uint32x4_t M)
{
    uint32x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}
float32x4_t vaddq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint64x2_t vaddq_u64(uint64x2_t N, uint64x2_t M)
{
    uint64x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
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


// vqaddq
uint8x16_t vqaddq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (size_t i=0; i<16; i++)
    {
        uint16_t temp = (uint16_t)N[i] + (uint16_t)M[i];
        if (temp > UINT8_MAX) {
            D[i] = UINT8_MAX;
        }
        else {
            D[i] = temp;
        }
    }
    return D;
}

uint16x4_t vpaddl_u8(uint8x8_t a)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++){
        r[i] = a[2*i] + a[2*i+1];
    }
    return r;
}

uint16x8_t vpaddlq_u8(uint8x16_t a)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++){
        r[i] = a[2*i] + a[2*i+1];
    }
    return r;
}

uint32x4_t vpaddlq_u16(uint16x8_t a)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++){
        r[i] = a[2*i] + a[2*i+1];
    }
    return r;
}

// sub
int8x8_t vsub_s8(int8x8_t N, int8x8_t M)
{
    int8x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int16x4_t vsub_s16(int16x4_t N, int16x4_t M)
{
    int16x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int32x2_t vsub_s32(int32x2_t N, int32x2_t M)
{
    int32x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int64x1_t vsub_s64(int64x1_t N, int64x1_t M)
{
    int64x1_t D;
    for (size_t i=0; i<1; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint8x8_t vsub_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint16x4_t vsub_u16(uint16x4_t N, uint16x4_t M)
{
    uint16x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint32x2_t vsub_u32(uint32x2_t N, uint32x2_t M)
{
    uint32x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint64x1_t vsub_u64(uint64x1_t N, uint64x1_t M)
{
    uint64x1_t D;
    for (size_t i=0; i<1; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

float32x2_t vsub_f32(float32x2_t N, float32x2_t M)
{
    float32x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

float64x1_t vsub_f32(float64x1_t N, float64x1_t M)
{
    float64x1_t D;
    for (size_t i=0; i<1; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

// vsubq_type
int8x16_t vsubq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (size_t i=0; i<16; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int16x8_t vsubq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int32x4_t vsubq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int64x2_t vsubq_s64(int64x2_t N, int64x2_t M)
{
    int64x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint8x16_t vsubq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (size_t i=0; i<16; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint16x8_t vsubq_u16(uint16x8_t N, uint16x8_t M)
{
    uint16x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint32x4_t vsubq_u32(uint32x4_t N, uint32x4_t M)
{
    uint32x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint64x2_t vsubq_u64(uint64x2_t N, uint64x2_t M)
{
    uint64x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

float32x4_t vsubq_f32(float32x4_t N, float32x4_t M)
{
    float32x4_t D;
    for (size_t i=0; i<4; i++)
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

int8x8_t vrsubhn_s16(int16x8_t N, int16x8_t M)
{
    int8x8_t D;
    const int16_t shift = 8;
    const int16_t delta = (1<<(shift-1));
    for (int i=0; i<8; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

int16x4_t	vrsubhn_s32	(int32x4_t N, int32x4_t M)
{
    int16x4_t D;
    const int32_t shift = 16;
    const int32_t delta = (1<<(shift-1));
    for (int i=0; i<4; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

int32x2_t	vrsubhn_s64	(int64x2_t N, int64x2_t M)
{
    int32x2_t D;
    const int64_t shift = 32;
    const int64_t delta = (1<<(shift-1));
    for (int i=0; i<2; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

uint8x8_t	vrsubhn_u16	(uint16x8_t N, uint16x8_t M)
{
    uint8x8_t D;
    const uint16_t shift = 8;
    const uint16_t delta = (1<<(shift-1));
    for (int i=0; i<8; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

uint16x4_t	vrsubhn_u32	(uint32x4_t N, uint32x4_t M)
{
    uint16x4_t D;
    const uint32_t shift = 16;
    const uint32_t delta = (1<<(shift-1));
    for (int i=0; i<4; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

uint32x2_t	vrsubhn_u64	(uint64x2_t N, uint64x2_t M)
{
    uint32x2_t D;
    const uint64_t shift = 32;
    const uint64_t delta = (1<<(shift-1));
    for (int i=0; i<2; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}


// vmulq
int8x16_t vmulq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i=0; i<16; i++) {
        D[i] = N[i] * M[i];
    }
    return D;
}
int16x8_t vmulq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i=0; i<8; i++) {
        D[i] = N[i] * M[i];
    }
    return D;
}
int32x4_t vmulq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i=0; i<4; i++) {
        D[i] = N[i] * M[i];
    }
    return D;
}
uint8x16_t vmulq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (int i=0; i<16; i++){
        D[i] = N[i] * M[i];
    }
    return D;
}
uint16x8_t vmulq_u16(uint16x8_t N, uint16x8_t M)
{
    uint16x8_t D;
    for (int i=0; i<8; i++) {
        D[i] = N[i] * M[i];
    }
    return D;
}
uint32x4_t vmulq_u32(uint32x4_t N, uint32x4_t M)
{
    uint32x4_t D;
    for (int i=0; i<4; i++) {
        D[i] = N[i] * M[i];
    }
    return D;
}

// vmulq_n
uint32x4_t vmulq_n_u32(uint32x4_t N, uint32_t M)
{
    uint32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

float32x4_t vmulq_n_f32(float32x4_t N, float32_t M)
{
    float32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

float32x4_t vmulq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
}

// vmull
uint16x8_t vmull_u8(uint8x8_t a, uint8x8_t b)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = a[i] * b[i];
    }
    return r;
}
uint32x4_t vmull_u16(uint16x4_t a, uint16x4_t b)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i] * b[i];
    }
    return r;
}
uint64x2_t vmull_u32(uint32x2_t a, uint32x2_t b)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = a[i] * b[i];
    }
    return r;
}

int16x8_t vmull_s8(int8x8_t a, int8x8_t b)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = a[i] * b[i];
    }
    return r;
}
int32x4_t vmull_s16(int16x4_t a, int16x4_t b)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i] * b[i];
    }
    return r;
}
int64x2_t vmull_s32(int32x2_t a, int32x2_t b)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = a[i] * b[i];
    }
    return r;
}

// vmull_n
int32x4_t vmull_n_s16(int16x4_t N, int16_t M)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

int64x2_t vmull_n_s32(int32x2_t N, int32_t M)
{
    int64x2_t D;
    for (int i=0; i<2; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

uint32x4_t vmull_n_u16(uint16x4_t N, uint16_t M)
{
    uint32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

uint64x2_t vmull_n_u32(uint32x2_t N, uint32_t M)
{
    uint64x2_t D;
    for (int i=0; i<2; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}


// vqdmull
int32x4_t vqdmull_s16(int16x4_t M, int16x4_t N)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        // saturating
        if (N[i] == INT16_MIN && M[i] == INT16_MIN) {
            D[i] = INT32_MAX;
        } 
        else { // most cases
            D[i] = (M[i] * N[i])*2;
        }
    }
    return D;
}

// vmlal_type
int16x8_t vmlal_s8(int16x8_t N, int8x8_t M, int8x8_t P)
{
    int16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

int32x4_t vmlal_s16(int32x4_t N, int16x4_t M, int16x4_t P)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

int64x2_t vmlal_s32(int64x2_t N, int32x2_t M, int32x2_t P)
{
    int64x2_t D;
    for (int i=0; i<2; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

uint16x8_t vmlal_u8(uint16x8_t N, uint8x8_t M, uint8x8_t P)
{
    uint16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

uint32x4_t vmlal_u16(uint32x4_t N, uint16x4_t M, uint16x4_t P)
{
    uint32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

uint64x2_t vmlal_u32(uint64x2_t N, uint32x2_t M, uint32x2_t P)
{
    uint64x2_t D;
    for (int i=0; i<2; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

// vmlsl_type
int16x8_t vmlsl_s8(int16x8_t N, int8x8_t M, int8x8_t P)
{
    int16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

int32x4_t vmlsl_s16(int32x4_t N, int16x4_t M, int16x4_t P)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

int64x2_t vmlsl_s32(int64x2_t N, int32x2_t M, int32x2_t P)
{
    int64x2_t D;
    for (int i=0; i<2; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

uint16x8_t vmlsl_u8(uint16x8_t N, uint8x8_t M, uint8x8_t P)
{
    uint16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

uint32x4_t vmlsl_u16(uint32x4_t N, uint16x4_t M, uint16x4_t P)
{
    uint32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

uint64x2_t vmlsl_u32(uint64x2_t N, uint32x2_t M, uint32x2_t P)
{
    uint64x2_t D;
    for (int i=0; i<2; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

// vmlaq
int8x16_t vmlaq_s8(int8x16_t N, int8x16_t M, int8x16_t P)
{
    int8x16_t D;
    for (int i=0; i<16; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

int16x8_t vmlaq_s16(int16x8_t N, int16x8_t M, int16x8_t P)
{
    int16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

int32x4_t vmlaq_s32(int32x4_t N, int32x4_t M, int32x4_t P)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

uint8x16_t vmlaq_u8(uint8x16_t N, uint8x16_t M, uint8x16_t P)
{
    uint8x16_t D;
    for (int i=0; i<16; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

uint16x8_t vmlaq_u16(uint16x8_t N, uint16x8_t M, uint16x8_t P)
{
    uint16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

uint32x4_t vmlaq_u32(uint32x4_t N, uint32x4_t M, uint32x4_t P)
{
    uint32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

float32x4_t vmlaq_f32(float32x4_t N, float32x4_t M, float32x4_t P)
{
    float32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

// vmlaq_n
float32x4_t vmlaq_n_f32(float32x4_t a, float32x4_t b, float32_t c)
{
    float32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = a[i] + b[i] * c;
    }
    return D;
}

// Vector manipulation 
////// vdup
int8x8_t vdup_n_s8(int8_t N)
{
    int8x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N;
    }
    return D;
}

int16x4_t vdup_n_s16(int16_t N)
{
    int16x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N;
    }
    return D;
}

int32x2_t vdup_n_s32(int32_t N)
{
    int32x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N;
    }
    return D;
}

int64x1_t vdup_n_s64(int64_t N)
{
    int64x1_t D;
    for (size_t i=0; i<1; i++)
    {
        D[i] = N;
    }
    return D;
}

uint8x8_t vdup_n_u8(uint8_t N)
{
    uint8x8_t D;
    for (size_t i=0; i<8; i++)
    {
        D[i] = N;
    }
    return D;
}

uint16x4_t vdup_n_u16(uint16_t N)
{
    uint16x4_t D;
    for (size_t i=0; i<4; i++)
    {
        D[i] = N;
    }
    return D;
}

uint32x2_t vdup_n_u32(uint32_t N)
{
    uint32x2_t D;
    for (size_t i=0; i<2; i++)
    {
        D[i] = N;
    }
    return D;
}

uint64x1_t vdup_n_u64(uint64_t N)
{
    uint64x1_t D;
    for (size_t i=0; i<1; i++)
    {
        D[i] = N;
    }
    return D;
}

////// vdupq
uint8x16_t vdupq_n_u8(uint8_t value)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++) {
        r[i] = value;
    }
    return r;
}
int8x16_t vdupq_n_s8(int8_t value)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++) {
        r[i] = value;
    }
    return r;
}
uint16x8_t vdupq_n_u16(uint16_t value)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = value;
    }
    return r;
}
int16x8_t vdupq_n_s16(int16_t value)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = value;
    }
    return r;
}
uint32x4_t vdupq_n_u32(uint32_t value)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = value;
    }
    return r;
}
int32x4_t vdupq_n_s32(int32_t value)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = value;
    }
    return r;
}
float32x4_t vdupq_n_f32(float32_t value)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++) {
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

float32x4_t vmovq_n_f32(float32_t value)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = value;
    }
    return r;
}

// vget_low
float32x2_t vget_low_f32(float32x4_t a)
{
    float32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i];
    }
    return r;
}

int32x2_t vget_low_s32(int32x4_t a)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i];
    }
    return r;
}

uint32x2_t vget_low_u32(uint32x4_t a)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i];
    }
    return r;
}

int16x4_t vget_low_s16(int16x8_t a)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

uint16x4_t vget_low_u16(uint16x8_t a)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

// vget_high
float32x2_t vget_high_f32(float32x4_t a)
{
    float32x2_t r;
    int mid = 4 / 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

int32x2_t vget_high_s32(int32x4_t a)
{
    int32x2_t r;
    int mid = 4 / 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

int16x4_t vget_high_s16(int16x8_t a)
{
    int16x4_t r;
    int mid = 8 / 2;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

uint16x4_t vget_high_u16(uint16x8_t a)
{
    uint16x4_t r;
    int mid = 8 / 2;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

uint32x2_t vget_high_u32(uint32x4_t a)
{
    uint32x2_t r;
    int mid = 4 / 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}


float32x2_t vpmax_f32(float32x2_t a, float32x2_t b)
{
    float32x2_t r;
    r[0] = a[0] > a[1] ? a[0] : a[1];
    r[1] = b[0] > b[1] ? b[0] : b[1];
    return r;
}

float32x2_t vpmin_f32(float32x2_t a, float32x2_t b)
{
    float32x2_t r;
    r[0] = a[0] < a[1] ? a[0] : a[1];
    r[1] = b[0] < b[1] ? b[0] : b[1];
    return r;
}

float32_t vget_lane_f32(float32x2_t v, const int lane)
{
    return v[lane];
}

float32_t vgetq_lane_f32(float32x4_t v, int lane)
{
    if (lane < 0 || lane > 3)
    {
        fprintf(stderr, "%s: lane should is out of range [0, 3]", __FUNCTION__);
        abort();
    }
    return v[lane];
}

// vminq_type
int8x16_t vminq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i=0; i<16; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int16x8_t vminq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int32x4_t vminq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int8x16_t vminq_u8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i=0; i<16; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int16x8_t vminq_u16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i=0; i<8; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int32x4_t vminq_u32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

float32x4_t vminq_f32(float32x4_t N, float32x4_t M)
{
    float32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

uint32x4_t vcltq_f32(float32x4_t N, float32x4_t M)
{
    uint32x4_t D;
    for (int i=0; i<4; i++)
    {
        if (N[i]<M[i]) {
            D[i] = 0xFFFFFFFF;
        } else {
            D[i] = 0;
        }
    }
    return D;
}

float32x4_t vbslq_f32(uint32x4_t mask, float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = mask[i] ? a[i] : b[i];
    }
    return r;
}

// shift right
int8x8_t vshrn_n_s16(int16x8_t a, const int n)
{
    if (n<1 || n>8) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    int8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = a[i] >> n;
    }
    return r;
}

uint16x4_t vshr_n_u16(uint16x4_t v, const int n)
{
    if (n<1 || n>8) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint16x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = v[i] >> n;
    }
    return D;
}

int16x4_t vshrn_n_s32(int32x4_t a, const int n)
{
    if (n<1 || n>16) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    int16x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i] >> n;
    }
    return r;
}

int32x2_t vshrn_n_s64(int64x2_t a, const int n)
{
    if (n<1 || n>32) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    int32x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = a[i] >> n;
    }
    return r;
}

uint8x8_t vshrn_n_u16(uint16x8_t a, const int n)
{
    if (n<1 || n>8) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = a[i] >> n;
    }
    return r;
}

uint16x4_t vshrn_n_u32(uint32x4_t a, const int n)
{
    if (n<1 || n>16) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint16x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i] >> n;
    }
    return r;
}

uint32x2_t vshrn_n_u64(uint64x2_t a, const int n)
{
    if (n<1 || n>32) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint32x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = a[i] >> n;
    }
    return r;
}


/// @param n 1-8
uint8x8_t vqshrun_n_s16(int16x8_t v, const int n)
{
    if (n<1 || n>8) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint8x8_t D;
    for (int i=0; i<8; i++) {
        int16_t temp = v[i] >> n;
        if (temp > UINT8_MAX) {
            temp = UINT8_MAX;
        } else if (temp < 0) {
            temp = 0;
        }
        D[i] = temp;
    }
    return D;
}

uint8x8_t vqrshrun_n_s16(int16x8_t v, const int n)
{
    if (n<1 || n>8) {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }
    uint8x8_t D;
    for (int i=0; i<8; i++) {
        int16_t temp = ( v[i] + (1<<(n-1) ) ) >> n;
        if (temp > UINT8_MAX) {
            temp = UINT8_MAX;
        } else if (temp < 0) {
            temp = 0;
        }
        D[i] = temp;
    }
    return D;
}

uint8x8_t vrshrn_n_u16(uint16x8_t a, const int n)
{
    uint8x8_t r;
    const int delta = (1 << (n-1));
    for (int i = 0; i < 8; i++) {
        r[i] = (a[i] + delta) >> n;
    }
    return r;
}

int32x4_t vsraq_n_s32(int32x4_t a, int32x4_t b, const int n)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = (a[i] >> n) + (b[i] >> n);
    }
    return r;
}

// shift left
int32x4_t vshlq_n_s32(int32x4_t M, const int n)
{
    int32x4_t D;
    for (int i=0; i<4; i++) {
        D[i] = M[i] << n;
    }
    return D;
}

uint16x8_t vshll_n_u8(uint8x8_t a, const int n)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = (uint16_t)a[i] << n;
    }
    return r;
}

// type conversion
uint8x8_t vreinterpret_u8_s8(int8x8_t a)
{
    return a;
}

int16x8_t vreinterpretq_s16_u16(uint16x8_t a)
{
    return a;
}

uint16x8_t vreinterpretq_u16_s16(int16x8_t a)
{
    return a;
}

uint16x4_t vreinterpret_u16_u8(uint8x8_t a)
{
    return a;
}

uint32x2_t vreinterpret_u32_u16(uint16x4_t a)
{
    return a;
}

uint8x8_t vreinterpret_u8_u32(uint32x2_t a)
{
    return a;
}

uint32x2_t vreinterpret_u32_u8(uint8x8_t a)
{
    return a;
}

int8x8_t vreinterpret_s8_u8(uint8x8_t a)
{
    return a;
}

int32x2_t vreinterpret_s32_s16(int16x4_t a)
{
    return a;
}

int16x4_t vreinterpret_s16_s32(int32x2_t a)
{
    return a;
}

float32x4_t vcvtq_f32_s32(int32x4_t a)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i];
    }
    return r;
}

int32x4_t vcvtq_s32_f32(float32x4_t a)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i];
    }
    return r;
}

uint32x4_t vcvtq_u32_f32(float32x4_t a)
{
    uint32x4_t r;
    for (int i = 0; i <4; i++) {
        r[i] = a[i];
    }
    return r;
}

int32x4_t vcvtnq_s32_f32(float32x4_t a)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i];
    }
    return r;
}

//----------------------------------------------------------------------
// 3. reverse and reverse square root
//----------------------------------------------------------------------
struct float_parts {
    explicit float_parts(float v);
    explicit operator float() const;

    uint32_t sign;
    uint32_t fraction;
    uint32_t exp;

    int exp_bits[8];
    int fraction_bits[23];
    std::string exp_bits_str = std::string(8, '0');
    std::string fraction_bits_str = std::string(23, '0');
private:
    void int32_to_binary(int data, int* bits, int n = 32) {
        for (int i = 0; i < n; i++){
            bits[n-1-i] = data & 1;
            data = data >> 1;
        }
    }
};

uint32_t RecipEstimate(uint32_t a) {
    a = a * 2 + 1;
    uint32_t b = (1 << 19) / a;
    return (b + 1) / 2;
}

float FPRecipEstimate(float operand) {
    float_parts parts{operand};
    parts.exp = 253 - parts.exp;
    uint32_t scaled = 0x100 | ((parts.fraction >> 15) & 0xFF);
    uint32_t estimate = RecipEstimate(scaled);
    parts.fraction = (estimate & 0xff) << 15;
    return float(parts);
}

float_parts::float_parts(float v) {
    uint32_t v_bits;
    memcpy(&v_bits, &v, sizeof(float));

    sign = (v_bits >> 31) & 0x1;
    fraction = v_bits & ((1 << 23) - 1);
    exp = (v_bits >> 23) & 0xff;

    int32_to_binary(exp, exp_bits, 8);
    int32_to_binary(fraction, fraction_bits, 23);

    for (int i = 0; i < 8; i++) {
        exp_bits_str[i] = exp_bits[i] + '0';
    }
    for (int i = 0; i < 23; i++) {
        fraction_bits_str[i] = fraction_bits[i] + '0';
    }
}

float_parts::operator float() const {
    uint32_t v_bits = 
        ((sign & 0x1) << 31) |
        (fraction & ((1 << 23) - 1)) |
        ((exp & 0xff) << 23);

    float result;
    memcpy(&result, &v_bits, sizeof(float));
    return result;
}

float32x4_t vrecpeq_f32(float32x4_t N)
{
    float32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = FPRecipEstimate(N[i]);
    }
    return D;
}

float32x4_t vrecpsq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = 2.0 - (a[i] * b[i]);
    }
    return r;
}

/// transpose
int8x8x2_t vtrn_s8(int8x8_t a, int8x8_t b)
{
    int8x8x2_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 4; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

uint8x8x2_t vtrn_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8x2_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 4; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

int16x4x2_t vtrn_s16(int16x4_t a, int16x4_t b)
{
    int16x4x2_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 2; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

uint16x4x2_t vtrn_u16(uint16x4_t a, uint16x4_t b)
{
    uint16x4x2_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 2; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

int32x2x2_t vtrn_s32(int32x2_t a, int32x2_t b)
{
    int32x2x2_t r;
    for (int i = 0; i < 1; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 1; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

uint32x2x2_t vtrn_u32(uint32x2_t a, uint32x2_t b)
{
    uint32x2x2_t r;
    for (int i = 0; i < 1; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 1; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

// trnq
uint16x8x2_t vtrnq_u16(uint16x8_t a, uint16x8_t b)
{
    uint16x8x2_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 4; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

uint32x4x2_t vtrnq_u32(uint32x4_t a, uint32x4_t b)
{
    uint32x4x2_t r;
    for (int i = 0; i < 2; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 2; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

int16x8x2_t vtrnq_s16(int16x8_t a, int16x8_t b)
{
    int16x8x2_t r;
    for (int i = 0; i < 4; i++) {
        r.val[0][2*i] = a[2*i];
        r.val[0][2*i+1] = b[2*i];
    }
    for (int i = 0; i < 4; i++) {
        r.val[1][2*i] = a[2*i+1];
        r.val[1][2*i+1] = b[2*i+1];
    }
    return r;
}

// zip
int16x4x2_t vzip_s16(int16x4_t a, int16x4_t b)
{
    int16x4x2_t r;
    const int n = 2;
    for (int i = 0; i < n; i++) {
        r.val[0][2*i] = a[i];
        r.val[0][2*i+1] = b[i];
    }
    for (int i = 0; i < n; i++) {
        r.val[1][2*i] = a[n + i];
        r.val[1][2*i+1] = b[n + i];
    }
    return r;
}

// combine
uint8x16_t vcombine_u8(uint8x8_t low, uint8x8_t high)
{
    uint8x16_t r;
    const int n = 8;
    for (int i = 0; i < n; i++) {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++) {
        r[n + i] = high[i];
    }
    return r;
}
uint16x8_t vcombine_u16(uint16x4_t low, uint16x4_t high)
{
    uint16x8_t r;
    const int n = 4;
    for (int i = 0; i < n; i++) {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++) {
        r[n + i] = high[i];
    }
    return r;
}
uint32x4_t vcombine_u32(uint32x2_t low, uint32x2_t high)
{
    uint32x4_t r;
    const int n = 2;
    for (int i = 0; i < n; i++) {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++) {
        r[n + i] = high[i];
    }
    return r;
}

int8x16_t vcombine_s8(int8x8_t low, int8x8_t high)
{
    int8x16_t r;
    const int n = 8;
    for (int i = 0; i < n; i++) {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++) {
        r[n + i] = high[i];
    }
    return r;
}
int16x8_t vcombine_s16(int16x4_t low, int16x4_t high)
{
    int16x8_t r;
    const int n = 4;
    for (int i = 0; i < n; i++) {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++) {
        r[n + i] = high[i];
    }
    return r;
}
int32x4_t vcombine_s32(int32x2_t low, int32x2_t high)
{
    int32x4_t r;
    const int n = 2;
    for (int i = 0; i < n; i++) {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++) {
        r[n + i] = high[i];
    }
    return r;
}

// vmov
int16x4_t vmovn_s32(int32x4_t a)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i];
    }
    return r;
}

uint16x4_t vmovn_u32(uint32x4_t a)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i];
    }
    return r;
}

uint8x8_t vmovn_u16(uint16x8_t a)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = a[i];
    }
    return r;
}

// vmovl
uint16x8_t vmovl_u8(uint8x8_t a)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = a[i];
    }
    return r;
}
uint32x4_t vmovl_u16(uint16x4_t a)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i];
    }
    return r;
}
uint64x2_t vmovl_u32(uint32x2_t a)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = a[i];
    }
    return r;
}

int16x8_t vmovl_s8(int8x8_t a)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++) {
        r[i] = a[i];
    }
    return r;
}
int32x4_t vmovl_s16(int16x4_t a)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i];
    }
    return r;
}
int64x2_t vmovl_s32(int32x2_t a)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++) {
        r[i] = a[i];
    }
    return r;
}

// vqmovn
uint8x8_t vqmovn_u16(uint16x8_t a)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        if (a[i] > UINT8_MAX) {
            r[i] = UINT8_MAX;
        } else {
            r[i] = a[i];
        }
    }
    return r;
}

uint8x8_t vqmovun_s16(int16x8_t a)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        if (a[i] < 0) {
            r[i] = 0;
        }
        else if (a[i] > UINT8_MAX) {
            r[i] = UINT8_MAX;
        } else {
            r[i] = a[i];
        }
    }
    return r;
}


// table lookup
uint8x8_t vqtbl1_u8(uint8x16_t t, uint8x8_t idx)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = t[idx[i]];
    }
    return r;
}

int32x2_t vrev64_s32(int32x2_t vec)
{
    int32x2_t r;
    const int n = 2;
    for (int i = 0; i < n; i++)
    {
        r[i] = vec[n - 1 - i];
    }
    return r;
}

// vext
uint8x8_t vext_u8(uint8x8_t a, uint8x8_t b, const int n)
{
    uint8x8_t r;
    int len = 8;
    if (n > 8 || n < 0) {
        fprintf(stderr, "%s: param n is not in range [0, 8]\n", __FUNCTION__);
        abort();
    }
    for (int i = 0; i < len - n; i++) {
        r[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        r[i + len - n] = b[i];
    }
    return r;
}

uint16x4_t vext_u16(uint16x4_t a, uint16x4_t b, const int n)
{
    uint16x4_t r;
    int len = 4;
    if (n > 3 || n < 0) {
        fprintf(stderr, "%s: param n is not in range [0, 4]\n", __FUNCTION__);
        abort();
    }
    for (int i = 0; i < len - n; i++) {
        r[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        r[i + len - n] = b[i];
    }
    return r;
}

int16x4_t vext_s16(int16x4_t a, int16x4_t b, const int n)
{
    int16x4_t r;
    int len = 4;
    if (n > 3 || n < 0) {
        fprintf(stderr, "%s: param n is not in range [0, 4]\n", __FUNCTION__);
        abort();
    }
    for (int i = 0; i < len - n; i++) {
        r[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        r[i + len - n] = b[i];
    }
    return r;
}

// vextq
uint16x8_t vextq_u16(uint16x8_t a, uint16x8_t b, const int n)
{
    uint16x8_t r;
    int len = 8;
    if (n > 8 || n < 0) {
        fprintf(stderr, "%s: param n is not in range [0, 8]\n", __FUNCTION__);
        abort();
    }
    for (int i = 0; i < len - n; i++) {
        r[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        r[i + len - n] = b[i];
    }
    return r;
}

// compare
uint8x16_t vcgtq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (int i=0; i<16; i++) {
        D[i] = N[i] > M[i] ? 0xFF : 0;
    }
    return D;
}

//Bitwise Select. This instruction sets each bit in the destination SIMD&FP register to the 
// corresponding bit from the first source SIMD&FP register when the original destination bit was 1,
// otherwise from the second source SIMD&FP register.
// the original destination 说的就是 mask
uint8x16_t vbslq_u8(uint8x16_t mask, uint8x16_t src1, uint8x16_t src2)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++) {
        r[i] = 0;
        for (int j = 0; j < 8; j++) {
            uint8_t x = (1 << (8 - 1 - j));
            if ( (mask[i] & x) == x) {
                r[i] += (src1[i] & x);
            } else {
                r[i] += (src2[i] & x);
            }
        }
    }
    return r;
}

// vtbl1
uint8x8_t vtbl1_u8(uint8x8_t a, uint8x8_t idx)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        int index = idx.val[i];
        if (index < 0 || index > 7) {
            r[i] = 0;
        } else {
            r[i] = a.val[index];
        }
    }
    return r;
}

// vtbl4
uint8x8_t vtbl4_u8(uint8x8x4_t a, uint8x8_t idx)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        int index = idx.val[i];
        if (index < 0 || index > 31) {
            r[i] = 0;
        } else if (index < 8) { // [0, 7]
            r[i] = a.val[0][index];
        } else if (index < 16) { // [8, 15]
            r[i] = a.val[1][index - 8];
        } else if (index < 24) { // [16, 23]
            r[i] = a.val[2][index - 16];
        } else { // [24, 31]
            r[i] = a.val[3][index - 24];
        }
    }
    return r;
}

// vtbl2
uint8x8_t vtbl2_u8(uint8x8x2_t a, uint8x8_t idx)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++) {
        int index = idx.val[i];
        if (index < 0 || index > 15) {
            r[i] = 0;
        } else if (index < 8) {
            r[i] = a.val[0][index];
        } else { // index in [8, 15]
            r[i] = a.val[1][index - 8];
        }
    }
    return r;
}

//----------------------------------------------------------------------
// 5. Helper functions
//----------------------------------------------------------------------

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


#endif // NEON_SIM_IMPLEMENTATION