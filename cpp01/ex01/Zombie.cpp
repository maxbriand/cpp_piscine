/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:41:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/31 23:19:47 by mbriand          ###   ########.fr       */
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

void	Zombie::announce(void)
{
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;	
}
