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

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "***** Cat class default constructor *****" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal()
{
	_type = copy._type;
	std::cout << "***** Cat class copy constructor *****" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	Animal::operator= (other);
	std::cout << "***** Cat class overload assignment *****" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "***** Cat class destructor *****" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaow miaow" << std::endl;
}