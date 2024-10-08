/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:30:01 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/06 17:36:48 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed_point)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = fixed_point;
}

Fixed&  Fixed::operator=(const Fixed& fixed_point)
{    
	std::cout << "Copy assignment operator called" << std::endl;
    this->_number = fixed_point._number;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
    return(this->_number);
}

void    Fixed::setRawBits(int const raw)
{
    this->_number = raw;
}
