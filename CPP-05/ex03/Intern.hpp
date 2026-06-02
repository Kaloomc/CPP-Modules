/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:45:06 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/02 17:07:01 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
	AForm* createShrubbery(const std::string& target);
    AForm* createRobotomy(const std::string& target);
    AForm* createPresidential(const std::string& target);
public:
	Intern();
	Intern(const Intern& src);
	Intern& operator=(const Intern& rhs);
	~Intern();

	AForm* makeForm(const std::string& type, const std::string& name);
};

typedef AForm* (Intern::*FormCreator)(const std::string& target);

#endif 