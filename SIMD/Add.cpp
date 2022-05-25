#include "pch.h"
constexpr size_t kSize{400'000'000};

using namespace std;

class AddingAlgorithmTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		vec_.resize(kSize);
		fill(execution::par_unseq,begin(vec_), end(vec_), 1);
	}
	vector<int> vec_{};
};

TEST_F(AddingAlgorithmTest, UnSequencialForeach)
{
	for_each(execution::unseq, begin(vec_), end(vec_),
		[](auto& data) { ++data; });

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(AddingAlgorithmTest, SequencialForeach)
{
	for_each(execution::seq, begin(vec_), end(vec_),
		[](auto& data) { ++data; });

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(AddingAlgorithmTest, ParallelForeach)
{
	for_each(execution::par, begin(vec_), end(vec_),
		[](auto& data) { ++data; });

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(AddingAlgorithmTest, ParallelUnsequencialForeach)
{
	for_each(execution::par_unseq, begin(vec_), end(vec_),
		[](auto& data) { ++data; });

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(AddingAlgorithmTest, IppAdd)
{
	ippsAddC_32s_ISfs(1, vec_.data(), kSize, 0);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}






