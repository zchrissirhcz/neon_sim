#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

void iterative_reciprocal_example()
{
    float32x4_t src = { 1.0, 2.0, 3.0, 4.0 };

    float32x4_t recip = vrecpeq_f32(src);
    //此时能达到千分之一左右的精度,如 1.0 的倒数为0.998047
    // 0.998047, 0.499023, 0.333008, 0.249512
    std::cout << recip << std::endl;

    float32x4_t rec = recip;
    recip = vmulq_f32 (vrecpsq_f32 (src, rec), rec);
    // 执行后能达到百万分之一左右的精度,如1.0 的倒数为 0.999996
    // 0.999996, 0.499998, 0.333333, 0.249999
    std::cout << recip << std::endl;

    rec = recip;
    recip = vmulq_f32 (vrecpsq_f32 (src, rec), rec);
    //再次执行后能基本能达到完全精度,如1.0 的倒数为 1.000000
    // 1, 0.5, 0.333333, 0.25
    std::cout << recip << std::endl;
}


#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>

// Convenience struct to deal with encoding and decoding ieee754 floats


// calculate 1/sqrt(a)
float my_inv_sqrt(float a)
{
    float x = 1;
    int cnt = 0;
    const int max_cnt = 5;
    while (true) {
        x = x * (1.5 - 0.5 * a * x * x);
        cnt ++;

        if (cnt > max_cnt) {
            break;
        }

        fprintf(stderr, "    cnt = %d, x = %lf\n", cnt, x);
    }
    return x;
}


float my_inv(float a)
{
    float x = 0.48;
    int cnt = 0;
    const int max_cnt = 5;
    while (true) {
        x = a * x * x;
        cnt ++;

        if (cnt > max_cnt) {
            break;
        }

        fprintf(stderr, "    cnt = %d, x = %lf\n", cnt, x);
    }
    return x;
}

float my_inv2(float a)
{
    int a_fx = a * (1 << 9);
    a_fx = a_fx*2 + 1;
    int b = (1<<19) / (2 * a_fx + 1);
    b = (b + 1) / 2;
    return b >> 9;
}


int main()
{
    // //- invert (needed for division): **vrecpeq_f32** or **vrecpeq_f64**
    // float32x4_t src = { 1.0, 2.0, 3.0, 4.0 };
    // float32x4_t rec = vrecpeq_f32(src);
    // // => reciprocal = { 0.998046875, 0.499023438, 0.333007813, 0.249511719 }
    // std::cout << rec << std::endl;

    //- invert (more accurately): use a [Newton-Raphson iteration](http://en.wikipedia.org/wiki/Division_algorithm#Newton.E2.80.93Raphson_division) to refine the estimate
    {
        std::cout << "eg7: ";
        float32x4_t v = { 1.0, 2.0, 3.0, 4.0 };
        float32x4_t reciprocal = vrecpeq_f32(v);
        float32x4_t ret = vrecpsq_f32(v, reciprocal);
        
        std::cout << ret << std::endl;
    }

    // float ret = FPRecipEstimate(2.0f);
    // std::cout << ret << std::endl;
    // float_parts fp2(ret);
    // std::cout << fp2.sign << " " << fp2.exp << "(" << fp2.exp_bits_str << "), " << fp2.fraction  << "(" << fp2.fraction_bits_str << ")" << std::endl;

    // std::cout 
    //           << FPRecipEstimate(1.0f) << ", "
    //           << FPRecipEstimate(2.0f) << ", "
    //           << FPRecipEstimate(3.0f) << ", "
    //           << FPRecipEstimate(4.0f) << "\n";


    return 0;
}
