#include <iostream>
#include <opencv2/core/types.hpp>
#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "opencv_helper.hpp"

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif


void threshold_gray(const cv::Mat& src, cv::Mat& dst, int thresh, int minval, int maxval)
{
    if (src.type() != CV_8UC1)
    {
        abort();
    }

    if (minval > maxval)
    {
        std::swap(minval, maxval);
    }

    cv::Size size = src.size();
    const int w = size.width;
    const int h = size.height;
    dst.create(size, CV_8UC1);

    const int sstep = src.step1();
    const int dstep = dst.step1();

#if __ARM_NEON
    uint8x16_t vthresh = vdupq_n_u8(thresh);
    uint8x16_t vmaxval = vdupq_n_u8(maxval);
    uint8x16_t vminval = vdupq_n_u8(minval);
#endif // __ARM_NEON

    for (int y = 0; y < h; y++)
    {
        const uchar* sp = src.data + y * sstep;
        uchar* dp = dst.data + y * dstep;

#if __ARM_NEON
        int nn = w >> 4;
        int remain = w - (nn << 4);
#else
        int remain = w;
#endif

#if __ARM_NEON
        for (int j = 0; j < nn; j++)
        {
            uint8x16_t v1 = vld1q_u8(sp);
            uint8x16_t vmask_gt = vcgtq_u8(v1, vthresh);
            v1 = vbslq_u8(vmask_gt, vmaxval, vminval);
            vst1q_u8(dp, v1);
            sp += 16;
            dp += 16;
        }
#endif // __ARM_NEON

        for (; remain > 0; remain--)
        {
            *dp++ = ( (*sp++) > thresh) ? maxval : minval;
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

    std::string image_path = load_prefix + "/1920x1080.png";
    cv::Mat src = cv::imread(image_path);
    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::Size ssize = src.size();

    const int thresh = 60;
    cv::Point p(2, 3);
    cv::Rect rect(1, 2, 4, 5);
    cv::Matx<int, 3, 3> mat =  // Matx33f
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    std::cout << mat(0, 0) << std::endl;
    std::cout << mat.rows << std::endl;

    cv::Mat res_cv;
    cv::threshold(gray, res_cv, thresh, 255, 0);
    cv::imwrite("res_cv.png", res_cv);

    cv::Mat res_my;
    threshold_gray(res_cv, res_my, thresh, 255, 0);
    cv::imwrite("res_my.png", res_my);

    cv::Mat diff;
    cv::absdiff(res_cv, res_my, diff);
    std::cout << std::boolalpha << almostEqual(res_cv, res_my, 5.0) << " " << cv::sum(diff) << std::endl;

    return 0;
}