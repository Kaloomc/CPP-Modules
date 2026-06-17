/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:19:05 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/17 22:37:50 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Test des grades valides ---" << std::endl;
    try {
        Bureaucrat hercules("Hercules", 2);
        std::cout << hercules << std::endl;
        hercules.incrementGrade();
        std::cout << "Après incrémentation : " << hercules << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Trop Haut (Instanciation) ---" << std::endl;
    try {
        Bureaucrat boss("The Boss", 0);
    }
    catch (std::exception& e) {
        std::cerr << "Exception capturée : " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Trop Bas (Incrémentation) ---" << std::endl;
    try {
        Bureaucrat stagiaire("Stagiaire", 149);
        stagiaire.decrementGrade();
        std::cout << stagiaire << std::endl;
        stagiaire.decrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception capturée : " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Forme Canonique ---" << std::endl;
    Bureaucrat original("Alice", 42);
    Bureaucrat copy(original);
    Bureaucrat assigned("Bob", 100);
    assigned = original;
    
    std::cout << "Original : " << original << std::endl;
    std::cout << "Copy     : " << copy << std::endl;
    std::cout << "Assigned : " << assigned << std::endl;

    return 0;
}