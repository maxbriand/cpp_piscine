/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:42:46 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 19:39:03 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& club)
{
    this->set_name(name);
    this->setWeapon(club);
}

HumanA::~HumanA(void){}

void    HumanA::attack(void)
{
    Weapon my_weapon;

    my_weapon = this->getWeapon();
    std::cout << this->get_name() << " attacks with their " << 
        my_weapon.getType() << std::endl;
}

void    HumanA::set_name(std::string name)
{
    this->_name = name;
}

std::string HumanA::get_name(void)
{
    return (this->_name);
}

void    HumanA::setWeapon(Weapon& player_weapon)
{
    this->_player_weapon = player_weapon;
}

Weapon&  HumanA::getWeapon(void)
{
    return (this->_player_weapon);
}
