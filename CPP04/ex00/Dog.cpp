/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "***** Dog class default constructor *****" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal()
{
	_type = copy._type;
	std::cout << "***** Dog class copy constructor *****" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	Animal::operator=(other);
	std::cout << "***** Dog class overload assignment *****" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "***** Dog class destructor *****" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
