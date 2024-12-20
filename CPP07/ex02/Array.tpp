/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : myArray(NULL), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : myArray(new T[n]()), len(n)
{
}

template <typename T>
Array<T>::Array(const Array& copy) : myArray(NULL), len(copy.len)
{
	unsigned int i;

	i = 0;
	if (len > 0)
	{
		myArray = new T[len];
		for (i = 0; i < len; i++)
		{
			myArray[i] = copy.myArray[i];
		}
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] myArray;
}

template <typename T>
Array<T>& Array<T>::Array::operator=(const Array& other)
{
	unsigned int i;

	i = 0;
	if (&other == this)
		return (*this);
	delete[] myArray;
	len = other.len;
	if (len > 0)
	{
		myArray = new T[len];
		for (i = 0; i < len; i++)
		{
			myArray[i] = other.myArray[i];
		}
	}
	else
		myArray = NULL;
	return (*this);
}

template <typename T>
T& Array<T>::Array::operator[](unsigned int id)
{
	if (id > size())
		throw std::out_of_range("Trying to reach an index that don't exist")  ;
	return (myArray[id]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (len);
}

#endif