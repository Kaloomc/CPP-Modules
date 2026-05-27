/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:08:20 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 10:55:41 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool ClapTrap::status(void) const
{
	if (this->hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is Dead!" << std::endl;
		return false;
	}
	if (this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy left!" << std::endl;
		return false;
	}
	return true;
}

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "A ClapTrap named " << this->name << " Spawned" << std::endl;
}

ClapTrap::ClapTrap(std::string name_) : name(name_), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "A ClapTrap named " << this->name << " Spawned" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "A ClapTrap named " << this->name << " has been Destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->status())
		return;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage!" << std::endl;
	if (this->hitPoints <= 0)
		return;
	if (amount >= static_cast<unsigned int>(this->hitPoints))
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->status())
		return;
	std::cout << "ClapTrap " << this->name << " repaired itself by " << amount << " points!" << std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}