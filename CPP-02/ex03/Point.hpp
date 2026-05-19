/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:54:48 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/19 17:27:59 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y; 
public:
	Point();
	Point(const float init_x, const float init_y);
	Point(const Fixed fixed_x, const Fixed fixed_y);
	Point(const Point& src);
	Point& operator=(const Point& copy);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif