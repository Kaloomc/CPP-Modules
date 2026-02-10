/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:11:50 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/10 18:16:48 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
using namespace std;

class contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string number;
	std::string secret;
public:
	std::string get_first_name() const { return first_name;};
	void set_first_name(std::string str) { first_name = str;};

	std::string get_last_name() const { return last_name;};
	void set_last_name(std::string str) { last_name = str;};

	std::string get_phone_number() const { return number;};
	void set_phone_number(std::string str) { number = str;};

	std::string get_secret() const { return secret;};
	void set_secret(std::string str) { secret = str;};
};
