#include <iostream>

#include "Link_List.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  const int N = 10;
  LinkList<int> L;

  for (int i = 0; i < N; i++) {
    L.insert(i + 1);
  }

  int n = N;
  for (int d : L) {
    EXPECT_EQ(d, n);
    --n;
  }

  EXPECT_EQ(n, 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
