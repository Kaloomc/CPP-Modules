/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:06:44 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 01:42:38 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name_) : weapon(0) ,name(name_) {}

void HumanB::attack(void)
{
	std::cout << this->name <<" attacks with their " << this->weapon->getType() << std::endl;
}

