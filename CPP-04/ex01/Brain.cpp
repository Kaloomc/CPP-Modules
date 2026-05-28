/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:26:41 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 15:27:11 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = rhs.ideas[i];
		}
	}
	return (*this);
}

std::string const	&Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return (this->ideas[index]);
	}
	static const std::string empty = "";
	return (empty);
}

void	Brain::setIdea(int index, std::string const &idea)
{
	if (index >= 0 && index < 100)
	{
		this->ideas[index] = idea;
	}
}