/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:34:05 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 20:12:25 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): \
	AForm("shrubbery creation", target, 145, 137){}

void	ShrubberyCreationForm::beSigned(const Bureaucrat& b)
{
	try 
	{
		if (b.getGrade() <= _signature_grade ){
			_is_signed = 1; std::cout << b.getName() << \
				" has signed a ShrubberyCreationForm!" << std::endl;}		
		else
			throw (AForm::GradeTooLowException());
	}
	catch (...)
	{
		std::cout << b.getName() << " cannot sign the ShrubberyCreationForm" << std::endl;
	}
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::string	file_name;

	file_name = _target + "_shrubbery";
	try 
	{
		if (_is_signed == 0)
			throw AForm::NotSignedException();
		else if (executor.getGrade() > _execution_grade)
			throw AForm::GradeTooLowException();
		std::cout << executor.getName() << " executed " << this->getName() << "!" << std::endl;
		std::ofstream file(file_name.c_str());
		if (file.is_open())
		{
			file << "       ^             ^\n";
			file << "      ^^^           ^^^\n";
			file << "     ^^^^^         ^^^^^\n";
			file << "    ^^^^^^^       ^^^^^^^\n" ;
			file << "      |||           |||\n";
			file << "      |||           |||\n";
			file.close();
		}
		else
		{
			std::cerr << "Failed to open the file!" << std::endl;
		}
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
