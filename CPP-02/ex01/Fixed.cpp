/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:59:52 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 23:46:13 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::number = 8;

Fixed::Fixed() : fixedPoint(0) // Default
{
    std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const int value) : fixedPoint(value << number) // Int
{
   std::cout << "Int constructor called" << std::endl;
} 

Fixed::Fixed(const float value) : fixedPoint(roundf(value * (1 << number))) // Float
{
   std::cout << "Float constructor called" << std::endl;
} 

Fixed::~Fixed() // Destructor
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout<< "Copy constructor called"<< std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->fixedPoint = rhs.getRawBits();
    }
    return *this;
}

float Fixed:: toFloat(void) const
{
	return (float)this->fixedPoint / (1 << number);
}

int Fixed:: toInt(void) const
{
	return this->fixedPoint >> 8;
}

int Fixed::getRawBits(void) const 
{
    return this->fixedPoint;
}

void Fixed::setRawBits(int const raw) 
{
    this->fixedPoint = raw;
}

std::ostream & operator<<(std::ostream & out, const Fixed & rhs)
{
    // On utilise la fonction de conversion que tu as déjà écrite
    out << rhs.toFloat();
    
    // On retourne le flux pour permettre d'enchaîner (ex: cout << a << b;)
    return out;
}