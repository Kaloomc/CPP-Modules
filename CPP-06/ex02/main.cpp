/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:08:21 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/18 16:37:21 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Base * generate(void)
{
	Base *generated;
	switch (rand() % 3)
	{
	case 0:
		generated = new A;
		break;
	case 1:
		generated = new B;
		break;
	case 2:
		generated = new C;
		break;
	}
	return generated;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified : A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "Identified : B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "Identified : C\n";
}

void identify(Base& p)
{
	try {
        
        (void)dynamic_cast<A&>(p);
		std::cout << "Identified : A\n";
    } 
    catch (...) {}
	try {
        
        (void)dynamic_cast<B&>(p);
		std::cout << "Identified : B\n";
    } 
    catch (...) {}
	try {
        
        (void)dynamic_cast<C&>(p);
		std::cout << "Identified : C\n";
    } 
    catch (...) {}
}

int main()
{

	Base *ptrA = new A;
	Base *ptrB = new B;
	Base *ptrC = new C;

	A a;
	B b;
	C c;

	Base &refA = a;
	Base &refB = b;
	Base &refC = c;
	
	std::srand (time(NULL));
	
	identify(ptrA);
	identify(ptrB);
	identify(ptrC);
	
	identify(refA);
	identify(refB);
	identify(refC);
	
	identify(generate());
	
	delete ptrA;
	delete ptrB;
	delete ptrC;
}