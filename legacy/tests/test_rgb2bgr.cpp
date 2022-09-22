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

using namespace och;

void rgb2bgr(const cv::Mat& src, cv::Mat& dst)
{
    if (src.type() != CV_8UC3) {
        abort();
    }

    cv::Size size = src.size();
    dst.create(size, src.type());
    const int w = size.width;
    const int h = size.height;
    const int channels = 3;
    const int sstep = src.step1();
    const int dstep = dst.step1();

    for (int y = 0; y < h; y++)
    {
        const uchar* sp = src.data + y * sstep;
        uchar* dp = dst.data + y * dstep;

#if __ARM_NEON
        int nn = w >> 3;
        int remain = w - (nn << 3);
#else
        int remain = w;
#endif // __ARM_NEON

#if __ARM_NEON
        for (int j = 0; j < nn; j++)
        {
            uint8x8x3_t v_pixel = vld3_u8(sp);
            uint8x8_t tmp = v_pixel.val[0];
            v_pixel.val[0] = v_pixel.val[2];
            v_pixel.val[2] = tmp;
            vst3_u8(dp, v_pixel);
            sp += 24;
            dp += 24;
        }
#endif // __ARM_NEON

        for (; remain > 0; remain--)
        {
            dp[2] = sp[0];
            dp[1] = sp[1];
            dp[0] = sp[2];
            dp += 3;
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
#elif __APPLE__
    std::string load_prefix = "/Users/zz/data";
#else
#pragma error
#endif

    std::string image_path = load_prefix + "/1920x1080.png";
    cv::Mat src = cv::imread(image_path);
    cv::Mat rgb;
    cv::cvtColor(src, rgb, cv::COLOR_BGR2RGB);

    cv::Mat bgr_cv;
    cv::cvtColor(rgb, bgr_cv, cv::COLOR_RGB2BGR);
    cv::imwrite("bgr_cv.png", bgr_cv);

    cv::Mat bgr_my;
    rgb2bgr(rgb, bgr_my);
    cv::imwrite("bgr_my.png", bgr_my);

    cv::Mat diff;
    cv::absdiff(bgr_cv, bgr_my, diff);
    std::cout << std::boolalpha << almostEqual(bgr_cv, bgr_my, 1.0) << " " << cv::sum(diff) << std::endl;

    return 0;
}