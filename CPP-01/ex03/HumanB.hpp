/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:01:11 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 01:42:23 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp" 

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB(std::string name_);

	void setWeapon(Weapon &weapon_) { this->weapon = &weapon_; };
	void attack(void);
};

