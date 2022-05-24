#include "pch.h"
using namespace std;
class AddingAlgorithmTest : public ::testing::Test {
protected:
    void SetUp() override {
        vec_.resize(10);
    }
    vector<int> vec_{};
};

TEST(Add, SequencialForeach)
{

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}