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


//void threshold_gray(unsigned char* input_gray, size_t height, size_t width, unsigned char* output_gray, unsigned char thresh, unsigned char minval, unsigned char maxval)
void threshold_gray(const cv::Mat& gray, cv::Mat& res, int thresh, int minval, int maxval)
{
    cv::Size ssize = gray.size();
    const int width = ssize.width;
    const int height = ssize.height;

    if (gray.type() != CV_8UC1) {
        abort();
    }

    res.create(ssize, CV_8UC1);
    const uchar* input_gray = gray.data;
    uchar* output_gray = res.data;

    if (minval > maxval) {
        std::swap(minval, maxval);
    }

    size_t total_len = height * width;
    size_t done = 0;

#if __ARM_NEON
    size_t step = 16;
    size_t vec_size = total_len - total_len % step;
    uint8x16_t v1;
    uint8x16_t vmask_gt;
    uint8x16_t vthresh = vdupq_n_u8(thresh);
    uint8x16_t vmaxval = vdupq_n_u8(maxval);
    uint8x16_t vminval = vdupq_n_u8(minval);
    for (size_t i=0; i<vec_size; i+=step) {
        v1 = vld1q_u8(input_gray);
        input_gray += step;
        vmask_gt = vcgtq_u8(v1, vthresh);
        v1 = vbslq_u8(vmask_gt, vmaxval, vminval);
        vst1q_u8(output_gray, v1);
        output_gray += step;
    }
    done = vec_size;
#endif
    for (; done<total_len; done++) {
        *output_gray = (input_gray[0]>thresh) ? maxval : minval;
        input_gray++;
        output_gray++;
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
    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    const int thresh = 60;

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