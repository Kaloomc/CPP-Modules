/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:15:37 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/02 17:19:47 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    std::cout << "==================================================" << std::endl;
    std::cout << "         PHASE 1 : EMBAUCHE DU PERSONNEL          " << std::endl;
    std::cout << "==================================================" << std::endl;
    
    Intern      someRandomIntern;
    Bureaucrat  boss("Hermes Vigor", 1);
    Bureaucrat  bureaucrateMoyen("Bob", 50);
    
    std::cout << boss << std::endl;
    std::cout << bureaucrateMoyen << std::endl;
    std::cout << std::endl;

    std::cout << "==================================================" << std::endl;
    std::cout << "     PHASE 2 : LE STAGIAIRE ET LES FORMULAIRES    " << std::endl;
    std::cout << "==================================================" << std::endl;
    
    AForm* rrf;
    AForm* scf;
    AForm* ppf;
    AForm* unknown;

    std::cout << "[Test Robotomy Request]" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << std::endl;

    std::cout << "[Test Shrubbery Creation]" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Cour de récréation");
    std::cout << std::endl;

    std::cout << "[Test Presidential Pardon]" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Fry");
    std::cout << std::endl;

    std::cout << "[Test Formulaire Inconnu]" << std::endl;
    unknown = someRandomIntern.makeForm("pass sanitaire", "Tout le monde");
    if (unknown)
    {
        boss.signForm(*unknown);
        delete unknown;
    }
    std::cout << std::endl;

    std::cout << "==================================================" << std::endl;
    std::cout << "     PHASE 3 : SIGNATURE ET EXÉCUTION DES FORMS   " << std::endl;
    std::cout << "==================================================" << std::endl;

    if (rrf)
    {
        std::cout << "\n--- Traitement de : " << rrf->getName() << " ---" << std::endl;
        bureaucrateMoyen.signForm(*rrf);
        bureaucrateMoyen.executeForm(*rrf);
        boss.executeForm(*rrf);
    }

    if (scf)
    {
        std::cout << "\n--- Traitement de : " << scf->getName() << " ---" << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf);
    }

    if (ppf)
    {
        std::cout << "\n--- Traitement de : " << ppf->getName() << " ---" << std::endl;
        boss.executeForm(*ppf);
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
    }

    std::cout << "\n==================================================" << std::endl;
    std::cout << "         PHASE 4 : NETTOYAGE DE LA MÉMOIRE        " << std::endl;
    std::cout << "==================================================" << std::endl;

    delete rrf;
    delete scf;
    delete ppf;

    std::cout << "Nettoyage effectué avec succès. Fin des tests." << std::endl;
    return 0;
}