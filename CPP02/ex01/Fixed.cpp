/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:32:43 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:33:10 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _int_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& from)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_int_value = from.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr) : _int_value(nbr << _nbr_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) : _int_value(static_cast<int>(roundf(nbr * (1 << _nbr_bits))))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((getRawBits() / static_cast<float>(1 << _nbr_bits)));
}

int Fixed::toInt(void) const
{
	return (getRawBits() >> _nbr_bits);
}

int Fixed::getRawBits(void) const
{
	return (this->_int_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_int_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& print)
{
	os << print.toFloat();
	return (os);
}
