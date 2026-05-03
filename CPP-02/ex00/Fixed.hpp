/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:46:26 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 23:11:59 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
	private:
		int fixedPoint;
		static const int number;
	public:
		~Fixed();
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& copy);
		Fixed();


		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif 