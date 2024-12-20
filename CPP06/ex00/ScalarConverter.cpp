/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void) copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

void handleInt(const std::string& literal)
{
	const char *var;
	char *trash;
	long number;

	var = literal.c_str();
	number = std::strtol(var, &trash, BASE);
	if (*trash)
		std::cout << "Can't convert literal!" << std::endl;
	else
	{
		if (number < std::numeric_limits<char>::min() ||
			number > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<char>(number)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
		if (number < std::numeric_limits<int>::min() ||
			number > std::numeric_limits<int>::max())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(number) << std::endl;
		if (number >= 1000000 || number <= -1000000)
			std::cout << "float: " << static_cast<float>(number) << "f" << std::endl << "double: " << static_cast<double>(number) << std::endl;
		else
			std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl << "double: " << static_cast<double>(number) << ".0" << std::endl;
	}
}

void handleFloat(const std::string& literal)
{
	const char *var;
	char *trash;
	float number;

	var = literal.c_str();
	number = std::strtof(var, &trash);
	if (*trash != 'f')
		std::cout << "Can't convert literal!" << std::endl;
	else
	{
		if (number < static_cast<float>(std::numeric_limits<char>::min()) ||
			number > static_cast<float>(std::numeric_limits<char>::max()))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<char>(number)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
		if (number < static_cast<float>(std::numeric_limits<int>::min()) ||
			number > static_cast<float>(std::numeric_limits<int>::max()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(number) << std::endl;
		if (number >= 1e6 || number <= -1e6 || (number - floor(number) != 0))
			std::cout << "float: " << number << "f" << std::endl  << "double: " << static_cast<double>(number) << std::endl;
		else
			std::cout << "float: " << number << ".0f" << std::endl << "double: " << static_cast<double>(number) << ".0" << std::endl;
	}
}

void handleDouble(const std::string& literal)
{
	const char *var;
	char *trash;
	double number;

	var = literal.c_str();
	number = std::strtod(var, &trash);
	if (*trash)
		std::cout << "Can't convert literal!" << std::endl;
	else
	{
		if (number < static_cast<double>(std::numeric_limits<char>::min()) ||
			number > static_cast<double>(std::numeric_limits<char>::max()))
			std::cout << "char: impossible" << std::endl;
		else if (!isprint(static_cast<char>(number)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
		if (number < static_cast<double>(std::numeric_limits<int>::min()) ||
			number > static_cast<double>(std::numeric_limits<int>::max()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(number) << std::endl;
		if (number >= 1e6 || number <= -1e6 || (number - floor(number) != 0))
			std::cout << "float: " << static_cast<float>(number) << "f" << std::endl << "double: " << number << std::endl;
		else
			std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl << "double: " << number << ".0" << std::endl;
	}
}

void detectType(const std::string& literal)
{
	if (literal.find('.') != literal.npos)
	{
		if (literal.operator[](literal.length() - 1) == 'f')
			handleFloat(literal);
		else
			handleDouble(literal);
	}
	else
		handleInt(literal);
}

void printChar(const std::string& literal)
{
	std::cout << "char: '" << literal << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
}

void printPseudoLiterals(const std::string& str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void checkPseudoLiterals(const std::string& str)
{
	std::string simple;

	if (str == "-inf" || str == "+inf" || str ==  "nan")
		simple = str;
	else if (str == "-inff" || str == "+inff" || str ==  "nanf")
		simple = str.substr(0, (str.length() - 1));
	printPseudoLiterals(simple);
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty())
		std::cout << "You're trying to convert an empty string." << std::endl;
	else if (str == "-inf" || str == "+inf" || str ==  "nan" || str == "-inff" || str == "+inff" || str ==  "nanf")
		checkPseudoLiterals(str);
	else if (str.length() == 1 && ((str[0] > 32 && str[0] < 48) || (str[0] > 57 && str[0] < 127)))
		printChar(str);
	else
		detectType(str);
}
