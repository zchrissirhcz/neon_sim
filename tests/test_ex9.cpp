#include <iostream>
#include <chrono>
#include <random>
#include <opencv2/opencv.hpp>

#if __ARM_NEON
#include <arm_neon.h>
#include "arm_neon_helper.hpp"
#else
#include "arm_neon_sim.hpp"
#endif


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
    cv::Mat src_float;
    src.convertTo(src_float, CV_32FC3);

    // float *data_tmp = new float[1080 * 720 * 3];
    // std::default_random_engine e;
    // std::uniform_real_distribution<float> u(0, 255);
    // for(int i = 0; i < 1080 * 720 * 3; ++i) {
    //     *(data_tmp + i) = u(e);
    // }

    //float *data = data_tmp;
    float* data = (float*)src_float.data;
    //float *data_res1 = new float[1080 * 720 * 3];
    cv::Mat res1(src.size(), CV_32FC3);
    float* data_res1 = (float*)res1.data;

    std::chrono::microseconds start_time = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()
            );

    for(int i = 0; i < 1080 * 720 * 3; ++i) {
        *data_res1 = ((*data) + 3.4 ) * 3.1;
        ++data_res1;
        ++data;
    }

    std::chrono::microseconds end_time = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );

    std::cout << "cost total time : " << (end_time - start_time).count() << " microseconds  -- common method" << std::endl;

    data = (float*)src_float.data;
    //float *data_res2 = new float[1080 * 720 * 3];
    cv::Mat res2(src.size(), CV_32FC3);
    float* data_res2 = (float*)res2.data;

    start_time = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );

    float32x4_t A = vdupq_n_f32(3.4);
    float32x4_t B = vdupq_n_f32(3.1);
    for(int i = 0; i < 1080 * 720 * 3 / 4; ++i) {
        float32x4_t C = (float32x4_t){*data, *(data + 1), *(data + 2), *(data + 3)};
        float32x4_t D = vmulq_f32(vaddq_f32(C, A), B);
        vst1q_f32(data_res2, D);
        data = data + 4;
        data_res2 = data_res2 + 4;
    }

    end_time = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );

    std::cout << "cost total time : " << (end_time - start_time).count() << " microseconds  -- neon method" << std::endl;

    cv::Mat res1_u8;
    res1.convertTo(res1_u8, CV_8UC3);
    cv::imwrite("ex9_res1.png", res1);

    cv::Mat res2_u8;
    res2.convertTo(res2_u8, CV_8UC3);
    cv::imwrite("ex9_res2.png", res2);

    return 0;
}
