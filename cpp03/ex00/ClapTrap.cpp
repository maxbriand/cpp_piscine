/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:08:00 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/08 14:07:08 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Noname"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "String constructor called" << std::endl;	
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout << "Copy constructor called" << std::endl;	
	*this = src;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = src._name;
	this->_attack_damage = src._attack_damage;
	this->_energy_points = src._energy_points;
	this->_hit_points = src._hit_points;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;		
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy_points && _hit_points )
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << \
				this->_attack_damage << " points of damage!" << std::endl;
		this->_energy_points -= 1;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " doesn't has enough hit or energy points to attack"\
				<< std::endl ;		
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " is taking " << amount \
				<< " points of damage!" << std::endl;		
		if (amount > _hit_points)
			_hit_points = 0;
		else
			_hit_points -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << "already has 0 hit points, he cannot lose more hit points"\
				<< std::endl;
	}	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points && _hit_points)
	{
		std::cout << "ClapTrap " << this->_name << " repairs himself of " << amount << " hit points" \
				<< std::endl;
		_energy_points -= 1;
		_hit_points += amount;	
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " doesn't has enough hit or energy points to repair itself"\
				<< std::endl ;
	}
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return(_energy_points);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return(_hit_points);
}

void	ClapTrap::setHitPoints(unsigned int amount)
{
	_hit_points = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	_energy_points = amount;
}
