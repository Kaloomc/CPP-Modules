/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:19:51 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/18 01:01:14 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <iomanip>

void ScalarConverter::convert(const std::string& str)
{

	std::string char_;
	int int_;
	float float_;
	double double_;
	int c = 0;

	if (str.length() == 1 && !std::isdigit(str[0]))
    	c = str[0];

	if (str.length() == 1 && std::isdigit(str[0]))
    	c = atoi(&str[0]);

	if (static_cast<char>(c) == 0)
		char_ = "Non displayable";
	else
		char_ = static_cast<char>(c);
	int_ = static_cast<int>(c);
	float_ = static_cast<float>(c);
	double_ = static_cast<double>(c);

	std::cout << "char: " << char_ << "\n";
	std::cout << "int: " << int_ << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << float_ << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1)<< double_ << "\n";
	
}