#pragma once

//----------------------------------------------------------------------
// 1. vector register type definition
//----------------------------------------------------------------------
#include <iostream>
#include <array>
#include <stdint.h>
#include <string.h>
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

uint32x4_t vld1q_u32(uint32_t const* ptr)
{
    uint32x4_t r;
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

int16x8_t vld1q_s16(int16_t const* ptr)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}

float32x4_t vld1q_dup_f32(float32_t const* ptr)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = ptr[0];
    }
    return r;
}

int16x8x3_t vld3q_s16(int16_t const * ptr)
{
    int16x8x3_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[3*i + 0];
        r.val[1][i] = ptr[3*i + 1];
        r.val[2][i] = ptr[3*i + 2];
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

void vst1q_f32(float32_t* ptr, float32x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val[i];
    }
}

void vst4q_lane_f32(float32_t* ptr, float32x4x4_t val, const int lane)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val.val[i][lane];
    }
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

float32x4_t	vaddq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++) {
        r[i] = a[i] + b[i];
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

float32x4_t vmulq_n_f32(float32x4_t N, float32_t M)
{
    float32x4_t D;
    for (int i=0; i<4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

float32x4_t	vmulq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
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

float32x4_t vmovq_n_f32(float32_t value)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = value;
    }
    return r;
}

float32x2_t vget_low_f32(float32x4_t a)
{
    float32x2_t r;
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

float32x4_t vget_high_f32(float32x4_t a)
{
    float32x2_t r;
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

float32x2_t	vpmax_f32(float32x2_t a, float32x2_t b)
{
    float32x2_t r;
    r[0] = a[0] > a[1] ? a[0] : a[1];
    r[1] = b[0] > b[1] ? b[0] : b[1];
    return r;
}

float32x2_t	vpmin_f32(float32x2_t a, float32x2_t b)
{
    float32x2_t r;
    r[0] = a[0] < a[1] ? a[0] : a[1];
    r[1] = b[0] < b[1] ? b[0] : b[1];
    return r;
}

float32_t vget_lane_f32(float32x2_t v, const int lane)
{
    float32_t r = v[lane];
    return r;
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

float32x4_t	vbslq_f32(uint32x4_t mask, float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = mask[i] ? a[i] : b[i];
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

// combine
uint8x16_t vcombine_u8(uint8x8_t low, uint8x8_t high)
{
    uint8x16_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = low[i];
    }
    for (int i = 0; i < 8; i++)
    {
        r[8 + i] = high[i];
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

uint16x4_t vext_u16(uint16x4_t a, uint16x4_t b, const int n)
{
    uint16x4_t r;
    int len = 4;
    if (len > 4 || len < 0) {
        abort();
    }
    for (int i = 0; i < len - n; i++)
    {
        r[i] = a[n + i];
    }
    for (int i = n; i < len; i++)
    {
        r[i] = b[i - n];
    }
    return r;
}

//----------------------------------------------------------------------
// 5. Helper functions
//----------------------------------------------------------------------

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
