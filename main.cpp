#include <iostream>
#include "Sq_List.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1)
{
    const int N = 10;
    SqList<int> L(N);

    for (int i = 0; i < N; i++) {
        L.insert(i , i + 1);
    }

    int n = 0;
    for (int d : L) {
        ++n;
        EXPECT_EQ(d, n);
    }

    EXPECT_EQ(n, N);

    //test-get
    EXPECT_EQ(L.get(0), 1);
    EXPECT_EQ(L.get(1), 2);
 
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
