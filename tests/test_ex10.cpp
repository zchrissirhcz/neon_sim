// image add

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

#include <opencv2/opencv.hpp>

template<int channels>
void add_v6(const cv::Mat& src1, const cv::Mat& src2, cv::Mat& dst)
{
    if (src1.size() != src2.size())
    {
        CV_Error(cv::Error::StsBadArg, "size should be same!");
    }
    if (src1.channels() != src2.channels())
    {
        CV_Error(cv::Error::StsBadArg, "channels should be same!");
    }
    int depth = CV_MAT_DEPTH(src1.type());
    if (depth != CV_8U) {
        CV_Error(cv::Error::StsBadArg, "only support uchar type");
    }
    if (src1.channels() != channels) {
        CV_Error(cv::Error::StsBadArg, cv::format("src.channels() != channels in template argument"));
    }

    dst.create(src1.size(), src1.type());
    const int width = src1.size().width;
    const int height = src1.size().height;
    
    for (int i = 0; i < height; i++)
    {
        uchar* dst_line = dst.ptr(i);
        const uchar* src1_line = src1.ptr(i);
        const uchar* src2_line = src2.ptr(i);

        int len = width * channels;
#if __ARM_NEON
        int nn = len >> 6;
        int remain = len - (nn << 6);
#else
        int remain = len;
#endif // __ARM_NEON

#if __ARM_NEON


        for (int j = 0; j < nn; j++)
        {
            // __builtin_prefetch(src1_line + 256);
            // __builtin_prefetch(src2_line + 256);

            uint8x16_t v_11 = vld1q_u8(src1_line);
            uint8x16_t v_21 = vld1q_u8(src1_line + 16);
            uint8x16_t v_31 = vld1q_u8(src1_line + 32);
            uint8x16_t v_41 = vld1q_u8(src1_line + 48);

            uint8x16_t v_12 = vld1q_u8(src2_line);
            uint8x16_t v_22 = vld1q_u8(src2_line + 16);
            uint8x16_t v_32 = vld1q_u8(src2_line + 32);
            uint8x16_t v_42 = vld1q_u8(src2_line + 48);

            uint8x16_t v_sum1 = vqaddq_u8(v_11, v_12);
            uint8x16_t v_sum2 = vqaddq_u8(v_21, v_22);
            uint8x16_t v_sum3 = vqaddq_u8(v_31, v_32);
            uint8x16_t v_sum4 = vqaddq_u8(v_41, v_42);

            vst1q_u8(dst_line, v_sum1);
            vst1q_u8(dst_line + 16, v_sum2);
            vst1q_u8(dst_line + 32, v_sum3);
            vst1q_u8(dst_line + 48, v_sum4);

            src1_line += 64;
            src2_line += 64;
            dst_line += 64;
        }
#endif // __ARM_NEON

        for (; remain > 0; remain--)
        {
            *dst_line = cv::saturate_cast<uint8_t>(*src1_line + *src2_line);
            dst_line++;
            src1_line++;
            src2_line++;
        }
    }
}

int main()
{

#if __ANDROID__
    std::string load_prefix = "/data/local/tmp";
#elif __linux__
    std::string load_prefix = "/home/zz/data";
#elif _MSC_VER
    std::string load_prefix = "d:/data";
#elif __APPLE__
    std::string load_prefix = "/Users/zz/data";
#else
#pragma error
#endif

    std::string image_path1 = load_prefix + "/nvidia_logo.bmp";
    std::string image_path2 = load_prefix + "/checker_board.bmp";

    cv::Mat src1 = cv::imread(image_path1);
    cv::Mat src2 = cv::imread(image_path2);

    cv::cvtColor(src1, src1, cv::COLOR_BGR2BGRA);
    cv::cvtColor(src2, src2, cv::COLOR_BGR2BGRA);

    const int channels = 4;

    cv::Mat dst_opt_v6;
    add_v6<channels>(src1, src2, dst_opt_v6);

    cv::Mat dst_cv;
    cv::add(src1, src2, dst_cv);

    cv::Mat diff;
    cv::absdiff(dst_cv, dst_opt_v6, diff);
    std::cout << cv::sum(diff) << std::endl;

    return 0;
}