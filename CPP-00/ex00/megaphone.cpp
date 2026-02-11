/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 22:39:51 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/07 22:48:31 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace	std;

void	to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	while (av[i])
	{
		to_upper(av[i]);
		cout << av[i];
		i++;
	}
	cout << "\n";
	return (0);
}
