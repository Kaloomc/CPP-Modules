/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:59:13 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/19 17:45:05 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float init_x, const float init_y) : x(init_x), y(init_y)
{
}

Point::Point(const Fixed fixed_x, const Fixed fixed_y) : x(fixed_x), y(fixed_y)
{
}

Point::Point(const Point& src) : x(src.x), y(src.y)
{
}

Point& Point::operator=(const Point& rhs)
{
	(void)rhs;
    return *this;
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}