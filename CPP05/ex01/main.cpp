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
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "Test 1: create a valid form" << std::endl;
	try
	{
		Form formA("FormA", 50, 25);
		std::cout << formA << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 1: Captured Exception: " << e.what() << std::endl;
	}

	std::cerr << "Test 2: create an invalid form - grade sign to high (0)\n(must throw an exception grade too high)" << std::endl;
	try
	{
		Form formB("FormB", 0, 25);
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 2: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 3: create an invalid form - grade sign to low (151)\n(must throw an exception grade too high)" << std::endl;
	try
	{
		Form formB("FormB", 151, 25);
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 3: Captured Exception: " << e.what() << std::endl;
	}

	std::cerr << "Test 4: create an invalid form - grade execute to high (0)\n(must throw an exception grade too high)" << std::endl;
	try
	{
		Form formB("FormB", 50, 0);
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 4: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 5: create an invalid form - grade execute to low (151)\n(must throw an exception grade too high)" << std::endl;
	try
	{
		Form formB("FormB", 50, 151);
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 5: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 6: create an invalid form - grade sign and execute to low (151)\n(must throw an exception grade too high)" << std::endl;
	try
	{
		Form formB("FormB", 151, 151);
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 6: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 7: create a valid bureaucrat and a valid formC\ntry to sign formC with insufficient sign grade (must throw an exception)" << std::endl;
	try
	{
		Bureaucrat jamendoe("jamendoe", 150);
		Form formC("FormC", 50, 25);
		std::cout << jamendoe << std::endl;
		std::cout << formC << std::endl;
		jamendoe.signForm(formC);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 7: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 8: create a valid bureaucrat and a valid formC\ntry to sign formC with sufficient sign grade (the form must be signed)" << std::endl;
	try
	{
		Bureaucrat jamendoe("jamendoe", 30);
		Form formD("FormD", 50, 25);
		std::cout << jamendoe << std::endl;
		std::cout << formD << std::endl;
		jamendoe.signForm(formD);
		std::cout << "Here " << jamendoe.getName() << " signed the " << formD.getName() << ".\nIn the next print the form must be signed!\n" << std::endl;
		std::cout << formD << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 8: Captured Exception: " << e.what() << std::endl;
	}


	std::cout << "Test 9: create a valid bureaucrat and a valid formC\ntry to sign formC with sufficient sign grade (the form must be signed)\nthen try to resign (must throw an exception)" << std::endl;
	try
	{
		Bureaucrat jamendoe("jamendoe", 30);
		Form formE("FormE", 50, 25);
		std::cout << jamendoe << std::endl;
		std::cout << formE << std::endl;
		jamendoe.signForm(formE);
		std::cout << "Here " << jamendoe.getName() << " signed the " << formE.getName() << ".\nIn the next print the form must be signed!\n" << std::endl;
		std::cout << formE << std::endl;
		std::cout << "When " << jamendoe.getName() << " try to sign " << formE.getName() << " again an exception must be thrown.\n" << std::endl;
		jamendoe.signForm(formE);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Test 9: Captured Exception: " << e.what() << std::endl;
	}
	return 0;
}
