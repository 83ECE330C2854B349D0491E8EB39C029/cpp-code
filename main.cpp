#include <iostream>
#include "Match.h"
#include "gtest/gtest.h"

TEST(Suite1, Test1) {
  Match t_match;
  std::string demo1 = "{([wick])}";
  std::string demo2 = "{nick)";

  EXPECT_EQ(true, t_match.Tmatch(demo1));
  EXPECT_EQ(false, t_match.Tmatch(demo2));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
