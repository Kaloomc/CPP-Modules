/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:01:42 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/19 15:13:32 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::srand(std::time(NULL));

    std::cout << "--- 1. TEST DU SUJET ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span : " << sp.shortestSpan() << " (Attendu: 2)" << std::endl;
        std::cout << "Longest Span  : " << sp.longestSpan() << " (Attendu: 14)" << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n--- 2. TEST DES EXCEPTIONS (Capacite depassee) ---" << std::endl;
    try {
        Span sp_full(2);
        sp_full.addNumber(1);
        sp_full.addNumber(2);
        std::cout << "Ajout du 3eme element..." << std::endl;
        sp_full.addNumber(3); // Doit throw
    } 
    catch (std::exception &e) {
        std::cerr << "Exception attrapee avec succes : " << e.what() << std::endl;
    }

    std::cout << "\n--- 3. TEST DES EXCEPTIONS (Pas assez d'elements) ---" << std::endl;
    try {
        Span sp_empty(5);
        sp_empty.addNumber(42);
        std::cout << "Tentative de calcul de span avec 1 seul element..." << std::endl;
        std::cout << sp_empty.shortestSpan() << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Exception attrapee avec succes : " << e.what() << std::endl;
    }

    std::cout << "\n--- 4. TEST DES 10 000 ELEMENTS (Performance) ---" << std::endl;
    try {
        Span big_sp(10000);
        for (int i = 0; i < 10000; ++i) {
            big_sp.addNumber(std::rand() % 1000000);
        }
        std::cout << "10 000 nombres ajoutes." << std::endl;
        std::cout << "Shortest Span : " << big_sp.shortestSpan() << std::endl;
        std::cout << "Longest Span  : " << big_sp.longestSpan() << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    std::cout << "\n--- 5. TEST DE LA PLAGE D'ITERATEURS ---" << std::endl;
    try {
        std::vector<int> vec;
        for (int i = 0; i < 15; ++i) {
            vec.push_back(i * 10);
        }

        Span iter_sp(20);
        iter_sp.addNumber(vec.begin(), vec.end());
        
        std::cout << "Nombres ajoutes via iterateurs depuis un std::vector." << std::endl;
        std::cout << "Shortest Span : " << iter_sp.shortestSpan() << " (Attendu: 10)" << std::endl;
        std::cout << "Longest Span  : " << iter_sp.longestSpan() << " (Attendu: 140)" << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}