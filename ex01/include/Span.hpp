#pragma once

#include <vector>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	template <typename InputIt>
	void addNumbers(InputIt begin, InputIt end);
	int shortestSpan();
	int longestSpan();

private:
	unsigned int n;
	std::vector<int> v;
};
