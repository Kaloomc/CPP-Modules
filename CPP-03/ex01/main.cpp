/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:14:14 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 10:57:00 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap pablo("pablo");
	
	pablo.attack("terry");
	pablo.takeDamage(5);
	pablo.beRepaired(2);
	pablo.takeDamage(10);
	pablo.attack("terry");

	return 0;
}