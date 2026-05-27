/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:28:12 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 10:28:23 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- TEST SCAVTRAP ---" << std::endl;
	ScavTrap pablo("Pablo");
	pablo.attack("Terry");
	pablo.takeDamage(5);
	pablo.beRepaired(2);
	pablo.guardGate();

	std::cout << "\n--- TEST FRAGTRAP ---" << std::endl;
	FragTrap marcel("Marcel");
	marcel.attack("un mur");
	marcel.takeDamage(50);
	marcel.beRepaired(20);
	marcel.highFivesGuys();

	std::cout << "\n--- DESTRUCTION ---" << std::endl;
	return 0;
}