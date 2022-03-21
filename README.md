# NEON 模拟库： C++ 重新实现 Intrinsics

## Known issues
1. 不保证 Intrinsics 的模拟实现的正确性； 但通过增加例子并持续验证， 可提高正确性。
1. `vgetq_lane_f32(sum_vec, 4)` 无法执行编译时越界检查(4不在`[0,3]`范围内), 只能在运行时执行范围检查
2. 无法处理汇编， 即不支持含有 `asm volatile("...")` 的文件。