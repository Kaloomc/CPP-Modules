/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:11:50 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/11 03:12:54 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	std::string get_first_name() const { return firstName;};
	void set_first_name(std::string str) { firstName = str;};

	std::string get_last_name() const { return lastName;};
	void set_last_name(std::string str) { lastName = str;};

	std::string get_phone_number() const { return phoneNumber;};
	void set_phone_number(std::string str) { phoneNumber = str;};

	std::string get_secret() const { return darkestSecret;};
	void set_secret(std::string str) { darkestSecret = str;};

	std::string get_nickname() const { return nickname;};
	void set_nickname(std::string str) { nickname = str;};
};

class PhoneBook {
private:
    Contact _contacts[8];
    int     _index;

public:
    PhoneBook() : _index(0) {}
    void addContact(); 
    void searchContact();
	void printContact(int index);
	Contact getContact(int index);
};

std::string formatColumn(std::string str);