/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:57:30 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/01 00:03:40 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void){}

Weapon::~Weapon(void){}

void	Weapon::setType(std::string type)
{
	this->_type = type;	
}

const std::string	Weapon::getType(void)
{
	return (this->_type);
}
