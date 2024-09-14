/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:32:46 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/13 13:48:09 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("default type"){}

AMateria::AMateria(const std::string& type) : _type(type){}

AMateria::AMateria(const AMateria& src)
{
    *this = src;
}

AMateria&   AMateria::operator=(const AMateria& src)
{
    _type = src._type;
    return (*this);
}

AMateria::~AMateria(){};

const std::string& AMateria::getType(void) const
{
    return (_type);
}

void use(ICharacter& target)
{
    std::cout << "* default message*" << std::endl;
}

