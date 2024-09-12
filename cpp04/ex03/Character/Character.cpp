/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:14 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/12 23:22:39 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("default_name"){}

Character::Character(std::string name) : _name(name){}

Character::~Character(void){}

Character::Character(const Character& src)
{
    *this = src;
}

Character& Character::operator=(const Character& src)
{
    this->_name = src._name;
    this->
}

const std::string& 	Character::getName(void) const
{
    return (_name);
}

void    Character::equip(AMateria* m)
{}

void    Character::unequip(int idx)
{}

void    Character::use(int idx, ICharacter& target)
{
    
}
