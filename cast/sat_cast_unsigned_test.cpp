#include "sat_cast_test.h"

bool DEBUG=false;


TEST(saturate_cast_unsigned, uchar)
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

        unsigned a = cv::saturate_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", a);

        unsigned b = sat_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_unsigned, schar)
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

        unsigned a = cv::saturate_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", a);

        unsigned b = sat_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_unsigned, ushort)
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

        unsigned a = cv::saturate_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", a);

        unsigned b = sat_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_unsigned, short)
{
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

        unsigned a = cv::saturate_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", a);

        unsigned b = sat_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_unsigned, int)
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

        unsigned a = cv::saturate_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", a);

        unsigned b = sat_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_unsigned, float)
{
    std::vector<float> input_lst = 
    {
        100.1,
        -100.2,
        257.3,
        -257.5,
        255.0001,
        249.4999,
        249.5001,
        3147483648.f
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        float input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %f\n", input);

        unsigned a = cv::saturate_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", a);

        unsigned b = sat_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_unsigned, double)
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
        3147483648.0
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        double input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %lf\n", input);

        unsigned a = cv::saturate_cast<unsigned>(input);
        if(DEBUG) printf("%d\n", a);

        unsigned b = sat_cast<unsigned>(input);
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