/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Empty type")
{
	std::cout << "***** AAnimal class default constructor *****" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) : _type(copy._type)
{
	std::cout << "***** AAnimal class copy constructor *****" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "***** AAnimal class destructor *****" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal Base Class Sound" << std::endl;
}
