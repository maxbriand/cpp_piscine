/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:30:56 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/08 21:49:12 by mbriand          ###   ########.fr       */
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

Fixed	Fixed::operator+(const Fixed& rn) const
{
	return Fixed(this->toFloat() + rn.toFloat());	
}

Fixed	Fixed::operator-(const Fixed& rn) const
{
	return Fixed(this->toFloat() - rn.toFloat());	
}

Fixed	Fixed::operator*(const Fixed& rn) const
{
	return Fixed(this->toFloat() * rn.toFloat());	
}

Fixed	Fixed::operator/(const Fixed& rn) const
{
	return Fixed(this->toFloat() / rn.toFloat());	
}

bool	Fixed::operator>(const Fixed& rn) const
{
	if (this->toFloat() > rn.toFloat())
		return (1);
	else
		return (0);
}

bool	Fixed::operator<(const Fixed& rn) const
{
	if (this->toFloat() < rn.toFloat())
		return (1);
	else
		return (0);
}

bool	Fixed::operator>=(const Fixed& rn) const
{
	if (this->toFloat() >= rn.toFloat())
		return (1);
	else
		return (0);
}

bool	Fixed::operator<=(const Fixed& rn) const
{
	if (this->toFloat() <= rn.toFloat())
		return (1);
	else
		return (0);
}

bool	Fixed::operator==(const Fixed& rn) const
{
	if (this->toFloat() == rn.toFloat())
		return (1);
	else
		return (0);
}

bool	Fixed::operator!=(const Fixed& rn) const
{
	if (this->toFloat() != rn.toFloat())
		return (1);
	else
		return (0);
}

Fixed&	Fixed::operator++(void)
{
	_fixed_point_number++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed save = *this;
	_fixed_point_number++;
	return (save);
}

Fixed&	Fixed::operator--(void)
{
	_fixed_point_number--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed save = *this;
	_fixed_point_number++;
	return (save);
}

Fixed&	Fixed::min(Fixed& fp1, Fixed& fp2)
{
	if (fp1.getRawBits() > fp2.getRawBits())
		return (fp2);
	else if (fp1.getRawBits() < fp2.getRawBits())
		return (fp1);
	return (fp1);
}

const Fixed&	Fixed::min(const Fixed& fp1, const Fixed& fp2)
{
	if (fp1.getRawBits() > fp2.getRawBits())
		return (fp2);
	else if (fp1.getRawBits() < fp2.getRawBits())
		return (fp1);
	return (fp1);
}

Fixed&	Fixed::max(Fixed& fp1, Fixed& fp2)
{
	if (fp1.getRawBits() > fp2.getRawBits())
		return (fp1);
	else if (fp1.getRawBits() < fp2.getRawBits())
		return (fp2);
	return (fp1);
}

const Fixed&	Fixed::max(const Fixed& fp1, const Fixed& fp2)
{
	std::cout << "const max " << fp1.toFloat() << " and " << fp2.toFloat() << std::endl;
	if (fp1.getRawBits() > fp2.getRawBits())
		return (fp1);
	else if (fp1.getRawBits() < fp2.getRawBits())
		return (fp2);
	return (fp1);
}
