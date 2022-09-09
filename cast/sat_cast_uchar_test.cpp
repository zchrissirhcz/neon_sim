#include "sat_cast_test.h"

bool DEBUG=false;

TEST(saturate_cast_uchar, schar)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
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

        uchar a = cv::saturate_cast<uchar>(input);
        if(DEBUG) printf("%d\n", a);

        uchar b = sat_cast<uchar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_uchar, ushort)
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

        uchar a = cv::saturate_cast<uchar>(input);
        if(DEBUG) printf("%d\n", a);

        uchar b = sat_cast<uchar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_uchar, short)
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

        uchar a = cv::saturate_cast<uchar>(input);
        if(DEBUG) printf("%d\n", a);

        uchar b = sat_cast<uchar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_uchar, unsigned)
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
        0
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        unsigned input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        uchar a = cv::saturate_cast<uchar>(input);
        if(DEBUG) printf("%d\n", a);

        uchar b = sat_cast<uchar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_uchar, int)
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
        257,
        -257,
        (1U<<31) - 100U,
        0
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        int input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %d\n", input);

        uchar a = cv::saturate_cast<uchar>(input);
        if(DEBUG) printf("%d\n", a);

        uchar b = sat_cast<uchar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_uchar, float)
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

        uchar a = cv::saturate_cast<uchar>(input);
        if(DEBUG) printf("%d\n", a);

        uchar b = sat_cast<uchar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}

TEST(saturate_cast_uchar, double)
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

        uchar a = cv::saturate_cast<uchar>(input);
        if(DEBUG) printf("%d\n", a);

        uchar b = sat_cast<uchar>(input);
        if(DEBUG) printf("%d\n", b);

        EXPECT_EQ(a, b);
    }
}


TEST(saturate_cast_uchar, int64)
{
    //int input = -100;
    // 100
    // -100
    // 257
    // -257
    std::vector<int64> input_lst = 
    {
        100,
        -100,
        257,
        -257,
        255,
        249,
        (1LL<<31),
        (1LL<<32),
        (1LL<<62),
        -(1LL<<62)
    };

    for (int i=0; i<input_lst.size(); i++)
    {
        int64 input = input_lst[i];
        if(DEBUG) printf("\n>>> input is %ld\n", input);

        uchar a = cv::saturate_cast<uchar>(input);
        if(DEBUG) printf("%d\n", a);

        uchar b = sat_cast<uchar>(input);
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