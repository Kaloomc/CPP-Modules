/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:30:47 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/18 14:50:05 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1 : État initial ---" << std::endl;
	
	Data* originalData = new Data;
	originalData->value = 42;

	std::cout << "Adresse de originalData : " << originalData << std::endl;
	std::cout << "Valeur contenue         : " << originalData->value << std::endl;

	std::cout << "\n--- Test 2 : La Sérialisation ---" << std::endl;
	
	uintptr_t raw = Serializer::serialize(originalData);
	
	std::cout << "Valeur raw (uintptr_t)  : 0x" << std::hex << raw << std::dec << std::endl;

	std::cout << "\n--- Test 3 : La Désérialisation ---" << std::endl;
	
	Data* deserializedData = Serializer::deserialize(raw);
	
	std::cout << "Adresse deserializedData: " << deserializedData << std::endl;
	std::cout << "Valeur contenue         : " << deserializedData->value << std::endl;

	std::cout << "\n--- Test 4 : Test egalité ---" << std::endl;
	
	if (originalData == deserializedData) {
		std::cout << "[SUCCÈS] Les pointeurs sont strictement identiques." << std::endl;
	} else {
		std::cout << "[ERREUR] Les pointeurs sont différents." << std::endl;
	}

	std::cout << "\n--- Test 5 : Edge Cases (Pointeur NULL) ---" << std::endl;
	
	uintptr_t nullRaw = Serializer::serialize(NULL);
	Data* nullData = Serializer::deserialize(nullRaw);

	if (nullData == NULL) {
		std::cout << "[SUCCÈS] Le pointeur NULL a été géré correctement." << std::endl;
	} else {
		std::cout << "[ERREUR] La gestion du pointeur NULL a échoué." << std::endl;
	}

	delete originalData;

	return 0;
}