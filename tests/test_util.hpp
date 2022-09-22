#pragma once

#include "gtest/gtest.h"

#include <iostream>
#include <cmath>

#define NEON_SIM_IMPLEMENTATION

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif // __ARM_NEON

static bool almostEqual(const uint8x8_t& expected, const uint8x8_t& actual, double eps=0)
{
    for (int i = 0; i < 8; i++)
    {
        const double diff = std::fabs((double)expected[i] - (double)actual[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual[i] << ") != expected[" << i << "] (" << (int)expected[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}
