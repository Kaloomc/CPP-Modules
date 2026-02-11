/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:43:25 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/11 03:16:23 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <ostream>

std::string getInput(std::string prompt) {
    std::string input = "";
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << "\nInterruption détectée. Retour au menu." << std::endl;
            exit(0);
        }
        if (!input.empty())
            break;
        std::cout << "Erreur : Le champ ne peut pas être vide." << std::endl;
    }
    return input;
}

void printConctact(Contact contact, int index)
{
	std::cout << std::endl << "         index: " << index + 1 << std::endl
		<< "         First Name: " << contact.get_first_name() << std::endl
		<< "         Last Name: " << contact.get_last_name() << std::endl
		<< "         Nickname: " << contact.get_nickname() << std::endl
		<< "         Phone Number: " << contact.get_phone_number() << std::endl
		<< "         Darkest Secret: " << contact.get_secret() << std::endl << std::endl;
}

Contact PhoneBook::getContact(int index)
{
	return this->_contacts[index];
}

void PhoneBook::printContact(int index)
{
	printConctact(this->_contacts[index],index);
}

void printColumn(Contact contact,int index)
{
	std::cout << std::setw(10) << std::right << index + 1 << "|";
    std::cout << std::setw(10) << std::right << formatColumn(contact.get_first_name()) << "|";
    std::cout << std::setw(10) << std::right << formatColumn(contact.get_last_name()) << "|";
    std::cout << std::setw(10) << std::right << formatColumn(contact.get_nickname()) << "|" << std::endl;
}

void PhoneBook::searchContact() {

	std::string input;
	
    for (int i = 0; i < 8; i++) {
		if(!this->_contacts[i].get_first_name().empty())
			printColumn(this->_contacts[i] ,i);
	}
	
	while (true)
	{
		std::cout << "Entrez l'index du contact : ";
		if (!std::getline(std::cin, input))
		    break;
		std::stringstream ss(input);
		int index;
					
		if (!(ss >> index)) {
		    std::cout << "Erreur : Index invalide (pas un nombre)." << std::endl;
		} else if (index < 1 || index > 8) {
		    std::cout << "Erreur : L'index doit être entre 1 et 8." << std::endl;
		} else if (this->getContact(index - 1).get_first_name().empty()) {
		    std::cout << "Erreur : Ce contact n'existe pas encore." << std::endl;
		} else {
		    this->printContact(index - 1);
			break;
		}
	}
}

void PhoneBook::addContact() {
    std::string input;
    Contact     newContact;

	
	newContact.set_first_name(getInput("first name: "));
    newContact.set_last_name(getInput("last name: "));
    newContact.set_nickname(getInput("nickname: "));
    newContact.set_phone_number(getInput("phone number: "));
    newContact.set_secret(getInput("darkest secret: "));

   	this->_contacts[this->_index % 8] = newContact;
	this->_index++;
}

int	main(void)
{
	PhoneBook repertory;
	std::string input;

	while (true) {
        std::cout << "PhoneBook: ";
        if (!std::getline(std::cin, input) || input == "EXIT")
            break;
        if (input == "ADD")
            repertory.addContact();
        else if (input == "SEARCH")
		{
            repertory.searchContact();
			
		}
    }
    return 0;
}