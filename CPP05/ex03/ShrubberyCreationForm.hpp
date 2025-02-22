/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{

private:

	std::string const	_target;

public:

	//***** Orthodox Canonical Form *****
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	//***** Orthodox Canonical Form *****

	ShrubberyCreationForm(std::string const& target);

	std::string getTarget(void) const;
	void run() const;

};

#endif
