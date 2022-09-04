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
0. 良好的跨平台支持： 不依赖 SSE， 完全由 C++ 11 实现

1. 支持初始化列表（和NDK保持一致）; NEON_2_SSE.h 则不支持
```c++
int8x8_t a = {1, -2, 3, 4, 5, 6, 7, 8};
```

2. 支持数据类型不匹配的编译时检查（和NDK保持一致）；NEON_2_SSE.h 则不支持
```c++
    uint8_t b[4] = {5, 6, 7, 8};
    uint16x4_t v_b = vld1_u16(b);
```

3. 支持等宽向量数据类型转换(和NDK保持一致)，也可一键关闭转换（有些编译器如arm-gcc-9.2.1编译报错，需手动开-flax-vector-conversions来避开）
```c++
template<class T, size_t N>
struct TxN
{
    ...

    // type operator
    template<typename T2, size_t N2>
    operator TxN<T2, N2>()
    {
        if (sizeof(T)*N == sizeof(T2)*N2) {
            TxN<T2, N2> obj;
            memcpy(obj.val, val, sizeof(T)*N);
            return obj;
        }
        abort();
    }

    ...
}
```

## Known issues
1. 不保证 Intrinsics 的模拟实现的正确性； 但通过增加例子并持续验证， 可提高正确性。
1. `vgetq_lane_f32(sum_vec, 4)` 无法执行编译时越界检查(4不在`[0,3]`范围内), 只能在运行时执行范围检查
2. 无法处理汇编， 即不支持含有 `asm volatile("...")` 的文件。