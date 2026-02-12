/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:54:28 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 00:22:42 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	~Zombie();

	void announce(void);

	std::string get_name() const { return name;};
    void set_name(std::string str) { name = str;};
};

Zombie *zombieHorde(int N, std:: string name);