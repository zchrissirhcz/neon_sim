/**
 * Saturating casts
 * 
 * OpenCV's saturate_cast<Tp> will ignore Tp=int case.
 * Thus, I implement sat_cast
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#include <limits.h>

typedef unsigned char uchar;
typedef signed char   schar;

// define template functions with default behaviour: cast to template type.
template<typename Tp> static inline Tp sat_cast(int8_t v)       { return Tp(v); }
template<typename Tp> static inline Tp sat_cast(uint8_t v)      { return Tp(v); }
template<typename Tp> static inline Tp sat_cast(int16_t v)      { return Tp(v); }
template<typename Tp> static inline Tp sat_cast(uint16_t v)     { return Tp(v); }
template<typename Tp> static inline Tp sat_cast(int32_t v)      { return Tp(v); }
template<typename Tp> static inline Tp sat_cast(uint32_t v)     { return Tp(v); }
template<typename Tp> static inline Tp sat_cast(int64_t v)      { return Tp(v); }
template<typename Tp> static inline Tp sat_cast(uint64_t v)     { return Tp(v); }
template<typename Tp> static inline Tp sat_cast(float v)      { return Tp(v); }

//template<> static inline int8_t sat_cast(int8_t v)
template<> static inline int8_t sat_cast(uint8_t v)
{

}

template<> static inline int8_t sat_cast(int16_t v);
template<> static inline int8_t sat_cast(uint16_t v);
template<> static inline int8_t sat_cast(int32_t v);
template<> static inline int8_t sat_cast(uint32_t v);
template<> static inline int8_t sat_cast(int64_t v);
template<> static inline int8_t sat_cast(uint64_t v);
template<> static inline int8_t sat_cast(float v);

// template specializations
// template<> inline uint8_t sat_cast<int8_t>(uint8_t v)
// {
    
// }






//template<> inline uchar saturate_cast<uchar>(int v)          { return (uchar)((unsigned)v <= UCHAR_MAX ? v : v > 0 ? UCHAR_MAX : 0); }

// uchar saturate_cast_uchar(int a)
// {
//     return uchar(a);
// }

int main()
{
    // 
    //uchar a = saturate_cast_uchar(-100);
    uchar a = sat_cast<uchar>(-100);
    //std::cout << a << std::endl;
    printf("%d\n", a);

    return 0;
}