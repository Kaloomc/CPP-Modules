/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:19:05 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/02 14:24:23 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "===== INITIALISATION DES BUREAUCRATES =====" << std::endl;
    Bureaucrat boss("Hermes", 1);       // Peut tout faire
    Bureaucrat assistant("Bob", 40);     // Grade moyen
    Bureaucrat intern("Stagiaire", 150); // Ne peut rien faire [cite: 131]
    
    std::cout << boss << std::endl;      // Test de l'opérateur << [cite: 150]
    std::cout << assistant << std::endl;
    std::cout << intern << std::endl;
    std::cout << std::endl;

    std::cout << "===== TEST 1 : SHRUBBERY CREATION FORM =====" << std::endl;
    std::cout << "--> Requis: Sign 145, Exec 137" << std::endl;
    {
        ShrubberyCreationForm shrub("home");
        
        intern.executeForm(shrub);
        intern.signForm(shrub);  
        boss.signForm(shrub);
        assistant.executeForm(shrub);
    }
    std::cout << std::endl;

    std::cout << "===== TEST 2 : ROBOTOMY REQUEST FORM =====" << std::endl;
    std::cout << "--> Requis: Sign 72, Exec 45" << std::endl;
    {
        RobotomyRequestForm robot("Bender");
        
        assistant.signForm(robot);
        
        assistant.executeForm(robot); 
        
        boss.executeForm(robot);
        boss.executeForm(robot);
    }
    std::cout << std::endl;

    std::cout << "===== TEST 3 : PRESIDENTIAL PARDON FORM =====" << std::endl;
    std::cout << "--> Requis: Sign 25, Exec 5" << std::endl;
    {
        PresidentialPardonForm pardon("Arthur Dent");
        
        assistant.signForm(pardon); // Grade 40 < 25 -> Échec de signature ! [cite: 176, 177, 182]
        
        boss.signForm(pardon);      // Grade 1 >= 25 -> Réussite [cite: 175, 177, 180]
        
        assistant.executeForm(pardon); // Grade 40 < 5 -> Échec d'exécution ! [cite: 209, 213, 216]
        
        boss.executeForm(pardon);      // Grade 1 >= 5 -> Réussite ! [cite: 208, 213, 215]
    }

    return 0;
}