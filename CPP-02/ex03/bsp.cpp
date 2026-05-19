/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:07:29 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/19 17:32:54 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed scalar_product(const Point& v1,const Point& v2)
{
	return ((v1.getX() * v2.getX()) + (v1.getY() * v2.getY()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point v0(c.getX() - a.getX(), c.getY() - a.getY());
	Point v1(b.getX() - a.getX(), b.getY() - a.getY());
	Point v2(point.getX() - a.getX(), point.getY() - a.getY());

	Fixed dot00 = scalar_product(v0,v0);
	Fixed dot01 = scalar_product(v0,v1);
	Fixed dot02 = scalar_product(v0,v2);
	Fixed dot11 = scalar_product(v1,v1);
	Fixed dot12 = scalar_product(v1,v2);

	Fixed denominator = (dot00 * dot11) - (dot01 * dot01);

	if (denominator == 0)
		return false;

	Fixed u = ((dot11 * dot02) - (dot01 * dot12)) / denominator;
	Fixed v = ((dot00 * dot12) - (dot01 * dot02)) / denominator;

	return (u > Fixed(0)) && (v > Fixed(0)) && (u + v < Fixed(1));
}