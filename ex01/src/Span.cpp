#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span &other) : v(other.v), n(other.n) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		n = other.n;
		v = other.v;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (v.size() + 1 > n)
		throw std::runtime_error("Span is full");
	v.push_back(number);
}

template <typename InputIt>
void Span::addNumbers(InputIt begin, InputIt end)
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

int Span::shortestSpan()
{
	unsigned int shortestSpan = 0;

	if (v.size() == 0 || v.size() == 1)
		throw std::runtime_error("No span can be found");

	std::sort(v.begin(), v.end());
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		if (i == 0)
		{
			shortestSpan = v[i + 1] - v[i];
				continue;
		}
		int diff = v[i + 1] - v[i];
		if (diff < shortestSpan)
			shortestSpan = diff;
	}
	return shortestSpan;
}

int Span::longestSpan()
{
	if (v.size() == 0 || v.size() == 1)
		throw std::runtime_error("No span can be found");
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

