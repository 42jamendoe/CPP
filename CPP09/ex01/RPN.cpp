/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& copy)
{
	values = copy.values;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this == &other)
		return (*this);
	values = other.values;
	return (*this);
}

RPN::~RPN()
{

}

void RPN::testInput(const std::string& line) const
{
	size_t i;
	size_t j;

	i = 0;
	while (i < line.size())
	{
		j = i % 2;
		if (((j == 0) && (!isdigit(line[i]) && line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/'))
		|| ((j == 1) && (line[i] != ' ')))
			throw RPN_error();
		i++;
	}
}

void RPN::handleOperations(std::string entry)
{
	int result = 0;
	int second = values.top();
	values.pop();
	int first = values.top();
	values.pop();
	if (entry[0] == '+')
		result = first + second;
	else if (entry[0] == '-')
		result = first - second;
	else if (entry[0] == '/' && second != 0)
		result = first / second;
	else if (entry[0] == '*')
		result = first * second;
	else
		throw RPN_error();
	values.push(result);
}


void RPN::parse_arg(char* arg)
{
	int result;
	std::string cpp_arg = arg;
	testInput(cpp_arg);
	std::istringstream tmp(cpp_arg);
	std::string entry;
	while(!tmp.eof())
	{
		getline(tmp, entry, ' ');
        if (isdigit(entry[0]))
			values.push(entry[0] - 48);
		else
		{
			if (values.size() < 2)
				throw RPN_error();
			handleOperations(entry);
		}
	}
	if (values.size() > 1)
		throw RPN_error();
    result = values.top();
	std::cout << result << std::endl;
}


const char* RPN::RPN_error::what() const throw()
{
	return("Error");
}