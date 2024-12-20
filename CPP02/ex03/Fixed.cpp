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


Fixed::Fixed() : _int_value(0)
{
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& from)
{
	_int_value = (from.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int nbr) : _int_value(nbr * (1 << _nbr_bits))
{
}

Fixed::Fixed(const float nbr) : _int_value(static_cast<int>(roundf(nbr * (1 << _nbr_bits))))
{
}

bool Fixed::operator<(const Fixed& arg) const
{
	return (this->getRawBits() < arg.getRawBits());
}

bool Fixed::operator>(const Fixed& arg) const
{
	return (this->getRawBits() > arg.getRawBits());
}

bool Fixed::operator<=(const Fixed& arg) const
{
	return (this->getRawBits() <= arg.getRawBits());
}

bool Fixed::operator>=(const Fixed& arg) const
{
	return (this->getRawBits() >= arg.getRawBits());
}

bool Fixed::operator==(const Fixed& arg) const
{
	return (this->getRawBits() == arg.getRawBits());
}

bool Fixed::operator!=(const Fixed& arg) const
{
	return (this->getRawBits() != arg.getRawBits());
}

Fixed Fixed::operator+(const Fixed& arg) const
{
	Fixed tmp;
	tmp.setRawBits (this->getRawBits() + arg.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& arg) const
{
	Fixed tmp;
	tmp.setRawBits (this->getRawBits() - arg.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& arg) const
{
	Fixed tmp;
	tmp.setRawBits ((this->getRawBits() * arg.getRawBits()) / (1 << this->_nbr_bits));
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& arg) const
{
	Fixed tmp;
	tmp.setRawBits ((this->getRawBits() * ( 1 << this->_nbr_bits) / arg.getRawBits()));
	return (tmp);
}

Fixed& Fixed::operator++()
{
	Fixed::setRawBits (getRawBits() + 1);
	return (*this);
}

Fixed& Fixed::operator--()
{
	Fixed::setRawBits (getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	Fixed::setRawBits (getRawBits() + 1);
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	Fixed::setRawBits (getRawBits() - 1);
	return (tmp);
}

float Fixed::toFloat(void) const
{
	return (((float)getRawBits() / (1 << _nbr_bits)));
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

const Fixed& Fixed::min(Fixed& arg1, Fixed& arg2)
{
	if (arg1.getRawBits() < arg2.getRawBits())
		return (arg1);
	return (arg2);
}
const Fixed& Fixed::min(const Fixed& arg1, const Fixed& arg2)
{
	if (arg1.getRawBits() < arg2.getRawBits())
		return (arg1);
	return (arg2);
}
const Fixed& Fixed::max(Fixed& arg1, Fixed& arg2)
{
	if (arg1.getRawBits() > arg2.getRawBits())
		return (arg1);
	return (arg2);
}
const Fixed& Fixed::max(const Fixed& arg1, const Fixed& arg2)
{
	if (arg1.getRawBits() > arg2.getRawBits())
		return (arg1);
	return (arg2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& print)
{
	os << print.toFloat();
	return (os);
}
