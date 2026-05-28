/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:07:01 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 15:11:12 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== 1. TESTS DU SUJET (POLYMORPHISME) ===" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound(); 
        j->makeSound(); 
        meta->makeSound(); 

        delete meta;
        delete j;
        delete i;
    }

    std::cout << "\n=== 2. TESTS COMPLÉMENTAIRES (SUR LA PILE / STACK) ===" << std::endl;
    {
        Animal genericAnimal;
        Dog    myDog;
        Cat    myCat;

        std::cout << "Type: " << genericAnimal.getType() << " -> ";
        genericAnimal.makeSound();

        std::cout << "Type: " << myDog.getType() << " -> ";
        myDog.makeSound();

        std::cout << "Type: " << myCat.getType() << " -> ";
        myCat.makeSound();
    }

    std::cout << "\n=== 3. TESTS DE LA FORME CANONIQUE (COPIE & AFFECTATION) ===" << std::endl;
    {
        Dog originalDog;
        std::cout << "Création d'une copie par constructeur de copie :" << std::endl;
        Dog copyDog(originalDog);
        
        Cat originalCat;
        Cat assignedCat;
        std::cout << "Test de l'opérateur d'affectation :" << std::endl;
        assignedCat = originalCat;
    }

    std::cout << "\n=== 4. TESTS DU CAS \"WRONG\" (SANS VIRTUAL) ===" << std::endl;
    {
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        std::cout << "Type: " << wrongCat->getType() << " " << std::endl;


        wrongCat->makeSound(); 
        wrongMeta->makeSound();

        delete wrongMeta;
        delete wrongCat;
    }

    return 0;
}