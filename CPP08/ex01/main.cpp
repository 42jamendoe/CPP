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
#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "1. Created span {6, 3, 17, 9, 11}\n(shortest span = 11 - 9 = 2) (longest span = 17 - 3 = 14)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "2. Test to add one number up limit (should throw an exception)" << std::endl;
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "3. Test to calculate short span with less than two numbers" << std::endl;
		Span sp(2);
		sp.addNumber(10);
		std::cout << "Shortest span:" << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "4. Test to calculate longest span with less than two numbers" << std::endl;
		Span sp(2);
		sp.addNumber(10);
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "5. Test with 10000 random numbers" << std::endl;
		Span sp(10000);
		std::srand(static_cast<unsigned int>(std::time(NULL)));

		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(std::rand() % 100000);
		}
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "6. Test with 10000 numbers equal to 42" << std::endl;
		Span sp(10000);
		std::vector<int> array_int (10000, 42);
		sp.aut_addNumber(array_int);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl << "7. Try to add 10 numbers to a span with limit of 5" << std::endl;
		Span sp(5);
		std::vector<int> numbers(10, 42);
		sp.aut_addNumber(numbers);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
