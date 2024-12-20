/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	_type = "Cat";
	std::cout << "***** Cat class default constructor *****" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy), _brain(new Brain(*copy._brain))
{
	_type = copy._type;
	std::cout << "***** Cat class copy constructor *****" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	Animal::operator= (other);
	delete _brain;
	_brain = new Brain(*other._brain);
	_type = other._type;
	std::cout << "***** Cat class overload assignment *****" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "***** Cat class destructor *****" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaow miaow" << std::endl;
}