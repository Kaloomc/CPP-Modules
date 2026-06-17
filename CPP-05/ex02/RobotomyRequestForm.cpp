/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:29:18 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/17 21:46:18 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45) , _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request", 72, 45) , _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const  RobotomyRequestForm& rhs)
{
	if(this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(!this->getSigned())
		throw AForm::FormNotSignedException();
	if(executor.getGrade() > this->getRequireGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "* SOME DRILLING NOISES *" << std::endl;

	if(rand() % 2 == 1)
		std::cout << this->_target << " has been robotomized successfully !" << std::endl;
	else	
		std::cout << "robotomy failed on "  << this->_target<<  std::endl;
}