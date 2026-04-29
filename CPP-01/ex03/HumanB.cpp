/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:06:44 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 17:29:26 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name_) : weapon(NULL) ,name(name_) {}

void HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name <<" attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name <<" have no weapon " << std::endl;
		
}

void HumanB::setWeapon(Weapon &weapon_)
{
	this->weapon = &weapon_;
}

