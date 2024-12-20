/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Brain.hpp"

Brain::Brain()
{
	int i;

	i = 0;
	while (i < ARRAY_SIZE)
	{
		_ideas[i] = "Brain's ideia about...";
		i++;
	}
	std::cout << "***** Brain class default constructor *****" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	int i;

	i = 0;
	while (i < ARRAY_SIZE)
	{
		_ideas[i] = copy._ideas[i];
		i++;
	}
	std::cout << "***** Brain class copy constructor *****" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this == &other)
		return (*this);
	int i;
	i = 0;
	while (i < ARRAY_SIZE)
	{
		this->_ideas[i] = other._ideas[i];
		i++;
	}
	std::cout << "***** Brain class overload assignment *****" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "***** Brain class destructor *****" << std::endl;
}
