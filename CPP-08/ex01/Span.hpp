/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:04:56 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 15:52:12 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <stdexcept>
#include <exception>
#include <vector>

class Span
{
private:
	std::vector<int> span;
	unsigned int _size;
public:
	Span();
	Span(unsigned int N);
	Span(const Span& cpy);
	Span& operator=(const Span& rhs);
	~Span();

	void addNumber(int number);
	
	int shortestSpan() const;
	int longestSpan() const;
	
	class FullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

	class TooSmall : public std::exception {
    public:
        virtual const char* what() const throw();
    };

	template <typename Iterator>
    void addNumber(Iterator begin, Iterator end)
    {
        unsigned int distance = std::distance(begin, end);

        if (distance > (_size - span.size()))
        {
            throw std::out_of_range("Exception : Span capacity exceeded");
        }
        
        span.insert(span.end(), begin, end);
    }
};


#endif