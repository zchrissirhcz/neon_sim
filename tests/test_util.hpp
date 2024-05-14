#pragma once

//#include "gtest/gtest.h"
#include "utest.h"
#define TEST UTEST

#include <iostream>
#include <vector>
#include <cmath>


//#include <arm_neon.h>
//#include "neon_helper.hpp"
#include "neon_sim.h"


static bool almostEqual(const uint8x8_t& expected, const uint8x8_t& actual, double eps=0)
{
    for (int i = 0; i < 8; i++)
    {
        const double diff = std::fabs((double)expected.val[i] - (double)actual.val[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual.val[i] << ") != expected[" << i << "] (" << (int)expected.val[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

static bool almostEqual(const int8x8_t& expected, const int8x8_t& actual, double eps=0)
{
    for (int i = 0; i < 8; i++)
    {
        const double diff = std::fabs((double)expected.val[i] - (double)actual.val[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual.val[i] << ") != expected[" << i << "] (" << (int)expected.val[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

static bool almostEqual(const uint16x8_t& expected, const uint16x8_t& actual, double eps=0)
{
    for (int i = 0; i < 8; i++)
    {
        const double diff = std::fabs((double)expected.val[i] - (double)actual.val[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual.val[i] << ") != expected[" << i << "] (" << (int)expected.val[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

static bool almostEqual(const int16x8_t& expected, const int16x8_t& actual, double eps=0)
{
    for (int i = 0; i < 8; i++)
    {
        const double diff = std::fabs((double)expected.val[i] - (double)actual.val[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual.val[i] << ") != expected[" << i << "] (" << (int)expected.val[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

static bool almostEqual(const int8x16_t& expected, const int8x16_t& actual, double eps=0)
{
    for (int i = 0; i < 16; i++)
    {
        const double diff = std::fabs((double)expected.val[i] - (double)actual.val[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual.val[i] << ") != expected[" << i << "] (" << (int)expected.val[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

static bool almostEqual(const uint8x8x2_t& expected, const uint8x8x2_t& actual)
{
    for (int i = 0; i < 2; i++)
    {
        if (!almostEqual(expected.val[i], actual.val[i]))
        {
            return false;
        }
    }
    return true;
}

static bool almostEqual(const float32x4_t& expected, const float32x4_t& actual, double eps=0)
{
    for (int i = 0; i < 4; i++)
    {
        const double diff = std::fabs((double)expected.val[i] - (double)actual.val[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual.val[i] << ") != expected[" << i << "] (" << (int)expected.val[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

static bool almostEqual(const int16x4_t& expected, const int16x4_t& actual, double eps=0)
{
    for (int i = 0; i < 4; i++)
    {
        const double diff = std::fabs((double)expected.val[i] - (double)actual.val[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual.val[i] << ") != expected[" << i << "] (" << (int)expected.val[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

static bool almostEqual(const std::vector<float>& expected, const std::vector<float>& actual, double eps=0)
{
    for (int i = 0; i < 4; i++)
    {
        const double diff = std::fabs(expected[i] - actual[i]);
        if (diff > eps)
        {
            std::cerr << "array[" << i << "] (" << (int)actual[i] << ") != expected[" << i << "] (" << (int)expected[i] 
                      << "), diff = " << diff << ", EPS = " << eps << std::endl;
            return false;
        }
    }
    return true;
}

