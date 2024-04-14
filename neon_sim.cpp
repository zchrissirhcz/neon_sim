#include "neon_sim.hpp"

////// Load
// vld1
uint8x8_t vld1_u8(uint8_t const* ptr)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
int8x8_t vld1_s8(int8_t const* ptr)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
uint16x4_t vld1_u16(uint16_t const* ptr)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
int16x4_t vld1_s16(int16_t const* ptr)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
uint32x2_t vld1_u32(uint32_t const* ptr)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
uint64x1_t vld1_u64(uint64_t const* ptr)
{
    uint64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
int32x2_t vld1_s32(int32_t const* ptr)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
int64x1_t vld1_s64(int64_t const* ptr)
{
    int64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
float32x2_t vld1_f32(float32_t const* ptr)
{
    float32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
float64x1_t vld1_f64(float64_t const* ptr)
{
    float64x1_t r;
    r[0] = ptr[0];
    return r;
}

// vld1q
uint8x16_t vld1q_u8(uint8_t const* ptr)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
int8x16_t vld1q_s8(int8_t const* ptr)
{
    int8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
uint16x8_t vld1q_u16(uint16_t const* ptr)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
int16x8_t vld1q_s16(int16_t const* ptr)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
uint32x4_t vld1q_u32(uint32_t const* ptr)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
int32x4_t vld1q_s32(int32_t const* ptr)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
int64x2_t vld1q_s64(int64_t const* ptr)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
uint64x2_t vld1q_u64(uint64_t const* ptr)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}
float32x4_t vld1q_f32(float32_t const* ptr)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ptr[i];
    }
    return r;
}

// vld2
uint8x8x2_t vld2_u8(uint8_t const* ptr)
{
    uint8x8x2_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
int8x8x2_t vld2_s8(int8_t const* ptr)
{
    int8x8x2_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
uint16x4x2_t vld2_u16(uint16_t const* ptr)
{
    uint16x4x2_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
int16x4x2_t vld2_s16(int16_t const* ptr)
{
    int16x4x2_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
uint32x2x2_t vld2_u32(uint32_t const* ptr)
{
    uint32x2x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
int32x2x2_t vld_s32(int32_t const* ptr)
{
    int32x2x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
float32x2x2_t vld2_f32(float const* ptr)
{
    float32x2x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}

// vld2q
uint8x16x2_t vld2q_u8(uint8_t const* ptr)
{
    uint8x16x2_t r;
    for (int i = 0; i < 16; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
int8x16x2_t vld2q_s8(int8_t const* ptr)
{
    int8x16x2_t r;
    for (int i = 0; i < 16; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
uint16x8x2_t vld2q_u16(uint16_t const* ptr)
{
    uint16x8x2_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
int16x8x2_t vld2q_s16(int16_t const* ptr)
{
    int16x8x2_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
uint32x4x2_t vld2q_u32(uint32_t const* ptr)
{
    uint32x4x2_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}
int32x4x2_t vld2q_s32(int32_t const* ptr)
{
    int32x4x2_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[2 * i + 0];
        r.val[1][i] = ptr[2 * i + 1];
    }
    return r;
}

// vld3
uint8x8x3_t vld3_u8(uint8_t const* ptr)
{
    uint8x8x3_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
int8x8x3_t vld3_s8(int8_t const* ptr)
{
    int8x8x3_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
uint16x4x3_t vld3_u16(uint16_t const* ptr)
{
    uint16x4x3_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
int16x4x3_t vld3_s16(int16_t const* ptr)
{
    int16x4x3_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
uint32x2x3_t vld3_u32(uint32_t const* ptr)
{
    uint32x2x3_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
int32x2x3_t vld3_s32(int32_t const* ptr)
{
    int32x2x3_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
float32x2x3_t vld3_f32(float const* ptr)
{
    float32x2x3_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}

// vld3q
uint8x16x3_t vld3q_u8(uint8_t const* ptr)
{
    uint8x16x3_t r;
    for (int i = 0; i < 16; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
int8x16x3_t vld3q_s8(int8_t const* ptr)
{
    int8x16x3_t r;
    for (int i = 0; i < 16; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
uint16x8x3_t vld3q_u16(uint16_t const* ptr)
{
    uint16x8x3_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
int16x8x3_t vld3q_s16(int16_t const* ptr)
{
    int16x8x3_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
uint32x4x3_t vld3q_u32(uint32_t const* ptr)
{
    uint32x4x3_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}
int32x4x3_t vld3q_s32(int32_t const* ptr)
{
    int32x4x3_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[3 * i + 0];
        r.val[1][i] = ptr[3 * i + 1];
        r.val[2][i] = ptr[3 * i + 2];
    }
    return r;
}

//////////
// vld4
uint8x8x4_t vld4_u8(uint8_t const* ptr)
{
    uint8x8x4_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
int8x8x4_t vld4_s8(int8_t const* ptr)
{
    int8x8x4_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
uint16x4x4_t vld4_u16(uint16_t const* ptr)
{
    uint16x4x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
int16x4x4_t vld4_s16(int16_t const* ptr)
{
    int16x4x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
uint32x2x4_t vld4_u32(uint32_t const* ptr)
{
    uint32x2x4_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
int32x2x4_t vld4_s32(int32_t const* ptr)
{
    int32x2x4_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
float32x2x4_t vld4_f32(float const* ptr)
{
    float32x2x4_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}

// vld4q
uint8x16x4_t vld4q_u8(uint8_t const* ptr)
{
    uint8x16x4_t r;
    for (int i = 0; i < 16; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
int8x16x4_t vld4q_s8(int8_t const* ptr)
{
    int8x16x4_t r;
    for (int i = 0; i < 16; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
uint16x8x4_t vld4q_u16(uint16_t const* ptr)
{
    uint16x8x4_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
int16x8x4_t vld4q_s16(int16_t const* ptr)
{
    int16x8x4_t r;
    for (int i = 0; i < 8; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
uint32x4x4_t vld4q_u32(uint32_t const* ptr)
{
    uint32x4x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}
int32x4x4_t vld4q_s32(int32_t const* ptr)
{
    int32x4x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][i] = ptr[4 * i + 0];
        r.val[1][i] = ptr[4 * i + 1];
        r.val[2][i] = ptr[4 * i + 2];
        r.val[3][i] = ptr[4 * i + 3];
    }
    return r;
}

// vld1q_dup
float32x4_t vld1q_dup_f32(float32_t const* ptr)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ptr[0];
    }
    return r;
}

int8x8_t vld1_lane_s8(int8_t const* ptr, int8x8_t src, const int lane)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = src[i];
    }
    r[lane] = ptr[0];
    return r;
}

uint8x8_t vld1_lane_u8(uint8_t const* ptr, uint8x8_t src, const int lane)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = src[i];
    }
    r[lane] = ptr[0];
    return r;
}

/// vldX_lane_type, X > 1
uint8x8x2_t vld2_lane_u8(uint8_t const* ptr, uint8x8x2_t src, const int lane)
{
    uint8x8x2_t res;
    if (!(lane >= 0 && lane <= 7))
    {
        fprintf(stderr, "only support [0, 7] for param lane\n");
        abort();
    }
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == lane)
            {
                res.val[j][i] = ptr[j];
            }
            else
            {
                res.val[j][i] = src.val[j][i];
            }
        }
    }
    return res;
}

uint8x8x3_t vld3_lane_u8(uint8_t const* ptr, uint8x8x3_t src, const int lane)
{
    if (!(lane >= 0 && lane <= 7))
    {
        fprintf(stderr, "only support [0, 7] for param lane\n");
        abort();
    }
    uint8x8x3_t res;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == lane)
            {
                res.val[j][i] = ptr[j];
            }
            else
            {
                res.val[j][i] = src.val[j][i];
            }
        }
    }
    return res;
}

uint8x8x4_t vld4_lane_u8(uint8_t const* ptr, uint8x8x4_t src, const int lane)
{
    if (!(lane >= 0 && lane <= 7))
    {
        fprintf(stderr, "only support [0, 7] for param lane\n");
        abort();
    }
    uint8x8x4_t res;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            if (i == lane)
            {
                res.val[j][i] = ptr[j];
            }
            else
            {
                res.val[j][i] = src.val[j][i];
            }
        }
    }
    return res;
}

////// Store

// vst1
void vst1_u8(uint8_t* ptr, uint8x8_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1_s8(int8_t* ptr, int8x8_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1_u16(uint16_t* ptr, uint16x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1_s16(int16_t* ptr, int16x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1_u32(uint32_t* ptr, uint32x2_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1_s32(int32_t* ptr, int32x2_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1_s64(int64_t* ptr, int64x1_t val)
{
    for (int i = 0; i < 1; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1_u64(uint64_t* ptr, uint64x1_t val)
{
    for (int i = 0; i < 1; i++)
    {
        ptr[i] = val[i];
    }
}

// vst1q
void vst1q_u8(uint8_t* ptr, uint8x16_t val)
{
    for (int i = 0; i < 16; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1q_s8(int8_t* ptr, int8x16_t val)
{
    for (int i = 0; i < 16; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1q_u16(uint16_t* ptr, uint16x8_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1q_s16(int16_t* ptr, int16x8_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1q_u32(uint32_t* ptr, uint32x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1q_s32(int32_t* ptr, int32x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1q_s64(int64_t* ptr, int64x2_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1q_u64(uint64_t* ptr, uint64x2_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[i] = val[i];
    }
}
void vst1q_f32(float32_t* ptr, float32x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val[i];
    }
}

// vst2
void vst2_s8(int8_t* ptr, int8x8x2_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2_s16(int16_t* ptr, int16x4x2_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2_s32(int32_t* ptr, int32x2x2_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}

void vst2_u8(uint8_t* ptr, uint8x8x2_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2_u16(uint16_t* ptr, uint16x4x2_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2_u32(uint32_t* ptr, uint32x2x2_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}

// vst2q
void vst2q_s8(int8_t* ptr, int8x16x2_t val)
{
    for (int i = 0; i < 16; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2q_s16(int16_t* ptr, int16x8x2_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2q_s32(int32_t* ptr, int32x4x2_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2q_u8(uint8_t* ptr, uint8x16x2_t val)
{
    for (int i = 0; i < 16; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2q_u16(uint16_t* ptr, uint16x8x2_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}
void vst2q_u32(uint32_t* ptr, uint32x4x2_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[2 * i + 0] = val.val[0][i];
        ptr[2 * i + 1] = val.val[1][i];
    }
}

// vst3
void vst3_s8(int8_t* ptr, int8x8x3_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3_s16(int16_t* ptr, int16x4x3_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3_s32(int32_t* ptr, int32x2x3_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}

void vst3_u8(uint8_t* ptr, uint8x8x3_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3_u16(uint16_t* ptr, uint16x4x3_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3_u32(uint32_t* ptr, uint32x2x3_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}

// vst3q
void vst3q_s8(int8_t* ptr, int8x16x3_t val)
{
    for (int i = 0; i < 16; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3q_s16(int16_t* ptr, int16x8x3_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3q_s32(int32_t* ptr, int32x4x3_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3q_u8(uint8_t* ptr, uint8x16x3_t val)
{
    for (int i = 0; i < 16; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3q_u16(uint16_t* ptr, uint16x8x3_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}
void vst3q_u32(uint32_t* ptr, uint32x4x3_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[3 * i + 0] = val.val[0][i];
        ptr[3 * i + 1] = val.val[1][i];
        ptr[3 * i + 2] = val.val[2][i];
    }
}

////////////////////////
// vst4
void vst4_s8(int8_t* ptr, int8x8x4_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
void vst4_s16(int16_t* ptr, int16x4x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
void vst4_s32(int32_t* ptr, int32x2x4_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}

void vst4_u8(uint8_t* ptr, uint8x8x4_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 4] = val.val[3][i];
    }
}
void vst4_u16(uint16_t* ptr, uint16x4x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
void vst4_u32(uint32_t* ptr, uint32x2x4_t val)
{
    for (int i = 0; i < 2; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 2] = val.val[3][i];
    }
}

// vst4q
void vst4q_s8(int8_t* ptr, int8x16x4_t val)
{
    for (int i = 0; i < 16; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
void vst4q_s16(int16_t* ptr, int16x8x4_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
void vst4q_s32(int32_t* ptr, int32x4x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
void vst4q_u8(uint8_t* ptr, uint8x16x4_t val)
{
    for (int i = 0; i < 16; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
void vst4q_u16(uint16_t* ptr, uint16x8x4_t val)
{
    for (int i = 0; i < 8; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
void vst4q_u32(uint32_t* ptr, uint32x4x4_t val)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[4 * i + 0] = val.val[0][i];
        ptr[4 * i + 1] = val.val[1][i];
        ptr[4 * i + 2] = val.val[2][i];
        ptr[4 * i + 3] = val.val[3][i];
    }
}
///////////////////////

// vst4q_lane
void vst4q_lane_f32(float32_t* ptr, float32x4x4_t val, const int lane)
{
    for (int i = 0; i < 4; i++)
    {
        ptr[i] = val.val[i][lane];
    }
}

// vmaxq_type
int8x16_t vmaxq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int16x8_t vmaxq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int32x4_t vmaxq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int8x16_t vmaxq_u8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int16x8_t vmaxq_u16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

int32x4_t vmaxq_u32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

float32x4_t vmaxq_f32(float32x4_t N, float32x4_t M)
{
    float32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] > M[i] ? N[i] : M[i];
    }
    return D;
}

// Vector Arithmetic

// vadd
int8x8_t vadd_s8(int8x8_t N, int8x8_t M)
{
    int8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int16x4_t vadd_s16(int16x4_t N, int16x4_t M)
{
    int16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int32x2_t vadd_s32(int32x2_t N, int32x2_t M)
{
    int32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int64x1_t vadd_s64(int64x1_t N, int64x1_t M)
{
    int64x1_t D;
    D[0] = N[0] + M[0];
    return D;
}

uint8x8_t vadd_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint16x4_t vadd_u16(uint16x4_t N, uint16x4_t M)
{
    uint16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint32x2_t vadd_u32(uint32x2_t N, uint32x2_t M)
{
    uint32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint64x1_t vadd_u64(uint64x1_t N, uint64x1_t M)
{
    uint64x1_t D;
    D[0] = N[0] + M[0];
    return D;
}

// vaddl
uint16x8_t vaddl_u8(uint8x8_t a, uint8x8_t b)
{
    uint16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = (uint16_t)(a[i]) + (uint16_t)(b[i]);
    }
    return D;
}

int16x8_t vaddw_s8(int16x8_t a, int8x8_t b)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

int32x4_t vaddw_s16(int32x4_t a, int16x4_t b)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

int64x2_t vaddw_s32(int64x2_t a, int32x2_t b)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint16x8_t vaddw_u8(uint16x8_t a, uint8x8_t b)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint32x4_t vaddw_u16(uint32x4_t a, uint16x4_t b)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint64x2_t vaddw_u32(uint64x2_t a, uint32x2_t b)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

#if __aarch64__
int16x8_t vaddw_high_s8(int16x8_t a, int8x16_t b)
{
    int16x8_t r;
    const int ofs = 8;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] + b[ofs + i];
    }
    return r;
}

int32x4_t vaddw_high_s16(int32x4_t a, int16x8_t b)
{
    int32x4_t r;
    const int ofs = 4;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] + b[ofs + i];
    }
    return r;
}

int64x2_t vaddw_high_s32(int64x2_t a, int32x4_t b)
{
    int64x2_t r;
    const int ofs = 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] + b[ofs + i];
    }
    return r;
}

uint16x8_t vaddw_high_u8(uint16x8_t a, uint8x16_t b)
{
    uint16x8_t r;
    const int ofs = 8;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] + b[ofs + i];
    }
    return r;
}

uint32x4_t vaddw_high_u16(uint32x4_t a, uint16x8_t b)
{
    uint32x4_t r;
    const int ofs = 4;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] + b[ofs + i];
    }
    return r;
}

uint64x2_t vaddw_high_u32(uint64x2_t a, uint32x4_t b)
{
    uint64x2_t r;
    const int ofs = 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] + b[ofs + i];
    }
    return r;
}
#endif // __aarch64__

// vaddhn
#if __aarch64__
int8x16_t vaddhn_high_s16(int8x8_t r, int16x8_t a, int16x8_t b)
{
    int8x16_t ret;
    for (int i = 0; i < 8; i++)
        ret[i] = r[i];
    for (int i = 0; i < 8; i++)
        ret[i + 8] = (int8_t)((a[i] + b[i]) >> 8);
    return ret;
}

int16x8_t vaddhn_high_s32(int16x4_t r, int32x4_t a, int32x4_t b)
{
    int16x8_t ret;
    for (int i = 0; i < 4; i++)
        ret[i] = r[i];
    for (int i = 0; i < 4; i++)
        ret[i + 4] = (int16_t)((a[i] + b[i]) >> 4);
    return ret;
}

int32x4_t vaddhn_high_s64(int32x2_t r, int64x2_t a, int64x2_t b)
{
    int32x4_t ret;
    for (int i = 0; i < 2; i++)
        ret[i] = r[i];
    for (int i = 0; i < 2; i++)
        ret[i + 2] = (int32_t)((a[i] + b[i]) >> 2);
    return ret;
}

uint8x16_t vaddhn_high_u16(uint8x8_t r, uint16x8_t a, uint16x8_t b)
{
    uint8x16_t ret;
    for (int i = 0; i < 8; i++)
        ret[i] = r[i];
    for (int i = 0; i < 8; i++)
        ret[i + 8] = (uint8_t)((a[i] + b[i]) >> 8);
    return ret;
}

uint16x8_t vaddhn_high_u32(uint16x4_t r, uint32x4_t a, uint32x4_t b)
{
    uint16x8_t ret;
    for (int i = 0; i < 4; i++)
        ret[i] = r[i];
    for (int i = 0; i < 4; i++)
        ret[i + 4] = (uint16_t)((a[i] + b[i]) >> 4);
    return ret;
}

uint32x4_t vaddhn_high_u64(uint32x2_t r, uint64x2_t a, uint64x2_t b)
{
    uint32x4_t ret;
    for (int i = 0; i < 2; i++)
        ret[i] = r[i];
    for (int i = 0; i < 2; i++)
        ret[i + 2] = (uint32_t)((a[i] + b[i]) >> 2);
    return ret;
}
#endif // __aarch64__

// vaddq

int8x16_t vaddq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (size_t i = 0; i < 16; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int16x8_t vaddq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int32x4_t vaddq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

int64x2_t vaddq_s64(int64x2_t N, int64x2_t M)
{
    int64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint8x16_t vaddq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (size_t i = 0; i < 16; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint16x8_t vaddq_u16(uint16x8_t N, uint16x8_t M)
{
    uint16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint32x4_t vaddq_u32(uint32x4_t N, uint32x4_t M)
{
    uint32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}
float32x4_t vaddq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] + b[i];
    }
    return r;
}

uint64x2_t vaddq_u64(uint64x2_t N, uint64x2_t M)
{
    uint64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] + M[i];
    }
    return D;
}

uint8x8_t vqadd_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        uint16_t temp = (uint16_t)a[i] + (uint16_t)b[i];
        if (temp > UINT8_MAX)
        {
            r[i] = UINT8_MAX;
        }
        else
        {
            r[i] = temp;
        }
    }
    return r;
}

// vaddl_high
#if __aarch64__
int16x8_t vaddl_high_s8(int8x16_t a, int8x16_t b)
{
    int16x8_t r;
    const int ofs = 16 / 2;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[ofs + i] + b[ofs + i];
    }
    return r;
}

int32x4_t vaddl_high_s16(int16x8_t a, int16x8_t b)
{
    int32x4_t r;
    const int ofs = 8 / 2;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[ofs + i] + b[ofs + i];
    }
    return r;
}

int64x2_t vaddl_high_s32(int32x4_t a, int32x4_t b)
{
    int64x2_t r;
    const int ofs = 4 / 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[ofs + i] + b[ofs + i];
    }
    return r;
}

uint16x8_t vaddl_high_u8(uint8x16_t a, uint8x16_t b)
{
    uint16x8_t r;
    const int ofs = 16 / 2;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[ofs + i] + b[ofs + i];
    }
    return r;
}

uint32x4_t vaddl_high_u16(uint16x8_t a, uint16x8_t b)
{
    uint32x4_t r;
    const int ofs = 8 / 2;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[ofs + i] + b[ofs + i];
    }
    return r;
}

uint64x2_t vaddl_high_u32(uint32x4_t a, uint32x4_t b)
{
    uint64x2_t r;
    const int ofs = 4 / 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[ofs + i] + b[ofs + i];
    }
    return r;
}
#endif // __aarch64__

// vqaddq
uint8x16_t vqaddq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (size_t i = 0; i < 16; i++)
    {
        uint16_t temp = (uint16_t)N[i] + (uint16_t)M[i];
        if (temp > UINT8_MAX)
        {
            D[i] = UINT8_MAX;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

uint16x4_t vpaddl_u8(uint8x8_t a)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[2 * i] + a[2 * i + 1];
    }
    return r;
}

uint16x8_t vpaddlq_u8(uint8x16_t a)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[2 * i] + a[2 * i + 1];
    }
    return r;
}

uint32x4_t vpaddlq_u16(uint16x8_t a)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[2 * i] + a[2 * i + 1];
    }
    return r;
}

// sub
int8x8_t vsub_s8(int8x8_t N, int8x8_t M)
{
    int8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int16x4_t vsub_s16(int16x4_t N, int16x4_t M)
{
    int16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int32x2_t vsub_s32(int32x2_t N, int32x2_t M)
{
    int32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int64x1_t vsub_s64(int64x1_t N, int64x1_t M)
{
    int64x1_t D;
    for (size_t i = 0; i < 1; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint8x8_t vsub_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint16x4_t vsub_u16(uint16x4_t N, uint16x4_t M)
{
    uint16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint32x2_t vsub_u32(uint32x2_t N, uint32x2_t M)
{
    uint32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint64x1_t vsub_u64(uint64x1_t N, uint64x1_t M)
{
    uint64x1_t D;
    for (size_t i = 0; i < 1; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

float32x2_t vsub_f32(float32x2_t N, float32x2_t M)
{
    float32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

float64x1_t vsub_f32(float64x1_t N, float64x1_t M)
{
    float64x1_t D;
    for (size_t i = 0; i < 1; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

// vsubq_type
int8x16_t vsubq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (size_t i = 0; i < 16; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int16x8_t vsubq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int32x4_t vsubq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
int64x2_t vsubq_s64(int64x2_t N, int64x2_t M)
{
    int64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint8x16_t vsubq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (size_t i = 0; i < 16; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint16x8_t vsubq_u16(uint16x8_t N, uint16x8_t M)
{
    uint16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint32x4_t vsubq_u32(uint32x4_t N, uint32x4_t M)
{
    uint32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}
uint64x2_t vsubq_u64(uint64x2_t N, uint64x2_t M)
{
    uint64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

float32x4_t vsubq_f32(float32x4_t N, float32x4_t M)
{
    float32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] - M[i];
    }
    return D;
}

// vsubhn
int8x8_t vsubhn_s16(int16x8_t N, int16x8_t M)
{
    int8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = (N[i] - M[i]) >> 8;
    }
    return D;
}

int16x4_t vsubn_s32(int32x4_t N, int32x4_t M)
{
    int16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = (N[i] - M[i]) >> 8;
    }
    return D;
}

int32x2_t vsubn_s64(int64x2_t N, int64x2_t M)
{
    int32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = (N[i] - M[i]) >> 8;
    }
    return D;
}

uint8x8_t vsubhn_u16(uint16x8_t N, uint16x8_t M)
{
    uint8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = (N[i] - M[i]) >> 8;
    }
    return D;
}

uint16x4_t vsubn_u32(uint32x4_t N, uint32x4_t M)
{
    uint16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = (N[i] - M[i]) >> 8;
    }
    return D;
}

uint32x2_t vsubn_u64(uint64x2_t N, uint64x2_t M)
{
    uint32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = (N[i] - M[i]) >> 8;
    }
    return D;
}

int8x8_t vhsub_s8(int8x8_t N, int8x8_t M)
{
    int8x8_t D;
    for (int i = 0; i < 8; i++)
    {
        //D[i] = (N[i] - M[i]) / 2; //not ok: result differs with `>>1`. 说明，移位和除法，是不一样的！
        D[i] = (N[i] - M[i]) >> 1; //ok
    }
    return D;
}

int16x4_t vhsub_s16(int16x4_t N, int16x4_t M)
{
    int16x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

int32x2_t vhsub_s32(int32x2_t N, int32x2_t M)
{
    int32x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

uint8x8_t vhsub_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

uint16x4_t vhsub_u16(uint16x4_t N, uint16x4_t M)
{
    uint16x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

uint32x2_t vhsub_u32(uint32x2_t N, uint32x2_t M)
{
    uint32x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

// vhsubq
int8x16_t vhsubq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

int16x8_t vhsubq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

int32x4_t vhsubq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

uint8x16_t vhsubq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

uint16x8_t vhsubq_u16(uint16x8_t N, uint16x8_t M)
{
    uint16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

uint32x4_t vhsubq_u32(uint32x4_t N, uint32x4_t M)
{
    uint32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = (N[i] - M[i]) >> 1;
    }
    return D;
}

// vqsub
int8x8_t vqsub_s8(int8x8_t N, int8x8_t M)
{
    int8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        int16_t temp = (int16_t)N[i] - (int16_t)M[i];
        if (temp > INT8_MAX)
        {
            D[i] = INT8_MAX;
        }
        else if (temp < INT8_MIN)
        {
            D[i] = INT8_MIN;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

int16x4_t vqsub_s16(int16x4_t N, int16x4_t M)
{
    int16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        int32_t temp = (int32_t)N[i] - (int32_t)M[i];
        if (temp > INT16_MAX)
        {
            D[i] = INT16_MAX;
        }
        else if (temp < INT16_MIN)
        {
            D[i] = INT16_MIN;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

int32x2_t vqsub_s32(int32x2_t N, int32x2_t M)
{
    int32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        int64_t temp = (int64_t)N[i] - (int64_t)M[i];
        if (temp > INT32_MAX)
        {
            D[i] = INT32_MAX;
        }
        else if (temp < INT32_MIN)
        {
            D[i] = INT32_MIN;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

int64x1_t vqsub_s64(int64x1_t N, int64x1_t M)
{
    int64x1_t D;
    for (size_t i = 0; i < 1; i++)
    {
        double temp = (double)N[i] - (double)M[i];
        if (temp > (double)(INT64_MAX))
        {
            D[i] = INT64_MAX;
        }
        else if (temp < INT64_MIN)
        {
            D[i] = INT64_MIN;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

// vsubl
int16x8_t vsubl_s8(int8x8_t N, int8x8_t M)
{
    int16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = (int16_t)(N[i]) - (int16_t)(M[i]);
    }
    return D;
}

int32x4_t vsubl_s16(int16x4_t N, int16x4_t M)
{
    int32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = (int32_t)(N[i]) - (int32_t)(M[i]);
    }
    return D;
}

int64x2_t vsubl_s32(int32x4_t N, int32x2_t M)
{
    int64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = (int64_t)(N[i]) - (int64_t)(M[i]);
    }
    return D;
}

uint16x8_t vsubl_u8(uint8x8_t N, uint8x8_t M)
{
    uint16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = (uint16_t)(N[i]) - (uint16_t)(M[i]);
    }
    return D;
}

uint32x4_t vsubl_u16(uint16x4_t N, uint16x4_t M)
{
    uint32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = (uint32_t)(N[i]) - (uint32_t)(M[i]);
    }
    return D;
}

uint64x2_t vsubl_u32(uint32x4_t N, uint32x2_t M)
{
    uint64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = (uint64_t)(N[i]) - (uint64_t)(M[i]);
    }
    return D;
}

// vsubw
int16x8_t vsubw_s8(int16x8_t N, int8x8_t M)
{
    int16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] - (int16_t)(M[i]);
    }
    return D;
}

int32x4_t vsubw_s16(int32x4_t N, int16x4_t M)
{
    int32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] - (int32_t)(M[i]);
    }
    return D;
}

int64x2_t vsubw_s32(int64x2_t N, int32x2_t M)
{
    int64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] - (int64_t)(M[i]);
    }
    return D;
}

uint16x8_t vsubw_u8(uint16x8_t N, uint8x8_t M)
{
    uint16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N[i] - (uint16_t)(M[i]);
    }
    return D;
}

uint32x4_t vsubw_u16(uint32x4_t N, uint16x4_t M)
{
    uint32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N[i] - (uint32_t)(M[i]);
    }
    return D;
}

uint64x2_t vsubw_u32(uint64x2_t N, uint32x2_t M)
{
    uint64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N[i] - (uint64_t)(M[i]);
    }
    return D;
}

uint8x8_t vqsub_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        int16_t temp = (int16_t)N[i] - (int16_t)M[i];
        if (temp > UINT8_MAX)
        {
            D[i] = UINT8_MAX;
        }
        else if (temp < 0)
        {
            D[i] = 0;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

uint16x4_t vqsub_u16(uint16x4_t N, uint16x4_t M)
{
    uint16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        int32_t temp = (int32_t)N[i] - (int32_t)M[i];
        if (temp > UINT16_MAX)
        {
            D[i] = UINT16_MAX;
        }
        else if (temp < 0)
        {
            D[i] = 0;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

uint32x2_t vqsub_u32(uint32x2_t N, uint32x2_t M)
{
    uint32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        int64_t temp = (int64_t)N[i] - (int64_t)M[i];
        if (temp > UINT32_MAX)
        {
            D[i] = UINT32_MAX;
        }
        else if (temp < 0)
        {
            D[i] = 0;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

uint64x1_t vqsub_u64(uint64x1_t N, uint64x1_t M)
{
    uint64x1_t D;
    for (size_t i = 0; i < 1; i++)
    {
        double temp = (double)N[i] - (double)M[i];
        if (temp > (double)(UINT64_MAX))
        {
            D[i] = UINT64_MAX;
        }
        else if (temp < 0)
        {
            D[i] = 0;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

// vqsubq
int8x16_t vqsubq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (size_t i = 0; i < 16; i++)
    {
        int16_t temp = (int16_t)N[i] - (int16_t)M[i];
        if (temp > INT8_MAX)
        {
            D[i] = INT8_MAX;
        }
        else if (temp < INT8_MIN)
        {
            D[i] = INT8_MIN;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

int16x8_t vqsubq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        int32_t temp = (int32_t)N[i] - (int32_t)M[i];
        if (temp > INT16_MAX)
        {
            D[i] = INT16_MAX;
        }
        else if (temp < INT16_MIN)
        {
            D[i] = INT16_MIN;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

int32x4_t vqsubq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        int64_t temp = (int64_t)N[i] - (int64_t)M[i];
        if (temp > INT32_MAX)
        {
            D[i] = INT32_MAX;
        }
        else if (temp < INT32_MIN)
        {
            D[i] = INT32_MIN;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

int64x2_t vqsubq_s64(int64x2_t N, int64x2_t M)
{
    int64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        double temp = (double)N[i] - (double)M[i];
        if (temp > (double)(INT64_MAX))
        {
            D[i] = INT64_MAX;
        }
        else if (temp < INT64_MIN)
        {
            D[i] = INT64_MIN;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

uint8x16_t vqsubq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (size_t i = 0; i < 16; i++)
    {
        int16_t temp = (int16_t)N[i] - (int16_t)M[i];
        if (temp > UINT8_MAX)
        {
            D[i] = UINT8_MAX;
        }
        else if (temp < 0)
        {
            D[i] = 0;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

uint16x8_t vqsubq_u16(uint16x8_t N, uint16x8_t M)
{
    uint16x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        int32_t temp = (int32_t)N[i] - (int32_t)M[i];
        if (temp > UINT16_MAX)
        {
            D[i] = UINT16_MAX;
        }
        else if (temp < 0)
        {
            D[i] = 0;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

uint32x4_t vqsubq_u32(uint32x4_t N, uint32x4_t M)
{
    uint32x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        int64_t temp = (int64_t)N[i] - (int64_t)M[i];
        if (temp > UINT32_MAX)
        {
            D[i] = UINT32_MAX;
        }
        else if (temp < 0)
        {
            D[i] = 0;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

uint64x2_t vqsubq_u64(uint64x2_t N, uint64x2_t M)
{
    uint64x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        double temp = (double)N[i] - (double)M[i];
        if (temp > (double)(UINT64_MAX))
        {
            D[i] = UINT64_MAX;
        }
        else if (temp < 0)
        {
            D[i] = 0;
        }
        else
        {
            D[i] = temp;
        }
    }
    return D;
}

int8x8_t vrsubhn_s16(int16x8_t N, int16x8_t M)
{
    int8x8_t D;
    const int16_t shift = 8;
    const int16_t delta = (1 << (shift - 1));
    for (int i = 0; i < 8; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

int16x4_t vrsubhn_s32(int32x4_t N, int32x4_t M)
{
    int16x4_t D;
    const int32_t shift = 16;
    const int32_t delta = (1 << (shift - 1));
    for (int i = 0; i < 4; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

int32x2_t vrsubhn_s64(int64x2_t N, int64x2_t M)
{
    int32x2_t D;
    const int64_t shift = 32;
    const int64_t delta = (1 << (shift - 1));
    for (int i = 0; i < 2; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

uint8x8_t vrsubhn_u16(uint16x8_t N, uint16x8_t M)
{
    uint8x8_t D;
    const uint16_t shift = 8;
    const uint16_t delta = (1 << (shift - 1));
    for (int i = 0; i < 8; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

uint16x4_t vrsubhn_u32(uint32x4_t N, uint32x4_t M)
{
    uint16x4_t D;
    const uint32_t shift = 16;
    const uint32_t delta = (1 << (shift - 1));
    for (int i = 0; i < 4; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

uint32x2_t vrsubhn_u64(uint64x2_t N, uint64x2_t M)
{
    uint32x2_t D;
    const uint64_t shift = 32;
    const uint64_t delta = (1 << (shift - 1));
    for (int i = 0; i < 2; i++)
    {
        D[i] = (N[i] - M[i] + delta) >> shift;
    }
    return D;
}

// vmul
int8x8_t vmul_s8(int8x8_t N, int8x8_t M)
{
    int8x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}

int16x4_t vmul_s16(int16x4_t N, int16x4_t M)
{
    int16x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}

int32x2_t vmul_s32(int32x2_t N, int32x2_t M)
{
    int32x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}

uint8x8_t vmul_u8(uint8x8_t N, uint8x8_t M)
{
    uint8x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}

uint16x4_t vmul_u16(uint16x4_t N, uint16x4_t M)
{
    uint16x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}

uint32x2_t vmul_u32(uint32x2_t N, uint32x2_t M)
{
    uint32x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}

// vmulq
int8x16_t vmulq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}
int16x8_t vmulq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}
int32x4_t vmulq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}
uint8x16_t vmulq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}
uint16x8_t vmulq_u16(uint16x8_t N, uint16x8_t M)
{
    uint16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}
uint32x4_t vmulq_u32(uint32x4_t N, uint32x4_t M)
{
    uint32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M[i];
    }
    return D;
}

float32x4_t vmulq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
}

// vmul_n
int16x4_t vmul_n_s16(int16x4_t N, int16_t M)
{
    int16x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

int32x2_t vmul_n_s32(int32x2_t N, int32_t M)
{
    int32x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

uint16x4_t vmul_n_u16(uint16x4_t N, uint16_t M)
{
    uint16x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

uint32x2_t vmul_n_u32(uint32x2_t N, uint32_t M)
{
    uint32x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

float32x2_t vmul_n_f32(float32x2_t N, float32_t M)
{
    float32x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

#if __aarch64__
float64x1_t vmul_n_f64(float64x1_t N, float64_t M)
{
    float64x1_t D;
    for (int i = 0; i < 1; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}
#endif // __aarch64__

// vmulq_n
int16x8_t vmulq_n_s16(int16x8_t N, int16_t M)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

int32x4_t vmulq_n_s32(int32x4_t N, int32_t M)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

uint16x8_t vmulq_n_u16(uint16x8_t N, uint16_t M)
{
    uint16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

uint32x4_t vmulq_n_u32(uint32x4_t N, uint32_t M)
{
    uint32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

float32x4_t vmulq_n_f32(float32x4_t N, float32_t M)
{
    float32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

#if __aarch64__
float64x2_t vmulq_n_f64(float64x2_t N, float64_t M)
{
    float64x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}
#endif // __aarch64__

// vmull
uint16x8_t vmull_u8(uint8x8_t a, uint8x8_t b)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
}
uint32x4_t vmull_u16(uint16x4_t a, uint16x4_t b)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
}
uint64x2_t vmull_u32(uint32x2_t a, uint32x2_t b)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
}

int16x8_t vmull_s8(int8x8_t a, int8x8_t b)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
}
int32x4_t vmull_s16(int16x4_t a, int16x4_t b)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
}
int64x2_t vmull_s32(int32x2_t a, int32x2_t b)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] * b[i];
    }
    return r;
}

// vmull_n
int32x4_t vmull_n_s16(int16x4_t N, int16_t M)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

int64x2_t vmull_n_s32(int32x2_t N, int32_t M)
{
    int64x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

uint32x4_t vmull_n_u16(uint16x4_t N, uint16_t M)
{
    uint32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

uint64x2_t vmull_n_u32(uint32x2_t N, uint32_t M)
{
    uint64x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] * M;
    }
    return D;
}

// vqdmull
int32x4_t vqdmull_s16(int16x4_t M, int16x4_t N)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        // saturating
        if (N[i] == INT16_MIN && M[i] == INT16_MIN)
        {
            D[i] = INT32_MAX;
        }
        else
        { // most cases
            D[i] = (M[i] * N[i]) * 2;
        }
    }
    return D;
}

// vmlal_type
int16x8_t vmlal_s8(int16x8_t N, int8x8_t M, int8x8_t P)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

int32x4_t vmlal_s16(int32x4_t N, int16x4_t M, int16x4_t P)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

int64x2_t vmlal_s32(int64x2_t N, int32x2_t M, int32x2_t P)
{
    int64x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

uint16x8_t vmlal_u8(uint16x8_t N, uint8x8_t M, uint8x8_t P)
{
    uint16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

uint32x4_t vmlal_u16(uint32x4_t N, uint16x4_t M, uint16x4_t P)
{
    uint32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

uint64x2_t vmlal_u32(uint64x2_t N, uint32x2_t M, uint32x2_t P)
{
    uint64x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] + (M[i] * P[i]);
    }
    return D;
}

// vmlsl_type
int16x8_t vmlsl_s8(int16x8_t N, int8x8_t M, int8x8_t P)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

int32x4_t vmlsl_s16(int32x4_t N, int16x4_t M, int16x4_t P)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

int64x2_t vmlsl_s32(int64x2_t N, int32x2_t M, int32x2_t P)
{
    int64x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

uint16x8_t vmlsl_u8(uint16x8_t N, uint8x8_t M, uint8x8_t P)
{
    uint16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

uint32x4_t vmlsl_u16(uint32x4_t N, uint16x4_t M, uint16x4_t P)
{
    uint32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

uint64x2_t vmlsl_u32(uint64x2_t N, uint32x2_t M, uint32x2_t P)
{
    uint64x2_t D;
    for (int i = 0; i < 2; i++)
    {
        D[i] = N[i] - (M[i] * P[i]);
    }
    return D;
}

// vmlaq
int8x16_t vmlaq_s8(int8x16_t N, int8x16_t M, int8x16_t P)
{
    int8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

int16x8_t vmlaq_s16(int16x8_t N, int16x8_t M, int16x8_t P)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

int32x4_t vmlaq_s32(int32x4_t N, int32x4_t M, int32x4_t P)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

uint8x16_t vmlaq_u8(uint8x16_t N, uint8x16_t M, uint8x16_t P)
{
    uint8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

uint16x8_t vmlaq_u16(uint16x8_t N, uint16x8_t M, uint16x8_t P)
{
    uint16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

uint32x4_t vmlaq_u32(uint32x4_t N, uint32x4_t M, uint32x4_t P)
{
    uint32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

float32x4_t vmlaq_f32(float32x4_t N, float32x4_t M, float32x4_t P)
{
    float32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] + M[i] * P[i];
    }
    return D;
}

// vmlaq_n
float32x4_t vmlaq_n_f32(float32x4_t a, float32x4_t b, float32_t c)
{
    float32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = a[i] + b[i] * c;
    }
    return D;
}

// Vector manipulation
////// vdup
int8x8_t vdup_n_s8(int8_t N)
{
    int8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N;
    }
    return D;
}

int16x4_t vdup_n_s16(int16_t N)
{
    int16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N;
    }
    return D;
}

int32x2_t vdup_n_s32(int32_t N)
{
    int32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N;
    }
    return D;
}

int64x1_t vdup_n_s64(int64_t N)
{
    int64x1_t D;
    for (size_t i = 0; i < 1; i++)
    {
        D[i] = N;
    }
    return D;
}

uint8x8_t vdup_n_u8(uint8_t N)
{
    uint8x8_t D;
    for (size_t i = 0; i < 8; i++)
    {
        D[i] = N;
    }
    return D;
}

uint16x4_t vdup_n_u16(uint16_t N)
{
    uint16x4_t D;
    for (size_t i = 0; i < 4; i++)
    {
        D[i] = N;
    }
    return D;
}

uint32x2_t vdup_n_u32(uint32_t N)
{
    uint32x2_t D;
    for (size_t i = 0; i < 2; i++)
    {
        D[i] = N;
    }
    return D;
}

uint64x1_t vdup_n_u64(uint64_t N)
{
    uint64x1_t D;
    for (size_t i = 0; i < 1; i++)
    {
        D[i] = N;
    }
    return D;
}

////// vdupq
uint8x16_t vdupq_n_u8(uint8_t value)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = value;
    }
    return r;
}
int8x16_t vdupq_n_s8(int8_t value)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = value;
    }
    return r;
}
uint16x8_t vdupq_n_u16(uint16_t value)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = value;
    }
    return r;
}
int16x8_t vdupq_n_s16(int16_t value)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = value;
    }
    return r;
}
uint32x4_t vdupq_n_u32(uint32_t value)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = value;
    }
    return r;
}
int32x4_t vdupq_n_s32(int32_t value)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = value;
    }
    return r;
}
float32x4_t vdupq_n_f32(float32_t value)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = value;
    }
    return r;
}

float32x4_t vmovq_n_f32(float32_t value)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = value;
    }
    return r;
}

// vget_low
float32x2_t vget_low_f32(float32x4_t a)
{
    float32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i];
    }
    return r;
}

int32x2_t vget_low_s32(int32x4_t a)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i];
    }
    return r;
}

uint32x2_t vget_low_u32(uint32x4_t a)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i];
    }
    return r;
}

int16x4_t vget_low_s16(int16x8_t a)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

uint16x4_t vget_low_u16(uint16x8_t a)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

// vget_low_type 获取 128bit vector 的低半部分元素,输出的是元素类型相同的 64bit vector。
int8x8_t vget_low_s8(int8x16_t a)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i];
    }
    return r;
}

uint8x8_t vget_low_u8(uint8x16_t a)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i];
    }
    return r;
}

// vget_high
float32x2_t vget_high_f32(float32x4_t a)
{
    float32x2_t r;
    int mid = 4 / 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

int32x2_t vget_high_s32(int32x4_t a)
{
    int32x2_t r;
    int mid = 4 / 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

int16x4_t vget_high_s16(int16x8_t a)
{
    int16x4_t r;
    int mid = 8 / 2;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

uint16x4_t vget_high_u16(uint16x8_t a)
{
    uint16x4_t r;
    int mid = 8 / 2;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

uint32x2_t vget_high_u32(uint32x4_t a)
{
    uint32x2_t r;
    int mid = 4 / 2;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

int8x8_t vget_high_s8(int8x16_t a)
{
    int8x8_t r;
    int mid = 16 / 2;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

uint8x8_t vget_high_u8(uint8x16_t a)
{
    uint8x8_t r;
    int mid = 16 / 2;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[mid + i];
    }
    return r;
}

float32x2_t vpmax_f32(float32x2_t a, float32x2_t b)
{
    float32x2_t r;
    r[0] = a[0] > a[1] ? a[0] : a[1];
    r[1] = b[0] > b[1] ? b[0] : b[1];
    return r;
}

float32x2_t vpmin_f32(float32x2_t a, float32x2_t b)
{
    float32x2_t r;
    r[0] = a[0] < a[1] ? a[0] : a[1];
    r[1] = b[0] < b[1] ? b[0] : b[1];
    return r;
}

float32_t vget_lane_f32(float32x2_t v, const int lane)
{
    return v[lane];
}

float32_t vgetq_lane_f32(float32x4_t v, int lane)
{
    if (lane < 0 || lane > 3)
    {
        fprintf(stderr, "%s: lane should is out of range [0, 3]", __FUNCTION__);
        abort();
    }
    return v[lane];
}

// vgetq_lane_type
uint8_t vgetq_lane_u8(uint8x16_t v, const int lane)
{
    return v[lane];
}

uint16_t vgetq_lane_u16(uint16x8_t v, const int lane)
{
    return v[lane];
}

uint32_t vgetq_lane_u32(uint32x4_t v, const int lane)
{
    return v[lane];
}

uint64_t vgetq_lane_u64(uint64x2_t v, const int lane)
{
    return v[lane];
}

int8_t vgetq_lane_s8(int8x16_t v, const int lane)
{
    return v[lane];
}

int16_t vgetq_lane_s16(int16x8_t v, const int lane)
{
    return v[lane];
}

int32_t vgetq_lane_s32(int32x4_t v, const int lane)
{
    return v[lane];
}

int64_t vgetq_lane_s64(int64x2_t v, const int lane)
{
    return v[lane];
}

float64_t vgetq_lane_f64(float64x2_t v, const int lane)
{
    return v[lane];
}

// vminq_type
int8x16_t vminq_s8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int16x8_t vminq_s16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int32x4_t vminq_s32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int8x16_t vminq_u8(int8x16_t N, int8x16_t M)
{
    int8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int16x8_t vminq_u16(int16x8_t N, int16x8_t M)
{
    int16x8_t D;
    for (int i = 0; i < 8; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

int32x4_t vminq_u32(int32x4_t N, int32x4_t M)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

float32x4_t vminq_f32(float32x4_t N, float32x4_t M)
{
    float32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = N[i] < M[i] ? N[i] : M[i];
    }
    return D;
}

uint32x4_t vcltq_f32(float32x4_t N, float32x4_t M)
{
    uint32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        if (N[i] < M[i])
        {
            D[i] = 0xFFFFFFFF;
        }
        else
        {
            D[i] = 0;
        }
    }
    return D;
}

float32x4_t vbslq_f32(uint32x4_t mask, float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = mask[i] ? a[i] : b[i];
    }
    return r;
}

// shift right
int8x8_t vshrn_n_s16(int16x8_t a, const int n)
{
    if (n < 1 || n > 8)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] >> n;
    }
    return r;
}

uint16x4_t vshr_n_u16(uint16x4_t v, const int n)
{
    if (n < 1 || n > 8)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint16x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = v[i] >> n;
    }
    return D;
}

int16x4_t vshrn_n_s32(int32x4_t a, const int n)
{
    if (n < 1 || n > 16)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] >> n;
    }
    return r;
}

int32x2_t vshrn_n_s64(int64x2_t a, const int n)
{
    if (n < 1 || n > 32)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] >> n;
    }
    return r;
}

uint8x8_t vshrn_n_u16(uint16x8_t a, const int n)
{
    if (n < 1 || n > 8)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] >> n;
    }
    return r;
}

uint16x4_t vshrn_n_u32(uint32x4_t a, const int n)
{
    if (n < 1 || n > 16)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] >> n;
    }
    return r;
}

uint32x2_t vshrn_n_u64(uint64x2_t a, const int n)
{
    if (n < 1 || n > 32)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] >> n;
    }
    return r;
}

/// @param n 1-8
uint8x8_t vqshrun_n_s16(int16x8_t v, const int n)
{
    if (n < 1 || n > 8)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }

    uint8x8_t D;
    for (int i = 0; i < 8; i++)
    {
        int16_t temp = v[i] >> n;
        if (temp > UINT8_MAX)
        {
            temp = UINT8_MAX;
        }
        else if (temp < 0)
        {
            temp = 0;
        }
        D[i] = temp;
    }
    return D;
}

uint16x4_t vqshrun_n_s32(int32x4_t v, const int n)
{
    if (n < 1 || n > 16)
    {
        fprintf(stderr, "%s: param n out of range\n", __FUNCTION__);
        abort();
    }
    uint16x4_t D;
    for (int i = 0; i < 4; i++)
    {
        int32_t temp = (v[i] + (1 << (n - 1))) >> n;
        if (temp > UINT16_MAX)
        {
            temp = UINT16_MAX;
        }
        else if (temp < 0)
        {
            temp = 0;
        }
    }
    return D;
}

/// @param n 1-32
uint32x2_t vqshrun_n_s64(int64x2_t v, const int n)
{
    if (n < 1 || n > 32)
    {
        fprintf(stderr, "%s: param n out of range\n", __FUNCTION__);
        abort();
    }
    uint32x2_t D;
    for (int i = 0; i < 2; i++)
    {
        int64_t temp = (v[i] + (1 << (n - 1))) >> n;
        if (temp > UINT32_MAX)
        {
            temp = UINT32_MAX;
        }
        else if (temp < 0)
        {
            temp = 0;
        }
    }
    return D;
}

uint8x8_t vqrshrun_n_s16(int16x8_t v, const int n)
{
    if (n < 1 || n > 8)
    {
        fprintf(stderr, "%s: param n not in range [1, 8]\n", __FUNCTION__);
        abort();
    }
    uint8x8_t D;
    for (int i = 0; i < 8; i++)
    {
        int16_t temp = (v[i] + (1 << (n - 1))) >> n;
        if (temp > UINT8_MAX)
        {
            temp = UINT8_MAX;
        }
        else if (temp < 0)
        {
            temp = 0;
        }
        D[i] = temp;
    }
    return D;
}

uint8x8_t vrshrn_n_u16(uint16x8_t a, const int n)
{
    uint8x8_t r;
    const int delta = (1 << (n - 1));
    for (int i = 0; i < 8; i++)
    {
        r[i] = (a[i] + delta) >> n;
    }
    return r;
}

int32x4_t vsraq_n_s32(int32x4_t a, int32x4_t b, const int n)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = (a[i] >> n) + (b[i] >> n);
    }
    return r;
}

// shift left
int32x4_t vshlq_n_s32(int32x4_t M, const int n)
{
    int32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = M[i] << n;
    }
    return D;
}

uint16x8_t vshll_n_u8(uint8x8_t a, const int n)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = (uint16_t)a[i] << n;
    }
    return r;
}

// type conversion
uint8x8_t vreinterpret_u8_s8(int8x8_t a)
{
    return a;
}

int16x8_t vreinterpretq_s16_u16(uint16x8_t a)
{
    return a;
}

uint16x8_t vreinterpretq_u16_s16(int16x8_t a)
{
    return a;
}

uint16x4_t vreinterpret_u16_u8(uint8x8_t a)
{
    return a;
}

uint32x2_t vreinterpret_u32_u16(uint16x4_t a)
{
    return a;
}

uint8x8_t vreinterpret_u8_u32(uint32x2_t a)
{
    return a;
}

uint32x2_t vreinterpret_u32_u8(uint8x8_t a)
{
    return a;
}

int8x8_t vreinterpret_s8_u8(uint8x8_t a)
{
    return a;
}

int32x2_t vreinterpret_s32_s16(int16x4_t a)
{
    return a;
}

int16x4_t vreinterpret_s16_s32(int32x2_t a)
{
    return a;
}

// vreinterpretq_u8_type
uint8x16_t vreinterpretq_u8_s8(int8x16_t a)
{
    return a;
}

uint8x16_t vreinterpretq_u8_s16(int16x8_t a)
{
    return a;
}

uint8x16_t vreinterpretq_u8_s32(int32x4_t a)
{
    return a;
}

uint8x16_t vreinterpretq_u8_f32(float32x4_t a)
{
    return a;
}

uint8x16_t vreinterpretq_u8_u16(uint16x8_t a)
{
    return a;
}

uint8x16_t vreinterpretq_u8_u32(uint32x4_t a)
{
    return a;
}

uint8x16_t vreinterpretq_u8_u64(uint64x2_t a)
{
    return a;
}

uint8x16_t vreinterpretq_u8_s64(int64x2_t a)
{
    return a;
}

#if __fp16
uint8x16_t vreinterpretq_u8_f16(float16x8_t a)
{
    return a;
}
#endif // __fp16

uint8x16_t vreinterpretq_u8_f64(float64x2_t a)
{
    return a;
}

// vreinterpretq_u32_type
uint32x4_t vreinterpretq_u32_s8(int8x16_t a)
{
    return a;
}

uint32x4_t vreinterpretq_u32_s16(int16x8_t a)
{
    return a;
}

uint32x4_t vreinterpretq_u32_s32(int32x4_t a)
{
    return a;
}

uint32x4_t vreinterpretq_u32_f32(float32x4_t a)
{
    return a;
}

uint32x4_t vreinterpretq_u32_u8(uint8x16_t a)
{
    return a;
}

uint32x4_t vreinterpretq_u32_u16(uint16x8_t a)
{
    return a;
}

uint32x4_t vreinterpretq_u32_u64(uint64x2_t a)
{
    return a;
}

uint32x4_t vreinterpretq_u32_s64(int64x2_t a)
{
    return a;
}

#if __fp16
uint32x4_t vreinterpretq_u32_f16(float16x8_t a)
{
    return a;
}
#endif // __fp16

uint32x4_t vreinterpretq_u32_f64(float64x2_t a)
{
    return a;
}

float32x4_t vcvtq_f32_s32(int32x4_t a)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

int32x4_t vcvtq_s32_f32(float32x4_t a)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

uint32x4_t vcvtq_u32_f32(float32x4_t a)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

int32x4_t vcvtnq_s32_f32(float32x4_t a)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

//----------------------------------------------------------------------
// 3. reverse and reverse square root
//----------------------------------------------------------------------
struct float_parts
{
    explicit float_parts(float v);
    explicit operator float() const;

    uint32_t sign;
    uint32_t fraction;
    uint32_t exp;

    int exp_bits[8];
    int fraction_bits[23];
    std::string exp_bits_str = std::string(8, '0');
    std::string fraction_bits_str = std::string(23, '0');

private:
    void int32_to_binary(int data, int* bits, int n = 32)
    {
        for (int i = 0; i < n; i++)
        {
            bits[n - 1 - i] = data & 1;
            data = data >> 1;
        }
    }
};

uint32_t RecipEstimate(uint32_t a)
{
    a = a * 2 + 1;
    uint32_t b = (1 << 19) / a;
    return (b + 1) / 2;
}

float FPRecipEstimate(float operand)
{
    float_parts parts{operand};
    parts.exp = 253 - parts.exp;
    uint32_t scaled = 0x100 | ((parts.fraction >> 15) & 0xFF);
    uint32_t estimate = RecipEstimate(scaled);
    parts.fraction = (estimate & 0xff) << 15;
    return float(parts);
}

float_parts::float_parts(float v)
{
    uint32_t v_bits;
    memcpy(&v_bits, &v, sizeof(float));

    sign = (v_bits >> 31) & 0x1;
    fraction = v_bits & ((1 << 23) - 1);
    exp = (v_bits >> 23) & 0xff;

    int32_to_binary(exp, exp_bits, 8);
    int32_to_binary(fraction, fraction_bits, 23);

    for (int i = 0; i < 8; i++)
    {
        exp_bits_str[i] = exp_bits[i] + '0';
    }
    for (int i = 0; i < 23; i++)
    {
        fraction_bits_str[i] = fraction_bits[i] + '0';
    }
}

float_parts::operator float() const
{
    uint32_t v_bits = ((sign & 0x1) << 31) | (fraction & ((1 << 23) - 1)) | ((exp & 0xff) << 23);

    float result;
    memcpy(&result, &v_bits, sizeof(float));
    return result;
}

float32x4_t vrecpeq_f32(float32x4_t N)
{
    float32x4_t D;
    for (int i = 0; i < 4; i++)
    {
        D[i] = FPRecipEstimate(N[i]);
    }
    return D;
}

float32x4_t vrecpsq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = 2.0 - (a[i] * b[i]);
    }
    return r;
}

/// transpose
int8x8x2_t vtrn_s8(int8x8_t a, int8x8_t b)
{
    int8x8x2_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 4; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

uint8x8x2_t vtrn_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8x2_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 4; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

int16x4x2_t vtrn_s16(int16x4_t a, int16x4_t b)
{
    int16x4x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 2; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

uint16x4x2_t vtrn_u16(uint16x4_t a, uint16x4_t b)
{
    uint16x4x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 2; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

int32x2x2_t vtrn_s32(int32x2_t a, int32x2_t b)
{
    int32x2x2_t r;
    for (int i = 0; i < 1; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 1; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

uint32x2x2_t vtrn_u32(uint32x2_t a, uint32x2_t b)
{
    uint32x2x2_t r;
    for (int i = 0; i < 1; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 1; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

// trnq
uint16x8x2_t vtrnq_u16(uint16x8_t a, uint16x8_t b)
{
    uint16x8x2_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 4; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

uint32x4x2_t vtrnq_u32(uint32x4_t a, uint32x4_t b)
{
    uint32x4x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 2; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

int16x8x2_t vtrnq_s16(int16x8_t a, int16x8_t b)
{
    int16x8x2_t r;
    for (int i = 0; i < 4; i++)
    {
        r.val[0][2 * i] = a[2 * i];
        r.val[0][2 * i + 1] = b[2 * i];
    }
    for (int i = 0; i < 4; i++)
    {
        r.val[1][2 * i] = a[2 * i + 1];
        r.val[1][2 * i + 1] = b[2 * i + 1];
    }
    return r;
}

// zip
int16x4x2_t vzip_s16(int16x4_t a, int16x4_t b)
{
    int16x4x2_t r;
    const int n = 2;
    for (int i = 0; i < n; i++)
    {
        r.val[0][2 * i] = a[i];
        r.val[0][2 * i + 1] = b[i];
    }
    for (int i = 0; i < n; i++)
    {
        r.val[1][2 * i] = a[n + i];
        r.val[1][2 * i + 1] = b[n + i];
    }
    return r;
}

// combine
uint8x16_t vcombine_u8(uint8x8_t low, uint8x8_t high)
{
    uint8x16_t r;
    const int n = 8;
    for (int i = 0; i < n; i++)
    {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++)
    {
        r[n + i] = high[i];
    }
    return r;
}
uint16x8_t vcombine_u16(uint16x4_t low, uint16x4_t high)
{
    uint16x8_t r;
    const int n = 4;
    for (int i = 0; i < n; i++)
    {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++)
    {
        r[n + i] = high[i];
    }
    return r;
}
uint32x4_t vcombine_u32(uint32x2_t low, uint32x2_t high)
{
    uint32x4_t r;
    const int n = 2;
    for (int i = 0; i < n; i++)
    {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++)
    {
        r[n + i] = high[i];
    }
    return r;
}

int8x16_t vcombine_s8(int8x8_t low, int8x8_t high)
{
    int8x16_t r;
    const int n = 8;
    for (int i = 0; i < n; i++)
    {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++)
    {
        r[n + i] = high[i];
    }
    return r;
}
int16x8_t vcombine_s16(int16x4_t low, int16x4_t high)
{
    int16x8_t r;
    const int n = 4;
    for (int i = 0; i < n; i++)
    {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++)
    {
        r[n + i] = high[i];
    }
    return r;
}
int32x4_t vcombine_s32(int32x2_t low, int32x2_t high)
{
    int32x4_t r;
    const int n = 2;
    for (int i = 0; i < n; i++)
    {
        r[i] = low[i];
    }
    for (int i = 0; i < n; i++)
    {
        r[n + i] = high[i];
    }
    return r;
}

// vmov
int16x4_t vmovn_s32(int32x4_t a)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

uint16x4_t vmovn_u32(uint32x4_t a)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}

uint8x8_t vmovn_u16(uint16x8_t a)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i];
    }
    return r;
}

// vmovl
uint16x8_t vmovl_u8(uint8x8_t a)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i];
    }
    return r;
}
uint32x4_t vmovl_u16(uint16x4_t a)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}
uint64x2_t vmovl_u32(uint32x2_t a)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i];
    }
    return r;
}

int16x8_t vmovl_s8(int8x8_t a)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i];
    }
    return r;
}
int32x4_t vmovl_s16(int16x4_t a)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i];
    }
    return r;
}
int64x2_t vmovl_s32(int32x2_t a)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i];
    }
    return r;
}

// vqmovn
uint8x8_t vqmovn_u16(uint16x8_t a)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        if (a[i] > UINT8_MAX)
        {
            r[i] = UINT8_MAX;
        }
        else
        {
            r[i] = a[i];
        }
    }
    return r;
}

uint8x8_t vqmovun_s16(int16x8_t a)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        if (a[i] < 0)
        {
            r[i] = 0;
        }
        else if (a[i] > UINT8_MAX)
        {
            r[i] = UINT8_MAX;
        }
        else
        {
            r[i] = a[i];
        }
    }
    return r;
}

// table lookup
uint8x8_t vqtbl1_u8(uint8x16_t t, uint8x8_t idx)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = t[idx[i]];
    }
    return r;
}

// vext
uint8x8_t vext_u8(uint8x8_t a, uint8x8_t b, const int n)
{
    uint8x8_t r;
    int len = 8;
    if (n > 8 || n < 0)
    {
        fprintf(stderr, "%s: param n is not in range [0, 8]\n", __FUNCTION__);
        abort();
    }
    for (int i = 0; i < len - n; i++)
    {
        r[i] = a[i + n];
    }
    for (int i = 0; i < n; i++)
    {
        r[i + len - n] = b[i];
    }
    return r;
}

uint16x4_t vext_u16(uint16x4_t a, uint16x4_t b, const int n)
{
    uint16x4_t r;
    int len = 4;
    if (n > 3 || n < 0)
    {
        fprintf(stderr, "%s: param n is not in range [0, 4]\n", __FUNCTION__);
        abort();
    }
    for (int i = 0; i < len - n; i++)
    {
        r[i] = a[i + n];
    }
    for (int i = 0; i < n; i++)
    {
        r[i + len - n] = b[i];
    }
    return r;
}

int16x4_t vext_s16(int16x4_t a, int16x4_t b, const int n)
{
    int16x4_t r;
    int len = 4;
    if (n > 3 || n < 0)
    {
        fprintf(stderr, "%s: param n is not in range [0, 4]\n", __FUNCTION__);
        abort();
    }
    for (int i = 0; i < len - n; i++)
    {
        r[i] = a[i + n];
    }
    for (int i = 0; i < n; i++)
    {
        r[i + len - n] = b[i];
    }
    return r;
}

// vextq
uint16x8_t vextq_u16(uint16x8_t a, uint16x8_t b, const int n)
{
    uint16x8_t r;
    int len = 8;
    if (n > 8 || n < 0)
    {
        fprintf(stderr, "%s: param n is not in range [0, 8]\n", __FUNCTION__);
        abort();
    }
    for (int i = 0; i < len - n; i++)
    {
        r[i] = a[i + n];
    }
    for (int i = 0; i < n; i++)
    {
        r[i + len - n] = b[i];
    }
    return r;
}

// compare
uint8x16_t vcgtq_u8(uint8x16_t N, uint8x16_t M)
{
    uint8x16_t D;
    for (int i = 0; i < 16; i++)
    {
        D[i] = N[i] > M[i] ? 0xFF : 0;
    }
    return D;
}

//Bitwise Select. This instruction sets each bit in the destination SIMD&FP register to the
// corresponding bit from the first source SIMD&FP register when the original destination bit was 1,
// otherwise from the second source SIMD&FP register.
// the original destination 说的就是 mask
uint8x16_t vbslq_u8(uint8x16_t mask, uint8x16_t src1, uint8x16_t src2)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = 0;
        for (int j = 0; j < 8; j++)
        {
            uint8_t x = (1 << (8 - 1 - j));
            if ((mask[i] & x) == x)
            {
                r[i] += (src1[i] & x);
            }
            else
            {
                r[i] += (src2[i] & x);
            }
        }
    }
    return r;
}

// vtbl1
uint8x8_t vtbl1_u8(uint8x8_t a, uint8x8_t idx)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        int index = idx.val[i];
        if (index < 0 || index > 7)
        {
            r[i] = 0;
        }
        else
        {
            r[i] = a.val[index];
        }
    }
    return r;
}

// vtbl4
uint8x8_t vtbl4_u8(uint8x8x4_t a, uint8x8_t idx)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        int index = idx.val[i];
        if (index < 0 || index > 31)
        {
            r[i] = 0;
        }
        else if (index < 8)
        { // [0, 7]
            r[i] = a.val[0][index];
        }
        else if (index < 16)
        { // [8, 15]
            r[i] = a.val[1][index - 8];
        }
        else if (index < 24)
        { // [16, 23]
            r[i] = a.val[2][index - 16];
        }
        else
        { // [24, 31]
            r[i] = a.val[3][index - 24];
        }
    }
    return r;
}

// vtbl2
uint8x8_t vtbl2_u8(uint8x8x2_t a, uint8x8_t idx)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        int index = idx.val[i];
        if (index < 0 || index > 15)
        {
            r[i] = 0;
        }
        else if (index < 8)
        {
            r[i] = a.val[0][index];
        }
        else
        { // index in [8, 15]
            r[i] = a.val[1][index - 8];
        }
    }
    return r;
}

// vand_type
int8x8_t vand_s8(int8x8_t a, int8x8_t b)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

int16x4_t vand_s16(int16x4_t a, int16x4_t b)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

int32x2_t vand_s32(int32x2_t a, int32x2_t b)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

int64x1_t vand_s64(int64x1_t a, int64x1_t b)
{
    int64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

uint8x8_t vand_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

uint16x4_t vand_u16(uint16x4_t a, uint16x4_t b)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

uint32x2_t vand_u32(uint32x2_t a, uint32x2_t b)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

uint64x1_t vand_u64(uint64x1_t a, uint64x1_t b)
{
    uint64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

// vandq_type
int8x16_t vandq_s8(int8x16_t a, int8x16_t b)
{
    int8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

int16x8_t vandq_s16(int16x8_t a, int16x8_t b)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

int32x4_t vandq_s32(int32x4_t a, int32x4_t b)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

int64x2_t vandq_s64(int64x2_t a, int64x2_t b)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

uint8x16_t vandq_u8(uint8x16_t a, uint8x16_t b)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

uint16x8_t vandq_u16(uint16x8_t a, uint16x8_t b)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

uint32x4_t vandq_u32(uint32x4_t a, uint32x4_t b)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

uint64x2_t vandq_u64(uint64x2_t a, uint64x2_t b)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] & b[i];
    }
    return r;
}

// vorr_type
int8x8_t vorr_s8(int8x8_t a, int8x8_t b)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

int16x4_t vorr_s16(int16x4_t a, int16x4_t b)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

int32x2_t vorr_s32(int32x2_t a, int32x2_t b)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

int64x1_t vorr_s64(int64x1_t a, int64x1_t b)
{
    int64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

uint8x8_t vorr_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

uint16x4_t vorr_u16(uint16x4_t a, uint16x4_t b)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

uint32x2_t vorr_u32(uint32x2_t a, uint32x2_t b)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

uint64x1_t vorr_u64(uint64x1_t a, uint64x1_t b)
{
    uint64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

// vorrq_type
int8x16_t vorrq_s8(int8x16_t a, int8x16_t b)
{
    int8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

int16x8_t vorrq_s16(int16x8_t a, int16x8_t b)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

int32x4_t vorrq_s32(int32x4_t a, int32x4_t b)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

int64x2_t vorrq_s64(int64x2_t a, int64x2_t b)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

uint8x16_t vorrq_u8(uint8x16_t a, uint8x16_t b)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

uint16x8_t vorrq_u16(uint16x8_t a, uint16x8_t b)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

uint32x4_t vorrq_u32(uint32x4_t a, uint32x4_t b)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

uint64x2_t vorrq_u64(uint64x2_t a, uint64x2_t b)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] | b[i];
    }
    return r;
}

// veor_type
int8x8_t veor_s8(int8x8_t a, int8x8_t b)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

int16x4_t veor_s16(int16x4_t a, int16x4_t b)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

int32x2_t veor_s32(int32x2_t a, int32x2_t b)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

int64x1_t veor_s64(int64x1_t a, int64x1_t b)
{
    int64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

uint8x8_t veor_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

uint16x4_t veor_u16(uint16x4_t a, uint16x4_t b)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

uint32x2_t ver_u32(uint32x2_t a, uint32x2_t b)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

uint64x1_t veor_u64(uint64x1_t a, uint64x1_t b)
{
    uint64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

// veorq_type
int8x16_t veorq_s8(int8x16_t a, int8x16_t b)
{
    int8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

int16x8_t veorq_s16(int16x8_t a, int16x8_t b)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

int32x4_t veorq_s32(int32x4_t a, int32x4_t b)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

int64x2_t veorq_s64(int64x2_t a, int64x2_t b)
{
    int64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

uint8x16_t veorq_u8(uint8x16_t a, uint8x16_t b)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

uint16x8_t veorq_u16(uint16x8_t a, uint16x8_t b)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

uint32x4_t veorq_u32(uint32x4_t a, uint32x4_t b)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

uint64x2_t veorq_u64(uint64x2_t a, uint64x2_t b)
{
    uint64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] ^ b[i];
    }
    return r;
}

// vmvn_type
int8x8_t vmvn_s8(int8x8_t a)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

int16x4_t vmvn_s16(int16x4_t a)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

int32x2_t vmvn_s32(int32x2_t a)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

uint8x8_t vmvn_u8(uint8x8_t a)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

uint16x4_t vmvn_u16(uint16x4_t a)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

uint32x2_t vmvn_u32(uint32x2_t a)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

// vmvnq_type
int8x16_t vmvnq_s8(int8x16_t a)
{
    int8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

int16x8_t vmvnq_s16(int16x8_t a)
{
    int16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

int32x4_t vmvnq_s32(int32x4_t a)
{
    int32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

uint8x16_t vmvnq_u8(uint8x16_t a)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

uint16x8_t vmvnq_u16(uint16x8_t a)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

uint32x4_t vmvnq_u32(uint32x4_t a)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = ~a[i];
    }
    return r;
}

// vzip_type
int8x8x2_t vzip_s8(int8x8_t a, int8x8_t b)
{
    int8x8x2_t r;
    const int vlen = 8;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            r.val[0][i] = a[i / 2];
            r.val[1][i] = a[i / 2 + vlen / 2];
        }
        else
        {
            r.val[0][i] = b[i / 2];
            r.val[1][i] = b[i / 2 + vlen / 2];
        }
    }
    return r;
}

uint8x8x2_t vzip_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8x2_t r;
    const int vlen = 8;
    for (int i = 0; i < 8; i++)
    {
        if (i % 2 == 0)
        {
            r.val[0][i] = a[i / 2];
            r.val[1][i] = a[i / 2 + vlen / 2];
        }
        else
        {
            r.val[0][i] = b[i / 2];
            r.val[1][i] = b[i / 2 + vlen / 2];
        }
    }
    return r;
}

// vuzp_type
uint8x8x2_t vuzp_u8(uint8x8_t a, uint8x8_t b)
{
    uint8x8x2_t r;
    for (int i = 0; i < 8; i += 2)
    {
        r.val[0][i / 2] = a[i];
        r.val[1][i / 2] = a[i + 1];
    }

    for (int i = 0; i < 8; i += 2)
    {
        r.val[0][i / 2 + 4] = b[i];
        r.val[1][i / 2 + 4] = b[i + 1];
    }
    return r;
}

int8x8x2_t vuzp_s8(int8x8_t a, int8x8_t b)
{
    int8x8x2_t r;
    for (int i = 0; i < 8; i += 2)
    {
        r.val[0][i / 2] = a[i];
        r.val[1][i / 2] = a[i + 1];
    }

    for (int i = 0; i < 8; i += 2)
    {
        r.val[0][i / 2 + 4] = b[i];
        r.val[1][i / 2 + 4] = b[i + 1];
    }
    return r;
}

// vrev16_type
int8x8_t vrev16_s8(int8x8_t vec)
{
    int8x8_t r;
    for (int i = 0; i < 8; i += 2)
    {
        r[i] = vec[i + 1];
        r[i + 1] = vec[i];
    }
    return r;
}

uint8x8_t vrev16_u8(uint8x8_t vec)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i += 2)
    {
        r[i] = vec[i + 1];
        r[i + 1] = vec[i];
    }
    return r;
}

// vrev16q_type
int8x16_t vrev16q_s8(int8x16_t vec)
{
    int8x16_t r;
    for (int i = 0; i < 16; i += 2)
    {
        r[i] = vec[i + 1];
        r[i + 1] = vec[i];
    }
    return r;
}

uint8x16_t vrev16q_u8(uint8x16_t vec)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i += 2)
    {
        r[i] = vec[i + 1];
        r[i + 1] = vec[i];
    }
    return r;
}

// vrev32_type
int8x8_t vrev32_s8(int8x8_t vec)
{
    int8x16_t r;
    for (int i = 0; i < 16; i += 4)
    {
        r[i + 0] = vec[i + 3];
        r[i + 1] = vec[i + 2];
        r[i + 2] = vec[i + 1];
        r[i + 3] = vec[i + 0];
    }
    return r;
}

int16x4_t vrev32_s16(int16x4_t vec)
{
    int16x4_t r;
    for (int i = 0; i < 4; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

uint8x8_t vrev32_u8(uint8x8_t vec)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i += 4)
    {
        r[i + 0] = vec[i + 3];
        r[i + 1] = vec[i + 2];
        r[i + 2] = vec[i + 1];
        r[i + 3] = vec[i + 0];
    }
    return r;
}

uint16x4_t vrev32_u16(uint16x4_t vec)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

// vrev32q_type
int8x16_t vrev32q_s8(int8x16_t vec)
{
    int8x16_t r;
    for (int i = 0; i < 16; i += 4)
    {
        r[i + 0] = vec[i + 3];
        r[i + 1] = vec[i + 2];
        r[i + 2] = vec[i + 1];
        r[i + 3] = vec[i + 0];
    }
    return r;
}

int16x8_t vrev32q_s16(int16x8_t vec)
{
    int16x8_t r;
    for (int i = 0; i < 8; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

uint8x16_t vrev32q_u8(uint8x16_t vec)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i += 4)
    {
        r[i + 0] = vec[i + 3];
        r[i + 1] = vec[i + 2];
        r[i + 2] = vec[i + 1];
        r[i + 3] = vec[i + 0];
    }
    return r;
}

uint16x8_t vrev32q_u16(uint16x8_t vec)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

// vrev64_type
int8x8_t vrev64_s8(int8x8_t vec)
{
    int8x8_t r;
    for (int i = 0; i < 8; i += 8)
    {
        r[i + 0] = vec[i + 7];
        r[i + 1] = vec[i + 6];
        r[i + 2] = vec[i + 5];
        r[i + 3] = vec[i + 4];
        r[i + 4] = vec[i + 3];
        r[i + 5] = vec[i + 2];
        r[i + 6] = vec[i + 1];
        r[i + 7] = vec[i + 0];
    }
    return r;
}

int16x4_t vrev64_s16(int16x4_t vec)
{
    int16x4_t r;
    for (int i = 0; i < 4; i += 4)
    {
        r[i + 0] = vec[i + 3];
        r[i + 1] = vec[i + 2];
        r[i + 2] = vec[i + 1];
        r[i + 3] = vec[i + 0];
    }
    return r;
}

int32x2_t vrev64_s32(int32x2_t vec)
{
    int32x2_t r;
    for (int i = 0; i < 2; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

uint8x8_t vrev64_u8(uint8x8_t vec)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i += 8)
    {
        r[i + 0] = vec[i + 7];
        r[i + 1] = vec[i + 6];
        r[i + 2] = vec[i + 5];
        r[i + 3] = vec[i + 4];
        r[i + 4] = vec[i + 3];
        r[i + 5] = vec[i + 2];
        r[i + 6] = vec[i + 1];
        r[i + 7] = vec[i + 0];
    }
    return r;
}

uint16x4_t vrev64_u16(uint16x4_t vec)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i += 4)
    {
        r[i + 0] = vec[i + 3];
        r[i + 1] = vec[i + 2];
        r[i + 2] = vec[i + 1];
        r[i + 3] = vec[i + 0];
    }
    return r;
}

uint32x2_t vrev64_u32(uint32x2_t vec)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

float32x2_t vrev64_f32(float32x2_t vec)
{
    float32x2_t r;
    for (int i = 0; i < 2; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

// vrev64q_type
int8x16_t vrev64q_s8(int8x16_t vec)
{
    int8x16_t r;
    for (int i = 0; i < 8; i += 8)
    {
        r[i + 0] = vec[i + 7];
        r[i + 1] = vec[i + 6];
        r[i + 2] = vec[i + 5];
        r[i + 3] = vec[i + 4];
        r[i + 4] = vec[i + 3];
        r[i + 5] = vec[i + 2];
        r[i + 6] = vec[i + 1];
        r[i + 7] = vec[i + 0];
    }
    return r;
}

int16x8_t vrev64q_s16(int16x8_t vec)
{
    int16x8_t r;
    for (int i = 0; i < 4; i += 4)
    {
        r[i + 0] = vec[i + 3];
        r[i + 1] = vec[i + 2];
        r[i + 2] = vec[i + 1];
        r[i + 3] = vec[i + 0];
    }
    return r;
}

int32x4_t vrev64q_s32(int32x4_t vec)
{
    int32x4_t r;
    for (int i = 0; i < 4; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

uint8x16_t vrev64q_u8(uint8x16_t vec)
{
    uint8x16_t r;
    for (int i = 0; i < 16; i += 8)
    {
        r[i + 0] = vec[i + 7];
        r[i + 1] = vec[i + 6];
        r[i + 2] = vec[i + 5];
        r[i + 3] = vec[i + 4];
        r[i + 4] = vec[i + 3];
        r[i + 5] = vec[i + 2];
        r[i + 6] = vec[i + 1];
        r[i + 7] = vec[i + 0];
    }
    return r;
}

uint16x8_t vrev64q_u16(uint16x8_t vec)
{
    uint16x8_t r;
    for (int i = 0; i < 8; i += 4)
    {
        r[i + 0] = vec[i + 3];
        r[i + 1] = vec[i + 2];
        r[i + 2] = vec[i + 1];
        r[i + 3] = vec[i + 0];
    }
    return r;
}

uint32x4_t vrev64q_u32(uint32x4_t vec)
{
    uint32x4_t r;
    for (int i = 0; i < 4; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

float32x4_t vrev64q_f32(float32x4_t vec)
{
    float32x4_t r;
    for (int i = 0; i < 4; i += 2)
    {
        r[i + 0] = vec[i + 1];
        r[i + 1] = vec[i + 0];
    }
    return r;
}

// Vector arithmetic / Division
#if __aarch64__
// vdiv_type
float32x2_t vdiv_f32(float32x2_t a, float32x2_t b)
{
    float32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] / b[i];
    }
    return r;
}

float64x1_t vdiv_f64(float64x1_t a, float64x1_t b)
{
    float64x1_t r;
    for (int i = 0; i < 1; i++)
    {
        r[i] = a[i] / b[i];
    }
    return r;
}

//float16x4_t	vdiv_f16	(float16x4_t a, float16x4_t b);

// vdivq_type
float32x4_t vdivq_f32(float32x4_t a, float32x4_t b)
{
    float32x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = a[i] / b[i];
    }
    return r;
}

float64x2_t vdivq_f64(float64x2_t a, float64x2_t b)
{
    float64x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = a[i] / b[i];
    }
    return r;
}

//float16x8_t	vdivq_f16	(float16x8_t a, float16x8_t b);
#endif // __aarch64__

// saturated shift right and narrow
int8x8_t vqshrn_n_s16(int16x8_t a, const int n)
{
    int8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = std::min(std::max(a[i] >> n, INT8_MIN), INT8_MAX);
    }
    return r;
}

int16x4_t vqshrn_n_s32(int32x4_t a, const int n)
{
    int16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = std::min(std::max(a[i] >> n, INT16_MIN), INT16_MAX);
    }
    return r;
}

int32x2_t vqshrn_n_s64(int64x2_t a, const int n)
{
    int32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = std::min<int32_t>(std::max<int64_t>(a[i] >> n, INT32_MIN), INT32_MAX);
    }
    return r;
}

uint8x8_t vqshrn_n_u16(uint16x8_t a, const int n)
{
    uint8x8_t r;
    for (int i = 0; i < 8; i++)
    {
        r[i] = std::min(a[i] >> n, UINT8_MAX);
    }
    return r;
}

uint16x4_t vqshrn_n_u32(uint32x4_t a, const int n)
{
    uint16x4_t r;
    for (int i = 0; i < 4; i++)
    {
        r[i] = std::min<uint32_t>(a[i] >> n, UINT16_MAX);
    }
    return r;
}

uint32x2_t vqshrn_n_u64(uint64x2_t a, const int n)
{
    uint32x2_t r;
    for (int i = 0; i < 2; i++)
    {
        r[i] = std::min<uint64_t>(a[i] >> n, UINT32_MAX);
    }
    return r;
}