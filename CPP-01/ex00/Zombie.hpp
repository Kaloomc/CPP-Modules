/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:54:28 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/03 12:11:38 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
private:
	std::string name;
public:
	~Zombie();

	void announce(void) const;

	std::string get_name() const;
    void set_name(std::string str);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif