/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:30:01 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/05 17:37:01 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): number(0){}

Fixed::~Fixed(void){}

Fixed::Fixed(const Fixed& fixed_point)
{
    *this = fixed_point;
}

Fixed&  Fixed::operator=(const Fixed& fixed_point)
{    
    this->number = fixed_point.number;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return(this->number);
}

void    Fixed::setRawBits(int const raw)
{
    this->number = raw;
}
