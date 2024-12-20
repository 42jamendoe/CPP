/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "***** Wrong Cat class default constructor *****" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal()
{
	_type = copy._type;
	std::cout << "***** Wrong Cat class copy constructor *****" << std::endl;
};
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "***** Wrong Cat class destructor *****" << std::endl;
};

void WrongCat::makeSound() const
{
	std::cout << "Wrong Miau Miau" << std::endl;
}