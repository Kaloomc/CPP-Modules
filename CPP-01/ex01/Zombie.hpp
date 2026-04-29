/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:54:28 by fgarnier          #+#    #+#             */
/*   Updated: 2026/04/29 17:29:04 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_H
#define Zombie_H

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	~Zombie();

	void announce(void);

	std::string get_name() const; 
    void set_name(std::string str) ; 
};

Zombie *zombieHorde(int N, std:: string name);

#endif