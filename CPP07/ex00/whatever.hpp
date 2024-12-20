/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:53:44 by jamendoe          #+#    #+#             */
/*   Updated: 2024/07/04 22:53:51 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T>
void swap(T& a, T& b)
{	T tmp = a;

	a = b;
	b = tmp;
};

template <typename T>
const T& max(const T& a, const T& b)
{
	if(a <= b)
		return (b);
	return (a);
};

template <typename T>
const T& min(const T& a, const T& b)
{
	if(a >= b)
		return (b);
	return (a);
};

#endif
