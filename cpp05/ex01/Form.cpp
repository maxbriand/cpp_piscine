/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:15:51 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/18 23:08:15 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default_form"), _is_signed(0), _signature_grade(3), _execution_grade(2){}

Form::~Form(){}

Form::Form(const Form& src) : _name(src._name), _signature_grade(src._signature_grade), \
								_execution_grade(src._execution_grade)
{
	*this = src;
}

Form&	Form::operator=(const Form& src)
{
	this->_is_signed = src._is_signed;
	return (*this);
}

Form::Form(const std::string name) : _name(name), _is_signed(0), _signature_grade(1), _execution_grade(2){}

std::string	Form::getName() const	
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_is_signed);
}

int	Form::getSignatureGrade() const
{
	return (_signature_grade);
}

int	Form::getSignatureExecution() const
{
	return (_execution_grade);
}

void	Form::beSigned(const Bureaucrat& b)
{
	try
	{
		if (b.getGrade() > getSignatureGrade())
			throw Form::GradeTooLowException();
		_is_signed = 1;
	}
	catch (...)
	{
		std::cout << b.getName() << " has a grade too low to sign!" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Form& src)
{
	o << src.getName() << " form of signature grade: " << src.getSignatureGrade() << ", of execution grade: ";
	o << src.getSignatureExecution() << ", and of status: ";
	if (src.getIsSigned())
		o << "SIGNED";
	else
		o << "NOT SIGNED";
	return (o);
}
