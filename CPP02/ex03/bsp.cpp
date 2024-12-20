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
#include "Point.hpp"

float ft_triangle_area(Point const a, Point const b, Point const c)
{
	float area;

	area = 0.5f * (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
		+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
		+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));
	if (area < 0)
		area *= -1;
	return (area);
}


bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float area_abc = ft_triangle_area (a, b, c);
	float area_abp = ft_triangle_area (a, b, point);
	float area_acp = ft_triangle_area (a, c, point);
	float area_bcp = ft_triangle_area (b, c, point);
	if (area_abc == (area_abp + area_acp + area_bcp) && area_abp != 0.0f
	&& area_acp != 0.0f && area_bcp != 0.0f)
		return (true);
	return (false);
}
