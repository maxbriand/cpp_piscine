/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:32:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 15:17:38 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;	
	_type = "Cat";
}

Cat::Cat(const Cat& src): Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;	
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat Copy assignent operator called" << std::endl;
	this->_type = src._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaooooou!" << std::endl;	
}
