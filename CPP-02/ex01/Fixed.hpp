/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:46:26 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 23:44:34 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int fixedPoint;
		static const int number;
	public:
		Fixed(); // Default constructor
		Fixed(const int value); // Int constructor
		Fixed(const float value); // Float constructor
		Fixed(const Fixed& src); // Copy constructor
		Fixed& operator=(const Fixed& copy);
		~Fixed(); // Destructor

		float toFloat( void ) const;
		int toInt( void ) const;
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & out, const Fixed & rhs);

#endif 