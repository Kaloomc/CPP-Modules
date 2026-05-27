/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:27:47 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 10:54:30 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default_Frag")
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap générique a été créé." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) 
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " est prêt à en découdre !" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap " << this->name << " copy constructor called." << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " s'est auto-détruit." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (!this->status())
		return;
	std::cout << "FragTrap " << this->name << " lève la main et demande un High Five !" << std::endl;
}