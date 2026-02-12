/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:19:05 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 00:27:19 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std:: string name)
{
	if (N <= 0) return NULL; 

    if (N > 1000000) {
        std::cerr << "Trop de zombies !" << std::endl;
        return NULL;
    }
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].set_name(name);
	}
	

	return zombies;
}