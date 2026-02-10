/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:43:25 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/10 18:14:09 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

contact ADD()
{
	string input;
	contact contact_;

	input = "";
	while(input == "")
	{
		cout << "first name: ";
		getline(cin, input);
		if (input == "")
			cout << "* field can't be empty *" << endl;
		contact_.set_first_name(input);
	}
	input = "";
	while(input == "")
	{
		cout << "last name: ";
		getline(cin, input);
		if (input == "")
			cout << "* field can't be empty *" << endl;
		contact_.set_last_name(input);
	}
	input = "";
	while(input == "")
	{
		cout << "phone number: ";
		getline(cin, input);
		if (input == "")
			cout << "* field can't be empty *" << endl;
		contact_.set_phone_number(input);
	}
	input = "";
	while(input == "")
	{
		cout << "darkest secret: ";
		getline(cin, input);
		if (input == "")
			cout << "* field can't be empty *" << endl;
		contact_.set_secret(input);
	}
	return contact_;
}


int main()
{
	contact contacts[7];
	string input;
	
	cout << "Phonebook: ";
	if (!getline(cin, input))
    	return 0; 
	if(input == "ADD")
	{
		contacts[0] = ADD();
	}

	cout << contacts[0].get_first_name() << endl;
	cout << contacts[0].get_last_name() << endl;
	cout << contacts[0].get_phone_number() << endl;
	cout << contacts[0].get_secret() << endl;
}