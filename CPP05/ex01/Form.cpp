/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _grade_sign(1), _grade_execute(1)
{}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), \
_grade_sign(copy._grade_sign), _grade_execute(copy._grade_execute)
{}

Form& Form::operator=(const Form& other)
{
	if (this == &other)
		return (*this);
	_signed = other._signed;
	return (*this);
}

Form::~Form()
{}

Form::Form(std::string const& name, int const grade_sign, int const grade_exec) : _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& c)
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

std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSign(void) const
{
	return (_signed);
}

int Form::getGradeSign(void) const
{
	return (_grade_sign);
}

int Form::getGradeExec(void) const
{
	return (_grade_execute);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (_grade_sign >= bureaucrat.getGrade())
		_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw ()
{
	return ("The Grade to sign or to execute is too high.\n");
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return ("The Grade to sign or to execute is too low.\n");
}
