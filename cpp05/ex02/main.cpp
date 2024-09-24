/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:44:37 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/19 17:09:23 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "colors.hpp"

int	main(void)
{
	std::cout << BBLU << "ShrubberyCreationForm: Default Constructor" << CLR << std::endl;
	AForm* f1 (new ShrubberyCreationForm());
	std::cout << "Is Signed: " << f1->getIsSigned() << " - 0" << std::endl;
	std::cout << "Name: " << f1->getName() << " - ShrubberyCreationForm" << std::endl;
	std::cout << "Signature Grade: " << f1->getSignatureGrade() << " - 145" << std::endl;
	std::cout << "Execution Grade: " << f1->getSignatureExecution() << " - 137" << std::endl;	
	delete f1;

	std::cout << std::endl << BBLU << "ShrubberyCreationForm: Parametized Constructor" << CLR << std::endl;
	ShrubberyCreationForm* f2 (new ShrubberyCreationForm("home"));
	std::cout << "Is Signed: " << f2->getIsSigned() << " - 0" << std::endl;
	std::cout << "Name: " << f2->getName() << " - ShrubberyCreationForm" << std::endl;
	std::cout << "Signature Grade: " << f2->getSignatureGrade() << " - 145" << std::endl;
	std::cout << "Execution Grade: " << f2->getSignatureExecution() << " - 137" << std::endl;	

	std::cout << std::endl << BBLU << "ShrubberyCreationForm: Copy Constructor" << CLR << std::endl;
	ShrubberyCreationForm* f3 (new ShrubberyCreationForm(*f2));
	std::cout << "Is Signed: " << f3->getIsSigned() << " - 0" << std::endl;
	std::cout << "Name: " << f3->getName() << " - ShrubberyCreationForm" << std::endl;
	std::cout << "Signature Grade: " << f3->getSignatureGrade() << " - 145" << std::endl;
	std::cout << "Execution Grade: " << f3->getSignatureExecution() << " - 137" << std::endl;	

	std::cout << std::endl << BBLU << "ShrubberyCreationForm: Operator assignment" << CLR << std::endl;
	f2->beSigned(Bureaucrat("Edward", 150)); // try to blocked the is signed setting 150
	*f3 = *f2;
	std::cout << "Is Signed: " << f3->getIsSigned() << " - 1" << std::endl;
	std::cout << "Name: " << f3->getName() << " - ShrubberyCreationForm" << std::endl;
	std::cout << "Signature Grade: " << f3->getSignatureGrade() << " - 145" << std::endl;
	std::cout << "Execution Grade: " << f3->getSignatureExecution() << " - 137" << std::endl;	
	
	delete f2;
	delete f3;

	std::cout << std::endl << BBLU << "ShrubberyCreationForm: Execution function" << CLR << std::endl;
	ShrubberyCreationForm* f4 (new ShrubberyCreationForm("ascii_tree"));
	f4->beSigned(Bureaucrat("Molly", 1)); // try 150 
	f4->execute(Bureaucrat("Ben", 2)); // try 150
	delete f4;

	std::cout << std::endl << BBLU << "ShrubberyCreationForm: ExecuteForm function" << CLR << std::endl;
	Bureaucrat b1("Ken", 120);
	ShrubberyCreationForm f5("hotel");
	f5.beSigned(b1);
	b1.executeForm(f5);

	std::cout << std::endl << BBLU << "PresidentialCreationForm: ExecuteForm function" << CLR << std::endl;
	Bureaucrat b2("Nils", 2);
	PresidentialPardonForm f6("Zion");
	f6.beSigned(b2);
	b2.executeForm(f6);

	std::cout << std::endl << BBLU << "RobotomyRequestForm: ExecuteForm function" << CLR << std::endl;
	Bureaucrat b3("Manhattan", 4); // test too low level
	RobotomyRequestForm f7("Zion");
	f7.beSigned(b3);
	b3.executeForm(f7);

	std::cout << std::endl << BBLU << "Using AForm* to exec" << CLR << std::endl;
	AForm* f8(new ShrubberyCreationForm("blop"));
	f8->beSigned(b3);
	b3.executeForm(*f8);
	
	delete f8;
	return(0);
}