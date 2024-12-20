/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& c)
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

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void ShrubberyCreationForm::run() const
{
	std::fstream new_file;
	std::string filename;

	filename = getTarget() + "_shrubbery";
	new_file.open(filename.c_str() , std::fstream::out | std::fstream::app);
	if (!new_file.is_open())
	{
		std::cerr << "Error\nThe file " << _target << "+ \"_shrubbery\" isn't opened! Can't write the ascii tree." << std::endl;
		return ;
	}
	new_file << "        _-_        " << std::endl;
	new_file << "     /~~   ~~\\     " << std::endl;
	new_file << "  /~~         ~~\\  " << std::endl;
	new_file << " {               } " << std::endl;
	new_file << "  \\  _-     -_  /  " << std::endl;
	new_file << "    ~  \\\\ //  ~    " << std::endl;
	new_file << " _- -   | | _- _   " << std::endl;
	new_file << "   _ -  | |   -_   " << std::endl;
	new_file << "       // \\\\       " << std::endl;
	new_file.close();
}