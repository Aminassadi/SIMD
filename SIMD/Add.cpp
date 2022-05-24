#include "pch.h"
#include <execution>
constexpr size_t kSize{100'000'000};

using namespace std;

class AddingAlgorithmTest : public ::testing::Test
{
protected:
	void PopulateVector()
	{
		for (size_t i{}; i < kSize; ++i)
		{
			vec_[i] = i;
		}
	}

	void SetUp() override
	{
		vec_.resize(kSize);
		PopulateVector();
	}

	vector<uint64_t> vec_{};
};

TEST_F(AddingAlgorithmTest, UnSequencialForeach)
{
	for_each(execution::unseq, begin(vec_), end(vec_),
		[](uint64_t& data) { ++data; });

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(AddingAlgorithmTest, SequencialForeach)
{
	for_each(execution::seq, begin(vec_), end(vec_),
		[](uint64_t& data) { ++data; });

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(AddingAlgorithmTest, ParallelForeach)
{
	for_each(execution::par, begin(vec_), end(vec_),
		[](uint64_t& data) { ++data; });

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST_F(AddingAlgorithmTest, ParallelUnsequencialForeach)
{
	for_each(execution::par_unseq, begin(vec_), end(vec_),
		[](uint64_t& data) { ++data; });

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
