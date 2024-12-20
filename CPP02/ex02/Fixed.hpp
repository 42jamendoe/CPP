/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:34:15 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:34:19 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

private:

	int _int_value;
	static const int _nbr_bits = 8;

public:

	//***** Orthodox Canonical Form *****
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& from);
	~Fixed();
	//***** Orthodox Canonical Form *****

	Fixed(const int nbr);
	Fixed(const float nbr);
	bool operator<(const Fixed& arg) const;
	bool operator>(const Fixed& arg) const;
	bool operator<=(const Fixed& arg) const;
	bool operator>=(const Fixed& arg) const;
	bool operator==(const Fixed& arg) const;
	bool operator!=(const Fixed& arg) const;
	Fixed operator+(const Fixed& arg) const;
	Fixed operator-(const Fixed& arg) const;
	Fixed operator*(const Fixed& arg) const;
	Fixed operator/(const Fixed& arg) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	static const Fixed& min(Fixed& arg1, Fixed& arg2);
	static const Fixed& min(const Fixed& arg1, const Fixed& arg2);
	static const Fixed& max(Fixed& arg1, Fixed& arg2);
	static const Fixed& max(const Fixed& arg1, const Fixed& arg2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& print);

#endif
