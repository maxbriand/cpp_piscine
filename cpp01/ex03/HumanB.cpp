/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:42:34 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 23:46:44 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name){}

HumanB::~HumanB(void){}

void    HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void    HumanB::attack(void) const
{
    std::cout << this->_name << " attacks with their " << 
        this->_weapon->getType() << std::endl; 
}
