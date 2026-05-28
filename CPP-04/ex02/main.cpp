/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:07:01 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/27 16:15:04 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- TEST EXERCICE 02 : CLASSE ABSTRAITE ---" << std::endl;
 
    //Animal a;
    //Animal* b = new Animal();


    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "Si ça compile, c'est que l'instanciation de Animal est bien commentée !" << std::endl;
    
    j->makeSound();
    i->makeSound();

    delete j;
    delete i;

    return 0;
}