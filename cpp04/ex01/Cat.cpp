/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:32:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/11 15:07:19 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;	
	_type = "Cat";
	_brain = new Brain;
}

Cat::Cat(const Cat& src): Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;	
	this->_brain = NULL;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat Copy assignent operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	if (_brain)
		delete _brain;
	_brain = new Brain(*(src._brain));
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaooooou!" << std::endl;	
}
