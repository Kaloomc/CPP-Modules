/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:57:36 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 17:11:30 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_H
#define Weapon_H

#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type_); 
	const std::string& getType(void) const;
	void setType(std::string str);
};

#endif