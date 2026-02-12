/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:02:31 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/11 21:24:55 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    randomChump("StackZombie");

    Zombie* heapZombie = newZombie("HeapZombie");

    heapZombie->announce();

    delete heapZombie;

    return 0;
}