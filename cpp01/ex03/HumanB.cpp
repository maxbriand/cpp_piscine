/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:42:34 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 19:34:28 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->set_name(name);
}

HumanB::~HumanB(void){}

void    HumanB::attack(void)
{
    Weapon my_weapon;

    my_weapon = this->getWeapon();
    std::cout << this->get_name() << " attacks with their " << 
        my_weapon.getType() << std::endl; 
}

void    HumanB::set_name(std::string name)
{
    this->_name = name;
}

std::string HumanB::get_name(void)
{
    return (this->_name);
}

void    HumanB::setWeapon(Weapon& player_weapon)
{
    this->_player_weapon = player_weapon;
}

Weapon&  HumanB::getWeapon(void)
{
    return (this->_player_weapon);
}

