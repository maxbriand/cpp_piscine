/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:33 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/10 16:19:43 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;	
	this->_type = src._type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;	
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "~Animal sound~" << std::endl;
}
