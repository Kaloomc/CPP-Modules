/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:39:32 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/28 16:59:45 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), signed_(false), requireGradeToSign(150), requireGradeToExecute(150) {}

AForm::AForm(std::string name_, int requireGradeToSign_, int requireGradeToExecute_)
	: name(name_), signed_(false), requireGradeToSign(requireGradeToSign_), requireGradeToExecute(requireGradeToExecute_) {
	if (requireGradeToSign < 1 || requireGradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (requireGradeToSign > 150 || requireGradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src)
	: name(src.name), signed_(src.signed_), requireGradeToSign(src.requireGradeToSign), requireGradeToExecute(src.requireGradeToExecute) {}

AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs) {
		this->signed_ = rhs.signed_;
	}
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return name; }

bool AForm::getSigned() const { return signed_; }

int AForm::getRequireGradeToSign() const { return requireGradeToSign; }

int AForm::getRequireGradeToExecute() const { return requireGradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > requireGradeToSign)
		throw AForm::GradeTooLowException();
	signed_ = true;
}

std::ostream& operator<<(std::ostream& o, const AForm& i) {
	o << "AForm " << i.getName() << ", signed: " << (i.getSigned() ? "yes" : "no") 
	  << ", requires grade " << i.getRequireGradeToSign() << " to sign, and grade " 
	  << i.getRequireGradeToExecute() << " to execute.";
	return o;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed.";
}