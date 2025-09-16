#include <vector>
#include <deque>
#include <list>
#include <cstdarg>
#include <iostream>

#include "easyfind.hpp"

template <typename T>
T fillIntContainer(int count, ...)
{
    T container;

    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
        container.push_back(va_arg(args, int));

    va_end(args);

    return container;
}

int main()
{
    std::vector<int> v = fillIntContainer<std::vector<int> >(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    std::deque<int> d = fillIntContainer<std::deque<int> >(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    std::list<int> l = fillIntContainer<std::list<int> >(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    int target = 3;
    try
    {
        std::cout << *easyfind(v, target) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << *easyfind(d, target) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << *easyfind(l, target) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    target = 42;

    try
    {
        std::cout << *easyfind(v, target) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << *easyfind(d, target) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << *easyfind(l, target) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}