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
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "Test 1: create a burocrat *jamendoe* with valid grade (50)" << std::endl;
	Bureaucrat b1("jamendoe", 50);
	std::cout << b1 << std::endl;

	std::cout << "Test 2: increment the grade (49 is higher than 50)" << std::endl;
	b1.incrementGrade();
	std::cout << b1 << std::endl;

	std::cout << "Test 3: decrement the grade (from 49 get back to 50)" << std::endl;
	b1.decrementGrade();
	std::cout << b1 << std::endl;

	std::cout << "Test 4: try to create a burocrat *jamendoe* with an invalid grade, below 150\n(should throw an exception 151 is less than 150)" << std::endl;
	try
	{
		Bureaucrat b2("jamendoe", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 4: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 5: try to create a burocrat *jamendoe* with an invalid grade, above 1\n(should throw an exception 0 is higher than 1)" << std::endl;
	try
	{
		Bureaucrat b3("jamendoe", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Test 5: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 6: create a burocrat *jamendoe* with valid grade (1)" << std::endl;
	Bureaucrat b4("jamendoe", 1);
	std::cout << b4 << std::endl;

	std::cout << "     Test 6a: increment grade (should throw an exception)" << std::endl;
	try
	{
		b4.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "     Test 6a: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 7: create a burocrat *jamendoe* with valid grade (150)" << std::endl;
	Bureaucrat b5("jamendoe", 150);
	std::cout << b5 << std::endl;

	std::cout << "     Test 7a: decrement grade (should throw an exception)" << std::endl;
	try
	{
		b5.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "     Test 7a: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 8: copy first bureaucrat (from b1) | name = *jamendoe* grade = *50*" << std::endl;
	Bureaucrat b6(b1);
	std::cout << b6 << std::endl;

	std::cout << "Test 9: assign a bureaucrat to first one (b1) | name = *jamendoe* grade = *50*\n(created with name = *jamendoe assigned* and grade = *75*\nThe name of burocrat can't change because is const\nThe grade must change to 50)" << std::endl;
	Bureaucrat b7("jamendoe assigned", 75);
	b7 = b1;
	std::cout << b7 << std::endl;

	return 0;
}
