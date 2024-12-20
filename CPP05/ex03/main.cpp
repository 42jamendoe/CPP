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
#include "AForm.hpp"
#include "Intern.hpp"


int main()
{
	Intern random_intern;
	AForm* form;

	std::cout << "Test 1: Creating Presidential Pardon Form by random_intern" << std::endl;
	try
	{
		form = random_intern.makeForm("presidential pardon", "John");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Test 1: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 2: Creating Robotomy Request Form by random_intern" << std::endl;
	try
	{
		form = random_intern.makeForm("robotomy request", "John");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Test 2: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 3: Creating Shrubbery Creation Form by random_intern" << std::endl;
	try
	{
		form = random_intern.makeForm("shrubbery creation", "John");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Test 3: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 4: Creating Invalid Form by jamendoe" << std::endl;
	try
	{
		form = random_intern.makeForm("invalid", "John");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Test 4: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 5: Creating Presidential Pardon Form by random_intern, sign and execute by high grade bureaucrat" << std::endl;
	try
	{
		form = random_intern.makeForm("presidential pardon", "John_Presidential");
		std::cout << *form << std::endl;
		Bureaucrat high_grade("HighGrade", 1);
		high_grade.signForm(*form);
		std::cout << *form << std::endl;
		high_grade.executeForm(*form);
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Test 5: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 6: Creating Robotomy Request Form by random_intern, sign and execute by high grade bureaucrat" << std::endl;
	try
	{
		form = random_intern.makeForm("robotomy request", "John_robotomy");;
		std::cout << *form << std::endl;
		Bureaucrat high_grade("HighGrade", 1);
		high_grade.signForm(*form);
		std::cout << *form << std::endl;
		high_grade.executeForm(*form);
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Test 6: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 7: Creating Shrubbery Creation Form by random_intern, sign and execute by high grade bureaucrat" << std::endl;
	try
	{
		form = random_intern.makeForm("shrubbery creation", "John_Shrubbery");
		std::cout << *form << std::endl;
		Bureaucrat high_grade("HighGrade", 1);
		high_grade.signForm(*form);
		std::cout << *form << std::endl;
		high_grade.executeForm(*form);
		delete form;
	}
	catch (std::exception& e)
	{
		std::cerr << "Test 7: Captured Exception: " << e.what() << std::endl;
	}
	return 0;
}
