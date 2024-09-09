/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:30:56 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/07 22:50:02 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_point_number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_number = roundf(number * (1 << _bits));
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_number = roundf(number * (1 << _bits));
}

Fixed::Fixed(const Fixed& fixed_number)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = fixed_number;
}

Fixed&  Fixed::operator=(const Fixed& fixed_number)
{    
	std::cout << "Copy assignment operator called" << std::endl;
    this->_fixed_point_number = fixed_number._fixed_point_number;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float) _fixed_point_number / (1 << _bits));
}

int	Fixed::toInt(void) const
{
	return(_fixed_point_number / (1 << _bits));	
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixed_point_number);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed_point_number = raw;
}

std::ostream& operator<<(std::ostream& o, const Fixed& fixed_number)
{
	o << fixed_number.toFloat();
	return (o);
}
