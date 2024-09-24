/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:44:37 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 20:32:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	Intern	someRandomIntern;
	AForm*	rrf;
	Bureaucrat ee("sa", 1);
	

	rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
	rrf->beSigned(ee);
	rrf->execute(ee);


	AForm*	rrff;

	rrff = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << rrff->getName() << std::endl;
	
	AForm*	rrfff;

	rrfff = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << rrfff->getName() << std::endl;


	AForm*	dxwsa;

	try 
	{
		dxwsa = someRandomIntern.makeForm("robotomy request", "Bender");
		if (!dxwsa)
			throw std::exception();
		std::cout << dxwsa->getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "This form doesn't exist" << std::endl;
	}
	return(0);
}