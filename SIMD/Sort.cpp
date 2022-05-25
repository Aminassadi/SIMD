#include "pch.h"
constexpr size_t kSize{50'000'000};
using namespace std;
class Sort : public ::testing::Test
{
protected:
	void SetUp() override
	{
		std::srand(static_cast<int>(std::time(nullptr)));
		vec_.resize(kSize);
		std::for_each(std::execution::par_unseq, std::begin(vec_),
		              std::end(vec_), [](auto& data) { data = std::rand(); });
	}
	vector<int> vec_{};
};
TEST_F(Sort, SequencialSort)
{
	std::sort(std::execution::seq, std::begin(vec_), std::end(vec_));
}
TEST_F(Sort, UnSequencialSort)
{
	std::sort(std::execution::unseq, std::begin(vec_), std::end(vec_));
}
TEST_F(Sort, ParallelUnSequencialSort)
{
	std::sort(std::execution::par_unseq, std::begin(vec_), std::end(vec_));
}
TEST_F(Sort, ParallelSort)
{
	std::sort(std::execution::par, std::begin(vec_), std::end(vec_));
}
TEST_F(Sort, IppSort)
{
	ippsSortAscend_32s_I(vec_.data(), kSize);
}