/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:59:52 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/18 19:48:04 by fgarnier         ###   ########.fr       */
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

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->fixedPoint < other.fixedPoint;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->fixedPoint > other.fixedPoint;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->fixedPoint <= other.fixedPoint;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->fixedPoint >= other.fixedPoint;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->fixedPoint== other.fixedPoint;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->fixedPoint != other.fixedPoint;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

Fixed& Fixed::operator++()
{
	this->fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->fixedPoint;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->fixedPoint;
	return temp;
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
    // On utilise la fonction de conversion
    out << rhs.toFloat();
    
    // On retourne le flux pour permettre d'enchaîner (ex: cout << a << b;)
    return out;
}