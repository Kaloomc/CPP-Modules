/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:13:54 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/18 11:47:22 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{

	if(ac != 2)
	{
		std::cout << "No argument" << std::endl;
		return 1;
	}
	Harl harl;
	
	harl.complain(av[1]);
	return 0;
}