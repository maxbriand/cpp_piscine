/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:42:46 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 23:34:05 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& club) : _weapon(club), _name(name){}

HumanA::~HumanA(void){}

// should I use a const for this function?
void    HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}
