/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:09 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 22:48:13 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): \
	AForm("RobotomyRequestForm", target, 72, 45){}

void	RobotomyRequestForm::beSigned(const Bureaucrat& b)
{
	try 
	{
		if (b.getGrade() <= _signature_grade ){
			_is_signed = 1; std::cout << b.getName() << \
				" has signed a RobotomyRequestForm!" << std::endl;}		
		else
			throw (AForm::GradeTooLowException());
	}
	catch (...)
	{
		std::cout << b.getName() << " cannot sign the RobotomyRequestForm" << std::endl;
	}
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	int random_value;
	
	random_value = 0;
	try 
	{
		if (_is_signed == 0)
			throw AForm::NotSignedException();
		else if (executor.getGrade() > _execution_grade)
			throw AForm::GradeTooLowException();
		std::cout << "* drilling noise*" << std::endl;	
		std::srand(std::time(0));
		random_value = std::rand() % 2;
		if (random_value == 0)
			std::cout << _target << " has been robotomized!" << std::endl;
		else
			std::cout << "The robotomy failed!" << std::endl;
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
