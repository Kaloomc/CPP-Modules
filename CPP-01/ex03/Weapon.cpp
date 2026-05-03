/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:05:55 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/03 12:10:24 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type_) : type(type_) {}

const std::string& Weapon::getType(void) const
{
	return type;
}

void Weapon::setType(std::string str)
{
	type = str;
}