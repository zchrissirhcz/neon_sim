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


//void rgb2bgr(unsigned char* src_buf, size_t height, size_t width, unsigned char* dst_buf)
void rgb2gray(const cv::Mat& rgb, cv::Mat& bgr)
{
    cv::Size ssize = rgb.size();
    bgr.create(ssize, rgb.type());
    if (rgb.type() != CV_8UC3) {
        abort();
    }

    const int width = ssize.width;
    const int height = ssize.height;
    const int channels = 3;
    const uchar* src_buf = rgb.data;
    uchar* dst_buf = bgr.data;

    size_t done = 0;
    size_t total_len = width * height * channels;
#if __ARM_NEON
    size_t step = 24;
    size_t vec_size = total_len - total_len % step;

    uint8x8x3_t v;
    uint8x8_t tmp;

    for (size_t i=0; i<vec_size; i+=step) {
        v = vld3_u8(src_buf);
        src_buf += step;
        tmp = v.val[0];
        v.val[0] = v.val[2];
        v.val[2] = tmp;
        vst3_u8(dst_buf, v);
        dst_buf += step;
    }

    done = vec_size;
#endif // __ARM_NEON

    for ( ; done<total_len; done+=3) {
        dst_buf[2] = src_buf[0];
        dst_buf[1] = src_buf[1];
        dst_buf[0] = src_buf[2];
        dst_buf += 3;
        src_buf += 3;
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

    cv::Mat bgr_cv;
    cv::cvtColor(rgb, bgr_cv, cv::COLOR_RGB2BGR);
    cv::imwrite("bgr_cv.png", bgr_cv);

    cv::Mat bgr_my;
    rgb2gray(rgb, bgr_my);
    cv::imwrite("bgr_my.png", bgr_my);

    cv::Mat diff;
    cv::absdiff(bgr_cv, bgr_my, diff);
    std::cout << std::boolalpha << almostEqual(bgr_cv, bgr_my, 1.0) << " " << cv::sum(diff) << std::endl;

    return 0;
}