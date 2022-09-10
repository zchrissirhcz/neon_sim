# neon_sim

ARM NEON Intrinsics implementation in C++, for accurate understanding of each "neon function".

## Usage
Replace
```c++
#if __ARM_NEON
#include <arm_neon.h>
#endif // __ARM_NEON
```
with
```c++
#define NEON_SIM_IMPLEMENTATION

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif // __ARM_NEON
```


## Features
- Real cross-platform
    - 100% in C/C++, no SSE stuffs
    - "Debuggable inside the intrinsics"
- Closer to native neon usage
    - Support initializer list
        ```c++
        int8x8_t a = {1, -2, 3, 4, 5, 6, 7, 8};
        ```
    - Support compile time vector type checking
        ```c++
        uint8_t b[4] = {5, 6, 7, 8};
        uint16x4_t v_b = vld1_u16(b);
        ```
    - Support same-length-differnt-type conversion(require `-flax-vector-conversions` sometimes)

## Known issues
1. The correctness of the simulation implementation is not guaranteed. 
2. However, the accuracy can be improved by adding examples and continuously verifying.
3. Not Support inline assembly, i.e. `asm volatile("...")` stuffs.
4. `vgetq_lane_f32(sum_vec, 4)` failed to check-and-report index out of bounds of `[0, 3]` in compile time.
