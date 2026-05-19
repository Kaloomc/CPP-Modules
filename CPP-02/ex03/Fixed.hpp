/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:46:26 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/18 13:48:12 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
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

		//operator
		Fixed operator*(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		//increment
		Fixed& operator++();
		Fixed operator++(int);

		Fixed& operator--();
		Fixed operator--(int);

		//comparator
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);

		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
		float toFloat( void ) const;
		int toInt( void ) const;
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

std::ostream & operator<<(std::ostream & out, const Fixed & rhs);

#endif 