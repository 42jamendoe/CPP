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
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
	srand(time(NULL));

	int i = rand() % 3;
	if (i == 0)
	{
		std::cout << "A new *A* Object was created" << std::endl;
		return (new A());
	}
	else if (i == 1)
	{
		std::cout << "A new *B* Object was created" << std::endl;
		return (new B());
	}
	else if (i == 2)
	{
		std::cout << "A new *C* Object was created" << std::endl;
		return (new C());
	}
	else
		return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "The type of the object pointed to by p is *A* - test by pointer" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "The type of the object pointed to by p is *B* - test by pointer" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "The type of the object pointed to by p is *C* - test by pointer" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "The type of the object pointed to by p is *A* - test by reference" << std::endl;
	}
	catch (std::exception& e)
	{}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "The type of the object pointed to by p is *B* - test by reference" << std::endl;
	}
	catch (std::exception& e)
	{}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "The type of the object pointed to by p is *C* - test by reference" << std::endl;
	}
	catch (std::exception& e)
	{}
}

int main(int argc, char *argv[])
{
	(void) argv;
	if (argc > 1)
	{
		std::cout << "Error\nUsage: ./identify" << std::endl;
		return (1);
	}

	Base* test = generate();
	identify(test);
	identify(*test);
	delete test;

	return (0);
}
