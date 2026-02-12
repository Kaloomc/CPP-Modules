/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:02:31 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 00:28:43 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
	Zombie *horde = zombieHorde(N, "Foo");
	if(!horde)
		return 1;	
	for (int i = 0; i < N; i++) {
	    horde[i].announce();
	}
	delete [] horde;
	return 0;
}