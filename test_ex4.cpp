#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

int main()
{
    //#### Arithmetic
    //- add: **vaddq_f32** or **vaddq_f64**
    {
        std::cout << "eg1: ";
        float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 }, v2 = { 1.0, 1.0, 1.0, 1.0 };
        float32x4_t sum = vaddq_f32(v1, v2);
        // => sum = { 2.0, 3.0, 4.0, 5.0 }
        std::cout << sum << std::endl;
    }

    //- multiply: **vmulq_f32** or **vmulq_f64**
    {
        std::cout << "eg2: ";
        float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 }, v2 = { 1.0, 1.0, 1.0, 1.0 };
        float32x4_t prod = vmulq_f32(v1, v2);
        // => prod = { 1.0, 2.0, 3.0, 4.0 }
        std::cout << prod << std::endl;
    }
    
    //- multiply and accumulate: **vmlaq_f32**
    {
        std::cout << "eg3: ";
        float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 }, v2 = { 2.0, 2.0, 2.0, 2.0 }, v3 = { 3.0, 3.0, 3.0, 3.0 };
        float32x4_t acc = vmlaq_f32(v3, v1, v2);  // acc = v3 + v1 * v2
        // => acc = { 5.0, 7.0, 9.0, 11.0 }
        std::cout << acc << std::endl;
    }
    
    //- multiply by a scalar: **vmulq_n_f32** or **vmulq_n_f64**
    {
        std::cout << "eg4: ";
        float32x4_t v = { 1.0, 2.0, 3.0, 4.0 };
        float32_t s = 3.0;
        float32x4_t prod = vmulq_n_f32(v, s);
        // => prod = { 3.0, 6.0, 9.0, 12.0 }
        std::cout << prod << std::endl;
    }
    
    //- multiply by a scalar and accumulate: **vmlaq_n_f32** or **vmlaq_n_f64**
    {
        std::cout << "eg5: ";
        float32x4_t v1 = { 1.0, 2.0, 3.0, 4.0 }, v2 = { 1.0, 1.0, 1.0, 1.0 };
        float32_t s = 3.0;
        float32x4_t acc = vmlaq_n_f32(v1, v2, s);
        // => acc = { 4.0, 5.0, 6.0, 7.0 }
        std::cout << acc << std::endl;
    }
    
    //- invert (needed for division): **vrecpeq_f32** or **vrecpeq_f64**
    {
        std::cout << "eg6: ";
        float32x4_t v = { 1.0, 2.0, 3.0, 4.0 };
        float32x4_t reciprocal = vrecpeq_f32(v);
        // => reciprocal = { 0.998046875, 0.499023438, 0.333007813, 0.249511719 }
        std::cout << reciprocal << std::endl;
    }
    
    //- invert (more accurately): use a [Newton-Raphson iteration](http://en.wikipedia.org/wiki/Division_algorithm#Newton.E2.80.93Raphson_division) to refine the estimate
    {
        std::cout << "eg7: ";
        float32x4_t v = { 1.0, 2.0, 3.0, 4.0 };
        float32x4_t reciprocal = vrecpeq_f32(v);
        float32x4_t inverse = vmulq_f32(vrecpsq_f32(v, reciprocal), reciprocal);
        // => inverse = { 0.999996185, 0.499998093, 0.333333015, 0.249999046 }
        std::cout << inverse << std::endl;
    }

    //#### Load

    //- load vector: **vld1q_f32** or **vld1q_f64**
    {
        std::cout << "eg8: ";
        float values[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
        float32x4_t v = vld1q_f32(values);
        // => v = { 1.0, 2.0, 3.0, 4.0 }
        std::cout << v << std::endl;
    }

    //- load same value for all lanes: **vld1q_dup_f32** or **vld1q_dup_f64**
    {
        std::cout << "eg9: ";
        float val = 3.0;
        float32x4_t v = vld1q_dup_f32(&val);
        // => v = { 3.0, 3.0, 3.0, 3.0 }
        std::cout << v << std::endl;
    }

    //- set all lanes to a hardcoded value: **vmovq_n_f16** or **vmovq_n_f32** or **vmovq_n_f64**
    {
        std::cout << "eg10: ";
        float32x4_t v = vmovq_n_f32(1.5);
        // => v = { 1.5, 1.5, 1.5, 1.5 }
        std::cout << v << std::endl;
    }

    //#### Store

    //- store vector: **vst1q_f32** or **vst1q_f64**
    {
        std::cout << "eg11: ";
        float32x4_t v = { 1.0, 2.0, 3.0, 4.0 };
        float values[5];
        vst1q_f32(values, v);
        // => values = { 1.0, 2.0, 3.0, 4.0, #undef }
        std::cout << v << std::endl;
    }

    //- store lane of array of vectors: **vst4q_lane_f16** or **vst4q_lane_f32** or **vst4q_lane_f64** (change to **vst1...** / **vst2...** / **vst3...** for other array lengths);
    {
        std::cout << "eg12: ";
        float32x4_t v0 = { 1.0, 2.0, 3.0, 4.0 }, v1 = { 5.0, 6.0, 7.0, 8.0 }, v2 = { 9.0, 10.0, 11.0, 12.0 }, v3 = { 13.0, 14.0, 15.0, 16.0 };
        float32x4x4_t u = { v0, v1, v2, v3 };
        float buff[4];
        vst4q_lane_f32(buff, u, 0);
        // => buff = { 1.0, 5.0, 9.0, 13.0 }
        for (int i = 0; i < 4; i++)
        {
            if (i > 0) std::cout << ", ";
            std::cout << buff[i];
        }
        std::cout << std::endl;
    }

    //#### Arrays

    //- access to values: **val[n]**
    {
        std::cout << "eg13: ";
        float32x4_t v0 = { 1.0, 2.0, 3.0, 4.0 }, v1 = { 5.0, 6.0, 7.0, 8.0 }, v2 = { 9.0, 10.0, 11.0, 12.0 }, v3 = { 13.0, 14.0, 15.0, 16.0 };
        float32x4x4_t ary = { v0, v1, v2, v3 };
        float32x4_t v = ary.val[2];
        // => v = { 9.0, 10.0, 11.0, 12.0 }
        std::cout << v << std::endl;
    }

    //#### Max and min

    //- max of two vectors, element by element:
    {
        std::cout << "eg14: ";
        float32x4_t v0 = { 5.0, 2.0, 3.0, 4.0 }, v1 = { 1.0, 6.0, 7.0, 8.0 };
        float32x4_t v2 = vmaxq_f32(v0, v1);
        // => v2 = { 5.0, 6.0, 7.0, 8.0 }
        std::cout << v2 << std::endl;
    }

    //- max of vector elements, using folding maximum:
    {
        std::cout << "eg15: ";
        float32x4_t v0 = { 1.0, 2.0, 3.0, 4.0 };
        float32x2_t maxOfHalfs = vpmax_f32(vget_low_f32(v0), vget_high_f32(v0));
        float32x2_t maxOfMaxOfHalfs = vpmax_f32(maxOfHalfs, maxOfHalfs);
        float maxValue = vget_lane_f32(maxOfMaxOfHalfs, 0);
        // => maxValue = 4.0
        std::cout << maxValue << std::endl;
    }

    //- min of two vectors, element by element:
    {
        std::cout << "eg16: ";
        float32x4_t v0 = { 5.0, 2.0, 3.0, 4.0 }, v1 = { 1.0, 6.0, 7.0, 8.0 };
        float32x4_t v2 = vminq_f32(v0, v1);
        // => v2 = { 1.0, 2.0, 3.0, 4.0 }
        std::cout << v2 << std::endl;
    }

    //- min of vector elements, using folding minimum:
    {
        std::cout << "eg17: ";
        float32x4_t v0 = { 1.0, 2.0, 3.0, 4.0 };
        float32x2_t minOfHalfs = vpmin_f32(vget_low_f32(v0), vget_high_f32(v0));
        float32x2_t minOfMinOfHalfs = vpmin_f32(minOfHalfs, minOfHalfs);
        float minValue = vget_lane_f32(minOfMinOfHalfs, 0);
        // => minValue = 1.0
        std::cout << minValue << std::endl;
    }

    //### Conditionals

    //- ternary operator: use vector comparison (for example **vcltq_f32** for *less than* comparison)
    {
        std::cout << "eg18: ";
        float32x4_t v1 = { 1.0, 0.0, 1.0, 0.0 }, v2 = { 0.0, 1.0, 1.0, 0.0 };
        uint32x4_t mask = vcltq_f32(v1, v2);  // v1 < v2
        float32x4_t ones = vmovq_n_f32(10.0), twos = vmovq_n_f32(20.0); // the conditional branches: if condition is true returns 10.0, else returns 20.0
        float32x4_t v3 = vbslq_f32(mask, ones, twos);  // will select first if mask 0, second if mask 1
        // => v3 = { 20.0, 10.0, 20.0, 20.0 }
        std::cout << v3 << std::endl;
    }

    return 0;
}