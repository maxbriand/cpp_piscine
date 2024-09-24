/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:33:56 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 16:36:41 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): \
	AForm("PresidentialPardonForm", target, 25, 5){}

void	PresidentialPardonForm::beSigned(const Bureaucrat& b)
{
	try 
	{
		if (b.getGrade() <= _signature_grade ){
			_is_signed = 1; std::cout << b.getName() << \
				" has signed a PresidentialPardonForm!" << std::endl;}		
		else
			throw (AForm::GradeTooLowException());
	}
	catch (...)
	{
		std::cout << b.getName() << " cannot sign the PresidentialPardonForm" << std::endl;
	}
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	try 
	{
		if (_is_signed == 0)
			throw AForm::NotSignedException();
		else if (executor.getGrade() > _execution_grade)
			throw AForm::GradeTooLowException();
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
	}
	catch (AForm::NotSignedException& e)
	{
		std::cout << executor.getName() << " cannot execute the form because it's not signed!"<< std::endl;
	}
	catch (...)
	{
		std::cout << executor.getName() << " cannot execute the form because his level is too low!"<< std::endl;		
	}
}
