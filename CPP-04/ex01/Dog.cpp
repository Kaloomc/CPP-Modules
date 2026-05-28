/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:58:09 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 16:26:46 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal(), brain(new Brain)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &src) : Animal(src)
{
    std::cout << "Dog copy constructor called\n";

    this->brain = new Brain(*src.brain);
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &rhs)
    {
        Animal::operator=(rhs); 
        *this->brain = *rhs.brain; 
    }
    return *this;
}

void Dog::makeSound() const
{
	std::cout << "WHAAAAF WHAAAF !" << std::endl;
}