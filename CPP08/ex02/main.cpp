/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:32:43 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:33:10 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "MutantStack.hpp"

int main()
{
	std::cout << "Create an int stack" << std::endl;
	MutantStack<int> mstack;
	std::cout << "\nTest push() and top():" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	std::cout << "\nTest pop():" << std::endl;
	mstack.pop();
	std::cout << "Top element after pop: " << mstack.top() << std::endl;
	std::cout << "\nTest size():" << std::endl;
	std::cout << "Stack size: " << mstack.size() << std::endl;
	std::cout << "\nAdd more elements, 3, 5, 737 and 0:" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Stack size after pushing elements: " << mstack.size() << std::endl;
	std::cout << "\nTest iterators (begin e end):" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "Elements of the stack: ";
	for (; it != ite; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "\nTest constant iterators (begin e end):" << std::endl;
	const MutantStack<int> const_mstack = mstack;
	MutantStack<int>::const_iterator cit = const_mstack.begin();
	MutantStack<int>::const_iterator cite = const_mstack.end();
	std::cout << "Elements of the stack const: ";
	for (; cit != cite; ++cit)
	{
		std::cout << *cit << " ";
	}
	std::cout << std::endl;
	std::cout << "\nTest reverse iterators (rbegin e rend):" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	std::cout << "Elements of the stack reverse order: ";
	for (; rit != rite; ++rit)
	{
		std::cout << *rit << " ";
	}
	std::cout << std::endl;
	std::cout << "\nTest const reverse iterators (rbegin e rend):" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
	std::cout << "Elements of the stack reverse order const: ";
	for (; crit != crite; ++crit)
	{
		std::cout << *crit << " ";
	}
	std::cout << std::endl;
	std::cout << "\nTest MutantStack with std::string:" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("42");
	strStack.push("Porto");
	strStack.push("jamendoe");
	MutantStack<std::string>::iterator sit = strStack.begin();
	MutantStack<std::string>::iterator site = strStack.end();
	std::cout << "Elements of the string stack: ";
	for (; sit != site; ++sit)
	{
		std::cout << *sit << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl << "Test copy" << std::endl;
	MutantStack<int> copiedStack(mstack);
	std::cout << "Elements of copied stack: ";
	for (it = copiedStack.begin(); it != copiedStack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl << "Test overload assignment" << std::endl;
	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << "Elements of stack (assigned): ";
	for (it = assignedStack.begin(); it != assignedStack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	return 0;
}

// subject test
//int main()
//{
//	MutantStack<int> mstack;
//	mstack.push(5);
//	mstack.push(17);
//	std::cout << mstack.top() << std::endl;
//	mstack.pop();
//	std::cout << mstack.size() << std::endl;
//	mstack.push(3);
//	mstack.push(5);
//	mstack.push(737);
////[...]
//	mstack.push(0);
//	MutantStack<int>::iterator it = mstack.begin();
//	MutantStack<int>::iterator ite = mstack.end();
//	++it;
//	--it;
//	while (it != ite)
//	{
//		std::cout << *it << std::endl;
//		++it;
//	}
//	std::stack<int> s(mstack);
//	return 0;
//}

//int main()
//{
//	std::cout << "\nWith list container" << std::endl;
//	std::list<int> lstack;
//	lstack.push_back(5);
//	lstack.push_back(17);
//	std::cout << lstack.back() << std::endl;
//	lstack.pop_back();
//	std::cout << lstack.size() << std::endl;
//	lstack.push_back(3);
//	lstack.push_back(5);
//	lstack.push_back(737);
////[...]
//	lstack.push_back(0);
//	std::list<int>::iterator itl = lstack.begin();
//	std::list<int>::iterator itel = lstack.end();
//	++itl;
//	--itl;
//	while (itl != itel)
//	{
//		std::cout << *itl << std::endl;
//		++itl;
//	}
//	std::list<int> sl(lstack);
//	return 0;
//}