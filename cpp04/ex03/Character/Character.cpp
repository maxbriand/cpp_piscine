/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:08:14 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/15 21:20:44 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("default_name")
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}

Character::Character(const Character& src)
{
	*this = src;
}

Character::~Character(void)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		if (_inventory[i])
			unequip(i);
		i++;
	}
}

Character&	Character::operator=(const Character& src)
{
	int	i;

	if (this == &src)
		return (*this);
	i = 0;
	while (i < 4)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i];
		i++;
	}
	_name = src._name;
	return (*this);
}

Character::Character(std::string name) : _name(name)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		_inventory[i] = NULL;
		i++;
	}
}

const std::string&	Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (_inventory[i] && _inventory[i] == m)
			return ;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break ;
		}
		i++;
	}
}

void	Character::unequip(int idx)
{
	if (_inventory[idx])
	{
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{	
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "empty inventory at this index" << std::endl;
}
