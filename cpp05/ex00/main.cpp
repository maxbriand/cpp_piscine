/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:44:37 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/18 23:11:08 by mbriand          ###   ########.fr       */
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
	
	
	return (0);
}