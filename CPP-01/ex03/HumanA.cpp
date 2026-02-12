/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:06:44 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 01:28:29 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name_, Weapon &weapon_) : weapon(weapon_), name(name_) {}

void HumanA::attack(void)
{
	std::cout << this->name <<" attacks with their " << this->weapon.getType() << std::endl;
}

