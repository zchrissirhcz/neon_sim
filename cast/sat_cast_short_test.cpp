#include "sat_cast_test.h"

bool DEBUG=false;


TEST(saturate_cast_short, uchar)
{
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

        short a = cv::saturate_cast<short>(input);
        if(DEBUG) printf("%d\n", a);

        short b = sat_cast<short>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_short, schar)
{
    std::vector<schar> input_lst = 
    {
        100,
        -100,
        -128,
        0,
        127
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        schar input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        short a = cv::saturate_cast<short>(input);
        if(DEBUG) printf("%d\n", a);

        short b = sat_cast<short>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_short, ushort)
{
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

        short a = cv::saturate_cast<short>(input);
        if(DEBUG) printf("%d\n", a);

        short b = sat_cast<short>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_short, unsigned)
{
    std::vector<unsigned> input_lst = 
    {
        100,
        257,
        (1U<<31) - 100U,
        (1U<<31) - 1U,
        0
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        unsigned input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        short a = cv::saturate_cast<short>(input);
        if(DEBUG) printf("%d\n", a);

        short b = sat_cast<short>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_short, int)
{
    std::vector<int> input_lst = 
    {
        100,
        -100,
        257,
        -257,
        (1U<<31) - 100U,
        0
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        int input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        short a = cv::saturate_cast<short>(input);
        if(DEBUG) printf("%d\n", a);

        short b = sat_cast<short>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_short, float)
{
    std::vector<float> input_lst = 
    {
        100.1,
        -100,2,
        257.3,
        -257.5,
        255.0001,
        249.4999,
        249.5001,
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        float input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %f\n", input);

        short a = cv::saturate_cast<short>(input);
        if(DEBUG) printf("%d\n", a);

        short b = sat_cast<short>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_short, double)
{
    std::vector<double> input_lst = 
    {
        100.1,
        -100,2,
        257.3,
        -257.5,
        255.0001,
        249.4999,
        249.5001,
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        double input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %lf\n", input);

        short a = cv::saturate_cast<short>(input);
        if(DEBUG) printf("%d\n", a);

        short b = sat_cast<short>(input);
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