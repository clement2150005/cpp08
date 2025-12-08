#pragma once

#include <vector>
#include <stdexcept>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();

	template <typename InputIt>
	void addNumbers(InputIt begin, InputIt end)
	{
		size_t rangeSize = std::distance(begin, end);
		if (v.size() + rangeSize > n)
			throw std::runtime_error("Adding range would exceed Span capacity");

		while (begin != end)
		{
			v.push_back(*begin);
			++begin;
		}
	}

private:
	unsigned int n;
	std::vector<int> v;
};
