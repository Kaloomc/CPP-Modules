/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 18:10:03 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/17 22:00:25 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation",145,137) , _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation",145,137) , _target(target) {}

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

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Error: Unable to open the target file.";
}

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
	std::ofstream outfile((this->_target + "_shrubbery").c_str());

	if (outfile.is_open())
	{
		outfile << "          ccee88oo\n"
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
		
		outfile.close();
	}
	else
	{
		throw ShrubberyCreationForm::FileOpenException();
	}
}