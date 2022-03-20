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

void rgb2gray(const cv::Mat& rgb, cv::Mat& gray)
{
    const cv::Size ssize = rgb.size();
    const int width = ssize.width;
    const int height = ssize.height;
    const uchar* rgb_buf = rgb.data;

    gray.create(ssize, CV_8UC1);
    uchar* gray_buf = gray.data;

    size_t done = 0;
    size_t num_pixels = width * height;

    const unsigned char weight_r = 77;
    const unsigned char weight_g = 151;
    const unsigned char weight_b = 28;
    const int shift_right = 8;

#if __ARM_NEON
    size_t gray_step = 8;
    size_t rgb_step = gray_step * 3;
    size_t gray_vec_size = num_pixels - num_pixels % gray_step;

    uint8x8x3_t v_rgb;
    uint16x8_t v_tmp;
    uint8x8_t v_gray;
    uint8x8_t v_weight_r = vdup_n_u8(weight_r);
    uint8x8_t v_weight_g = vdup_n_u8(weight_g);
    uint8x8_t v_weight_b = vdup_n_u8(weight_b);

    for (size_t i=0; i<gray_vec_size; i+=gray_step) {
        v_rgb = vld3_u8(rgb_buf);
        rgb_buf += rgb_step;
        v_tmp = vmull_u8(v_rgb.val[0], v_weight_r);
        v_tmp = vmlal_u8(v_tmp, v_rgb.val[1], v_weight_g);
        v_tmp = vmlal_u8(v_tmp, v_rgb.val[2], v_weight_b);

        //uint8x8_t vshrn_n_u16 (uint16x8_t __a, const int __b);
        //uint8x8_t vqshrn_n_u16 (uint16x8_t __a, const int __b);
        //v_gray = vshrq_n_u16(v_gray, shift_right);
        v_gray = vshrn_n_u16(v_tmp, 8);
        vst1_u8(gray_buf, v_gray);
        gray_buf += gray_step;
    }
    done = gray_vec_size;
#endif // __ARM_NEON

    for (; done < num_pixels; done++) {
        *gray_buf = (weight_r*rgb_buf[0] + weight_g*rgb_buf[1] + weight_b*rgb_buf[2]) >> 8;
        rgb_buf += 3;
        gray_buf++;
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