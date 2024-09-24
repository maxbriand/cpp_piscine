/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:44:37 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/16 23:09:11 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat* pt_b1(new Bureaucrat());
	std::cout << *pt_b1 << std::endl;
	delete pt_b1;

	Bureaucrat* pt_b2(new Bureaucrat("Britney", 199));
	std::cout << *pt_b2 << std::endl;
	delete pt_b2;

	Bureaucrat* pt_b3(new Bureaucrat("Bob", -1));
	std::cout << *pt_b3 << std::endl;

	Bureaucrat* pt_b4(new Bureaucrat(*pt_b3));
	std::cout << *pt_b4 << std::endl;
	delete pt_b3;

	pt_b4->Promotion();
	delete pt_b4;

	Bureaucrat* pt_b5(new Bureaucrat("Manuel", 150));
	pt_b5->Punition();
	pt_b5->Promotion();
	std::cout << *pt_b5 << std::endl;
	pt_b5->Punition();
	std::cout << *pt_b5 << std::endl;
	pt_b5->Punition();
	delete pt_b5;

	Bureaucrat* pt_b6(new Bureaucrat("Nils", 1));
	Bureaucrat* pt_b7(new Bureaucrat("Brosman", 3));

	std::cout << std::endl << "FORM TESTS" << std::endl << std::endl;
	std::cout << "Default constructor and beSigned" << std::endl;
	Form* f1(new Form());
	std::cout << *f1 << std::endl;
	f1->beSigned(*pt_b7);
	std::cout << *f1 << std::endl;
	f1->beSigned(*pt_b6);
	std::cout << *f1 << std::endl;
	delete f1;

	std::cout << std::endl << "String constructor and signForm" << std::endl;
	Form* f2(new Form("'Paper'"));
	std::cout << *f2 << std::endl;
	f2->beSigned(*pt_b7);
	pt_b7->signForm(*f2);
	f2->beSigned(*pt_b6);
	pt_b6->signForm(*f2);

	std::cout << std::endl << "Copy constructor and signForm" << std::endl;
	Form* f3(new Form(*f2));
	std::cout << *f3 << std::endl;
	Form* f4(new Form());
	*f4 = *f3;
	std::cout << *f4 << std::endl;

	*pt_b6 = *pt_b7;
	f4->beSigned(*pt_b6);

	delete f2; delete f3; delete f4;
	delete pt_b6; delete pt_b7;

	return (0);
}