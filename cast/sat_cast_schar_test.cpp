#include "sat_cast_test.h"

bool DEBUG=false;

TEST(saturate_cast_schar, uchar)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
    std::vector<uchar> input_lst = 
    {
        100,
        128,
        255,
        0,
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        uchar input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        schar a = cv::saturate_cast<schar>(input);
        if(DEBUG) printf("%d\n", a);

        schar b = sat_cast<schar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_schar, ushort)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
    std::vector<ushort> input_lst = 
    {
        100,
        257,
        (1<<15) - 100,
        (1<<15) - 100,
        (1<<16) - 100,
        (1<<16) - 1,
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        ushort input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        schar a = cv::saturate_cast<schar>(input);
        if(DEBUG) printf("%d\n", a);

        schar b = sat_cast<schar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_schar, short)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
    std::vector<short> input_lst = 
    {
        100,
        -100,
        257,
        -257,
        (1<<15) - 100,
        -(1<<15) + 100
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        short input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        schar a = cv::saturate_cast<schar>(input);
        if(DEBUG) printf("%d\n", a);

        schar b = sat_cast<schar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_schar, unsigned)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
    std::vector<unsigned> input_lst = 
    {
        100,
        257,
        (1U<<31) - 100U,
        (1U<<31) - 1U,
        0,
        126,
        127,
        128
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        unsigned input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        schar a = cv::saturate_cast<schar>(input);
        if(DEBUG) printf("%d\n", a);

        schar b = sat_cast<schar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_schar, int)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
    std::vector<int> input_lst = 
    {
        100,
        -100,
        128,
        -128,
        127,
        -127,
        0
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        int input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        schar a = cv::saturate_cast<schar>(input);
        if(DEBUG) printf("%d\n", a);

        schar b = sat_cast<schar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_schar, float)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
    std::vector<float> input_lst = 
    {
        100.1,
        -100,2,
        127.3,
        -127.5,
        126.2,
        -126.3,
        128.3,
        -128.2,
        255.0001,
        249.4999,
        249.5001,
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        float input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %f\n", input);

        schar a = cv::saturate_cast<schar>(input);
        if(DEBUG) printf("%d\n", a);

        schar b = sat_cast<schar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_schar, double)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
    std::vector<double> input_lst = 
    {
        100.1,
        -100,2,
        127.3,
        -127.5,
        126.2,
        -126.3,
        128.3,
        -128.2,
        255.0001,
        249.4999,
        249.5001,
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        double input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %f\n", input);

        schar a = cv::saturate_cast<schar>(input);
        if(DEBUG) printf("%d\n", a);

        schar b = sat_cast<schar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}



int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}