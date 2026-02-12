/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:34:23 by fgarnier          #+#    #+#             */
/*   Updated: 2026/02/12 00:47:30 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string a = "HI THIS IS BRAIN";
	std::string *stringPTR = &a;
	std::string &stringREF = a;

	std::cout << "Memory address \"a\": " << &a << std::endl
			<< "Memory address \"stringPTR\": " << stringPTR << std::endl
			<< "Memory address \"stringREF\": " << &stringREF << std::endl << std::endl;
	std::cout << "Value \"a\": " << a << std::endl
			<< "Value \"stringPTR\": " << *stringPTR << std::endl
			<< "Value \"stringREF\": " << stringREF << std::endl;
}