/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:53:20 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/15 19:28:50 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	_type = "cure";
}

Cure::Cure(const Cure& src) : AMateria(src)
{
	*this = src;
}

Cure::~Cure(void){}

Cure&	Cure::operator=(const Cure& src)
{
	this->_type = src._type;
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	AMateria* dest = new Cure(*this);
	return (dest);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
