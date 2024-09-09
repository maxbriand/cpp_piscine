/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:31:03 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/07 15:16:44 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    public:
                Fixed(void);
                Fixed(const Fixed& fixed_number);
                ~Fixed(void);
        Fixed&  operator=(const Fixed& fixed_number);
    public:
				Fixed(const int number);
				Fixed(const float number);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
		float 	toFloat(void) const;
		int 	toInt(void) const;

    private:
        int                 _fixed_point_number;
        static const int    _bits = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed_number);

#endif
