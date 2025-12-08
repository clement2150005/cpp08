#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        std::cout << "=== Single add test ===" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "\n=== Iterator range test ===" << std::endl;
        std::vector<int> numbers;
        for (int i = 0; i < 5; ++i)
            numbers.push_back(i * 10);

        Span sp2(10);
        sp2.addNumbers(numbers.begin(), numbers.end());
        sp2.addNumber(42);

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

        std::cout << "\n=== Large test (10000 numbers) ===" << std::endl;
        Span sp3(10000);
        for (int i = 0; i < 10000; ++i)
            sp3.addNumber(i);

        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

        std::cout << "\n=== Exception tests ===" << std::endl;
        Span sp4(2);
        sp4.addNumber(1);
        try { sp4.shortestSpan(); }
        catch (const std::exception &e) { std::cout << "Expected exception: " << e.what() << std::endl; }
        sp4.addNumber(2);
        try { sp4.addNumber(3); }
        catch (const std::exception &e) { std::cout << "Expected exception: " << e.what() << std::endl; }

    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
