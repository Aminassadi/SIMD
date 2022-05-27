#include "pch.h"
constexpr size_t kSize{1'000'000'000};
class Sum : public ::testing::Test
{
protected:
	void SetUp() override
	{
		vec_.resize(kSize);
		fill(std::execution::par_unseq, begin(vec_), end(vec_), 1);
	}
	std::vector<int> vec_{};
};
TEST_F(Sum, SequencialSumUsingAccumulate)
{
	auto result{ std::accumulate( std::begin(vec_), std::end(vec_), 0) };
}
TEST_F(Sum, SequencialSumUsingReduce)
{
	auto result{ std::reduce(std::execution::seq, std::begin(vec_), std::end(vec_), 0) };
}
TEST_F(Sum, ParalleSumUsingReduce)
{
	auto result{ std::reduce(std::execution::par, std::begin(vec_), std::end(vec_), 0) };
}
TEST_F(Sum, UnsequencialSumUsingReduce)
{
	auto result{ std::reduce(std::execution::unseq, std::begin(vec_), std::end(vec_), 0) };
}
TEST_F(Sum, ParallelUnsequencialSumUsingReduce)
{
	auto result{ std::reduce(std::execution::par_unseq, std::begin(vec_), std::end(vec_), 0) };
}
TEST_F(Sum, IppSum)
{
	int sum{};
	ippsSum_32s_Sfs(vec_.data(), vec_.size(), &sum, 0);
}