/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:57:36 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 01:24:53 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type_) { type = type_;}; 
	std::string getType(void) { return type;};
	void setType(std::string str) { type = str;};
};
