/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:18:26 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 18:15:02 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": is destroyed" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

std::string	Zombie::get_name(void)
{
	return (this->_name);	
}

void Zombie::announce(void)
{
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;	
}
