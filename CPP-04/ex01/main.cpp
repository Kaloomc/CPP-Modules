/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:07:01 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 16:20:08 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

const int ARRAY_SIZE = 4;

int main()
{
    std::cout << "=========================================================" << std::endl;
    std::cout << "1. TEST DU TABLEAU D'ANIMAUX (EXIGENCE DU SUJET)" << std::endl;
    std::cout << "=========================================================\n" << std::endl;
    
    Animal* animals[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i < ARRAY_SIZE / 2) {
            std::cout << "--- Création d'un Dog (Index " << i << ") ---" << std::endl;
            animals[i] = new Dog();
        } else {
            std::cout << "--- Création d'un Cat (Index " << i << ") ---" << std::endl;
            animals[i] = new Cat();
        }
    }

    std::cout << "\n[ Tableau rempli. Début de la phase de destruction ]\n" << std::endl;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "--- Suppression de l'animal (Index " << i << ") ---" << std::endl;
        delete animals[i];
    }

    std::cout << "\n=========================================================" << std::endl;
    std::cout << "2. TESTS DE COPIE PROFONDE (DEEP COPY)" << std::endl;
    std::cout << "=========================================================\n" << std::endl;

    std::cout << "--- A. Test avec le Constructeur par copie ---" << std::endl;
    Dog* dogA = new Dog();
    
    std::cout << "\n[ Copie de dogA vers dogB ]" << std::endl;
    Dog* dogB = new Dog(*dogA);

    std::cout << "\n[ Destruction de dogA ]" << std::endl;
    delete dogA; 

    std::cout << "\n[ Destruction de dogB ]" << std::endl;
    delete dogB; 

    std::cout << "\n--- B. Test avec l'Opérateur d'affectation ---" << std::endl;
    Cat catA;
    Cat catB;

    std::cout << "\n[ Affectation de catA à catB (catB = catA) ]" << std::endl;
    catB = catA;

    std::cout << "\n[ Fin du programme. Destruction de catA et catB sur la pile ]" << std::endl;
    return 0;
}