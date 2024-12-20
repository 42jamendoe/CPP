/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{

protected:

	std::string const	_name;
	int					_grade;

public:

	//***** Orthodox Canonical Form *****
	Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
	//***** Orthodox Canonical Form *****

	Bureaucrat(std::string const& name, int grade);
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

	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade();
	void decrementGrade();

};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& c);
#endif
