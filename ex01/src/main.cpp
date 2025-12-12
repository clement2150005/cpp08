#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    try
    {
        // ============================
        // Test 1
        // ============================
        std::cout << "=== Test 1 ===\n";
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Stored numbers: 6, 3, 17, 9, 11\n";
        std::cout << "Expected shortest: 2\n";
        std::cout << "Actual shortest:   " << sp.shortestSpan() << "\n";
        std::cout << "Expected longest: 14\n";
        std::cout << "Actual longest:    " << sp.longestSpan() << "\n\n";

        // ============================
        // Test 2
        // ============================
        std::cout << "=== Test 2 ===\n";
        std::vector<int> nums;
        for (int i = 0; i < 5; ++i)
            nums.push_back(i * 10);  // 0, 10, 20, 30, 40

        Span sp2(10);
        sp2.addNumbers(nums.begin(), nums.end());
        sp2.addNumber(42);

        std::cout << "Stored numbers: 0, 10, 20, 30, 40, 42\n";
        std::cout << "Expected shortest: 2\n";
        std::cout << "Actual shortest:   " << sp2.shortestSpan() << "\n";
        std::cout << "Expected longest: 42\n";
        std::cout << "Actual longest:    " << sp2.longestSpan() << "\n\n";

        // ============================
        // Test 3
        // ============================
        std::cout << "=== Test 3 ===\n";
        Span sp3(10000);
        for (int i = 0; i < 10000; ++i)
            sp3.addNumber(i);

        std::cout << "Stored numbers: 0 to 9999\n";
        std::cout << "Expected shortest: 1\n";
        std::cout << "Actual shortest:   " << sp3.shortestSpan() << "\n";
        std::cout << "Expected longest: 9999\n";
        std::cout << "Actual longest:    " << sp3.longestSpan() << "\n\n";

        // ============================
        // Test 4
        // ============================
        std::cout << "=== Test 4 ===\n";
        Span sp4(2);
        sp4.addNumber(1);

        std::cout << "Expected exception (shortestSpan with 1 number): No span can be found\n";
        std::cout << "Actual: ";
        try { sp4.shortestSpan(); }
        catch (const std::exception &e) { std::cout << e.what(); }
        std::cout << "\n\n";

        sp4.addNumber(2);
        std::cout << "Expected exception (addNumber past capacity): Span is full\n";
        std::cout << "Actual: ";
        try { sp4.addNumber(3); }
        catch (const std::exception &e) { std::cout << e.what(); }
        std::cout << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unexpected exception: " << e.what() << "\n";
    }
    return 0;
}
