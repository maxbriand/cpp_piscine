/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:11:33 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 20:14:59 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm*	Intern::makeForm(const std::string name_form, const std::string target)
{
	const std::string 	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	i;

	i = 0;
	while (i < 3)
	{
		if (forms[i] == name_form)
			break;
		i++;		
	}
	if (i == 3)
	{
		std::cout << "Intern cannot creates this form" << std::endl;
		return (0);
	}
	std::cout << "Intern creates " << forms[i] << "!" << std::endl;
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
	}
	return (0);
}

Intern::Intern(){}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern& Intern::operator=(const Intern& other)
{
	if (&other == this)
		return (*this);
	return (*this);
}

Intern::~Intern(){}
