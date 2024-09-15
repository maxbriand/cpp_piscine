/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:32:46 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/15 20:16:08 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default type"){}


AMateria::AMateria(const AMateria& src)
{
    *this = src;
}

AMateria&   AMateria::operator=(const AMateria& src)
{
    _type = src._type;
	return (*this);
}

AMateria::~AMateria(){}

AMateria::AMateria(const std::string& type) : _type(type){}

const std::string& AMateria::getType(void) const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* default message at *" << target.getName() << std::endl;
}
