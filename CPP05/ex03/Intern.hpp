/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{

public:

	//***** Orthodox Canonical Form *****
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& other);
	~Intern();
	//***** Orthodox Canonical Form *****

	class NoFormException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	AForm* createShrubbery(const std::string& form_target) const;
	AForm* createRobotomy(const std::string& form_target) const;
	AForm* createPresidential(const std::string& form_target) const;
	AForm* makeForm(const std::string& form_name, const std::string& form_target);

};

#endif
