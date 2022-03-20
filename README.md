# NEON 模拟库： C++ 重新实现 Intrinsics

## Known issues
`vgetq_lane_f32(sum_vec, 4)` 无法执行编译时越界检查(4不在`[0,3]`范围内)。