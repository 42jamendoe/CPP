/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>

template <typename T>
class Array
{

private:
	T* 				myArray;
	unsigned int	len;

public:

	//***** Orthodox Canonical Form *****
	Array();
	Array(const Array<T>& copy);
	Array<T>& operator=(const Array& other);
	~Array();
	//***** Orthodox Canonical Form *****

	Array(unsigned int n);
	T& operator[](unsigned int id);
	unsigned int size() const;

};

# include "Array.tpp"
#endif
