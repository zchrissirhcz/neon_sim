#include "bign.h"

BigN::BigN()
{
    memset(bits, 0, sizeof(bits));
    len = 1;
}

BigN::BigN(int num)
{
    *this = num;
}

BigN::BigN(long long num)
{
    *this = num;
}

BigN::BigN(unsigned long long num)
{
    *this = num;
}

BigN operator = (int num)
{
    char s[maxn];
    sprintf(s, "%d", num);
    *this = s;
    return *this;
}

BigN operator = (long long num)
{
    char s[maxn];
    sprintf(s, "%lld", num);
    *this = s;
    return *this;
}

BigN operator = (unsigned long long num)
{
    char s[maxn];
    sprintf(s, "%llu", num);
    *this = s;
    return *this;
}

BigN operator = (const char* num)
{
    len = strlen(num);
    for (int i = 0; i < len; i++)
    {
        s[i] = num[len-i-1] - '0';
    }
    return *this;
}


int main()
{
    BigN a {123232};
    BigN b {99999999};
    BigN c = a + b;
    BigN uint_max {UINT_MAX};
    if (c < uint_max)
    {
        printf("c < UINT_MAX\n");
        unsigned long long res = c;
        printf("%llu\n", res);
    }
    else
    {
        printf("c >= UINT_MAX\n");
    }

    BigN d = 100;
    BigN e = 999;
    BigN f = d - e;
    
    std::cout << f << std::endl;

    return 0;
}