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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{

	std::cout << "Test 1: Create 3 bureaucrats:" << std::endl;
	Bureaucrat jamendoe_low("jamendoe_150", 150);
	Bureaucrat jamendoe_mid("jamendoe_50", 50);
	Bureaucrat jamendoe_high("jamendoe_1", 1);
	std::cout << jamendoe_low;
	std::cout << jamendoe_mid;
	std::cout << jamendoe_high << std::endl;

	std::cout << "Test 2: Create a bureaucrat with an invalid low grade:" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid_low", 200);
	}
	catch (std::exception &e)
	{
		std::cerr << "Test 2: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 3: Create a bureaucrat with an invalid high grade:" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid_high", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Test 3: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 4: Create 3 Forms (Shrubbery_Target, Robotomy_Target, Pardon_Target:" << std::endl;
	ShrubberyCreationForm shrubberyForm("Shrubbery_Target");
	RobotomyRequestForm robotomyForm("Robotomy_Target");
	PresidentialPardonForm pardonForm("Pardon_Target");
	std::cout << shrubberyForm;
	std::cout << robotomyForm;
	std::cout << pardonForm << std::endl;

	std::cout << "Test 5: Sign a form without enough grade:" << std::endl;
	try
	{
		jamendoe_low.signForm(shrubberyForm);
	}
	catch
	(std::exception &e)
	{
		std::cerr << "Test 5: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 6: Sign a form" << std::endl;
	try
	{
		jamendoe_high.signForm(pardonForm);
	}
	catch
			(std::exception &e)
	{
		std::cerr << "Test 6: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 7: Sign a form and try to execute without grade" << std::endl;
	try
	{
		jamendoe_mid.signForm(robotomyForm);
		jamendoe_mid.executeForm(robotomyForm);
	}
	catch
			(std::exception &e)
	{
		std::cerr << "Test 7: Captured Exception: " << e.what() << std::endl;
	}

	std::cout << "Test 8: Execute it" << std::endl;
	try
	{
		jamendoe_high.executeForm(robotomyForm);
	}
	catch
			(std::exception &e)
	{
		std::cerr << "Test 8: Captured Exception: " << e.what() << std::endl;
	}
	std::cout << "Test 9: Execute it" << std::endl;
	try
	{
		ShrubberyCreationForm to_assign("jamendoe_target_assign");
		ShrubberyCreationForm to_change("jamendoe_target_change");
		Bureaucrat joao("jamendoe", 1);
		std::cout << to_assign << std::endl;
		std::cout << to_change << std::endl;
		joao.signForm(to_assign);
		std::cout << to_assign << std::endl;
		to_change = to_assign;
		std::cout << to_assign << std::endl;
		std::cout << to_change << std::endl;
	}
	catch
			(std::exception &e)
	{
		std::cerr << "Test 10: Captured Exception: " << e.what() << std::endl;
	}
	return 0;
}
