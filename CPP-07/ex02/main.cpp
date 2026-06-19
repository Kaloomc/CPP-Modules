/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 02:12:47 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 02:35:40 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "===========================================" << std::endl;
    std::cout << "       TEST 1 : Constructeur par défaut    " << std::endl;
    std::cout << "===========================================" << std::endl;
    Array<int> emptyArray;
    std::cout << "Taille de emptyArray : " << emptyArray.size() << " (devrait être 0)" << std::endl;

    std::cout << "\n===========================================" << std::endl;
    std::cout << " TEST 2 : Constructeur avec paramètre (n)  " << std::endl;
    std::cout << "===========================================" << std::endl;
    unsigned int n = 5;
    Array<int> intArray(n);
    std::cout << "Taille de intArray : " << intArray.size() << " (devrait être 5)" << std::endl;
    
    std::cout << "-> Vérification de l'initialisation par défaut :" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << " (devrait être 0)" << std::endl;
    }

    std::cout << "\n===========================================" << std::endl;
    std::cout << " TEST 3 : Assignation via l'opérateur []   " << std::endl;
    std::cout << "===========================================" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = (i + 1) * 10; // On assigne 10, 20, 30, 40, 50
        std::cout << "Nouvelle valeur intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    std::cout << "\n===========================================" << std::endl;
    std::cout << " TEST 4 : Constructeur par copie (Deep copy)" << std::endl;
    std::cout << "===========================================" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "-> Modification de la copie (copyArray[0] = 999)..." << std::endl;
    copyArray[0] = 999;
    std::cout << "intArray[0]  = " << intArray[0] << " (ne doit pas avoir changé, attendu: 10)" << std::endl;
    std::cout << "copyArray[0] = " << copyArray[0] << " (doit être 999)" << std::endl;

    std::cout << "\n===========================================" << std::endl;
    std::cout << " TEST 5 : Opérateur d'affectation (=)      " << std::endl;
    std::cout << "===========================================" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "-> Modification de l'array assigné (assignedArray[1] = 888)..." << std::endl;
    assignedArray[1] = 888;
    std::cout << "intArray[1]      = " << intArray[1] << " (ne doit pas avoir changé, attendu: 20)" << std::endl;
    std::cout << "assignedArray[1] = " << assignedArray[1] << " (doit être 888)" << std::endl;

    std::cout << "\n===========================================" << std::endl;
    std::cout << " TEST 6 : Exceptions (Hors limites)        " << std::endl;
    std::cout << "===========================================" << std::endl;
    
    std::cout << "-> Test d'un index trop grand (index 5 pour une taille de 5) :" << std::endl;
    try {
        std::cout << intArray[5] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception correctement attrapée : " << e.what() << std::endl;
    }

    std::cout << "-> Test d'un index négatif (index -1) :" << std::endl;
    try {
        std::cout << intArray[-1] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception correctement attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n===========================================" << std::endl;
    std::cout << " TEST 7 : Test avec un autre type (string) " << std::endl;
    std::cout << "===========================================" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Bonjour";
    stringArray[1] = "le";
    stringArray[2] = "monde!";
    
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }

    std::cout << "\n--- Fin des tests ---" << std::endl;
    return 0;
}