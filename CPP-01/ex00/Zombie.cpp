/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:57:54 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 17:26:51 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <ostream>

Zombie::~Zombie(void)
{
	std::cout << name << " is destroyed" << std::endl;
}

std::string Zombie::get_name() const
{
	return name;
}

void Zombie::set_name(std::string str)
{
	name = str;
}


void Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}