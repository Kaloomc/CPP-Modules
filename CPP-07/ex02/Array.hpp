/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 23:29:42 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 02:14:46 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array
{
private:
	T* elements;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& cpy);
	Array<T>& operator=(Array<T> const & rhs);
	~Array();

	T & operator[](unsigned int index);
	T const & operator[](unsigned int index) const;

	unsigned int size() const;

	class OutOfBounds : public std::exception {
    public:
        virtual const char* what() const throw() {
    		return "index is out of bounds!";
		}
    };
	
	
};

#include "Array.tpp"

#endif