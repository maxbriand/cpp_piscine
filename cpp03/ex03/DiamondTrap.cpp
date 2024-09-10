/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:40:18 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/10 14:29:40 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	_name = ClapTrap::_name;
	ClapTrap::_name = _name + "_clap_name";
	FragTrap::_hit_points = 100;
	FragTrap::_attack_damage = 30;
	_energy_points = ScavTrap::_energy_points;
}

DiamondTrap::DiamondTrap(std::string name) 
{
	std::cout << "DiamondTrap String constructor called" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	_name = name;
	FragTrap::_hit_points = 100;
	FragTrap::_attack_damage = 30;
	_energy_points = ScavTrap::_energy_points;
}

DiamondTrap::DiamondTrap(const DiamondTrap& src): ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = src;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	_name = src._name;
	ClapTrap::_name = src._name + "_clap_name";
	FragTrap::_hit_points = src._hit_points;
	FragTrap::_attack_damage = src._attack_damage;
	_energy_points = src._energy_points;
	return (*this);
}

DiamondTrap::~DiamondTrap(void) 
{
	std::cout << "DiamondTrap Destructor called" << std::endl;		
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "Am I: " << getName() << " or am I: " << ClapTrap::getName() <<std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (_name);
}
