/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:02:35 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/08 22:14:37 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) 
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) 
{
	std::cout << "FragTrap String constructor called" << std::endl;
	
	_name = name;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	_name = src._name;
	_hit_points = src._hit_points;
	_energy_points = src._energy_points;
	_attack_damage = src._attack_damage;
	return (*this);
}

FragTrap::~FragTrap(void) 
{
	std::cout << "FragTrap Destructor called" << std::endl;		
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << _name << " requests a high fives!"<< std::endl;	
}
