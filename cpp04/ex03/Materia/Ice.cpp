/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:53:06 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/15 13:53:05 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	_type = "ice";
}

Ice::Ice(const Ice& src) : AMateria(src)
{
	*this = src;
}

Ice::~Ice(void){}

Ice&	Ice::operator=(const Ice& src)
{
	this->_type = src._type;
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	AMateria* dest = new Ice(*this);
	return (dest);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
