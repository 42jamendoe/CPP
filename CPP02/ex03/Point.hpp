/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:34:15 by jamendoe          #+#    #+#             */
/*   Updated: 2024/06/10 09:34:19 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

private:

	Fixed const _x;
	Fixed const _y;

public:

	//***** Orthodox Canonical Form *****
	Point();
	Point(const Point& copy);
	Point& operator=(const Point& arg);
	~Point();
	//***** Orthodox Canonical Form *****

	Point(const float arg1, const float arg2);
	Fixed getX(void) const;
	Fixed getY(void) const;
};

float ft_triangle_area(Point const a, Point const b, Point const c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
