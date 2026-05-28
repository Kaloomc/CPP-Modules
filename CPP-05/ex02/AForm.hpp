/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:29:57 by fgarnier          #+#    #+#             */
/*   Updated: 2026/05/28 16:38:58 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool signed_;
	const int requireGradeToSign;
	const int requireGradeToExecute;
	
public:
	AForm();
	AForm(std::string name_,int requireGradeToSign_,int requireGradeToExecute);
	AForm(const AForm& src);
	AForm& operator=(const AForm& rhs);
	~AForm();

	std::string getName() const;
	bool getSigned() const;
	int getRequireGradeToSign() const;
	int getRequireGradeToExecute() const;

	void beSigned(const Bureaucrat& b);

	virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& o, const AForm& i);

#endif