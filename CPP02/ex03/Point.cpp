/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:32:43 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:33:10 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y)
{
}

Point& Point::operator=(const Point& arg)
{
	(void) arg;
	return (*this);
}

Point::~Point()
{

}

Point::Point(const float arg1, const float arg2) : _x(arg1), _y(arg2)
{
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}