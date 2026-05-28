/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:29:57 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/28 16:38:58 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool signed_;
	const int requireGradeToSign;
	const int requireGradeToExecute;
	
public:
	Form();
	Form(std::string name_,int requireGradeToSign_,int requireGradeToExecute);
	Form(const Form& src);
	Form& operator=(const Form& rhs);
	~Form();

	std::string getName() const;
	bool getSigned() const;
	int getRequireGradeToSign() const;
	int getRequireGradeToExecute() const;

	void beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high! Maximum allowed is 1.";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low! Minimum allowed is 150.";
        }
    };
};

std::ostream& operator<<(std::ostream& o, const Form& i);

#endif