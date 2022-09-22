#include "bignumber.h"

int main()
{
    BigNumber a = -2;
    BigNumber b = a - 4;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::string c = b.getString();
    std::cout << c << std::endl;

    return 0;
}