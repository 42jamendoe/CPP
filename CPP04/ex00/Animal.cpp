/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"

Animal::Animal() : _type("Empty type")
{
	std::cout << "***** Animal class default constructor *****" << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy._type)
{
	std::cout << "***** Animal class copy constructor *****" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	std::cout << "***** Animal class overload assignment *****" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "***** Animal class destructor *****" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal Base Class Sound" << std::endl;
}
