/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:10:03 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/02 16:27:31 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation",145,137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if(this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned()) 
    {
        throw AForm::FormNotSignedException(); 
    }

    if (executor.getGrade() > this->getRequireGradeToExecute())
    {
        throw AForm::GradeTooLowException();
    }
	std::ofstream File((this->_target + "_shrubbery").c_str());

	if (File.is_open())
	{
		File << "          ccee88oo\n"
			<< "      C8O8O8Q8PoOb o8oo\n"
			<< "     dOB69QO8PdUOpugoO9bD\n"
			<< "    CgggbU8OU qOp qOdoUOdcb\n"
			<< "        6OuU  /p u gcoUodpP\n"
			<< "          \\\\\\//  /douUP\n"
			<< "            \\\\\\////\n"
			<< "             |||/\\\n"
			<< "             |||\\/\n"
			<< "             |||||\n"
			<< "       .....//|||\\\\....\n";
		
		File.close();
	}
	else
	{
		std::cerr << "Erreur : Impossible de créer le fichier." << std::endl;
	}
}