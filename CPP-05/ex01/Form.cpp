/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:39:32 by fgarnier          #+#    #+#             */
/*   Updated: 2026/06/17 21:58:20 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), signed_(false), requireGradeToSign(150), requireGradeToExecute(150) {}

Form::Form(std::string name_, int requireGradeToSign_, int requireGradeToExecute_)
	: name(name_), signed_(false), requireGradeToSign(requireGradeToSign_), requireGradeToExecute(requireGradeToExecute_) {
	if (requireGradeToSign < 1 || requireGradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (requireGradeToSign > 150 || requireGradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src)
	: name(src.name), signed_(src.signed_), requireGradeToSign(src.requireGradeToSign), requireGradeToExecute(src.requireGradeToExecute) {}

Form& Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		this->signed_ = rhs.signed_;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return name; }

bool Form::getSigned() const { return signed_; }

int Form::getRequireGradeToSign() const { return requireGradeToSign; }

int Form::getRequireGradeToExecute() const { return requireGradeToExecute; }

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > requireGradeToSign)
		throw Form::GradeTooLowException();
	signed_ = true;
}

std::ostream& operator<<(std::ostream& o, const Form& i) {
	o << "Form " << i.getName() << ", signed: " << (i.getSigned() ? "yes" : "no") 
	  << ", requires grade " << i.getRequireGradeToSign() << " to sign, and grade " 
	  << i.getRequireGradeToExecute() << " to execute.";
	return o;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}
