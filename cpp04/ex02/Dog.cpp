/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:40:23 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/11 16:17:38 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;	
	_type = "Dog";
	_brain = new Brain;
}

Dog::Dog(const Dog& src): AAnimal()
{
	std::cout << "Dog copy constructor called" << std::endl;	
	this->_brain = NULL;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog Copy assignent operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	if (_brain)
		delete _brain;
	_brain = new Brain(*(src._brain));
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouuuuf!" << std::endl;	
}
