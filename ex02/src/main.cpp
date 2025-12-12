#include "MutantStack.hpp"
#include <iostream>

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int>   mlist;

	mstack.push(5);        mlist.push_back(5);
	mstack.push(17);       mlist.push_back(17);

	std::cout << "MutantStack: " << mstack.top() << std::endl;
	std::cout << "List:        " << mlist.back() << "\n" << std::endl;

	mstack.pop();          mlist.pop_back();

	std::cout << "MutantStack: " << mstack.size() << std::endl;
	std::cout << "List:        " << mlist.size() << "\n" << std::endl;

	mstack.push(3);        mlist.push_back(3);
	mstack.push(5);        mlist.push_back(5);
	mstack.push(737);      mlist.push_back(737);
	mstack.push(0);        mlist.push_back(0);

	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::list<int>::iterator lit  = mlist.begin();

	++it;  ++lit;
	--it;  --lit;

	while (it != ite)
	{
		std::cout << "MutantStack: " << *it << std::endl;
		std::cout << "List:        " << *lit << "\n" <<  std::endl;
		++it;
		++lit;
	}

	std::stack<int> s(mstack);
	std::list<int>  lcopy(mlist);

	return 0;
}
