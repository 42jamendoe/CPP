/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy), _target(copy._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& c)
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

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void PresidentialPardonForm::run() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}