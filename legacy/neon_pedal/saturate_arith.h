#ifndef SATURATE_ARITH_H
#define SATURATE_ARITH_H

#include "bignumber.h"
#include "sat_cast.h"

template<typename Tp>
Tp saturate_add(Tp a, Tp b)
{
    return sat_cast<Tp>( (int64_t)(a[i]) + (int64_t)(b[i]) );
}

int64_t string_to_int64(const std::string& str)
{
    int sign = 1;
    int start_pos = 0;
    if (str[0]=='-')
    {
        sign = -1;
        start_pos = 1;
    }

    int64_t value = 0;
    for (int i=start_pos; i<str.length(); i++)
    {
        value = value * 10 + (str[i] - '0');
    }
    return value;
}

uint64_t string_to_uint64(const std::string& str)
{
    int sign = 1;
    int start_pos = 0;

    uint64_t value = 0;
    for (int i=start_pos; i<str.length(); i++)
    {
        value = value * 10 + (str[i] - '0');
    }
    return value;
}


template<>
int64_t saturate_add(int64_t a, int64_t b)
{
    BigNumber ta {a};
    BigNumber tb {b};
    BigNumber tc = ta + tb;

    int64_t int64_max = 1ULL<<63 - 1;
    int64_t int64_min = - (1ULL<<63);

    BigNumber bn_int64_max { int64_max };
    BigNumber bn_int64_min { int64_min };

    int64_t res;

    if (tc > bn_int64_max)
    {
        res = int64_max;
    }
    else if (tc < bn_int64_min)
    {
        res = int64_min;
    }
    else
    {
        std::string ts = tc.getString();
        res = string_to_int64(ts);
    }

    return res;
}

template<>
uint64_t saturate_add(uint64_t a, uint64_t b)
{
    BigNumber ta {a};
    BigNumber tb {b};
    BigNumber tc = ta + tb;

    uint64_t uint64_max = 1ULL<<64 - 1;

    BigNumber bn_uint64_max { uint64_max };
    BigNumber bn_zero { 0 };

    uint64_t res;

    if (tc > bn_uint64_max)
    {
        res = uint64_max;
    }
    else if (tc < bn_zero)
    {
        res = 0;
    }
    else
    {
        std::string ts = tc.getString();
        res = string_to_uint64(ts);
    }

    return res;
}


#endif // SATURATE_ARITH_H