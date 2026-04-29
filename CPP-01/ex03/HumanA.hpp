/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:01:11 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 16:07:38 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_H
#define HumanA_H

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

#endif
