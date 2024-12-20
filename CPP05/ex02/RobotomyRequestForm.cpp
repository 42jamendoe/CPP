/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(), _target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy), _target(copy._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& c)
{
	out << "Name: " << c.getName() << std::endl;
	out << "Target: " << c.getTarget() << std::endl;
	if (c.getSign())
		out << "Is signed?: Yes" << std::endl;
	else
		out << "Is signed?: No" << std::endl;
	out << "Grade to sign: " << c.getGradeSign() << std::endl;
	out << "Grade to execute: " << c.getGradeExec() << std::endl;
	return (out);
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void RobotomyRequestForm::run() const
{
	std::cout << ".. drilling noises ..... drilling noises" << std::endl;
	std::srand((unsigned int)(time(NULL)));
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully 50% of the time" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}
