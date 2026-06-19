/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 14:11:01 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 15:52:23 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

Span::Span() : _size(0) {}

Span::Span(unsigned int N) : _size(N)
{
    span.reserve(N);
}

Span::Span(const Span& cpy) : span(cpy.span), _size(cpy._size) {}

Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs) {
        span = rhs.span;
        _size = rhs._size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if(span.size() >= _size)
        throw Span::FullException();
    else
        span.push_back(number);
}

int Span::shortestSpan() const
{
	
	if (span.size() <= 1) {
        throw Span::TooSmall();
    }

	std::vector<int> localSpan = span;

	std::sort(localSpan.begin(),localSpan.end());
	
	int min_span = std::numeric_limits<int>::max();

	for (size_t i = 1; i < localSpan.size(); ++i) {
        int current_span = localSpan[i] - localSpan[i - 1]; 
        
        if (current_span < min_span) {
            min_span = current_span;
        }
    }

	return min_span;
}
int Span::longestSpan() const
{
	if (span.size() <= 1) {
        throw Span::TooSmall();
    }
    int min = *std::min_element(span.begin(), span.end());
    int max = *std::max_element(span.begin(), span.end());
    return max - min;	
}

const char* Span::FullException::what() const throw()
{
    return "This Span is full.";
}

const char* Span::TooSmall::what() const throw()
{
    return "Container must have at least 2 numbers.";
}