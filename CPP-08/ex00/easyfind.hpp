/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:12:01 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 15:47:40 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <exception>

class NotInList : public std::exception {
    public:
        virtual const char* what() const throw()
		{
			return "didnt find it sorry!";
		}
};


template <typename T> typename T::iterator easyfind(T &container, int search)
{
	typename T::iterator it = std::find(container.begin(), container.end(), search);
	
	if (it == container.end()) {
		throw NotInList();
	}
	return it;
}

#endif