/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:01:11 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 01:42:17 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp" 

class HumanA
{
private:
	Weapon &weapon;
	std::string name;
public:
	HumanA(std::string name_, Weapon &weapon_);
	void attack(void);	
};

