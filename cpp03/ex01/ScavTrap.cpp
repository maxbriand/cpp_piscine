/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:18:44 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/08 21:59:20 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) 
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) 
{
	std::cout << "ScavTrap String constructor called" << std::endl;
	
	_name = name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_attack_damage = src._attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap(void) 
{
	std::cout << "ScavTrap Destructor called" << std::endl;		
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;	
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energy_points && _hit_points )
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << \
				this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points -= 1;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " doesn't has enough hit or energy points to attack"\
				<< std::endl ;		
	}
}

