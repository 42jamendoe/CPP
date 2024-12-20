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

Dog::Dog() : AAnimal(), _brain(new Brain())
{
	_type = "Dog";
	std::cout << "***** Dog class default constructor *****" << std::endl;
}

Dog::Dog(const Dog& copy) : AAnimal(copy), _brain(new Brain(*copy._brain))
{
	_type = copy._type;
	std::cout << "***** Dog class copy constructor *****" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	AAnimal::operator=(other);
	delete _brain;
	_brain = new Brain(*other._brain);
	_type = other._type;
	std::cout << "***** Dog class overload assignment *****" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "***** Dog class destructor *****" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
