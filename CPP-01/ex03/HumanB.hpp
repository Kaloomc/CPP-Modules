/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:01:11 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/03 12:06:11 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>


class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(std::string name_);

	void setWeapon(Weapon &weapon_);
	void attack(void);
};

#endif