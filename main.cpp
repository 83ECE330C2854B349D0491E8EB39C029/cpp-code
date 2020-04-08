#include <iostream>
#include "Sq_Stack.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  const int N = 6;
  Stack<int> S;

  for (int i = 1; i < N; i++) {
    S.push(i);
  }

  EXPECT_EQ(S.pop(), 5);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
