/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this == &other)
		return (*this);
	_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string const& name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& c)
{
	out << c.getName() << ", bureaucrat grade " << c.getGrade() << "." << std::endl;
	return (out);
}

void Bureaucrat::signForm(AForm& name)
{
	if (!name.getSign())
	{
		try
		{
			name.beSigned(*this);
			std::cout << getName() << " signed " << name.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << getName() << " couldn't sign " << name.getName() << " because: " << e.what() << std::endl;
		}
	}
	else
		std::cout << getName() << " couldn't sign " << name.getName() << " because it is already signed." << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (form.getSign())
	{
		try
		{
			form.execute(*this);
			std::cout << getName() << " executed " << form.getName() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << getName() << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
		}
	}
	else
		std::cout << getName() << " couldn't sign " << form.getName() << " because it isn't signed" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("The Grade can't be higher than 1.\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("The Grade can't be smaller than 150.\n");
}
