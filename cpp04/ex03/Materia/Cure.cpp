/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:53:20 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/12 23:05:32 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	_type = "cure";
}

Cure::Cure(const Cure& src)
{
	*this = src;
}

Cure&   Cure::operator=(const Cure& src)
{
	this->_type = src._type;
	return (*this);
}

Cure::~Cure(void){}

AMateria*   Cure::clone(void) const
{
	Cure	new_elem = *this;
	return (&new_elem);
}