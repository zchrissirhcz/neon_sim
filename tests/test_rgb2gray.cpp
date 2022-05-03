#include <ios>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "opencv_helper.hpp"

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif

void rgb2gray(const cv::Mat& src, cv::Mat& gray)
{
    if (src.type() != CV_8UC3) {
        abort();
    }
    const int channels = 3;

    const cv::Size size = src.size();
    const int w = size.width;
    const int h = size.height;
    const int sstep = src.step1();
    
    gray.create(size, CV_8UC1);
    const int dstep = gray.step1();

    // 定点版本的权值
    const unsigned char R2Y = 77;
    const unsigned char G2Y = 151;
    const unsigned char B2Y = 28;
    const int SHIFT = 8;

#if __ARM_NEON
    uint8x8_t v_r2y = vdup_n_u8(R2Y);
    uint8x8_t v_g2y = vdup_n_u8(G2Y);
    uint8x8_t v_b2y = vdup_n_u8(B2Y);
#endif // __ARM_NEON

    for (int y = 0; y < h; y++)
    {
        const uchar* sp = src.data + y * sstep;
        uchar* dp = gray.data + y * dstep;

#if __ARM_NEON
        int nn = w >> 3;
        int remain = w - (nn << 3);
#else
        int remain = w;
#endif // __ARM_NEON

#if __ARM_NEON
        for (int j = 0; j < nn; j++)
        {
            uint8x8x3_t v_src = vld3_u8(sp);
            uint16x8_t v_tmp = vmull_u8(v_src.val[0], v_r2y);
            v_tmp = vmlal_u8(v_tmp, v_src.val[1], v_g2y);
            v_tmp = vmlal_u8(v_tmp, v_src.val[2], v_b2y);
            uint8x8_t v_gray = vshrn_n_u16(v_tmp, SHIFT);
            vst1_u8(dp, v_gray);

            sp += 8 * 3;
            dp += 8;
        }
#endif // __ARM_NEON

        for (; remain > 0; remain--)
        {
            *dp++ = (R2Y * sp[0] + G2Y * sp[1] + B2Y * sp[2]) >> SHIFT;
            sp += 3;
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
#else
#pragma error
#endif

    std::string image_path = load_prefix + "/1920x1080.png";
    cv::Mat src = cv::imread(image_path);
    cv::Mat rgb;
    cv::cvtColor(src, rgb, cv::COLOR_BGR2RGB);

    cv::Mat gray_cv;
    cv::cvtColor(rgb, gray_cv, cv::COLOR_RGB2GRAY);
    cv::imwrite("gray_cv.png", gray_cv);

    cv::Mat gray_my;
    rgb2gray(rgb, gray_my);
    cv::imwrite("gray_my.png", gray_my);

    cv::Mat diff;
    cv::absdiff(gray_cv, gray_my, diff);
    std::cout << std::boolalpha << almostEqual(gray_cv, gray_my, 1.0) << " " << cv::sum(diff) << std::endl;

    return 0;
}