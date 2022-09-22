#ifndef SAT_CAST_H
#define SAT_CAST_H

/**
 * 提供了 sat_cast<Tp>(v),
 * 和 OpenCV 的 cv::saturate_cast<Tp>(v) 的结果一致，而不依赖于 OpenCV 库。
 * 
 */


#include <limits.h>
#include <algorithm>
#include <stdint.h>
#include <cmath>

typedef unsigned char uchar;
typedef signed char schar;

#if defined _MSC_VER || defined __BORLANDC__
   typedef __int64 int64;
   typedef unsigned __int64 uint64;
#  define CV_BIG_INT(n)   n##I64
#  define CV_BIG_UINT(n)  n##UI64
#else
   typedef int64_t int64;
   typedef uint64_t uint64;
#  define CV_BIG_INT(n)   n##LL
#  define CV_BIG_UINT(n)  n##ULL
#endif


#ifdef NEON_PEDAL_SUPPORT_FP16

class float16_t
{
public:
#if CV_FP16_TYPE

    float16_t() : h(0) {}
    explicit float16_t(float x) { h = (__fp16)x; }
    operator float() const { return (float)h; }
    static float16_t fromBits(ushort w)
    {
        Cv16suf u;
        u.u = w;
        float16_t result;
        result.h = u.h;
        return result;
    }
    static float16_t zero()
    {
        float16_t result;
        result.h = (__fp16)0;
        return result;
    }
    ushort bits() const
    {
        Cv16suf u;
        u.h = h;
        return u.u;
    }
protected:
    __fp16 h;

#else
    float16_t() : w(0) {}
    explicit float16_t(float x)
    {
    #if CV_FP16
        __m128 v = _mm_load_ss(&x);
        w = (ushort)_mm_cvtsi128_si32(_mm_cvtps_ph(v, 0));
    #else
        Cv32suf in;
        in.f = x;
        unsigned sign = in.u & 0x80000000;
        in.u ^= sign;

        if( in.u >= 0x47800000 )
            w = (ushort)(in.u > 0x7f800000 ? 0x7e00 : 0x7c00);
        else
        {
            if (in.u < 0x38800000)
            {
                in.f += 0.5f;
                w = (ushort)(in.u - 0x3f000000);
            }
            else
            {
                unsigned t = in.u + 0xc8000fff;
                w = (ushort)((t + ((in.u >> 13) & 1)) >> 13);
            }
        }

        w = (ushort)(w | (sign >> 16));
    #endif
    }

    operator float() const
    {
    #if CV_FP16
        float f;
        _mm_store_ss(&f, _mm_cvtph_ps(_mm_cvtsi32_si128(w)));
        return f;
    #else
        Cv32suf out;

        unsigned t = ((w & 0x7fff) << 13) + 0x38000000;
        unsigned sign = (w & 0x8000) << 16;
        unsigned e = w & 0x7c00;

        out.u = t + (1 << 23);
        out.u = (e >= 0x7c00 ? t + 0x38000000 :
                 e == 0 ? (static_cast<void>(out.f -= 6.103515625e-05f), out.u) : t) | sign;
        return out.f;
    #endif
    }

    static float16_t fromBits(ushort b)
    {
        float16_t result;
        result.w = b;
        return result;
    }
    static float16_t zero()
    {
        float16_t result;
        result.w = (ushort)0;
        return result;
    }
    ushort bits() const { return w; }
protected:
    ushort w;

#endif
};

#endif // NEON_PEDAL_SUPPORT_FP16

template<typename Tp> static inline Tp sat_cast(uchar v)    { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(schar v)    { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(ushort v)   { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(short v)    { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(unsigned v) { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(int v)      { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(float v)    { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(double v)   { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(int64 v)    { return Tp(v); }

template<typename Tp> static inline Tp sat_cast(uint64 v)   { return Tp(v); }

template<> inline uchar sat_cast<uchar>(schar v)        { return (uchar)std::max((int)v, 0); }
template<> inline uchar sat_cast<uchar>(ushort v)       { return (uchar)std::min((unsigned)v, (unsigned)UCHAR_MAX); }
template<> inline uchar sat_cast<uchar>(int v)          { return (uchar)((unsigned)v <= UCHAR_MAX ? v : v > 0 ? UCHAR_MAX : 0); }
template<> inline uchar sat_cast<uchar>(short v)        { return sat_cast<uchar>((int)v); }
template<> inline uchar sat_cast<uchar>(unsigned v)     { return (uchar)std::min(v, (unsigned)UCHAR_MAX); }
template<> inline uchar sat_cast<uchar>(float v)        { int iv = std::round(v); return sat_cast<uchar>(iv); }
template<> inline uchar sat_cast<uchar>(double v)       { int iv = std::round(v); return sat_cast<uchar>(iv); }
template<> inline uchar sat_cast<uchar>(int64 v)        { return (uchar)((uint64)v <= (uint64)UCHAR_MAX ? v : v > 0 ? UCHAR_MAX : 0); }
template<> inline uchar sat_cast<uchar>(uint64 v)       { return (uchar)std::min(v, (uint64)UCHAR_MAX); }

template<> inline schar sat_cast<schar>(uchar v)        { return (schar)std::min((int)v, SCHAR_MAX); }
template<> inline schar sat_cast<schar>(ushort v)       { return (schar)std::min((unsigned)v, (unsigned)SCHAR_MAX); }
template<> inline schar sat_cast<schar>(int v)          { return (schar)((unsigned)(v-SCHAR_MIN) <= (unsigned)UCHAR_MAX ? v : v > 0 ? SCHAR_MAX : SCHAR_MIN); }
template<> inline schar sat_cast<schar>(short v)        { return sat_cast<schar>((int)v); }
template<> inline schar sat_cast<schar>(unsigned v)     { return (schar)std::min(v, (unsigned)SCHAR_MAX); }
template<> inline schar sat_cast<schar>(float v)        { int iv = std::round(v); return sat_cast<schar>(iv); }
template<> inline schar sat_cast<schar>(double v)       { int iv = std::round(v); return sat_cast<schar>(iv); }
template<> inline schar sat_cast<schar>(int64 v)        { return (schar)((uint64)((int64)v-SCHAR_MIN) <= (uint64)UCHAR_MAX ? v : v > 0 ? SCHAR_MAX : SCHAR_MIN); }
template<> inline schar sat_cast<schar>(uint64 v)       { return (schar)std::min(v, (uint64)SCHAR_MAX); }

template<> inline ushort sat_cast<ushort>(schar v)      { return (ushort)std::max((int)v, 0); }
template<> inline ushort sat_cast<ushort>(short v)      { return (ushort)std::max((int)v, 0); }
template<> inline ushort sat_cast<ushort>(int v)        { return (ushort)((unsigned)v <= (unsigned)USHRT_MAX ? v : v > 0 ? USHRT_MAX : 0); }
template<> inline ushort sat_cast<ushort>(unsigned v)   { return (ushort)std::min(v, (unsigned)USHRT_MAX); }
template<> inline ushort sat_cast<ushort>(float v)      { int iv = std::round(v); return sat_cast<ushort>(iv); }
template<> inline ushort sat_cast<ushort>(double v)     { int iv = std::round(v); return sat_cast<ushort>(iv); }
template<> inline ushort sat_cast<ushort>(int64 v)      { return (ushort)((uint64)v <= (uint64)USHRT_MAX ? v : v > 0 ? USHRT_MAX : 0); }
template<> inline ushort sat_cast<ushort>(uint64 v)     { return (ushort)std::min(v, (uint64)USHRT_MAX); }

template<> inline short sat_cast<short>(ushort v)       { return (short)std::min((int)v, SHRT_MAX); }
template<> inline short sat_cast<short>(int v)          { return (short)((unsigned)(v - SHRT_MIN) <= (unsigned)USHRT_MAX ? v : v > 0 ? SHRT_MAX : SHRT_MIN); }
template<> inline short sat_cast<short>(unsigned v)     { return (short)std::min(v, (unsigned)SHRT_MAX); }
template<> inline short sat_cast<short>(float v)        { int iv = std::round(v); return sat_cast<short>(iv); }
template<> inline short sat_cast<short>(double v)       { int iv = std::round(v); return sat_cast<short>(iv); }
template<> inline short sat_cast<short>(int64 v)        { return (short)((uint64)((int64)v - SHRT_MIN) <= (uint64)USHRT_MAX ? v : v > 0 ? SHRT_MAX : SHRT_MIN); }
template<> inline short sat_cast<short>(uint64 v)       { return (short)std::min(v, (uint64)SHRT_MAX); }

template<> inline int sat_cast<int>(unsigned v)         { return (int)std::min(v, (unsigned)INT_MAX); }
template<> inline int sat_cast<int>(int64 v)            { return (int)((uint64)(v - INT_MIN) <= (uint64)UINT_MAX ? v : v > 0 ? INT_MAX : INT_MIN); }
template<> inline int sat_cast<int>(uint64 v)           { return (int)std::min(v, (uint64)INT_MAX); }
template<> inline int sat_cast<int>(float v)            { return std::round(v); }
template<> inline int sat_cast<int>(double v)           { return std::round(v); }

template<> inline unsigned sat_cast<unsigned>(schar v)  { return (unsigned)std::max(v, (schar)0); }
template<> inline unsigned sat_cast<unsigned>(short v)  { return (unsigned)std::max(v, (short)0); }
template<> inline unsigned sat_cast<unsigned>(int v)    { return (unsigned)std::max(v, (int)0); }
template<> inline unsigned sat_cast<unsigned>(int64 v)  { return (unsigned)((uint64)v <= (uint64)UINT_MAX ? v : v > 0 ? UINT_MAX : 0); }
template<> inline unsigned sat_cast<unsigned>(uint64 v) { return (unsigned)std::min(v, (uint64)UINT_MAX); }
// we intentionally do not clip negative numbers, to make -1 become 0xffffffff etc.
template<> inline unsigned sat_cast<unsigned>(float v)  { return static_cast<unsigned>((int)std::round(v)); }
template<> inline unsigned sat_cast<unsigned>(double v) { return static_cast<unsigned>((int)std::round(v)); }

template<> inline uint64 sat_cast<uint64>(schar v)      { return (uint64)std::max(v, (schar)0); }
template<> inline uint64 sat_cast<uint64>(short v)      { return (uint64)std::max(v, (short)0); }
template<> inline uint64 sat_cast<uint64>(int v)        { return (uint64)std::max(v, (int)0); }
template<> inline uint64 sat_cast<uint64>(int64 v)      { return (uint64)std::max(v, (int64)0); }

template<> inline int64 sat_cast<int64>(uint64 v)       { return (int64)std::min(v, (uint64)LLONG_MAX); }

#ifdef NEON_PEDAL_SUPPORT_FP16
template<typename Tp> static inline Tp sat_cast(float16_t v) { return sat_cast<Tp>((float)v); }

// in theory, we could use a LUT for 8u/8s->16f conversion,
// but with hardware support for FP32->FP16 conversion the current approach is preferable
template<> inline float16_t sat_cast<float16_t>(uchar v)   { return float16_t((float)v); }
template<> inline float16_t sat_cast<float16_t>(schar v)   { return float16_t((float)v); }
template<> inline float16_t sat_cast<float16_t>(ushort v)  { return float16_t((float)v); }
template<> inline float16_t sat_cast<float16_t>(short v)   { return float16_t((float)v); }
template<> inline float16_t sat_cast<float16_t>(unsigned v){ return float16_t((float)v); }
template<> inline float16_t sat_cast<float16_t>(int v)     { return float16_t((float)v); }
template<> inline float16_t sat_cast<float16_t>(uint64 v)  { return float16_t((float)v); }
template<> inline float16_t sat_cast<float16_t>(int64 v)   { return float16_t((float)v); }
template<> inline float16_t sat_cast<float16_t>(float v)   { return float16_t(v); }
template<> inline float16_t sat_cast<float16_t>(double v)  { return float16_t((float)v); }
#endif // NEON_PEDAL_SUPPORT_FP16

#endif // SAT_CAST_H
