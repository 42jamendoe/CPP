/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

private:

	std::string const	_name;
	bool				_signed;
	int const			_grade_sign;
	int const			_grade_execute;

public:

	//***** Orthodox Canonical Form *****
	AForm();
	AForm(const AForm& copy);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	//***** Orthodox Canonical Form *****

	AForm(std::string const& name, int const grade_sign, int const grade_exec);

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw ();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw ();
	};
	class FormSignedException : public std::exception
	{
	public:
		const char* what() const throw ();
	};

	std::string getName(void) const;
	bool getSign(void) const;
	int getGradeSign(void) const;
	int getGradeExec(void) const;

	void beSigned(Bureaucrat& name);

	void execute(Bureaucrat const & executor) const;
	virtual void run() const = 0;

};
std::ostream& operator<<(std::ostream& out, const AForm& c);
#endif
