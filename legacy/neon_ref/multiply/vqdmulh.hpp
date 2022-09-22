#pragma once

#include "pixel_neon_base.hpp"

namespace pxl {

//----------------------------------------------------------------------
// vqdmulh_type
//----------------------------------------------------------------------
int16x4_t vqdmulh_s16(int16x4_t M, int16x4_t N);
int32x2_t vqdmulh_s32(int32x2_t M, int32x2_t N);

//----------------------------------------------------------------------
// vqdmulhq_type
//----------------------------------------------------------------------
int16x8_t vqdmulhq_s16(int16x8_t M, int16x8_t N);
int32x4_t vqdmulhq_s32(int32x4_t M, int32x4_t N);

} // namespace pxl