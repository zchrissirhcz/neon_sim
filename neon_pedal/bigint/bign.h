/**
 * 大整数类
 * 
 * 目的：在做饱和运算的模拟时，cv::saturate_cast 不适合 saturate_cast<unsigned>(v1 + v2), 考虑每个类型的cast仍然自行实现
 * 
 * 但对于 uint64_t 类型的两个数字相加， v1 + v2, 结果保存为 float 或 double 都可能造成精度丢失。
 * 
 * 因此考虑自行实现一个 bigint 类，确保计算过程中精度不丢失， 同时
 * 
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include <limits.h>

const int maxn = 200;

class BigN
{
public:
    BigN();
    explicit BigN(int num);
    explicit BigN(long long num);
    explicit BigN(unsigned long long num);

    BigN operator= (int num);
    BigN operator= (long long num);
    BigN operator= (unsigned long long num);

    BigN operator+ (const BigN& other) const;
    BigN operator- (const BigN& other) const;
    
    bool operator < (const BigN& other) const;
    bool operator > (const BigN& other) const;
    bool operator <= (const BigN& other) const;
    bool operator >= (const BigN& other) const;
    bool operator != (const BigN& other) const;
    bool operator == (const BigN& other) const;

    operator unsigned long long() const;

    int bits[maxn];
    int len;
};

BigN::BigN(unsigned long long value)
{
    while (value != 0)
    {
        bits[i] = value % 10;
        value /= 10;
    }
}

BigN BigN::operator+ (const BigN& other) const
{
    BigN result;
    int carry = 0;
    int cur_len = len();
    int other_len = other.len();
    int result_len = std::max(cur_len, other_len);
    for (int i=0; i<result_len; i++)
    {
        int temp = carry;
        if (i < cur_len)
        {
            temp += bits[i];
        }
        if (i < other_len)
        {
            temp += other.bits[i];
        }
        result.bits.push_back(temp % 10);
        carry = temp / 10;
    }
    if (carry>0)
    {
        result.bits.push_back(carry);
    }
    return result;
}

BigN BigN::operator- (const BigN& other) const
{
    BigN result;
    int carry = 0;
    int cur_len = len();
    int other_len = other.len();
    for (int i=0; i<cur_len; i++)
    {
        int temp = bits[i] - carry;
        if (i < other_len)
        {
            temp -= other.bits[i];
        }
        if (temp >= 0)
        {
            carry = 0;
        }
        else
        {
            temp += 10;
            carry = 1;
        }
        result.bits[i] = temp;
    }
    return result;
}

bool BigN::operator < (const BigN& other) const
{
    int cur_len = len();
    int other_len = other.len();
    if (cur_len != other_len)
    {
        return cur_len < other_len;
    }

    // cur_len == other_len 的情况下，从高位向低位遍历，逐位判断
    for (int i = cur_len - 1; i >= 0; i--)
    {
        if (bits[i] != other.bits[i])
        {
            return bits[i] < other.bits[i];
        }
    }
    return false;
}

bool BigN::operator > (const BigN& other) const
{
    return other < *this;
}

bool BigN::operator <= (const BigN& other) const
{
    return !(other < *this);
}

bool BigN::operator >= (const BigN& other) const
{
    return !(*this < other);
}

bool BigN::operator != (const BigN& other) const
{
    return (other < *this) || (*this < other);
}

bool BigN::operator == (const BigN& other) const
{
    return !(other < *this) && !(*this < other);
}

std::ostream& operator<< (std::ostream& os, const BigN& bign)
{
    int cur_len = bign.len();
    for (int i=cur_len-1; i>=0; i--)
    {
        os << bign.bits[i];
    }
    return os;
}

BigN::operator unsigned long long() const
{
    int cur_len = len();
    int required_len = cur_len;
    if (required_len > 64)
    {
        required_len = 64;
    }

    unsigned long long value = 0;
    for (int i=0; i<required_len; i++)
    {
        value = value * 10 + bits[i];
    }
    return value;
}