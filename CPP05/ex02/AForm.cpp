/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _grade_sign(1), _grade_execute(1)
{}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), \
_grade_sign(copy._grade_sign), _grade_execute(copy._grade_execute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{}

AForm::AForm(std::string const& name, int const grade_sign, int const grade_exec) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& c)
{
	out << "Name: " << c.getName() << std::endl;
	if (c.getSign())
		out << "Is signed?: Yes" << std::endl;
	else
		out << "Is signed?: No" << std::endl;
	out << "Grade to sign: " << c.getGradeSign() << std::endl;
	out << "Grade to execute: " << c.getGradeExec() << std::endl;
	return (out);
}

std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSign(void) const
{
	return (_signed);
}

int AForm::getGradeSign(void) const
{
	return (_grade_sign);
}

int AForm::getGradeExec(void) const
{
	return (_grade_execute);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (_grade_sign >= bureaucrat.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw ()
{
	return ("The Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw ()
{
	return ("The Grade is too low.");
}

const char* AForm::FormSignedException::what() const throw ()
{
	return ("The Form is already signed.");
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw FormSignedException();
	else if (_grade_execute < executor.getGrade())
		throw GradeTooLowException();
	else if (_grade_execute >= executor.getGrade())
		run();
}
