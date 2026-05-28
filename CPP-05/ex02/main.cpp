/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:19:05 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/28 17:31:55 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    std::cout << "\n--- Test Formulaire (Instanciation) ---" << std::endl;
    try {
        Form f1("Form1", 0, 50);
    } catch (std::exception& e) {
        std::cerr << "Exception capturée f1: " << e.what() << std::endl;
    }

    try {
        Form f2("Form2", 50, 151);
    } catch (std::exception& e) {
        std::cerr << "Exception capturée f2: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test Formulaire Signatures ---" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        Bureaucrat intern("Intern", 150);
        Form taxForm("TaxForm", 50, 50);

        std::cout << taxForm << std::endl;

        intern.signForm(taxForm);
        std::cout << taxForm << std::endl;

        ceo.signForm(taxForm);
        std::cout << taxForm << std::endl;
        
        ceo.signForm(taxForm);
    } catch (std::exception& e) {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

    return 0;
}