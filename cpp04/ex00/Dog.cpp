/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:40:23 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 15:17:22 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;	
	_type = "Dog";
}

Dog::Dog(const Dog& src): Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;	
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog Copy assignent operator called" << std::endl;
	this->_type = src._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouuuuf!" << std::endl;	
}
