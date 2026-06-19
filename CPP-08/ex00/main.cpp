/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:06:49 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 14:02:21 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // ---------------------------------------------------
    // TEST 1 : std::vector
    // ---------------------------------------------------
    std::cout << "=== Test avec std::vector ===" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i * 10); // Ajoute : 0, 10, 20, 30, 40
    }

    try {
        // Cas qui fonctionne
        std::cout << "Recherche de 20 : ";
        std::vector<int>::iterator it1 = easyfind(vec, 20);
        std::cout << "Succès ! Valeur trouvée : " << *it1 << std::endl;

        // Cas qui déclenche l'exception
        std::cout << "Recherche de 42 : ";
        easyfind(vec, 42); 
        std::cout << "Cette ligne ne devrait pas s'afficher." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée -> " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // ---------------------------------------------------
    // TEST 2 : std::list
    // ---------------------------------------------------
    std::cout << "=== Test avec std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(4);
    lst.push_back(8);
    lst.push_back(15);
    lst.push_back(16);
    lst.push_back(23);
    lst.push_back(42);

    try {
        // Cas qui fonctionne
        std::cout << "Recherche de 42 : ";
        std::list<int>::iterator it2 = easyfind(lst, 42);
        std::cout << "Succès ! Valeur trouvée : " << *it2 << std::endl;

        // Cas qui déclenche l'exception
        std::cout << "Recherche de 99 : ";
        easyfind(lst, 99);
    } catch (const std::exception& e) {
        std::cerr << "Exception attrapée -> " << e.what() << std::endl;
    }

    return 0;
}