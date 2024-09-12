/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:32:53 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/09 15:55:12 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;	
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src): WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;	
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << "WrongCat Copy assignent operator called" << std::endl;
	this->_type = src._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongMiaooooou!" << std::endl;	
}
