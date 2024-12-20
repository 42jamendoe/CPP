/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& copy)
{
	(void) copy;
}

Intern& Intern::operator=(const Intern& other)
{
	if (this == &other)
		return (*this);
	return (*this);
}

Intern::~Intern()
{}

AForm* Intern::createShrubbery(const std::string& form_target) const
{
	ShrubberyCreationForm* work;
	work = new ShrubberyCreationForm(form_target);
	return work;
}

AForm* Intern::createRobotomy(const std::string& form_target) const
{
	RobotomyRequestForm* work;
	work = new RobotomyRequestForm(form_target);
	return work;
}

AForm* Intern::createPresidential(const std::string& form_target) const
{
	PresidentialPardonForm* work;
	work = new PresidentialPardonForm(form_target);
	return work;
}

AForm* Intern::makeForm(const std::string& form_name, const std::string& form_target)
{
	int i;
	AForm* intern_form;
	AForm* (Intern::*formCreators[3])(const std::string&) const = {&Intern::createPresidential, &Intern::createRobotomy, &Intern::createShrubbery};
	std::string type[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	i = 0;
	while (i < 3)
	{
		if (!type[i].compare(form_name))
		{
			intern_form = (this->*formCreators[i])(form_target);
			std::cout << "Intern creates " << form_name << std::endl << std::endl;
			return (intern_form);
		}
		i++;
	}
	throw NoFormException();
}

const char* Intern::NoFormException::what() const throw()
{
	return "This Form name doesn't exist!\n";
}