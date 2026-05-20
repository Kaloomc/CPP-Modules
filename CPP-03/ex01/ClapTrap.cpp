/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:08:20 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/19 19:38:59 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool ClapTrap::status(int hitPoint, int energyPoints, std::string name)
{
	if(hitPoint <= 0)
	{
		std::cout << "ClapTrap " << name << " is Dead!" << std::endl;
		return false;
	}
	if(energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << "has no energy left!" << std::endl;
		return false;
	}
	return true;
}

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name_) : name(name_), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "A ClapTrap named " << name << " Spawned" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "A ClapTrap named " << this->name << " has been Destroy" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
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
	if (!this->status(this->hitPoints, this->energyPoints, this->name))
		return;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage!" << std::endl;
	hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->status(this->hitPoints, this->energyPoints, this->name))
		return;
	std::cout << "ClapTrap " << this->name << " repaired itself by " << amount << " points!" << std::endl;
	hitPoints += amount;
}
