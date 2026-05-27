/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:21:53 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 10:48:20 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_Scav") 
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap par défaut est assemblé !" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " est assemblé !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called !" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap " << this->name << " est copié !" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " est détruit !" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->status())
		return;
	std::cout << "ScavTrap " << this->name << " shoots " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ScavTrap::guardGate()
{
	if (!this->status())
		return;
	std::cout << "ScavTrap " << this->name << " is now in GateKeeper mode!" << std::endl;
}